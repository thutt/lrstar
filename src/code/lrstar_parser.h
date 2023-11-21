
/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//    LRSTAR Parser Header

#if !defined(_LRSTAR_PARSER_H_)
#define _LRSTAR_PARSER_H_

enum ast_pass_t {
   FIRST_PASS  = 1,
   SECOND_PASS = 2,
   THIRD_PASS  = 3,
   FOURTH_PASS = 4,
};

class Symbol         // Symbol in Symbol Table.
{
public:
   char*  start;     // Start of symbol in input file or ?.
   int    length;    // Length of symbol.
   int    cell;      // Cell number in hash vector (if need to delete later).
   int    type;      // Type of symbol: int, char, float, short, ...
   int    term;      // Terminal number for lookup function.
   int    scope;     // Scope: global, local, inner loop, ...
};

class Node           // AST Node.
{
public:
   int    id;        // Node ID number  .                         4
   int    sti;       // Symbol-table index (perm or temp var).    4
   int    line;      // Line number in input file.                4
   char*  start;     // Start of symbol in input area.            4
   Node*  prev;      // Previous node.                            4
   Node*  next;      // Next node.                                4
   Node*  child;     // Child node.                               4
   Node*  parent;    // Parent node.                              4  32 bytes
};

class PStack         // Parser stack.
{
public:
   int    state;     // Parser state.
   int    sym;       // Tail symbol.
   int    sti;       // Symbol table index.
   int    line;      // Input line number.
   char*  start;     // Start of symbol in input file area.
   Node*  node;      // Pointer to node.
   Node*  last;      // Pointer to last in list.
};

class RStack         // Restore Stack.
{
public:
   PStack* ptr;      // Parse stack pointer.       4  4
   int     state;    // State.                        4
   int     sym;      // Symbol.                       4  12 bytes.
};

class SStack         // State stack.
{
public:
   int    state;     // Parser state.
};

class Stack          // AST Stack.
{
public:
   int    id;        // Node id.                      4
   int    counter;   // Counter of node accesses.     4   8 bytes
};


class lrstar_user_data_t {
   /* Extend this class for storing user data in the parser.
    * Use 'user_data' field.
    */
};


class lrstar_parser
{
public:
   /*
    * XXX This options should be resolved at compile time for
    *     performance reasons.
    */

   const bool opt_actions;            /* Init & terminate actions.    */
   const bool opt_debug_parser;       /* Debugging diagnostics.       */
   const bool opt_debug_trace;        /* Tracing.                     */
   const bool opt_expecting;          /* Expecting.                   */
   const bool opt_insensitive;        /* Case insensitive parser.     */
   const int  opt_lookaheads;         /* Non-deterministic lookahead. */
   const bool opt_make_ast;           /* Build AST.                   */
   const bool opt_nd_parsing;         /* Non-deterministic. parsing.  */
   const int  opt_nd_threads;         /* nd_parsing thread count.     */
   const bool opt_node_actions;       /* Node Actions.                */
   const bool opt_reversable;         /* Reversable grammar.          */
   const bool opt_semantics;          /* Semantics.                   */
   const int  opt_stksize;            /* Stack Size.                  */
   const bool opt_term_actions;       /* Term Actions.                */

public:
   lrstar_user_data_t *user_data;

public:
   lexer_t         lt;   /* Lexer tables. */
   parser_tables_t pt;   /* Parser tables. */

public:
   // Parser functions
   void    init_parser  (char* path, char* input, int max_syms, int max_nodes);
   int     parse        ();
   void    term_parser  ();
   void    print_prod   (const char* prefix, int p, int dot);

public:
   const char *grammar;         /* Name of grammar. */

public:
   // Parser variables
   char    path[256];     // Path of input file.
   PStack *PSstart;       // Parser stack start.
   PStack *PS;            // Parse stack pointer.
   int     n_nodes;       // Number of nodes in AST.
   int     n_symbols;     // Number of symbols.
   int     n_errors;

private:
   // Parser functions
   void    reduce       (int p);
   int     linkup       (int p);

private:
   // Parser variables
   RStack *RS;
   RStack *RSstart;
   uchar  *T_exp;       // Terminal expected.
   uchar  *S_exam;      // State examined.

   // Expecting functions ...
   int     restore      ();
   void    syntax_error (const char*, Token*, const char *);
   void    expecting    (int x);
   void    reduction    (int p, int x);
   void    print_terms  (int x);
   void    sort_terms   (int*);
   void    print_stack  ();

   // ND parsing ...
   int     LA;                     // Look Ahead token.
   int     n_warnings;             // Numbor of warnings.
   int     last_line;
   SStack **SS;                    // State stack pointer.
   SStack **SSstart;               // State stack start.
   int     *State;                 // State, during lookahead.
   int     *Action;                // Parsing action.
   int     *Parsed;                // Parsed (0 or 1).
   int     *LAcount;               // Lookahead count.

   void    nd_optimize       ();
   int     nd_parser         (int x, int t, int i);
   int     nd_parser_la      (int i, int la);
   void    print_action      (const char* str, int i);
   void    print_actions     (int na);
   void    print_lookaheads  ();

   // Symbol-Table Area ...
public:
   int     init_symtab  (int max_symbs);
   void    term_symtab  ();
   void    print_symtab ();
   int     add_symbol   (int, char*, char*);
   char*   symbol_name  (int sti);
   char*   symbol_name  (char* start, char* end);

public:
   static Symbol* symbol;        // Symbol.

private:
   uint    hashdiv;       // Hash divisor.
   int*    hashvec;       // Hash vector.
   int     max_cells;     // Maximum number of cells in the hash vector.
   int     max_symbols;   // Maximum number of symbols.

   // AST Area ...
public:
   Node*      root;             // Current root node.
   Node*      node;             // Current AST node.
   ast_pass_t traversal;        // AST traversal number: 1, 2, 3 ...
   int        direction;        // Node direction: TOP_DOWN, BOTTOM_UP.
   Stack*     stack;            // AST stack array.
   int        stacki;           // AST stack index.

private:
   int     max_nodes;     // Maximum number of nodes.
   int*    counter;       // Node counter array.
   Node*   nodearea;      // Node area or Node block allocated.
   char    indent[256];   // Indentation for printing current node.
   char    draw_plus[3];
   char    draw_vbar[3];
   char    draw_last[3];
   char    draw_space[3];

public:
   int     init_ast    (int max_nodes);
   void    term_ast    ();
   Node*   new_node    ();
   void    find_root   (Node* last);
   void    print_ast   ();
   void    print_ast   (Node* n);
   void    traverse    (ast_pass_t trav);
   void    traverse    (Node* n);
   void    traverse    (char* indent, Node* n);
   void    print_node  (char* indent, Node* n);
   void    tracer      (Node* n);

   lrstar_parser(const char         *grammar_,
                 lrstar_user_data_t *user_data_,
                 bool                actions_,
                 bool                debug_parser_,
                 bool                debug_trace_,
                 bool                expecting_,
                 bool                insensitive_,
                 int                 lookaheads_,
                 bool                make_ast_,
                 bool                nd_parsing_,
                 int                 nd_threads_,
                 bool                node_actions_,
                 bool                reversable_,
                 bool                semantics_,
                 int                 stksize_,
                 bool                term_actions_) :
         grammar(grammar_),
         user_data(user_data_),
         opt_actions(actions_),
         opt_debug_parser(debug_parser_),
         opt_debug_trace(debug_trace_),
         opt_expecting(expecting_),
         opt_insensitive(insensitive_),
         opt_lookaheads(lookaheads_),
         opt_make_ast(make_ast_),
         opt_nd_parsing(nd_parsing_),
         opt_nd_threads(nd_threads_),
         opt_node_actions(node_actions_),
         opt_reversable(reversable_),
         opt_semantics(semantics_),
         opt_stksize(stksize_),
         opt_term_actions(term_actions_),
         n_errors(0)
   {
      PSstart = new PStack[opt_stksize];
      RSstart = new RStack[opt_stksize];

      if (opt_nd_parsing) {
         SS      = new SStack *[opt_nd_threads];
         SSstart = new SStack *[opt_nd_threads];
         State   = new int[opt_nd_threads];
         Action  = new int[opt_nd_threads];
         Parsed  = new int[opt_nd_threads];
         LAcount = new int[opt_lookaheads + 1];
      }
   }

};
#endif
/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
