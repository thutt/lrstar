#include "lrstar_basic_defs.h"
#include "Fortran_LexerTables_typedef.h"
#include "Fortran_Parser.h"

const char Fortran_grammar_name[] = "Fortran";

void Fortran_init_actions(Fortran_parser_t *parser); /* User-supplied */
void Fortran_term_actions(Fortran_parser_t *parser); /* User-supplied */
static Fortran_parser_t::init_func_t Fortran_init_funcs_[2] = {
   Fortran_init_actions,
   Fortran_term_actions
};

int Fortran_error(Fortran_parser_t *parser, int &t);
int Fortran_lookup(Fortran_parser_t *parser, int &t);
// Terminal action function pointers ...
static Fortran_parser_t::tact_func_t Fortran_tact_funcs_[2] = {
   Fortran_error,
   Fortran_lookup,
};


Fortran_parser_t
generated_parser(/* grammar      */   &Fortran_grammar_name[0],
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
                 /* nact_func    */   0);

#include "lrstar_main.cpp"
