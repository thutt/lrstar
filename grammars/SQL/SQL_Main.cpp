#include "lrstar_basic_defs.h"
#include "SQL_LexerTables_typedef.h"
#include "SQL_Parser.h"

void SQL_init_actions(lrstar_parser *parser); /* User-supplied */
void SQL_term_actions(lrstar_parser *parser); /* User-supplied */
static init_func_t SQL_init_funcs_[2] = {
   SQL_init_actions,
   SQL_term_actions
};

int SQL_error(lrstar_parser *parser, int &t);
int SQL_lookup(lrstar_parser *parser, int &t);
// Terminal action function pointers ...
static tact_func_t SQL_tact_funcs_[2] = {
   SQL_error,
   SQL_lookup,
};


lrstar_parser generated_parser(/* grammar      */   "SQL",
                               /* user data    */   NULL,
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
                               /* init_func    */   &SQL_init_funcs_[0],
                               /* tact_func    */   &SQL_tact_funcs_[0],
                               /* nact_func    */   NULL);

#include "lrstar_main.cpp"
