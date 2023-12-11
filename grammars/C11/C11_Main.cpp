#include "lrstar_basic_defs.h"
#include "C11_LexerTables_typedef.h"
#include "C11_Parser.h"


const char C11_grammar_name[] = "C11";


void C11_init_actions(UNUSED_PARAM(C11_parser_t *parser)); /* User-supplied */
void C11_term_actions(UNUSED_PARAM(C11_parser_t *parser)); /* User-supplied */
static C11_parser_t::init_func_t C11_init_funcs_[2] = {
   C11_init_actions,
   C11_term_actions
};

int C11_error(UNUSED_PARAM(C11_parser_t *parser), UNUSED_PARAM(int &t));
int C11_lookup(UNUSED_PARAM(C11_parser_t *parser), UNUSED_PARAM(int &t));
// Terminal action function pointers ...
static C11_parser_t::tact_func_t C11_tact_funcs_[2] = {
   C11_error,
   C11_lookup,
};

C11_parser_t *
C11_new_parser(const char *input_path,
               char       *input_text,
               unsigned    max_symbols)
{
   return new C11_parser_t(/* input path   */   input_path,
                           /* input text   */   input_text,
                           /* max symbols  */   max_symbols,
                           /* init_func    */   &C11_init_funcs_[0],
                           /* tact_func    */   &C11_tact_funcs_[0],
                           /* nact_func    */   0);
}

