#include "lrstar_basic_defs.h"
#include "C_LexerTables_typedef.h"
#include "C_Parser.h"

const char C_grammar_name[] = "C";

void C_init_actions(UNUSED_PARAM(C_parser_t *parser)); /* User-supplied */
void C_term_actions(UNUSED_PARAM(C_parser_t *parser)); /* User-supplied */
static C_parser_t::init_func_t C_init_funcs_[2] = {
   C_init_actions,
   C_term_actions
};

int C_error(UNUSED_PARAM(C_parser_t *parser), UNUSED_PARAM(int &t));
int C_lookup(UNUSED_PARAM(C_parser_t *parser), UNUSED_PARAM(int &t));
// Terminal action function pointers ...
static C_parser_t::tact_func_t C_tact_funcs_[2] = {
   C_error,
   C_lookup,
};


C_parser_t
generated_parser(/* init_func    */   &C_init_funcs_[0],
                 /* tact_func    */   &C_tact_funcs_[0],
                 /* nact_func    */   0);

#include "lrstar_main.cpp"
