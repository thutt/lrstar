#include "lrstar_basic_defs.h"
#include "LRK_LexerTables_typedef.h"
#include "LRK_Parser.h"

const char LRK_grammar_name[] = "LRK";

void LRK_init_actions(LRK_parser_t *parser); /* User-supplied */
void LRK_term_actions(LRK_parser_t *parser); /* User-supplied */
static LRK_parser_t::init_func_t LRK_init_funcs_[2] = {
   LRK_init_actions,
   LRK_term_actions
};

int LRK_error(LRK_parser_t *parser, int &t);
int LRK_lookup(LRK_parser_t *parser, int &t);
// Terminal action function pointers ...
static LRK_parser_t::tact_func_t LRK_tact_funcs_[2] = {
   LRK_error,
   LRK_lookup,
};

// Node action function pointers ...
static LRK_parser_t::nact_func_t LRK_nact_funcs_[8] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
};


LRK_parser_t
generated_parser(/* grammar      */   &LRK_grammar_name[0],
                 /* actions      */   true,
                 /* debug_parser */   false,
                 /* debug_trace  */   false,
                 /* expecting    */   true,
                 /* insensitive  */   false,
                 /* lookaheads   */   1,
                 /* make_ast     */   true,
                 /* nd_parsing   */   false,
                 /* nd_threads   */   0,
                 /* node_actions */   true,
                 /* reversable   */   false,
                 /* semantics    */   true,
                 /* stksize      */   100,
                 /* term_actions */   true,
                 /* init_func    */   &LRK_init_funcs_[0],
                 /* tact_func    */   &LRK_tact_funcs_[0],
                 /* nact_func    */   &LRK_nact_funcs_[0]);

#include "lrstar_main.cpp"
