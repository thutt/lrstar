#include "lrstar_basic_defs.h"
#include "Typedef_LexerTables_typedef.h"
#include "Typedef_Parser.h"

void Typedef_init_actions(lrstar_parser *parser); /* User-supplied */
void Typedef_term_actions(lrstar_parser *parser); /* User-supplied */
static init_func_t Typedef_init_funcs_[2] = {
   Typedef_init_actions,
   Typedef_term_actions
};

int Typedef_error(lrstar_parser *parser, int &t);
int Typedef_lookup(lrstar_parser *parser, int &t);
// Terminal action function pointers ...
static tact_func_t Typedef_tact_funcs_[2] = {
   Typedef_error,
   Typedef_lookup,
};

// Node action function pointers ...
static nact_func_t Typedef_nact_funcs_[1] = {
   0,
};


lrstar_parser generated_parser(/* grammar      */   "Typedef",
                               /* user data    */   NULL,
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
                               /* init_func    */   &Typedef_init_funcs_[0],
                               /* tact_func    */   &Typedef_tact_funcs_[0],
                               /* nact_func    */   &Typedef_nact_funcs_[0]);

#include "lrstar_main.cpp"
