#include "lrstar_basic_defs.h"
#include "Typedef_LexerTables_typedef.h"
#include "Typedef_Parser.h"

const char Typedef_grammar_name[] = "Typedef";

void Typedef_init_actions(Typedef_parser_t *parser); /* User-supplied */
void Typedef_term_actions(Typedef_parser_t *parser); /* User-supplied */
static Typedef_parser_t::init_func_t Typedef_init_funcs_[2] = {
   Typedef_init_actions,
   Typedef_term_actions
};

int Typedef_error(Typedef_parser_t *parser, int &t);
int Typedef_lookup(Typedef_parser_t *parser, int &t);
// Terminal action function pointers ...
static Typedef_parser_t::tact_func_t Typedef_tact_funcs_[2] = {
   Typedef_error,
   Typedef_lookup,
};

// Node action function pointers ...
static Typedef_parser_t::nact_func_t Typedef_nact_funcs_[1] = {
   0,
};


Typedef_parser_t
generated_parser(/* grammar      */   &Typedef_grammar_name[0],
                 /* node_actions */   true,
                 /* reversable   */   false,
                 /* semantics    */   true,
                 /* stksize      */   100,
                 /* term_actions */   true,
                 /* init_func    */   &Typedef_init_funcs_[0],
                 /* tact_func    */   &Typedef_tact_funcs_[0],
                 /* nact_func    */   &Typedef_nact_funcs_[0]);

#include "lrstar_main.cpp"
