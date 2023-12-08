#include "lrstar_basic_defs.h"
#include "Calc_LexerTables_typedef.h"
#include "Calc_Parser.h"

const char Calc_grammar_name[] = "Calc";


void Calc_init_actions(UNUSED_PARAM(Calc_parser_t *parser)); /* User-supplied */
void Calc_term_actions(UNUSED_PARAM(Calc_parser_t *parser)); /* User-supplied */
static Calc_parser_t::init_func_t Calc_init_funcs_[2] = {
   Calc_init_actions,
   Calc_term_actions
};

int Calc_error(UNUSED_PARAM(Calc_parser_t *parser), UNUSED_PARAM(int &t));
int Calc_lookup(UNUSED_PARAM(Calc_parser_t *parser), UNUSED_PARAM(int &t));
// Terminal action function pointers ...
static Calc_parser_t::tact_func_t Calc_tact_funcs_[2] = {
   Calc_error,
   Calc_lookup,
};

int Calc_goal_(UNUSED_PARAM(Calc_parser_t *parser), UNUSED_PARAM(Node *node));
int Calc_program_(UNUSED_PARAM(Calc_parser_t *parser), UNUSED_PARAM(Node *node));
int Calc_store_(UNUSED_PARAM(Calc_parser_t *parser), UNUSED_PARAM(Node *node));
int Calc_if_(UNUSED_PARAM(Calc_parser_t *parser), UNUSED_PARAM(Node *node));
int Calc_target_(UNUSED_PARAM(Calc_parser_t *parser), UNUSED_PARAM(Node *node));
int Calc_eq_(UNUSED_PARAM(Calc_parser_t *parser), UNUSED_PARAM(Node *node));
int Calc_ne_(UNUSED_PARAM(Calc_parser_t *parser), UNUSED_PARAM(Node *node));
int Calc_add_(UNUSED_PARAM(Calc_parser_t *parser), UNUSED_PARAM(Node *node));
int Calc_sub_(UNUSED_PARAM(Calc_parser_t *parser), UNUSED_PARAM(Node *node));
int Calc_mul_(UNUSED_PARAM(Calc_parser_t *parser), UNUSED_PARAM(Node *node));
int Calc_div_(UNUSED_PARAM(Calc_parser_t *parser), UNUSED_PARAM(Node *node));
int Calc_pwr_(UNUSED_PARAM(Calc_parser_t *parser), UNUSED_PARAM(Node *node));
int Calc_int_(UNUSED_PARAM(Calc_parser_t *parser), UNUSED_PARAM(Node *node));
int Calc_ident_(UNUSED_PARAM(Calc_parser_t *parser), UNUSED_PARAM(Node *node));
int Calc_then_(UNUSED_PARAM(Calc_parser_t *parser), UNUSED_PARAM(Node *node));
int Calc_then2_(UNUSED_PARAM(Calc_parser_t *parser), UNUSED_PARAM(Node *node));
int Calc_else2_(UNUSED_PARAM(Calc_parser_t *parser), UNUSED_PARAM(Node *node));
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

Calc_parser_t *
Calc_new_parser()
{
   return new Calc_parser_t(/* init_func    */   &Calc_init_funcs_[0],
                            /* tact_func    */   &Calc_tact_funcs_[0],
                            /* nact_func    */   &Calc_nact_funcs_[0]);
}

Calc_parser_t *generated_parser = Calc_new_parser();

#include "lrstar_main.cpp"
