#include "lrstar_basic_defs.h"
#include "JSON_LexerTables_typedef.h"
#include "JSON_Parser.h"

const char JSON_grammar_name[] = "JSON";

void JSON_init_actions(UNUSED_PARAM(JSON_parser_t *parser)); /* User-supplied */
void JSON_term_actions(UNUSED_PARAM(JSON_parser_t *parser)); /* User-supplied */
static JSON_parser_t::init_func_t JSON_init_funcs_[2] = {
   JSON_init_actions,
   JSON_term_actions
};

int JSON_error(UNUSED_PARAM(JSON_parser_t *parser), UNUSED_PARAM(int &t));
int JSON_lookup(UNUSED_PARAM(JSON_parser_t *parser), UNUSED_PARAM(int &t));
// Terminal action function pointers ...
static JSON_parser_t::tact_func_t JSON_tact_funcs_[2] = {
   JSON_error,
   JSON_lookup,
};

// Node action function pointers ...
static JSON_parser_t::nact_func_t JSON_nact_funcs_[10] = {
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


JSON_parser_t
generated_parser(/* init_func    */   &JSON_init_funcs_[0],
                 /* tact_func    */   &JSON_tact_funcs_[0],
                 /* nact_func    */   &JSON_nact_funcs_[0]);

#include "lrstar_main.cpp"
