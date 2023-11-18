/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//    LRSTAR Parser Code

#include <string.h>
#include "lrstar_basic_defs.h"
#include "lrstar_library_defs.h"
#include "lrstar_parser.h"
#include "lrstar_main.h"

#define  UINT_MAX  0xffffffff
#define  INT_MAX   0x7fffffff
#define  EOF_CHAR          26
#define  FAILURE            0


// Symbol-table variables ...
Symbol*  lrstar_parser::symbol;


// lowercase[x] is x.
static const uchar lowercase[256] = {
   0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
   16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
   32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
   48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
   64, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
   112,113,114,115,116,117,118,119,120,121,122, 91, 92, 93, 94, 95,
   96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
   112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,

   128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,
   144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,
   160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,
   176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,
   192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,
   208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,
   224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,
   240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255
};



int   lrstar_parser::init_parser (char* patharg, char* input_start, int max_syms, int max_nodes)
{
   if (opt_nd_parsing) {
      for (int i = 0; i < opt_nd_threads; i++)
      {
         SSstart[i] = new SStack[opt_stksize];
      }
      for (int i = 0; i < opt_lookaheads + 1; i++)
      {
         LAcount[i] = 0;
      }
      last_line = 0;
      n_warnings = 0;
   }

   strcpy (path, patharg);
   PS           = PSstart;             // Set parse-stack pointer.
   n_errors     = 0;                   // Set number of errors.
   n_nodes      = 0;                   // In case of no parser creation.

   lt.init_lexer (input_start, 3);     // Initialize the lexer.
   init_symtab (max_syms);             // Initialize the symbol table.

   if (opt_make_ast) {
      init_ast (max_nodes);            // Initialize the parser.
   }

   if (opt_actions) {
      (*pt.init_func[0])(this);          // init_action()
   }

   T_exp  = new uchar[pt.n_terms];
   S_exam = new uchar[pt.n_states];

   memset (T_exp,  0, pt.n_terms);
   memset (S_exam, 0, pt.n_states);
   return 1; // Return OK.

Err:  n_errors++;
   return 0;

   goto Err; // Stops compiler from complaining.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  lrstar_parser::term_parser ()
{
   if (opt_make_ast) {
      term_ast();
   }

   term_symtab ();
   if (opt_actions) {
      (*pt.init_func[1])(this);               // term_action()
   }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//    LR Parser

int   lrstar_parser::parse ()
{
   int x, t, T, p;
   x = 0;                                          // State = 0 to start.
Read:
   T = t = lt.get_token ();                        // Get incoming token.
   if (opt_term_actions) {
      if (pt.tact_numb[t] >= 0) {                  // If token action ...
         lt.token.sti = (*pt.tact_func[pt.tact_numb[t]])(this, t);  // Call token-action function.
      }
   } else {
      lt.token.sti = -t;
   }
   if (opt_expecting) {
      RS = RSstart;
      RS->state = x;
      RS->ptr = PS;
   }

Test:
   if (pt.Bm[pt.Br[x] +
             pt.Bc[t]] & pt.Bf[t])              // Check B-matrix for shift action.
   {
      PS++;
      PS->state = x;                            // Put current state on stack.
      PS->sti   = lt.token.sti;                 // Put symbol-table index on stack.
      if (opt_make_ast) {
         PS->line  = lt.token.line;             // Put line number on stack.
         PS->start = lt.token.start;            // Put start address on stack.
         PS->node  = 0;                         // Set node on stack to zero.
      }

      if (opt_expecting) {
         PS->sym   = -t;                        // Put symbol on stack.
      }
      x = pt.Tm[pt.Tr[x] +
                pt.Tc[t]];                      // Get next state from terminal transition matrix.
      while (x < 0)                             // While shift-reduce actions.
      {
         p = -x;
      SR:
         PS -= pt.PL[p];                        // Reduce stack ptr by production length.
         if (opt_expecting) {
            PS->sym = pt.head_numb[p];          // Put symbol on stack.
         }
         reduce (p);                            // Call reduce action with production number.
         x = pt.Nm[pt.Nr[PS->state] +
                   pt.Nc[p]];                   // Get next state from nonterminal transition.
      }
      goto Read;                                // Go to read next token.
   }
   if ((p = pt.Rr[x]) > 0 ||                    // Default reduction 90% of the time.
       (p = pt.Rm[pt.Rc[t] - p]) > 0)           // Compute reduction?
   {
   Red:
      PS -= pt.PL[p];                              // Reduce parse stack ptr by rule length - 1.
      if (pt.PL[p] < 0)                            // Null production?
      {
         if (opt_expecting) {
            RS++;
            RS->ptr   = PS;
            RS->state = PS->state;
            RS->sym   = PS->sym;
         }
         PS->state = x;                         // Stack current state, replacing old state.
         if (opt_make_ast) {
            PS->node  = 0;                      // Set node on stack to zero.
         }
      }
      while (1)
      {
         if (opt_expecting) {
            PS->sym = pt.head_numb[p];                // Put symbol on stack.
         }
         reduce (p);                            // Call reduce action with production number.
         x = pt.Nm[pt.Nr[PS->state] +
                   pt.Nc[p]];                   // Get next state from nonterminal transition.
         if (x > 0) goto Test;                  // Continue parsing.
         p = -x;                                // Set production number.
         PS -= pt.PL[p];                        // Reduce parse stack ptr by rule length - 1.
      }
   }

   if (opt_nd_parsing) {
      int i, j, na, y;
      for (i = pt.nd_fterm[x]; i < pt.nd_fterm[x+1]; i++)   // For all ND terminals in this state.
      {
         if (pt.nd_term[i] == t)                      // Got a match?
         {
            j = pt.nd_faction[i];                     // Start of actions.
            na = 0;                                // Number of actions.
            do
            {
               State[na] = x;                      // Copy this state.
               Action[na++] = pt.nd_action[j];        // Copy this action.
            }
            while (++j < pt.nd_faction[i+1]);         // While there's more.
            y = nd_parser (x,t,na);                // ND lookahead parser.
            if (y > 0)                             // Shift?
            {
               PS++;                               // Increment parser stack pointer.
               PS->state = x;                      // Put current state on stack.
               PS->sti   = lt.token.sti;           // Put symbol table index on stack.
               if (opt_make_ast) {
                  PS->line  = lt.token.line;       // Put line number on stack.
                  PS->start = lt.token.start;      // Put start address on stack.
                  PS->node  = 0;                   // Set node on stack to zero.
               }
               if (y > pt.accept_state) { // Shift and reduce action?
                  p = y - pt.accept_state;            // Shift and reduce.
                  goto SR;                         // Go to shift reduce.
               }
               if (opt_expecting) {
                  PS->sym = -t;                       // Put symbol on stack.
               }
               x = y;                              // Shift and goto.
               goto Read;                          // Go to read another token.
            }
            if (y < 0)                             // Reduce ?
            {
               p = -y;                             // Reduce action.
               goto Red;                           // Go to reduce.
            }
         }
      }
   }

   if (x == pt.accept_state)                       // If Goal production.
   {
      PS -= pt.PL[p];                              // Reduce parse stack ptr by rule length - 1.
      reduce (p);                               // Call reduce action with production number.
      if (opt_nd_parsing) {
         print_lookaheads();                       // Print lookahead statistics.
      }
      print_symtab ();                          // Print the symbol table contents.
      if (opt_make_ast) {
         find_root (PS[0].node);
         print_ast ();
         traverse (FIRST_PASS);
      }

      if (opt_debug_parser) {
         fprintf (output, "\nDone.\n\n");
      }
      return lt.linenumb - 1;                // Success.
   }

   if (opt_expecting) {
      x = restore ();
      if (t != 0) {
         t = 0;                                    // Try <error>
         goto Test;
      }
   }

   if (n_errors < INT_MAX) {                   // Error message not printed?
      if (opt_expecting) {
         print_stack ();
      }
      syntax_error ("Error", &lt.token, pt.term_symb[T]);
      if (opt_expecting) {
         expecting (x);
         print_terms (x);
      }
   }
   return -lt.linenumb; // Failure.

   goto SR;  // Stops compiler from complaining.
   goto Red; // Stops compiler from complaining.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  lrstar_parser::reduce (int p)
{
   if (opt_semantics) {
      if (pt.argy[p] >= 0) {
         symbol[PS[0].sti].term = pt.argy[p];
      }
   }
   if (opt_make_ast) {
      int psi;                                        // Parse stack index.
      if (pt.node_numb[p] >= 0)                       // MAKE NODE ?
      {
         Node* n   = new_node ();                     // Get a new node.
         n->id     = pt.node_numb[p];                 // Set node id number.
         n->prev   = 0;                               // Set prev to nonexistent.
         n->next   = 0;                               // Set next to nonexistent.
         n->child  = 0;                               // Set child to nonexistent.
         n->parent = 0;                               // Set parent to nonexistent.
         if (pt.argx[p] >= 0)                         // If first argument specified.
         {
            psi      = pt.argx[p];                    // Get parse-stack index.
            n->sti   = PS[psi].sti;                   // Move sti from parse stack to node.
            n->line  = PS[psi].line;                  // Move line from parse stack to node.
            n->start = PS[psi].start;                 // Move start from parse stack to node.
         }
         else // No argument on production.
         {
            n->sti   = 0;                             // Set symbol-table index to zero.
            n->line  = 0;                             // Set line number to zero.
            n->start = 0;
         }
         psi = linkup(p);                             // Linkup the nodes in this rule.
         if (psi >= 0)                                // Any nodes found in this rule?
         {
            n->child = PS[psi].node;                  // Define child.
            PS[psi].node->parent = n;                 // Define parent.
         }
         PS[0].node = n;                              // Define this node in the parse stack.
         PS[0].last = n;                              // Define this node in the parse stack.
      }
      else                                            // Check for nodes not linked?
      {
         psi = linkup (p);                            // Get parse-stack index.
         if (psi > 0)                                 // If we have a node here ...
         {
            PS[0].node = PS[psi].node;                // Move node to 1st position.
            PS[0].last = PS[psi].last;                // Move last also.
         }
      }
   }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////

int   lrstar_parser::nd_parser (int x, int t, int na)
{
   int  i;
   int  la;             // Lookaheads to try.
   int  total;          // Total number parsed.
   int  limit;          // Lookahead limit.
   char string[64];

   if (opt_debug_parser) {
      if (lt.token.line > last_line) {
         printf ("\n");
      }
      last_line = lt.token.line;
      sprintf (string, "In state %d", x);
      printf ("////////////////////////////////////////////////////////////\n");
      syntax_error (string, &lt.token, pt.term_symb [t]);
      printf ("\n   STARTED LR(*) parsing for the following choices:\n\n");
      print_actions (na);
      n_warnings++;
   }

   // COPY PARSE STACK TO ND STATE STACK FOR EACH ACTION ...
   for (i = 0; i < na; i++)
   {
      SS[i] = SSstart[i];
      for (PStack* P = PSstart; P < PS;)
      {
         (++SS[i])->state = (++P)->state;
      }
      Parsed[i] = 1;
   }

   // TRY TO ACCEPT LOOKAHEAD TOKENS ...
   LA = t;
   total = 0;
   la = 0;
   i = 0;
   do
   {
      if (Parsed[i] > 0)
      {
         total += Parsed[i] = nd_parser_la (i,la);
      }
   }
   while (++i < na);

   // ONE ACTION SUCCEEDED ? ...
   if (total == 1)
   {
      LAcount[1]++;
      if (opt_debug_parser) {
         n_warnings = 0;
      }
      i = 0;
      do
      {
         if (Parsed[i] > 0) {
            if (opt_debug_parser) {
               printf("   CHOOSING ");
               print_action("", i);
               printf ("\n");
            }
            return Action[i];
         }
      }
      while (++i < na);
   }

   lt.lookahead.end = lt.token.end; // Prime get_lookahead().
   lt.lookahead_linenumb = lt.linenumb;
   limit = opt_lookaheads;
   la = 1;
   do
   {
      total = 0;
      LA = lt.get_lookahead();
      if (opt_term_actions) {
         if (pt.tact_numb[LA] >= 0) {                // If term action ...
            (*pt.tact_func[pt.tact_numb[LA]])(this, LA);   // Call term-action function.
         }
      }

      if (LA == pt.eof_symb) {
         limit = la; // <eof> ?
      }
      i = 0;
      do
      {
         if (Parsed[i] > 0)
         {
            total += Parsed[i] = nd_parser_la (i,la);
         }
      }
      while (++i < na);

      // ONE ACTION SUCCEEDED ? ...
      if (total == 1)
      {
         LAcount[la+1]++;
         if (opt_debug_parser) {
            n_warnings = 0;
         }
         i = 0;
         do
         {
            if (Parsed[i] > 0)
            {
               if (opt_debug_parser) {
                  printf ("   CHOOSING ");
                  print_action ("", i);
                  printf("\n");
               }
               lt.lookahead.start = 0; // Stop lookahead mode in lookup().
               return Action[i];
            }
         }
         while (++i < na);
      }

      // TOKEN NOT ACCEPTED, SYNTAX ERROR ...
      if (total == 0)
      {
         if (n_warnings == 0)
         {
            syntax_error ("Error", &lt.lookahead, pt.term_symb[LA]);
            printf ("\n   AMBIGUITY after %d lookaheads, unable to choose from:\n\n", la+1);
            print_actions(na);
         }
         else printf ("\n   AMBIGUITY after %d lookaheads, cannot make a decision.\n", la+1);
         n_errors = INT_MAX; // No more error messages.
         return FAILURE;
      }
   }
   while (++la < limit);

   // TRIED ALL LOOKAHEADS, STILL AMBIGUOUS ...
   LAcount[limit]++;
   if (Action[0] > 0) // Shift action?
   {
      if (opt_debug_parser) {
         printf("\n   AMBIGUITY after %d lookaheads, "
                "choosing the Shift action.\n", limit);
         printf("\n");
         n_warnings = 0;
      }
      lt.lookahead.start = 0; // Stop lookahead mode in lookup().
      return Action[0];
   }

   // Some parsers choose the lowest numbered reduction.
   // Not a good idea, because the grammar is ambiguous.
   // Fix the grammar or increase option /k, if necessary.
   if (opt_debug_parser) {
      printf("\n   AMBIGUITY after %d lookaheads, unable to decide.\n", limit);
   } else {
      sprintf (string, "In state %d", x);
      syntax_error (string, &lt.token, pt.term_symb[t]);
      printf ("\n   AMBIGUITY after %d lookaheads, unable to choose from:\n\n", limit);
      print_actions (na);
   }
   n_errors = INT_MAX; // No more error messages.
   return FAILURE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  lrstar_parser::print_actions (int na)
{
   int i = 0;
   do
   {
      print_action ("   * ", i);
   }
   while (++i < na);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  lrstar_parser::print_action (const char* str, int i)
{
   printf ("%s", str);
   int y = Action[i];
   if (y > 0)
   {
      printf ("Shift %s and ", symbol_name (lt.token.sti));
      if (y > pt.accept_state)            // Shift and reduce ?
      {
         int p = y - pt.accept_state;     // Convert to production number.
         print_prod ("reduce", p, -1);
      }
      else printf ("goto %d\n", y);
   }
   else
   {
      print_prod ("Reduce", -y, 0);
   }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   lrstar_parser::nd_parser_la (int i, int la)            // ND LA Parser.
{
   int p;                                          // Production (rule).
   if (la == 0) // LA is first one?
   {
      if (Action[i] > 0)                           // Shift and goto action?
      {
         SS[i]++;
         SS[i]->state = State[i];                  // Put State stack.
         if (Action[i] > pt.accept_state)             // Shift and reduce?
         {
            State[i] = pt.accept_state - Action[i];   // Convert to production number.
            goto SR;
         }
         State[i] = Action[i];                     // Get next state.
         return 1;
      }
      p = -Action[i];                              // Get production.
      goto Red;                                    // Reduce.
   }

Shft:
   if (pt.Bm[pt.Br[State[i]] +
             pt.Bc[LA]] & pt.Bf[LA])               // Check B-matrix for shift action.
   {
      SS[i]++;
      SS[i]->state = State[i];                     // Put current state on stack.
      State[i] = pt.Tm[pt.Tr[State[i]] +
                       pt.Tc[LA]];       // Get next state from terminal transition matrix.
      while (State[i] < 0)                         // While shift-reduce actions.
      {
      SR:
         p = -State[i];
         SS[i] -= pt.PL[p];                           // Reduce stack ptr by production length.
         State[i] = pt.Nm[pt.Nr[SS[i]->state] +
                          pt.Nc[p]]; // Get next state from nonterminal transition matrix.
      }
      return 1;                                    // Return success.
   }

   if ((p = pt.Rr[State[i]]) > 0 ||                      // Default reduction?
       (p = pt.Rm[pt.Rc[LA] - p]) > 0)                 // Compute reduction?
   {
   Red:
      SS[i] -= pt.PL[p];                              // Reduce parse stack ptr by rule length - 1.
      if (pt.PL[p] < 0) {
         SS[i]->state = State[i];      // Stack current state.
      }
      while (1) {
         State[i] = pt.Nm[pt.Nr[SS[i]->state] +
                          pt.Nc[p]]; // Get next state from nonterminal transition.
         if (State[i] > 0) goto Shft;              // If a state, continue parsing.
         p = -State[i];                            // Make the production number positive.
         SS[i] -= pt.PL[p];                           // Reduce parse stack ptr by rule length - 1.
      }
   }

   if (State[i] == pt.accept_state) {
      return 1;
   }

   // LOOK FOR A SHIFT ACTION FOR THIS TOKEN ...
   for (int j = pt.nd_fterm [State[i]];
        j < pt.nd_fterm [State[i]+1]; j++)
   {
      if (pt.nd_term[j] == LA)
      {
         int k = pt.nd_faction[j];
         if (pt.nd_action[k] > 0)                        // Shift action (always first one)?
         {
            SS[i]++;
            SS[i]->state = State[i];                  // Put State on stack.
            if (pt.nd_action[k] > pt.accept_state)          // Shift and reduce?
            {
               State[i] = pt.accept_state - pt.nd_action[k];// Convert to production number.
               goto SR;
            }
            State[i] = pt.nd_action[k];
            return 1;
         }
         if (opt_debug_parser) {
            // A recursive call to nd_parse() is needed to continue
            // the ND lookahead parsing.  This version of the LR(*)
            // algorithm does not support 2nd, 3rd or more depths of
            // recursion.  Probably the grammar has ambiguity that
            // needs to be resolved.
            n_warnings++;
            char string[16];
            sprintf (string, "In state %d", State[i]);
            if (la == 0) {
               syntax_error (string, &lt.token, pt.term_symb[LA]);
            } else {
               syntax_error (string, &lt.lookahead, pt.term_symb[LA]);
            }
            printf ("\n   STOPPED LR(*) parsing after %d lookaheads, "
                    "for conflicting actions:\n\n", la + 1);
            do {
               print_prod ("   * Reduce", -pt.nd_action[k], 0);
            } while (++k < pt.nd_faction[j+1]);
            print_action ("\n   IGNORING ", i);
         }
         return 0;
      }
   }
   if (opt_debug_parser) {
      char string[16];
      sprintf (string, "In state %d", State[i]);
      if (la == 0) {
         syntax_error (string, &lt.token, pt.term_symb[LA]);
      } else {
         syntax_error (string, &lt.lookahead, pt.term_symb[LA]);
      }
      print_action ("\n   IGNORING ", i);
   }
   return 0; // Did not find a match for LA in this state.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  lrstar_parser::print_lookaheads()
{
   int n = 0;
   for (int i = 0; i <= opt_lookaheads; i++)
   {
      if (LAcount[i] != 0)
      {
         const char* msg;
         if (n++ == 0) printf ("\n");
         if (LAcount[i] == 1) msg = "time";
         else                 msg = "times";
         if (i == 1)
            printf  ("      %3d Lookahead  needed: %6d %s\n", i, LAcount[i], msg);
         else printf  ("      %3d Lookaheads needed: %6d %s\n", i, LAcount[i], msg);
      }
   }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////

int   lrstar_parser::restore ()
{
   while (RS > RSstart)   // Restore PS, RS and states.
   {
      RS->ptr->state = RS->state;   // Reset state to saved state.
      RS->ptr->sym   = RS->sym;     // Reset symbol to saved symbol.
      RS--;
   }
   PS = RS->ptr;
   return RS->state;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  lrstar_parser::syntax_error (const char *msg, Token* T, const char* symb)
{
   char  c;
   char* p;
   char* lineout;
   char* pointer;
   char* linestart;
   char  string[256];

   n_errors++;
   if (*T->start <= 32)
   {
      T->end = T->start+1;
      *(T->end) = '\n';
      if (*T->start == 26) T->line--;
   }

   // Get line start ...
   for (linestart = T->start; *linestart != '\n'; linestart--);
   linestart++;

   // Get untabified line ...
   pointer = T->start;
   lineout = lt.untabify (linestart, pointer);

   // Make pointer line ...
   int i = 0;
   for (p = lineout; p < pointer; p++) string[i++] = '-';
   string[i] = 0;

   printf ("\n%s(%d) : %s, %s\n", path, T->line, msg, lineout);
   printf (  "%s(%d) : %s, %s^ ", path, T->line, msg, string);

   if (*T->start > 32)
   {
      c = *T->end;
      *T->end = 0;
      printf ("at %s %s\n", T->start, symb);
      *T->end = c;
   }
   else
   {
      int x = *T->start;
      if (x < 0) x += 256;
      printf ("at %d %s\n", x, symb);
   }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  lrstar_parser::expecting (int x)
{
   int t;                                       // Terminal number.
   S_exam[x] = 1;                               // Mark this state as seen.
   for (t = 0; t < pt.n_terms; t++)                // For all terminals.
   {
      if (pt.Bm[pt.Br[x] +
                pt.Bc[t]] & pt.Bf[t])           // Check B-matrix for shift action.
      {
         T_exp[t] = 1;                          // Mark this terminal.
      }
   }

   if (opt_nd_parsing) {
      int i, j;
      for (i = pt.nd_fterm[x]; i < pt.nd_fterm[x+1]; i++)      // For all terminals in this state.
      {
         for (j = pt.nd_faction[i];
              j < pt.nd_faction[i+1]; j++)  // For all actions for these terminals.
         {
            if (pt.nd_action[j] > 0)                        // Terminal transition.
            {
               T_exp[pt.nd_term[i]] = 1;                    // Mark this terminal.
            }
            else if (pt.nd_action[j] < 0)
            {
               int p = -pt.nd_action[j];
               reduction (p, x);
            }
         }
      }
   }
   int p, q;
   if ((p = pt.Rr[x]) > 0)                      // Default reduction?
   {
      reduction (p, x);
      return;
   }
   for (t = 0; t < pt.n_terms; t++)             // For all terminals.
   {
      q = pt.Rm[pt.Rc[t] - p];                    // Reduction for this terminal.
      if (q > 0)                             // If not zero production?
      {
         reduction(q, x);
      }
   }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  lrstar_parser::reduction (int q, int x)
{
   // Save parse stack pointers.
   RStack* RSx = RS;                // Reset restore-stack pointer.
   PStack* PSx = PS;                // Save parse-stack pointer.

   PS -= pt.PL[q];                     // Reduce parse stack ptr by rule length - 1.
   if (pt.PL[q] < 0)                   // Null production?
   {
      (++RS)->ptr = PS;             // Save parse-stack pointer.
      RS->state = PS->state;        // Save old state before replacing it.
      PS->state = x;                // Stack current state, replacing old state.
   }
   while (1)
   {
      x = pt.Nm[pt.Nr[PS->state] +
                pt.Nc[q]];   // Get next state from nonterminal transition.
      if (x > 0)
      {
         if (S_exam[x] == 0)           // Not been there yet?
            expecting (x);             // Recursive call, potential loop, but very rare.
         goto Done;
      }
      q = -x;                          // Set production number.
      PS -= pt.PL[q];                     // Reduce parse stack pointer.
   }

   // Restore parse stack.
Done:
   PS = PSx;                           // Restore PS.
   while (RS > RSx)
   {
      RS->ptr->state = RS->state;      // Reset state to saved state.
      RS--;
   }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  lrstar_parser::print_terms (int state)
{
   printf ("\n");
   if (state >= 0)
   {
      printf ("In state%5d, ", state);
   }
   printf ("Expecting one of the following:\n\n");

   int t, x;
   int* seq = new int [pt.n_terms];
   sort_terms (seq);

   for (t = 0; t < pt.n_terms; t++)
   {
      x = seq[t];
      // if (x == pt.eof_symb) continue;
      if (T_exp[x] == 1)
      {
         if (pt.term_symb[x][0] == '<' ||  pt.term_symb[x][0] == '{') {
            printf ("         %4d %-30s\n", x, pt.term_symb[x]);
         }
      }
   }
   for (t = 0; t < pt.n_terms; t++)
   {
      x = seq[t];
      if (x == pt.eof_symb) {
         continue;
      }
      if (T_exp[x] == 1)
      {
         if (pt.term_symb[x][0] != '<' && pt.term_symb[x][0] != '{') {
            printf ("         %4d %-30s\n", x, pt.term_symb[x]);
         }
      }
   }
   delete [] seq;
}

////////////////////////////////////////////////////////////////////////////////

void  lrstar_parser::sort_terms (int* seq)
{
   /* seq - the sorted sequence:
      name[seq[0]] gives the first name in the sorted list.
   */
   const char **P;
   const char *P_temp;
   int*  L, L_temp, seq_temp, i, j, leng, c;

   L = new int  [pt.n_terms];
   P = new const char *[pt.n_terms];
   for (i = 0; i < pt.n_terms; i++)
   {
      P[i] = pt.term_symb[i];
      L[i] = (int)strlen(pt.term_symb[i]);
      seq[i] = i;
   }
   for (i = 1; i < pt.n_terms; i++) // Bubble sort algorithm.
   {
      P_temp   = P[i];
      L_temp   = L[i];
      seq_temp = seq[i];
      j        = i - 1;
      do
      {
         leng = L[j];
         if (L_temp < L[j]) leng = L_temp;
         c = strncmp (P_temp, P[j], leng);
         if (c < 0 || (c == 0 && L_temp < L[j]))
         {
            P[j+1]   = P[j];
            L[j+1]   = L[j];
            seq[j+1] = seq[j];
            P[j]     = P_temp;
            L[j]     = L_temp;
            seq[j]   = seq_temp;
         }
         else break;
      }
      while (--j >= 0);
   }
   delete [] L;
   delete [] P;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  lrstar_parser::print_prod (const char* prefix, int p, int dot)
{
   const char* symb;
   int len = pt.f_tail[p + 1] - pt.f_tail[p];

   printf ("%s %4d %s -> ", prefix, p, pt.head_symb[pt.head_numb[p]]);
   for (int i = pt.f_tail[p]; i < pt.f_tail[p + 1]; i++)
   {
      int s = pt.tail[i];
      if (s >= 0) {
         symb = pt.term_symb[ s];
      } else {
         symb = pt.head_symb[-s];
      }
      if (len++ == dot) printf (". ");
      printf ("%s ", symb);
   }
   if (len == dot) printf (". ");
   printf ("\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  lrstar_parser::print_stack () // Print parser stack.
{
   if (opt_debug_parser) {
      printf ("\nParse stack:\n");
      for (PStack* ps = PSstart + 1; ps <= PS; ps++) {
         const char *name;
         const char *name2;
         int sym = ps->sym;
         if (sym <= 0) { // Terminal?
            name  = pt.term_symb[-sym];
            name2 = "";
            if (*name == '<' || *name == '{') {
               if (ps->sti > 0) {
                  name2 = symbol_name (ps->sti);
               }
            }
            printf("   state%5d %4d %s %s\n",  ps->state, -sym, name, name2);
         } else { // Nonterminal.
            name = pt.head_symb[sym];
            printf ("   state%5d %4d %s\n", ps->state, sym, name);
         }
      }
   }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   lrstar_parser::init_symtab (int max_symb)
{
   int i;
   n_symbols = 1;                // 0 is reserved for null symbol.
   if (max_symb <= 0)
   {
      printf ("Maximum number of symbols cannot be zero or negative.\n");
      quit (1); // Failure.
   }
   max_symbols = max_symb;
   max_cells   = 2*max_symbols;
   symbol      = new Symbol[max_symbols];
   hashvec     = new int[max_cells];
   hashdiv     = UINT_MAX / max_cells + 1;
   if (symbol == NULL || hashvec == NULL)
   {
      printf ("Not enough memory available for Symbol Table.\n");
      quit (1); // Failure.
   }
   for (i = 0; i < max_cells; i++)
   {
      hashvec[i] = -1;
   }
   return 1; // Success.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  lrstar_parser::term_symtab ()
{
   n_symbols--;
   delete [] symbol;
   delete [] hashvec;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   lrstar_parser::add_symbol (int t, char* token_start, char* token_end)
{
   char* p = token_start;                    // Point at start.
   int   length = (int)(token_end - p);      // Set length.
   uint  hash = length;                      // Set hash to length.
   int   i = 0;                              // Set shift value to 0.
   do {                                      // Assume length != 0
      if (opt_insensitive) {
         hash += lowercase[*p] << i;
      } else {
         hash += *p << i;
      }
      i += 4;
      i %= 32;
   } while (++p < token_end);
   int cell = hash % max_cells;              // Get first cell.
   int sti  = hashvec [cell];                // Get symbol table index.
   while (sti >= 0)                          // Symbol exists?
   {
      if (symbol[sti].length == length)      // If lengths are equal ...
      {
         p = token_start;                    // Point at token start.
         char* start = symbol[sti].start;
         char* end   = start + length;
         do
         {
            if (opt_insensitive) {
               if (lowercase[*p] != lowercase[*start]) {
                  goto Cont;
               }
            } else {
               if (*p != *start) {
                  goto Cont;                 // If characters not equal ...
               }
            }
            start++;
            p++;
         }
         while (start < end);                // while end not reached.
         return sti;                         // Return sti.
      }
   Cont:    cell = (hash *= 65549)/hashdiv;        // Get new cell number.
      sti  = hashvec[cell];                     // Get symbol table index.
   }
   // NEW SYMBOL ...
   if (n_symbols >= max_symbols)             // Reached maximum number?
   {
      printf("\nNumber of symbols exceeds %d.\n\n", max_symbols);
      quit (1); // Failure.
   }
   sti = hashvec[cell] = n_symbols;          // Put symbol number into hash vector.
   symbol[sti].start   = token_start;        // Pointer to original location in input file.
   symbol[sti].length  = length;             // Length of symbol.
   symbol[sti].cell    = cell;               // Cell in the hash vector.
   symbol[sti].type    = 0;                  // Type of symbol: int, char, float, short, ...
   symbol[sti].term    = t;                  // Terminal number for lookup funciton.
   symbol[sti].scope   = 0;                  // Scope: global, local, inner loop, ...
   n_symbols++;
   return sti;                               // Return symbol table index.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  lrstar_parser::print_symtab ()
{
   if (opt_debug_parser) {
      fprintf (output, "\nSymbol Table ...\n\n");
      if (n_symbols > 1) {
         fprintf (output, "   sti  leng  type     name "
                  "                               terminal\n");
         for (int i = 1; i < n_symbols; i++) {
            fprintf(output, " %5d %5d %5d     %-30s %4d %s\n",
                    i,
                    symbol[i].length,
                    symbol[i].type,
                    symbol_name(i),
                    symbol[i].term,
                    pt.term_symb[symbol[i].term]);
         }
      } else { // No symbols in the table.
         fprintf (output, "   Symbol Table is empty.\n");
      }
   }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

char* lrstar_parser::symbol_name (int sti)
{
   int i;
   char* p;
   static char name[100];
   if (sti < 0) // Terminal symbol?
   {
      p = (char *)pt.term_symb[-sti];
      for (i = 0; p[i] != 0; i++) {
         name[i] = p[i];
      }
      name[i] = 0;
   }
   else // Input file symbol.
   {
      int L;
      p = symbol[sti].start;
      L = symbol[sti].length;
      if (L >= 100)
      {
         L = 95;
         for (i = 0; i < L; i++) name[i] = p[i];
         name[i++] = ' ';
         name[i++] = '.';
         name[i++] = '.';
         name[i++] = '.';
         name[i] = 0;
      }
      else
      {
         for (i = 0; i < L; i++) name[i] = p[i];
         name[i] = 0;
      }
   }
   return name;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

char* lrstar_parser::symbol_name (char* start, char* end)
{
   char *p, *q;
   static char name[100];
   if (end - start > 99) end = start + 99;
   p = start;
   q = name;
   do
   {
      *q++ = *p++;
   }
   while (p < end);
   *q = 0;
   return name;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   lrstar_parser::linkup (int p)
{
   int i;
   int next = -1;
   if (opt_reversable && pt.reverse[p] != 0) {        // IF NOT TO REVERSE THE ORDER.
      for (i = 0; i <= pt.PL[p]; i++) {               // For each tail pointer.
         if (PS[i].node != 0) {                       // If tail points to node.
            if (next >= 0) {                          // If one waiting.
               PS[i   ].last->next = PS[next].node;   // Define next node.
               PS[next].node->prev = PS[i].last;      // Define previous node.
               PS[i   ].last       = PS[next].last;   // Change last to next last.
            }
            next = i;                                 // Next = Curr.
         }
      }
   } else {                                           // REVERSE THE ORDER.
      for (i = pt.PL[p]; i >= 0; i--) {               // For each tail pointer.
         if (PS[i].node != NULL) {                    // If tail points to node.
            if (next >= 0) {                          // If one waiting.
               PS[i   ].last->next = PS[next].node;   // Define next node.
               PS[next].node->prev = PS[i   ].last;   // Define previous node.
               PS[i   ].last       = PS[next].last;   // Change last to next last.
            }
            next = i;                                 // Next = Curr.
         }
      }
   }
   return (next);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  lrstar_parser::tracer (Node* n)
{
   if (opt_debug_trace) {
      if (opt_node_actions) {
         const char *dir;
         if      (direction == TOP_DOWN ) {
            dir = "*>";
         } else if (direction == PASS_OVER) {
            dir = "**";
         } else {
            dir = "<*";
         }
         printf("   %d %s %s (%s)\n", traversal, dir,
                pt.node_name[n->id], symbol_name(n->sti));
      }
   }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   lrstar_parser::init_ast (int max)
{
   n_nodes   = 1;
   max_nodes = max;  // max_nodes to allocate as needed.
   nodearea  = new Node[max_nodes];
   if (nodearea == NULL)
   {
      printf ("Not enough memory available for %d parser nodes.\n", max_nodes);
      quit (1); // Failure.
   }
   node         =  new_node();
   node->id     = -1; // Undefined.
   node->sti    =  0;
   node->line   =  0;
   node->start  =  0;
   node->next   =  0;
   node->prev   =  0;
   node->child  =  0;
   node->parent =  0;

   strcpy (draw_plus,  "+ ");
   strcpy (draw_vbar,  "| ");
   strcpy (draw_last,  "+ ");
   strcpy (draw_space, "  ");
   return 1; // Success.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  lrstar_parser::term_ast ()
{
   n_nodes--;
   delete [] stack;
   delete [] counter;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

Node* lrstar_parser::new_node()
{
   if (n_nodes % max_nodes == 0)                   // Filled up nodearea?
   {
      nodearea = new Node[max_nodes];              // Get another nodearea.
      if (nodearea == NULL)                        // Not got?
      {
         printf ("\nNot enough memory available for %d parser nodes.\n\n", max_nodes);
         quit (1); // Failure.
      }
   }
   Node* n = &(nodearea[n_nodes % max_nodes]);
   n_nodes++;
   return n;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  lrstar_parser::find_root (Node* last_node)
{
   root = last_node;                // Define root node.
   if (root != 0)
   {
      while (root->prev != 0)       // In case of a list only.
      {
         root = root->prev;         // Go up the list to first node.
      }
   }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  lrstar_parser::print_ast ()
{
   if (opt_debug_parser) {
      print_ast (root);
   }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  lrstar_parser::print_ast (Node* n) // Print subtree.
{
   char indent [512];
   strcpy (indent, draw_space);
   fprintf (output, "\nAbstract Syntax Tree ...\n\n");
   if (n != 0)
   {
      fprintf (output, "   sti  line   col  \n");
      traverse (indent, n); // Start parser traversal.
   }
   else
   {
      fprintf (output, "   Parser is empty.\n");
   }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  lrstar_parser::traverse(ast_pass_t trav)
{
   if (opt_node_actions) {
      if (n_nodes > 1) { // Any nodes in the tree?
         if (pt.n_nodeactns > 0) { // Any node actions?
            stacki  = -1;
            stack   = new Stack [opt_stksize];
            counter = new int [pt.n_nodenames];
            for (int i = 0; i < pt.n_nodenames; i++)
            {
               counter[i] = 0;
            }
            if (opt_debug_parser) {
               fprintf (output, "\nDoing Tree Traversal ...\n\n");
            } else {
               fprintf (output, "\n");
            }
            traversal = trav;
            Node* n = root;
            do {
               traverse (n);
               n = n->next;
            } while (n != 0);
         }
      }
   }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  lrstar_parser::traverse (Node* n)
{
   if (opt_node_actions) {
      int   i  = n->id;             // Node id.
      Node* c  = n->child;          // Child nove pointer.
      stacki++;
      counter[i]++;
      stack[stacki].id = i;
      stack[stacki].counter = counter[i];
      if (pt.nact_func[i] != 0) // Got a node action ?
      {
         direction = TOP_DOWN;
         tracer (n);
         (*pt.nact_func[i])(this, n);
      }
      while (c != 0)
      {
         traverse (c);
         c = c->next;
         /* if (c != 0)
            {
            if (nact_func[i] != 0) // Got a node action ?
            {
            direction = PASS_OVER;
            tracer (n);
            (*nact_func[i])(n);
            }
            } */
      }
      if (pt.nact_func[i] != 0) // Got a node action ?
      {
         direction = BOTTOM_UP;
         tracer (n);
         (*pt.nact_func[i])(this, n);
      }
      stacki--;
   }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  lrstar_parser::traverse (char *indent, Node* n)
{
   while (n->next != 0)
   {
      strcat (indent, draw_plus);
      print_node (indent, n);
      indent [strlen(indent)-2] = 0;
      if (n->child != 0)
      {
         strcat (indent, draw_vbar);
         traverse (indent, n->child);
         indent [strlen(indent)-2] = 0;
      }
      n = n->next;
   }

   strcat (indent, draw_last);
   print_node (indent, n);
   indent [strlen(indent)-2] = 0;
   if (n->child != 0)
   {
      strcat (indent, draw_space);
      traverse (indent, n->child);
      indent [strlen(indent)-2] = 0;
   }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  lrstar_parser::print_node (char *indent, Node* n)
{
   int id  = n->id;
   int sti = n->sti;
   if (sti != 0) // zero means no symbol.
   {
      int line = n->line;
      char* p = n->start - 1;
      while (*p != '\n') p--;
      int col = (int)(n->start - p);

      fprintf (output, "  %4d  %4d  %4d  %s%s", sti, line, col,
               indent, pt.node_name[id]);

      if (sti > 0) // In the symbol table?
      {
         char* p = symbol[sti].start + symbol[sti].length;
         char ch = *p;
         *p = 0;
         fprintf (output, " (%s)\n", symbol[sti].start);
         *p = ch;
      }
      else // A terminal symbol of the grammar!
      {
         fprintf (output, " (%s)\n", pt.term_symb[-sti]);
      }
   }
   else
   {
      fprintf(output, "     .     .     .  %s%s\n", indent, pt.node_name[id]);
   }
}

//#endif  /* gungla */

//                                                                           //
///////////////////////////////////////////////////////////////////////////////
/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
