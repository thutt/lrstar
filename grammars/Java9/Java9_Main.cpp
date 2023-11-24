#include "lrstar_basic_defs.h"
#include "Java9_LexerTables_typedef.h"
#include "Java9_Parser.h"

const char Java9_grammar_name[] = "Java9";

void Java9_init_actions(Java9_parser_t *parser); /* User-supplied */
void Java9_term_actions(Java9_parser_t *parser); /* User-supplied */
static Java9_parser_t::init_func_t Java9_init_funcs_[2] = {
   Java9_init_actions,
   Java9_term_actions
};

int Java9_error(Java9_parser_t *parser, int &t);
int Java9_lookup(Java9_parser_t *parser, int &t);
// Terminal action function pointers ...
static Java9_parser_t::tact_func_t Java9_tact_funcs_[2] = {
   Java9_error,
   Java9_lookup,
};

// Node action function pointers ...
static Java9_parser_t::nact_func_t Java9_nact_funcs_[1] = {
   0,
};


Java9_parser_t
generated_parser(/* grammar      */   &Java9_grammar_name[0],
                 /* init_func    */   &Java9_init_funcs_[0],
                 /* tact_func    */   &Java9_tact_funcs_[0],
                 /* nact_func    */   &Java9_nact_funcs_[0]);

#include "lrstar_main.cpp"
