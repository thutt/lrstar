#include "lrstar_basic_defs.h"
#include "Java9_LexerTables_typedef.h"
#include "Java9_Parser.h"

void Java9_init_actions(lrstar_parser *parser); /* User-supplied */
void Java9_term_actions(lrstar_parser *parser); /* User-supplied */
static init_func_t Java9_init_funcs_[2] = {
   Java9_init_actions,
   Java9_term_actions
};

int Java9_error(lrstar_parser *parser, int &t);
int Java9_lookup(lrstar_parser *parser, int &t);
// Terminal action function pointers ...
static tact_func_t Java9_tact_funcs_[2] = {
   Java9_error,
   Java9_lookup,
};

// Node action function pointers ...
static nact_func_t Java9_nact_funcs_[1] = {
   0,
};


lrstar_parser generated_parser(/* grammar      */   "Java9",
                               /* user data    */   NULL,
                               /* actions      */   true,
                               /* debug_parser */   false,
                               /* debug_trace  */   false,
                               /* expecting    */   true,
                               /* insensitive  */   false,
                               /* lookaheads   */   1,
                               /* make_ast     */   true,
                               /* nd_parsing   */   false,
                               /* nd_threads   */   0,
                               /* node_actions */   true,
                               /* reversable   */   false,
                               /* semantics    */   false,
                               /* stksize      */   100,
                               /* term_actions */   true,
                               /* init_func    */   &Java9_init_funcs_[0],
                               /* tact_func    */   &Java9_tact_funcs_[0],
                               /* nact_func    */   &Java9_nact_funcs_[0]);

#include "lrstar_main.cpp"
