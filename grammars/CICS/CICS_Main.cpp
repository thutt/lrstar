#include "lrstar_basic_defs.h"
#include "CICS_LexerTables_typedef.h"
#include "CICS_Parser.h"

const char CICS_grammar_name[] = "CICS";

void CICS_init_actions(CICS_parser_t *parser); /* User-supplied */
void CICS_term_actions(CICS_parser_t *parser); /* User-supplied */
static CICS_parser_t::init_func_t CICS_init_funcs_[2] = {
   CICS_init_actions,
   CICS_term_actions
};

int CICS_error(CICS_parser_t *parser, int &t);
int CICS_lookup(CICS_parser_t *parser, int &t);
// Terminal action function pointers ...
static CICS_parser_t::tact_func_t CICS_tact_funcs_[2] = {
   CICS_error,
   CICS_lookup,
};


CICS_parser_t
generated_parser(/* grammar      */   &CICS_grammar_name[0],
                 /* semantics    */   false,
                 /* stksize      */   100,
                 /* term_actions */   true,
                 /* init_func    */   &CICS_init_funcs_[0],
                 /* tact_func    */   &CICS_tact_funcs_[0],
                 /* nact_func    */   0);

#include "lrstar_main.cpp"
