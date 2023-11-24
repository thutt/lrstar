#include "lrstar_basic_defs.h"
#include "Vba_LexerTables_typedef.h"
#include "Vba_Parser.h"

const char Vba_grammar_name[] = "Vba";

void Vba_init_actions(Vba_parser_t *parser); /* User-supplied */
void Vba_term_actions(Vba_parser_t *parser); /* User-supplied */
static Vba_parser_t::init_func_t Vba_init_funcs_[2] = {
   Vba_init_actions,
   Vba_term_actions
};

int Vba_error(Vba_parser_t *parser, int &t);
int Vba_lookup(Vba_parser_t *parser, int &t);
// Terminal action function pointers ...
static Vba_parser_t::tact_func_t Vba_tact_funcs_[2] = {
   Vba_error,
   Vba_lookup,
};

// Node action function pointers ...
static Vba_parser_t::nact_func_t Vba_nact_funcs_[81] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
};


Vba_parser_t
generated_parser(/* grammar      */   &Vba_grammar_name[0],
                 /* node_actions */   true,
                 /* reversable   */   false,
                 /* semantics    */   true,
                 /* stksize      */   100,
                 /* term_actions */   true,
                 /* init_func    */   &Vba_init_funcs_[0],
                 /* tact_func    */   &Vba_tact_funcs_[0],
                 /* nact_func    */   &Vba_nact_funcs_[0]);

#include "lrstar_main.cpp"
