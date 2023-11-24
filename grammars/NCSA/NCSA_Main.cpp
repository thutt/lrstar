#include "lrstar_basic_defs.h"
#include "NCSA_LexerTables_typedef.h"
#include "NCSA_Parser.h"

const char NCSA_grammar_name[] = "NCSA";

void NCSA_init_actions(NCSA_parser_t *parser); /* User-supplied */
void NCSA_term_actions(NCSA_parser_t *parser); /* User-supplied */
static NCSA_parser_t::init_func_t NCSA_init_funcs_[2] = {
   NCSA_init_actions,
   NCSA_term_actions
};

int NCSA_error(NCSA_parser_t *parser, int &t);
int NCSA_lookup(NCSA_parser_t *parser, int &t);
// Terminal action function pointers ...
static NCSA_parser_t::tact_func_t NCSA_tact_funcs_[2] = {
   NCSA_error,
   NCSA_lookup,
};

// Node action function pointers ...
static NCSA_parser_t::nact_func_t NCSA_nact_funcs_[11] = {
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


NCSA_parser_t
generated_parser(/* grammar      */   &NCSA_grammar_name[0],
                 /* term_actions */   true,
                 /* init_func    */   &NCSA_init_funcs_[0],
                 /* tact_func    */   &NCSA_tact_funcs_[0],
                 /* nact_func    */   &NCSA_nact_funcs_[0]);

#include "lrstar_main.cpp"
