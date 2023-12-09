#include "lrstar_basic_defs.h"
#include "Vba_LexerTables_typedef.h"
#include "Vba_Parser.h"


const char Vba_grammar_name[] = "Vba";


void Vba_init_actions(UNUSED_PARAM(Vba_parser_t *parser)); /* User-supplied */
void Vba_term_actions(UNUSED_PARAM(Vba_parser_t *parser)); /* User-supplied */
static Vba_parser_t::init_func_t Vba_init_funcs_[2] = {
   Vba_init_actions,
   Vba_term_actions
};

int Vba_error(UNUSED_PARAM(Vba_parser_t *parser), UNUSED_PARAM(int &t));
int Vba_lookup(UNUSED_PARAM(Vba_parser_t *parser), UNUSED_PARAM(int &t));
// Terminal action function pointers ...
static Vba_parser_t::tact_func_t Vba_tact_funcs_[2] = {
   Vba_error,
   Vba_lookup,
};

// Node action function pointers ...
static Vba_parser_t::nact_func_t Vba_nact_funcs_[81] = {
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

Vba_parser_t *
Vba_new_parser()
{
   return new Vba_parser_t(/* init_func    */   &Vba_init_funcs_[0],
                           /* tact_func    */   &Vba_tact_funcs_[0],
                           /* nact_func    */   &Vba_nact_funcs_[0]);
}

Vba_parser_t *generated_parser = Vba_new_parser();

