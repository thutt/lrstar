#include "lrstar_basic_defs.h"
#include "Ada_LexerTables_typedef.h"
#include "Ada_Parser.h"

const char Ada_grammar_name[] = "Ada";


void Ada_init_actions(UNUSED_PARAM(Ada_parser_t *parser)); /* User-supplied */
void Ada_term_actions(UNUSED_PARAM(Ada_parser_t *parser)); /* User-supplied */
static Ada_parser_t::init_func_t Ada_init_funcs_[2] = {
   Ada_init_actions,
   Ada_term_actions
};

int Ada_error(UNUSED_PARAM(Ada_parser_t *parser), UNUSED_PARAM(int &t));
int Ada_lookup(UNUSED_PARAM(Ada_parser_t *parser), UNUSED_PARAM(int &t));
// Terminal action function pointers ...
static Ada_parser_t::tact_func_t Ada_tact_funcs_[2] = {
   Ada_error,
   Ada_lookup,
};

Ada_parser_t *
Ada_new_parser()
{
   return new Ada_parser_t(/* init_func    */   &Ada_init_funcs_[0],
                           /* tact_func    */   &Ada_tact_funcs_[0],
                           /* nact_func    */   0);
}

Ada_parser_t *generated_parser = Ada_new_parser();

#include "lrstar_main.cpp"
