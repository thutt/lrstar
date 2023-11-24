#include "lrstar_basic_defs.h"
#include "PL1_LexerTables_typedef.h"
#include "PL1_Parser.h"

void PL1_init_actions(lrstar_parser *parser); /* User-supplied */
void PL1_term_actions(lrstar_parser *parser); /* User-supplied */
static init_func_t PL1_init_funcs_[2] = {
   PL1_init_actions,
   PL1_term_actions
};

int PL1_error(lrstar_parser *parser, int &t);
int PL1_lookup(lrstar_parser *parser, int &t);
// Terminal action function pointers ...
static tact_func_t PL1_tact_funcs_[2] = {
   PL1_error,
   PL1_lookup,
};


lrstar_parser generated_parser(/* grammar      */   "PL1",
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
                               /* init_func    */   &PL1_init_funcs_[0],
                               /* tact_func    */   &PL1_tact_funcs_[0],
                               /* nact_func    */   NULL);

#include "lrstar_main.cpp"
