#include "lrstar_basic_defs.h"
#include "Modula2_LexerTables_typedef.h"
#include "Modula2_Parser.h"

const char Modula2_grammar_name[] = "Modula2";

void Modula2_init_actions(Modula2_parser_t *parser); /* User-supplied */
void Modula2_term_actions(Modula2_parser_t *parser); /* User-supplied */
static Modula2_parser_t::init_func_t Modula2_init_funcs_[2] = {
   Modula2_init_actions,
   Modula2_term_actions
};

int Modula2_error(Modula2_parser_t *parser, int &t);
int Modula2_lookup(Modula2_parser_t *parser, int &t);
// Terminal action function pointers ...
static Modula2_parser_t::tact_func_t Modula2_tact_funcs_[2] = {
   Modula2_error,
   Modula2_lookup,
};


Modula2_parser_t
generated_parser(/* grammar      */   &Modula2_grammar_name[0],
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
                 /* nact_func    */   0);

#include "lrstar_main.cpp"
