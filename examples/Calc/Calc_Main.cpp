#include "lrstar_basic_defs.h"
#include "Calc_LexerTables_typedef.h"
#include "Calc_Parser.h"

void Calc_init_actions(lrstar_parser *parser); /* User-supplied */
void Calc_term_actions(lrstar_parser *parser); /* User-supplied */
static lrstar_parser::init_func_t Calc_init_funcs_[2] = {
   Calc_init_actions,
   Calc_term_actions
};

int Calc_error(lrstar_parser *parser, int &t);
int Calc_lookup(lrstar_parser *parser, int &t);
// Terminal action function pointers ...
static lrstar_parser::tact_func_t Calc_tact_funcs_[2] = {
   Calc_error,
   Calc_lookup,
};

int Calc_goal_(lrstar_parser *parser, Node *node);
int Calc_program_(lrstar_parser *parser, Node *node);
int Calc_store_(lrstar_parser *parser, Node *node);
int Calc_if_(lrstar_parser *parser, Node *node);
int Calc_target_(lrstar_parser *parser, Node *node);
int Calc_eq_(lrstar_parser *parser, Node *node);
int Calc_ne_(lrstar_parser *parser, Node *node);
int Calc_add_(lrstar_parser *parser, Node *node);
int Calc_sub_(lrstar_parser *parser, Node *node);
int Calc_mul_(lrstar_parser *parser, Node *node);
int Calc_div_(lrstar_parser *parser, Node *node);
int Calc_pwr_(lrstar_parser *parser, Node *node);
int Calc_int_(lrstar_parser *parser, Node *node);
int Calc_ident_(lrstar_parser *parser, Node *node);
int Calc_then_(lrstar_parser *parser, Node *node);
int Calc_then2_(lrstar_parser *parser, Node *node);
int Calc_else2_(lrstar_parser *parser, Node *node);
// Node action function pointers ...
static lrstar_parser::nact_func_t Calc_nact_funcs_[17] = {
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


lrstar_parser generated_parser(/* grammar      */   "Calc",
                               /* user data    */   NULL,
                               /* actions      */   true,
                               /* debug_parser */   false,
                               /* debug_trace  */   false,
                               /* expecting    */   true,
                               /* insensitive  */   false,
                               /* lookaheads   */   1,
                               /* make_ast     */   true,
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
