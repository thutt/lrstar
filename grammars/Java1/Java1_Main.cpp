#include "lrstar_basic_defs.h"
#include "Java1_LexerTables_typedef.h"
#include "Java1_Parser.h"


const char Java1_grammar_name[] = "Java1";


void Java1_init_actions(UNUSED_PARAM(Java1_parser_t *parser)); /* User-supplied */
void Java1_term_actions(UNUSED_PARAM(Java1_parser_t *parser)); /* User-supplied */
static Java1_parser_t::init_func_t Java1_init_funcs_[2] = {
   Java1_init_actions,
   Java1_term_actions
};

int Java1_error(UNUSED_PARAM(Java1_parser_t *parser), UNUSED_PARAM(int &t));
int Java1_lookup(UNUSED_PARAM(Java1_parser_t *parser), UNUSED_PARAM(int &t));
// Terminal action function pointers ...
static Java1_parser_t::tact_func_t Java1_tact_funcs_[2] = {
   Java1_error,
   Java1_lookup,
};

Java1_parser_t *
Java1_new_parser(const char *input_path,
                 char       *input_text,
                 unsigned    max_symbols)
{
   return new Java1_parser_t(/* input path   */   input_path,
                             /* input text   */   input_text,
                             /* max symbols  */   max_symbols,
                             /* init_func    */   &Java1_init_funcs_[0],
                             /* tact_func    */   &Java1_tact_funcs_[0],
                             /* nact_func    */   0);
}

