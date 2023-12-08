#include "lrstar_basic_defs.h"
#include "Fortran_LexerTables_typedef.h"
#include "Fortran_Parser.h"

const char Fortran_grammar_name[] = "Fortran";


void Fortran_init_actions(UNUSED_PARAM(Fortran_parser_t *parser)); /* User-supplied */
void Fortran_term_actions(UNUSED_PARAM(Fortran_parser_t *parser)); /* User-supplied */
static Fortran_parser_t::init_func_t Fortran_init_funcs_[2] = {
   Fortran_init_actions,
   Fortran_term_actions
};

int Fortran_error(UNUSED_PARAM(Fortran_parser_t *parser), UNUSED_PARAM(int &t));
int Fortran_lookup(UNUSED_PARAM(Fortran_parser_t *parser), UNUSED_PARAM(int &t));
// Terminal action function pointers ...
static Fortran_parser_t::tact_func_t Fortran_tact_funcs_[2] = {
   Fortran_error,
   Fortran_lookup,
};

Fortran_parser_t *
Fortran_new_parser()
{
   return new Fortran_parser_t(/* init_func    */   &Fortran_init_funcs_[0],
                               /* tact_func    */   &Fortran_tact_funcs_[0],
                               /* nact_func    */   0);
}

Fortran_parser_t *generated_parser = Fortran_new_parser();

#include "lrstar_main.cpp"
