#include "lrstar_basic_defs.h"
#include "Pascal_LexerTables_typedef.h"
#include "Pascal_Parser.h"

const char Pascal_grammar_name[] = "Pascal";

void Pascal_init_actions(UNUSED_PARAM(Pascal_parser_t *parser)); /* User-supplied */
void Pascal_term_actions(UNUSED_PARAM(Pascal_parser_t *parser)); /* User-supplied */
static Pascal_parser_t::init_func_t Pascal_init_funcs_[2] = {
   Pascal_init_actions,
   Pascal_term_actions
};

int Pascal_error(UNUSED_PARAM(Pascal_parser_t *parser), UNUSED_PARAM(int &t));
int Pascal_lookup(UNUSED_PARAM(Pascal_parser_t *parser), UNUSED_PARAM(int &t));
// Terminal action function pointers ...
static Pascal_parser_t::tact_func_t Pascal_tact_funcs_[2] = {
   Pascal_error,
   Pascal_lookup,
};

// Node action function pointers ...
static Pascal_parser_t::nact_func_t Pascal_nact_funcs_[185] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
};


Pascal_parser_t
generated_parser(/* init_func    */   &Pascal_init_funcs_[0],
                 /* tact_func    */   &Pascal_tact_funcs_[0],
                 /* nact_func    */   &Pascal_nact_funcs_[0]);

#include "lrstar_main.cpp"
