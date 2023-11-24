#include "lrstar_basic_defs.h"
#include "Modula2_LexerTables_typedef.h"
#include "Modula2_Parser.h"

void Modula2_init_actions(lrstar_parser *parser); /* User-supplied */
void Modula2_term_actions(lrstar_parser *parser); /* User-supplied */
static lrstar_parser::init_func_t Modula2_init_funcs_[2] = {
   Modula2_init_actions,
   Modula2_term_actions
};

int Modula2_error(lrstar_parser *parser, int &t);
int Modula2_lookup(lrstar_parser *parser, int &t);
// Terminal action function pointers ...
static lrstar_parser::tact_func_t Modula2_tact_funcs_[2] = {
   Modula2_error,
   Modula2_lookup,
};


lrstar_parser generated_parser(/* grammar      */   "Modula2",
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
                               /* init_func    */   &Modula2_init_funcs_[0],
                               /* tact_func    */   &Modula2_tact_funcs_[0],
                               /* nact_func    */   NULL);

#include "lrstar_main.cpp"
