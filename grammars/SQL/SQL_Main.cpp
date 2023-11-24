#include "lrstar_basic_defs.h"
#include "SQL_LexerTables_typedef.h"
#include "SQL_Parser.h"

const char SQL_grammar_name[] = "SQL";

void SQL_init_actions(SQL_parser_t *parser); /* User-supplied */
void SQL_term_actions(SQL_parser_t *parser); /* User-supplied */
static SQL_parser_t::init_func_t SQL_init_funcs_[2] = {
   SQL_init_actions,
   SQL_term_actions
};

int SQL_error(SQL_parser_t *parser, int &t);
int SQL_lookup(SQL_parser_t *parser, int &t);
// Terminal action function pointers ...
static SQL_parser_t::tact_func_t SQL_tact_funcs_[2] = {
   SQL_error,
   SQL_lookup,
};


SQL_parser_t
generated_parser(/* grammar      */   &SQL_grammar_name[0],
                 /* nd_parsing   */   false,
                 /* nd_threads   */   0,
                 /* node_actions */   false,
                 /* reversable   */   false,
                 /* semantics    */   false,
                 /* stksize      */   100,
                 /* term_actions */   true,
                 /* init_func    */   &SQL_init_funcs_[0],
                 /* tact_func    */   &SQL_tact_funcs_[0],
                 /* nact_func    */   0);

#include "lrstar_main.cpp"
