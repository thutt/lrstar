#include "lrstar_basic_defs.h"
#include "LRK_LexerTables_typedef.h"
#include "LRK_Parser.h"

void LRK_init_actions(lrstar_parser *parser); /* User-supplied */
void LRK_term_actions(lrstar_parser *parser); /* User-supplied */
static lrstar_parser::init_func_t LRK_init_funcs_[2] = {
   LRK_init_actions,
   LRK_term_actions
};

int LRK_error(lrstar_parser *parser, int &t);
int LRK_lookup(lrstar_parser *parser, int &t);
// Terminal action function pointers ...
static lrstar_parser::tact_func_t LRK_tact_funcs_[2] = {
   LRK_error,
   LRK_lookup,
};

// Node action function pointers ...
static lrstar_parser::nact_func_t LRK_nact_funcs_[8] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
};


lrstar_parser generated_parser(/* grammar      */   "LRK",
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
                               /* semantics    */   true,
                               /* stksize      */   100,
                               /* term_actions */   true,
                               /* init_func    */   &LRK_init_funcs_[0],
                               /* tact_func    */   &LRK_tact_funcs_[0],
                               /* nact_func    */   &LRK_nact_funcs_[0]);

#include "lrstar_main.cpp"
