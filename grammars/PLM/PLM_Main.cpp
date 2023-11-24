#include "lrstar_basic_defs.h"
#include "PLM_LexerTables_typedef.h"
#include "PLM_Parser.h"

const char PLM_grammar_name[] = "PLM";

void PLM_init_actions(PLM_parser_t *parser); /* User-supplied */
void PLM_term_actions(PLM_parser_t *parser); /* User-supplied */
static PLM_parser_t::init_func_t PLM_init_funcs_[2] = {
   PLM_init_actions,
   PLM_term_actions
};

int PLM_error(PLM_parser_t *parser, int &t);
// Terminal action function pointers ...
static PLM_parser_t::tact_func_t PLM_tact_funcs_[1] = {
   PLM_error,
};


PLM_parser_t
generated_parser(/* init_func    */   &PLM_init_funcs_[0],
                 /* tact_func    */   &PLM_tact_funcs_[0],
                 /* nact_func    */   0);

#include "lrstar_main.cpp"
