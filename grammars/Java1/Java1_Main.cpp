#include "lrstar_basic_defs.h"
#include "Java1_LexerTables_typedef.h"
#include "Java1_Parser.h"

const char Java1_grammar_name[] = "Java1";

void Java1_init_actions(Java1_parser_t *parser); /* User-supplied */
void Java1_term_actions(Java1_parser_t *parser); /* User-supplied */
static Java1_parser_t::init_func_t Java1_init_funcs_[2] = {
   Java1_init_actions,
   Java1_term_actions
};

int Java1_error(Java1_parser_t *parser, int &t);
int Java1_lookup(Java1_parser_t *parser, int &t);
// Terminal action function pointers ...
static Java1_parser_t::tact_func_t Java1_tact_funcs_[2] = {
   Java1_error,
   Java1_lookup,
};


Java1_parser_t
generated_parser(/* grammar      */   &Java1_grammar_name[0],
                 /* actions      */   true,
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
                 /* init_func    */   &Java1_init_funcs_[0],
                 /* tact_func    */   &Java1_tact_funcs_[0],
                 /* nact_func    */   0);

#include "lrstar_main.cpp"
