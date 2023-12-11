#include "lrstar_basic_defs.h"
#include "Dbase_LexerTables_typedef.h"
#include "Dbase_Parser.h"


const char Dbase_grammar_name[] = "Dbase";


void Dbase_init_actions(UNUSED_PARAM(Dbase_parser_t *parser)); /* User-supplied */
void Dbase_term_actions(UNUSED_PARAM(Dbase_parser_t *parser)); /* User-supplied */
static Dbase_parser_t::init_func_t Dbase_init_funcs_[2] = {
   Dbase_init_actions,
   Dbase_term_actions
};

int Dbase_error(UNUSED_PARAM(Dbase_parser_t *parser), UNUSED_PARAM(int &t));
int Dbase_lookup(UNUSED_PARAM(Dbase_parser_t *parser), UNUSED_PARAM(int &t));
// Terminal action function pointers ...
static Dbase_parser_t::tact_func_t Dbase_tact_funcs_[2] = {
   Dbase_error,
   Dbase_lookup,
};

Dbase_parser_t *
Dbase_new_parser(const char *input_path,
                 char       *input_text,
                 unsigned    max_symbols)
{
   return new Dbase_parser_t(/* input path   */   input_path,
                             /* input text   */   input_text,
                             /* max symbols  */   max_symbols,
                             /* init_func    */   &Dbase_init_funcs_[0],
                             /* tact_func    */   &Dbase_tact_funcs_[0],
                             /* nact_func    */   0);
}

