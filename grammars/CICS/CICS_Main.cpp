#include "lrstar_basic_defs.h"
#include "CICS_LexerTables_typedef.h"
#include "CICS_Parser.h"

void CICS_init_actions(lrstar_parser *parser); /* User-supplied */
void CICS_term_actions(lrstar_parser *parser); /* User-supplied */
static lrstar_parser::init_func_t CICS_init_funcs_[2] = {
   CICS_init_actions,
   CICS_term_actions
};

int CICS_error(lrstar_parser *parser, int &t);
int CICS_lookup(lrstar_parser *parser, int &t);
// Terminal action function pointers ...
static lrstar_parser::tact_func_t CICS_tact_funcs_[2] = {
   CICS_error,
   CICS_lookup,
};


lrstar_parser generated_parser(/* grammar      */   "CICS",
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
                               /* init_func    */   &CICS_init_funcs_[0],
                               /* tact_func    */   &CICS_tact_funcs_[0],
                               /* nact_func    */   NULL);

#include "lrstar_main.cpp"
