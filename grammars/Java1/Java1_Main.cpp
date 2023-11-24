#include "lrstar_basic_defs.h"
#include "Java1_LexerTables_typedef.h"
#include "Java1_Parser.h"

void Java1_init_actions(lrstar_parser *parser); /* User-supplied */
void Java1_term_actions(lrstar_parser *parser); /* User-supplied */
static init_func_t Java1_init_funcs_[2] = {
   Java1_init_actions,
   Java1_term_actions
};

int Java1_error(lrstar_parser *parser, int &t);
int Java1_lookup(lrstar_parser *parser, int &t);
// Terminal action function pointers ...
static tact_func_t Java1_tact_funcs_[2] = {
   Java1_error,
   Java1_lookup,
};


lrstar_parser generated_parser(/* grammar      */   "Java1",
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
                               /* init_func    */   &Java1_init_funcs_[0],
                               /* tact_func    */   &Java1_tact_funcs_[0],
                               /* nact_func    */   NULL);

#include "lrstar_main.cpp"
