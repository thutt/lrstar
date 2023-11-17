
/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//    LRSTAR Parser Header

#if !defined(_LRSTAR_PARSER_H_)
#define _LRSTAR_PARSER_H_

#define  STKSIZE          100       // Parser-stack size.

// AST Traversal Passes.
#define FIRST_PASS       1
#define SECOND_PASS      2
#define THIRD_PASS       3
#define FOURTH_PASS      4

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
private:
   /*
    * XXX This options should be resolved at compile time for
    *     performance reasons.
    */

   bool actions;                /* Init & terminate actions.  */
   bool debug_parser;           /* Debugging diagnostics.     */
   bool debug_trace;            /* Tracing.                   */
   bool insensitive;            /* Case insensitive parser.   */
   bool make_ast;               /* Build AST.                 */
   bool node_actions;           /* Node Actions.              */
   bool reversable;             /* Reversable grammar.        */
   bool term_actions;           /* Term Actions.              */

public:
   lrstar_user_data_t *user_data;


public:
   lexer_t         lt;   /* Lexer tables. */
   parser_tables_t pt;   /* Parser tables. */

public:
   // Parser functions
   int     init_parser  (char* path, char* input, int max_syms, int max_nodes);
   int     parse        ();
   void    term_parser  ();
   void    print_prod   (const char* prefix, int p, int dot);

public:
   // Parser variables
   char    path[256];     // Path of input file.
   PStack  PSstart[STKSIZE];     // Parser stack start.
   PStack* PS;            // Parse stack pointer.
   int     n_nodes;       // Number of nodes in AST.
   int     n_symbols;     // Number of symbols.

private:
   // Parser functions
   void    reduce       (int p);
   int     linkup       (int p);

private:
   // Parser variables
   RStack* RS;
   RStack  RSstart[STKSIZE];
   uchar*  T_exp;       // Terminal expected.
   uchar*  S_exam;      // State examined.

   // Expecting functions ...
   int     restore      ();
   void    syntax_error (const char*, Token*, const char *);
   void    expecting    (int x);
   void    reduction    (int p, int x);
   void    print_terms  (int x);
   void    sort_terms   (int*);
   void    print_stack  ();

   // ND parsing ...
#ifdef ND_PARSING
   int     LA;                     // Look Ahead token.
   int     n_warnings;             // Numbor of warnings.
   int     last_line;
   SStack* SS      [ND_THREADS];   // State stack pointer.
   SStack* SSstart [ND_THREADS];   // State stack start.
   int     State   [ND_THREADS];   // State, during lookahead.
   int     Action  [ND_THREADS];   // Parsing action.
   int     Parsed  [ND_THREADS];   // Parsed (0 or 1).
   int     LAcount [LOOKAHEADS+1]; // Lookahead count.

   void    nd_optimize       ();
   int     nd_parser         (int x, int t, int i);
   int     nd_parser_la      (int i, int la);
   void    print_action      (const char* str, int i);
   void    print_actions     (int na);
   void    print_lookaheads  ();
#endif

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
   Node*   root;          // Current root node.
   Node*   node;          // Current AST node.
   int     traversal;     // AST traversal number: 1, 2, 3 ...
   int     direction;     // Node direction: TOP_DOWN, BOTTOM_UP.
   Stack*  stack;         // AST stack array.
   int     stacki;        // AST stack index.

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
   void    traverse    (int trav);
   void    traverse    (Node* n);
   void    traverse    (char* indent, Node* n);
   void    print_node  (char* indent, Node* n);
   void    tracer      (Node* n);

   lrstar_parser(lrstar_user_data_t *user_data_,
                 bool                actions_,
                 bool                debug_parser_,
                 bool                debug_trace_,
                 bool                insensitive_,
                 bool                make_ast_,
                 bool                node_actions_,
                 bool                reversable_,
                 bool                term_actions_) :
         user_data(user_data_),
         actions(actions_),
         debug_parser(debug_parser_),
         debug_trace(debug_trace_),
         insensitive(insensitive),
         make_ast(make_ast_),
         node_actions(node_actions_),
         reversable(reversable_),
         term_actions(term_actions_)
   {
   }

};
#endif
/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
