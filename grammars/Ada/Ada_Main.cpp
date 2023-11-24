#include "lrstar_basic_defs.h"
#include "Ada_LexerTables_typedef.h"
#include "Ada_Parser.h"

const char Ada_grammar_name[] = "Ada";

void Ada_init_actions(Ada_parser_t *parser); /* User-supplied */
void Ada_term_actions(Ada_parser_t *parser); /* User-supplied */
static Ada_parser_t::init_func_t Ada_init_funcs_[2] = {
   Ada_init_actions,
   Ada_term_actions
};

int Ada_error(Ada_parser_t *parser, int &t);
int Ada_lookup(Ada_parser_t *parser, int &t);
// Terminal action function pointers ...
static Ada_parser_t::tact_func_t Ada_tact_funcs_[2] = {
   Ada_error,
   Ada_lookup,
};


Ada_parser_t
generated_parser(/* init_func    */   &Ada_init_funcs_[0],
                 /* tact_func    */   &Ada_tact_funcs_[0],
                 /* nact_func    */   0);

#include "lrstar_main.cpp"
