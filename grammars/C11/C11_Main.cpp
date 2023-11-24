#include "lrstar_basic_defs.h"
#include "C11_LexerTables_typedef.h"
#include "C11_Parser.h"

const char C11_grammar_name[] = "C11";

void C11_init_actions(C11_parser_t *parser); /* User-supplied */
void C11_term_actions(C11_parser_t *parser); /* User-supplied */
static C11_parser_t::init_func_t C11_init_funcs_[2] = {
   C11_init_actions,
   C11_term_actions
};

int C11_error(C11_parser_t *parser, int &t);
int C11_lookup(C11_parser_t *parser, int &t);
// Terminal action function pointers ...
static C11_parser_t::tact_func_t C11_tact_funcs_[2] = {
   C11_error,
   C11_lookup,
};


C11_parser_t
generated_parser(/* grammar      */   &C11_grammar_name[0],
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
                 /* init_func    */   &C11_init_funcs_[0],
                 /* tact_func    */   &C11_tact_funcs_[0],
                 /* nact_func    */   0);

#include "lrstar_main.cpp"
