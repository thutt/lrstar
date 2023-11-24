#include "lrstar_basic_defs.h"
#include "ANTLR_LexerTables_typedef.h"
#include "ANTLR_Parser.h"

void ANTLR_init_actions(lrstar_parser *parser); /* User-supplied */
void ANTLR_term_actions(lrstar_parser *parser); /* User-supplied */
static init_func_t ANTLR_init_funcs_[2] = {
   ANTLR_init_actions,
   ANTLR_term_actions
};

int ANTLR_error(lrstar_parser *parser, int &t);
int ANTLR_lookup(lrstar_parser *parser, int &t);
// Terminal action function pointers ...
static tact_func_t ANTLR_tact_funcs_[2] = {
   ANTLR_error,
   ANTLR_lookup,
};


lrstar_parser generated_parser(/* grammar      */   "ANTLR",
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
                               /* init_func    */   &ANTLR_init_funcs_[0],
                               /* tact_func    */   &ANTLR_tact_funcs_[0],
                               /* nact_func    */   NULL);

#include "lrstar_main.cpp"
