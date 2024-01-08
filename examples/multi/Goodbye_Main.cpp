#include "lrstar_basic_defs.h"
#include "Goodbye_LexerTables_typedef.h"
#include "Goodbye_Parser.h"


const char Goodbye_grammar_name[] = "Goodbye";


void Goodbye_init_actions(UNUSED_PARAM(Goodbye_parser_t *parser)); /* User-supplied */
void Goodbye_term_actions(UNUSED_PARAM(Goodbye_parser_t *parser)); /* User-supplied */
static Goodbye_parser_t::init_func_t Goodbye_init_funcs_[2] = {
   Goodbye_init_actions,
   Goodbye_term_actions
};

int Goodbye_error(UNUSED_PARAM(Goodbye_parser_t *parser), UNUSED_PARAM(int &t));
int Goodbye_lookup(UNUSED_PARAM(Goodbye_parser_t *parser), UNUSED_PARAM(int &t));
// Terminal action function pointers ...
static Goodbye_parser_t::tact_func_t Goodbye_tact_funcs_[2] = {
   Goodbye_error,
   Goodbye_lookup,
};

// Node action function pointers ...
static Goodbye_parser_t::nact_func_t Goodbye_nact_funcs_[1] = {
   0,
};

Goodbye_parser_t *
Goodbye_new_parser(const char *input_path,
                   char       *input_text,
                   unsigned    max_symbols)
{
   return new Goodbye_parser_t(/* input path   */   input_path,
                               /* input text   */   input_text,
                               /* max symbols  */   max_symbols,
                               /* init_func    */   &Goodbye_init_funcs_[0],
                               /* tact_func    */   &Goodbye_tact_funcs_[0],
                               /* nact_func    */   &Goodbye_nact_funcs_[0]);
}

