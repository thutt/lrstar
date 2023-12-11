#include "lrstar_basic_defs.h"
#include "Modula2_LexerTables_typedef.h"
#include "Modula2_Parser.h"


const char Modula2_grammar_name[] = "Modula2";


void Modula2_init_actions(UNUSED_PARAM(Modula2_parser_t *parser)); /* User-supplied */
void Modula2_term_actions(UNUSED_PARAM(Modula2_parser_t *parser)); /* User-supplied */
static Modula2_parser_t::init_func_t Modula2_init_funcs_[2] = {
   Modula2_init_actions,
   Modula2_term_actions
};

int Modula2_error(UNUSED_PARAM(Modula2_parser_t *parser), UNUSED_PARAM(int &t));
int Modula2_lookup(UNUSED_PARAM(Modula2_parser_t *parser), UNUSED_PARAM(int &t));
// Terminal action function pointers ...
static Modula2_parser_t::tact_func_t Modula2_tact_funcs_[2] = {
   Modula2_error,
   Modula2_lookup,
};

Modula2_parser_t *
Modula2_new_parser(const char *input_path,
                   char       *input_text,
                   unsigned    max_symbols)
{
   return new Modula2_parser_t(/* input path   */   input_path,
                               /* input text   */   input_text,
                               /* max symbols  */   max_symbols,
                               /* init_func    */   &Modula2_init_funcs_[0],
                               /* tact_func    */   &Modula2_tact_funcs_[0],
                               /* nact_func    */   0);
}

