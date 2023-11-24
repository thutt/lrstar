#include "lrstar_basic_defs.h"
#include "Zeus_LexerTables_typedef.h"
#include "Zeus_Parser.h"

const char Zeus_grammar_name[] = "Zeus";

void Zeus_init_actions(Zeus_parser_t *parser); /* User-supplied */
void Zeus_term_actions(Zeus_parser_t *parser); /* User-supplied */
static Zeus_parser_t::init_func_t Zeus_init_funcs_[2] = {
   Zeus_init_actions,
   Zeus_term_actions
};

int Zeus_error(Zeus_parser_t *parser, int &t);
int Zeus_lookup(Zeus_parser_t *parser, int &t);
// Terminal action function pointers ...
static Zeus_parser_t::tact_func_t Zeus_tact_funcs_[2] = {
   Zeus_error,
   Zeus_lookup,
};


Zeus_parser_t
generated_parser(/* grammar      */   &Zeus_grammar_name[0],
                 /* debug_parser */   false,
                 /* debug_trace  */   false,
                 /* expecting    */   true,
                 /* insensitive  */   false,
                 /* lookaheads   */   1,
                 /* make_ast     */   false,
                 /* nd_parsing   */   false,
                 /* nd_threads   */   0,
                 /* node_actions */   false,
                 /* reversable   */   false,
                 /* semantics    */   false,
                 /* stksize      */   100,
                 /* term_actions */   true,
                 /* init_func    */   &Zeus_init_funcs_[0],
                 /* tact_func    */   &Zeus_tact_funcs_[0],
                 /* nact_func    */   0);

#include "lrstar_main.cpp"
