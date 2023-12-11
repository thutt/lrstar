#include "lrstar_basic_defs.h"
#include "CICS_LexerTables_typedef.h"
#include "CICS_Parser.h"


const char CICS_grammar_name[] = "CICS";


void CICS_init_actions(UNUSED_PARAM(CICS_parser_t *parser)); /* User-supplied */
void CICS_term_actions(UNUSED_PARAM(CICS_parser_t *parser)); /* User-supplied */
static CICS_parser_t::init_func_t CICS_init_funcs_[2] = {
   CICS_init_actions,
   CICS_term_actions
};

int CICS_error(UNUSED_PARAM(CICS_parser_t *parser), UNUSED_PARAM(int &t));
int CICS_lookup(UNUSED_PARAM(CICS_parser_t *parser), UNUSED_PARAM(int &t));
// Terminal action function pointers ...
static CICS_parser_t::tact_func_t CICS_tact_funcs_[2] = {
   CICS_error,
   CICS_lookup,
};

CICS_parser_t *
CICS_new_parser(const char *input_path,
                char       *input_text,
                unsigned    max_symbols)
{
   return new CICS_parser_t(/* input path   */   input_path,
                            /* input text   */   input_text,
                            /* max symbols  */   max_symbols,
                            /* init_func    */   &CICS_init_funcs_[0],
                            /* tact_func    */   &CICS_tact_funcs_[0],
                            /* nact_func    */   0);
}

