#include "lrstar_basic_defs.h"
#include "COBOL_LexerTables_typedef.h"
#include "COBOL_Parser.h"

const char COBOL_grammar_name[] = "COBOL";

void COBOL_init_actions(COBOL_parser_t *parser); /* User-supplied */
void COBOL_term_actions(COBOL_parser_t *parser); /* User-supplied */
static COBOL_parser_t::init_func_t COBOL_init_funcs_[2] = {
   COBOL_init_actions,
   COBOL_term_actions
};

int COBOL_error(COBOL_parser_t *parser, int &t);
int COBOL_lookup(COBOL_parser_t *parser, int &t);
// Terminal action function pointers ...
static COBOL_parser_t::tact_func_t COBOL_tact_funcs_[2] = {
   COBOL_error,
   COBOL_lookup,
};


COBOL_parser_t
generated_parser(/* grammar      */   &COBOL_grammar_name[0],
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
                 /* nact_func    */   0);

#include "lrstar_main.cpp"
