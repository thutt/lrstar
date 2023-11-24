#include "lrstar_basic_defs.h"
#include "ANTLR_LexerTables_typedef.h"
#include "ANTLR_Parser.h"

const char ANTLR_grammar_name[] = "ANTLR";

void ANTLR_init_actions(ANTLR_parser_t *parser); /* User-supplied */
void ANTLR_term_actions(ANTLR_parser_t *parser); /* User-supplied */
static ANTLR_parser_t::init_func_t ANTLR_init_funcs_[2] = {
   ANTLR_init_actions,
   ANTLR_term_actions
};

int ANTLR_error(ANTLR_parser_t *parser, int &t);
int ANTLR_lookup(ANTLR_parser_t *parser, int &t);
// Terminal action function pointers ...
static ANTLR_parser_t::tact_func_t ANTLR_tact_funcs_[2] = {
   ANTLR_error,
   ANTLR_lookup,
};


ANTLR_parser_t
generated_parser(/* grammar      */   &ANTLR_grammar_name[0],
                 /* reversable   */   false,
                 /* semantics    */   false,
                 /* stksize      */   100,
                 /* term_actions */   true,
                 /* init_func    */   &ANTLR_init_funcs_[0],
                 /* tact_func    */   &ANTLR_tact_funcs_[0],
                 /* nact_func    */   0);

#include "lrstar_main.cpp"
