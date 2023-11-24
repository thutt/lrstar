#include "lrstar_basic_defs.h"
#include "XPL_LexerTables_typedef.h"
#include "XPL_Parser.h"

void XPL_init_actions(lrstar_parser *parser); /* User-supplied */
void XPL_term_actions(lrstar_parser *parser); /* User-supplied */
static lrstar_parser::init_func_t XPL_init_funcs_[2] = {
   XPL_init_actions,
   XPL_term_actions
};

int XPL_error(lrstar_parser *parser, int &t);
int XPL_lookup(lrstar_parser *parser, int &t);
// Terminal action function pointers ...
static lrstar_parser::tact_func_t XPL_tact_funcs_[2] = {
   XPL_error,
   XPL_lookup,
};


lrstar_parser generated_parser(/* grammar      */   "XPL",
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
                               /* init_func    */   &XPL_init_funcs_[0],
                               /* tact_func    */   &XPL_tact_funcs_[0],
                               /* nact_func    */   NULL);

#include "lrstar_main.cpp"
