#include "lrstar_basic_defs.h"
#include "Ada_LexerTables_typedef.h"
#include "Ada_Parser.h"

void Ada_init_actions(lrstar_parser *parser); /* User-supplied */
void Ada_term_actions(lrstar_parser *parser); /* User-supplied */
static lrstar_parser::init_func_t Ada_init_funcs_[2] = {
   Ada_init_actions,
   Ada_term_actions
};

int Ada_error(lrstar_parser *parser, int &t);
int Ada_lookup(lrstar_parser *parser, int &t);
// Terminal action function pointers ...
static lrstar_parser::tact_func_t Ada_tact_funcs_[2] = {
   Ada_error,
   Ada_lookup,
};


lrstar_parser generated_parser(/* grammar      */   "Ada",
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
                               /* init_func    */   &Ada_init_funcs_[0],
                               /* tact_func    */   &Ada_tact_funcs_[0],
                               /* nact_func    */   NULL);

#include "lrstar_main.cpp"
