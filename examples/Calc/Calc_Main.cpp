#include "lrstar_basic_defs.h"
#include "Calc_LexerTables_typedef.h"
#include "Calc_Parser.h"

const char Calc_grammar_name[] = "Calc";

void Calc_init_actions(Calc_parser_t *parser); /* User-supplied */
void Calc_term_actions(Calc_parser_t *parser); /* User-supplied */
static Calc_parser_t::init_func_t Calc_init_funcs_[2] = {
   Calc_init_actions,
   Calc_term_actions
};

int Calc_error(Calc_parser_t *parser, int &t);
int Calc_lookup(Calc_parser_t *parser, int &t);
// Terminal action function pointers ...
static Calc_parser_t::tact_func_t Calc_tact_funcs_[2] = {
   Calc_error,
   Calc_lookup,
};

int Calc_goal_(Calc_parser_t *parser, Node *node);
int Calc_program_(Calc_parser_t *parser, Node *node);
int Calc_store_(Calc_parser_t *parser, Node *node);
int Calc_if_(Calc_parser_t *parser, Node *node);
int Calc_target_(Calc_parser_t *parser, Node *node);
int Calc_eq_(Calc_parser_t *parser, Node *node);
int Calc_ne_(Calc_parser_t *parser, Node *node);
int Calc_add_(Calc_parser_t *parser, Node *node);
int Calc_sub_(Calc_parser_t *parser, Node *node);
int Calc_mul_(Calc_parser_t *parser, Node *node);
int Calc_div_(Calc_parser_t *parser, Node *node);
int Calc_pwr_(Calc_parser_t *parser, Node *node);
int Calc_int_(Calc_parser_t *parser, Node *node);
int Calc_ident_(Calc_parser_t *parser, Node *node);
int Calc_then_(Calc_parser_t *parser, Node *node);
int Calc_then2_(Calc_parser_t *parser, Node *node);
int Calc_else2_(Calc_parser_t *parser, Node *node);
// Node action function pointers ...
static Calc_parser_t::nact_func_t Calc_nact_funcs_[17] = {
   Calc_goal_,
   Calc_program_,
   Calc_store_,
   Calc_if_,
   Calc_target_,
   Calc_eq_,
   Calc_ne_,
   Calc_add_,
   Calc_sub_,
   Calc_mul_,
   Calc_div_,
   Calc_pwr_,
   Calc_int_,
   Calc_ident_,
   Calc_then_,
   Calc_then2_,
   Calc_else2_,
};


Calc_parser_t
generated_parser(/* grammar      */   &Calc_grammar_name[0],
                 /* nd_parsing   */   false,
                 /* nd_threads   */   0,
                 /* node_actions */   true,
                 /* reversable   */   true,
                 /* semantics    */   false,
                 /* stksize      */   100,
                 /* term_actions */   true,
                 /* init_func    */   &Calc_init_funcs_[0],
                 /* tact_func    */   &Calc_tact_funcs_[0],
                 /* nact_func    */   &Calc_nact_funcs_[0]);

#include "lrstar_main.cpp"
