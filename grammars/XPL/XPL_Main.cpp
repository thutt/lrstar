#include "lrstar_basic_defs.h"
#include "XPL_LexerTables_typedef.h"
#include "XPL_Parser.h"

const char XPL_grammar_name[] = "XPL";

void XPL_init_actions(XPL_parser_t *parser); /* User-supplied */
void XPL_term_actions(XPL_parser_t *parser); /* User-supplied */
static XPL_parser_t::init_func_t XPL_init_funcs_[2] = {
   XPL_init_actions,
   XPL_term_actions
};

int XPL_error(XPL_parser_t *parser, int &t);
int XPL_lookup(XPL_parser_t *parser, int &t);
// Terminal action function pointers ...
static XPL_parser_t::tact_func_t XPL_tact_funcs_[2] = {
   XPL_error,
   XPL_lookup,
};


XPL_parser_t
generated_parser(/* grammar      */   &XPL_grammar_name[0],
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
                 /* init_func    */   &XPL_init_funcs_[0],
                 /* tact_func    */   &XPL_tact_funcs_[0],
                 /* nact_func    */   0);

#include "lrstar_main.cpp"
