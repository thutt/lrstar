#include "lrstar_basic_defs.h"
#include "Hello_LexerTables_typedef.h"
#include "Hello_Parser.h"


const char Hello_grammar_name[] = "Hello";


void Hello_init_actions(UNUSED_PARAM(Hello_parser_t *parser)); /* User-supplied */
void Hello_term_actions(UNUSED_PARAM(Hello_parser_t *parser)); /* User-supplied */
static Hello_parser_t::init_func_t Hello_init_funcs_[2] = {
   Hello_init_actions,
   Hello_term_actions
};

int Hello_error(UNUSED_PARAM(Hello_parser_t *parser), UNUSED_PARAM(int &t));
int Hello_lookup(UNUSED_PARAM(Hello_parser_t *parser), UNUSED_PARAM(int &t));
// Terminal action function pointers ...
static Hello_parser_t::tact_func_t Hello_tact_funcs_[2] = {
   Hello_error,
   Hello_lookup,
};

// Node action function pointers ...
static Hello_parser_t::nact_func_t Hello_nact_funcs_[1] = {
   0,
};

Hello_parser_t *
Hello_new_parser(const char *input_path,
                 char       *input_text,
                 unsigned    max_symbols)
{
   return new Hello_parser_t(/* input path   */   input_path,
                             /* input text   */   input_text,
                             /* max symbols  */   max_symbols,
                             /* init_func    */   &Hello_init_funcs_[0],
                             /* tact_func    */   &Hello_tact_funcs_[0],
                             /* nact_func    */   &Hello_nact_funcs_[0]);
}

