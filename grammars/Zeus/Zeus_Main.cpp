#include "lrstar_basic_defs.h"
#include "Zeus_LexerTables_typedef.h"
#include "Zeus_Parser.h"

void Zeus_init_actions(lrstar_parser *parser); /* User-supplied */
void Zeus_term_actions(lrstar_parser *parser); /* User-supplied */
static lrstar_parser::init_func_t Zeus_init_funcs_[2] = {
   Zeus_init_actions,
   Zeus_term_actions
};

int Zeus_error(lrstar_parser *parser, int &t);
int Zeus_lookup(lrstar_parser *parser, int &t);
// Terminal action function pointers ...
static lrstar_parser::tact_func_t Zeus_tact_funcs_[2] = {
   Zeus_error,
   Zeus_lookup,
};


lrstar_parser generated_parser(/* grammar      */   "Zeus",
                               /* user data    */   NULL,
                               /* actions      */   true,
                               /* debug_parser */   false,
                               /* debug_trace  */   false,
                               /* expecting    */   true,
                               /* insensitive  */   false,
                               /* lookaheads   */   1,
                               /* make_ast     */   false,
                               /* nd_parsing   */   false,
                               /* nd_threads   */   0,
                               /* node_actions */   false,
                               /* reversable   */   false,
                               /* semantics    */   false,
                               /* stksize      */   100,
                               /* term_actions */   true,
                               /* init_func    */   &Zeus_init_funcs_[0],
                               /* tact_func    */   &Zeus_tact_funcs_[0],
                               /* nact_func    */   NULL);

#include "lrstar_main.cpp"
