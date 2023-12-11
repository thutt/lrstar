#include "lrstar_basic_defs.h"
#include "SQL_LexerTables_typedef.h"
#include "SQL_Parser.h"


const char SQL_grammar_name[] = "SQL";


void SQL_init_actions(UNUSED_PARAM(SQL_parser_t *parser)); /* User-supplied */
void SQL_term_actions(UNUSED_PARAM(SQL_parser_t *parser)); /* User-supplied */
static SQL_parser_t::init_func_t SQL_init_funcs_[2] = {
   SQL_init_actions,
   SQL_term_actions
};

int SQL_error(UNUSED_PARAM(SQL_parser_t *parser), UNUSED_PARAM(int &t));
int SQL_lookup(UNUSED_PARAM(SQL_parser_t *parser), UNUSED_PARAM(int &t));
// Terminal action function pointers ...
static SQL_parser_t::tact_func_t SQL_tact_funcs_[2] = {
   SQL_error,
   SQL_lookup,
};

SQL_parser_t *
SQL_new_parser(const char *input_path,
               char       *input_text,
               unsigned    max_symbols)
{
   return new SQL_parser_t(/* input path   */   input_path,
                           /* input text   */   input_text,
                           /* max symbols  */   max_symbols,
                           /* init_func    */   &SQL_init_funcs_[0],
                           /* tact_func    */   &SQL_tact_funcs_[0],
                           /* nact_func    */   0);
}

