#include "lrstar_basic_defs.h"
#include "COBOL_LexerTables_typedef.h"
#include "COBOL_Parser.h"

void COBOL_init_actions(lrstar_parser *parser); /* User-supplied */
void COBOL_term_actions(lrstar_parser *parser); /* User-supplied */
static lrstar_parser::init_func_t COBOL_init_funcs_[2] = {
   COBOL_init_actions,
   COBOL_term_actions
};

int COBOL_error(lrstar_parser *parser, int &t);
int COBOL_lookup(lrstar_parser *parser, int &t);
// Terminal action function pointers ...
static lrstar_parser::tact_func_t COBOL_tact_funcs_[2] = {
   COBOL_error,
   COBOL_lookup,
};


lrstar_parser generated_parser(/* grammar      */   "COBOL",
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
                               /* init_func    */   &COBOL_init_funcs_[0],
                               /* tact_func    */   &COBOL_tact_funcs_[0],
                               /* nact_func    */   NULL);

#include "lrstar_main.cpp"
