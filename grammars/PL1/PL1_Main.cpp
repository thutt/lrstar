#include "lrstar_basic_defs.h"
#include "PL1_LexerTables_typedef.h"
#include "PL1_Parser.h"

const char PL1_grammar_name[] = "PL1";

void PL1_init_actions(PL1_parser_t *parser); /* User-supplied */
void PL1_term_actions(PL1_parser_t *parser); /* User-supplied */
static PL1_parser_t::init_func_t PL1_init_funcs_[2] = {
   PL1_init_actions,
   PL1_term_actions
};

int PL1_error(PL1_parser_t *parser, int &t);
int PL1_lookup(PL1_parser_t *parser, int &t);
// Terminal action function pointers ...
static PL1_parser_t::tact_func_t PL1_tact_funcs_[2] = {
   PL1_error,
   PL1_lookup,
};


PL1_parser_t
generated_parser(/* grammar      */   &PL1_grammar_name[0],
                 /* nd_parsing   */   false,
                 /* nd_threads   */   0,
                 /* node_actions */   false,
                 /* reversable   */   false,
                 /* semantics    */   false,
                 /* stksize      */   100,
                 /* term_actions */   true,
                 /* init_func    */   &PL1_init_funcs_[0],
                 /* tact_func    */   &PL1_tact_funcs_[0],
                 /* nact_func    */   0);

#include "lrstar_main.cpp"
