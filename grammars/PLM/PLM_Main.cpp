#include "lrstar_basic_defs.h"
#include "PLM_LexerTables_typedef.h"
#include "PLM_Parser.h"

void PLM_init_actions(lrstar_parser *parser); /* User-supplied */
void PLM_term_actions(lrstar_parser *parser); /* User-supplied */
static init_func_t PLM_init_funcs_[2] = {
   PLM_init_actions,
   PLM_term_actions
};

int PLM_error(lrstar_parser *parser, int &t);
// Terminal action function pointers ...
static tact_func_t PLM_tact_funcs_[1] = {
   PLM_error,
};


lrstar_parser generated_parser(/* grammar      */   "PLM",
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
                               /* init_func    */   &PLM_init_funcs_[0],
                               /* tact_func    */   &PLM_tact_funcs_[0],
                               /* nact_func    */   NULL);

#include "lrstar_main.cpp"
