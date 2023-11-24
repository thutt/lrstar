#include "lrstar_basic_defs.h"
#include "Fortran_LexerTables_typedef.h"
#include "Fortran_Parser.h"

void Fortran_init_actions(lrstar_parser *parser); /* User-supplied */
void Fortran_term_actions(lrstar_parser *parser); /* User-supplied */
static lrstar_parser::init_func_t Fortran_init_funcs_[2] = {
   Fortran_init_actions,
   Fortran_term_actions
};

int Fortran_error(lrstar_parser *parser, int &t);
int Fortran_lookup(lrstar_parser *parser, int &t);
// Terminal action function pointers ...
static lrstar_parser::tact_func_t Fortran_tact_funcs_[2] = {
   Fortran_error,
   Fortran_lookup,
};


lrstar_parser generated_parser(/* grammar      */   "Fortran",
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
                               /* init_func    */   &Fortran_init_funcs_[0],
                               /* tact_func    */   &Fortran_tact_funcs_[0],
                               /* nact_func    */   NULL);

#include "lrstar_main.cpp"
