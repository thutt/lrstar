#include "lrstar_basic_defs.h"
#include "Calc_LexerTables_typedef.h"
#include "Calc_Parser.h"

namespace Calc {

const char grammar_name[] = "Calc";


void init_actions(UNUSED_PARAM(parser_t *parser)); /* User-supplied */
void term_actions(UNUSED_PARAM(parser_t *parser)); /* User-supplied */
static parser_t::init_func_t init_funcs_[2] = {
   init_actions,
   term_actions
};

int error(UNUSED_PARAM(parser_t *parser), UNUSED_PARAM(int &t));
int lookup(UNUSED_PARAM(parser_t *parser), UNUSED_PARAM(int &t));
// Terminal action function pointers.
static parser_t::tact_func_t tact_funcs_[2] = {
   error,
   lookup,
};

void goal_(UNUSED_PARAM(unsigned traversal_number),
                UNUSED_PARAM(parse_direction_t direction),
                UNUSED_PARAM(parser_t *parser),
                UNUSED_PARAM(Node *node));
void program_(UNUSED_PARAM(unsigned traversal_number),
                   UNUSED_PARAM(parse_direction_t direction),
                   UNUSED_PARAM(parser_t *parser),
                   UNUSED_PARAM(Node *node));
void store_(UNUSED_PARAM(unsigned traversal_number),
                 UNUSED_PARAM(parse_direction_t direction),
                 UNUSED_PARAM(parser_t *parser),
                 UNUSED_PARAM(Node *node));
void if_(UNUSED_PARAM(unsigned traversal_number),
              UNUSED_PARAM(parse_direction_t direction),
              UNUSED_PARAM(parser_t *parser),
              UNUSED_PARAM(Node *node));
void target_(UNUSED_PARAM(unsigned traversal_number),
                  UNUSED_PARAM(parse_direction_t direction),
                  UNUSED_PARAM(parser_t *parser),
                  UNUSED_PARAM(Node *node));
void eq_(UNUSED_PARAM(unsigned traversal_number),
              UNUSED_PARAM(parse_direction_t direction),
              UNUSED_PARAM(parser_t *parser),
              UNUSED_PARAM(Node *node));
void ne_(UNUSED_PARAM(unsigned traversal_number),
              UNUSED_PARAM(parse_direction_t direction),
              UNUSED_PARAM(parser_t *parser),
              UNUSED_PARAM(Node *node));
void add_(UNUSED_PARAM(unsigned traversal_number),
               UNUSED_PARAM(parse_direction_t direction),
               UNUSED_PARAM(parser_t *parser),
               UNUSED_PARAM(Node *node));
void sub_(UNUSED_PARAM(unsigned traversal_number),
               UNUSED_PARAM(parse_direction_t direction),
               UNUSED_PARAM(parser_t *parser),
               UNUSED_PARAM(Node *node));
void mul_(UNUSED_PARAM(unsigned traversal_number),
               UNUSED_PARAM(parse_direction_t direction),
               UNUSED_PARAM(parser_t *parser),
               UNUSED_PARAM(Node *node));
void div_(UNUSED_PARAM(unsigned traversal_number),
               UNUSED_PARAM(parse_direction_t direction),
               UNUSED_PARAM(parser_t *parser),
               UNUSED_PARAM(Node *node));
void pwr_(UNUSED_PARAM(unsigned traversal_number),
               UNUSED_PARAM(parse_direction_t direction),
               UNUSED_PARAM(parser_t *parser),
               UNUSED_PARAM(Node *node));
void int_(UNUSED_PARAM(unsigned traversal_number),
               UNUSED_PARAM(parse_direction_t direction),
               UNUSED_PARAM(parser_t *parser),
               UNUSED_PARAM(Node *node));
void ident_(UNUSED_PARAM(unsigned traversal_number),
                 UNUSED_PARAM(parse_direction_t direction),
                 UNUSED_PARAM(parser_t *parser),
                 UNUSED_PARAM(Node *node));
void then_(UNUSED_PARAM(unsigned traversal_number),
                UNUSED_PARAM(parse_direction_t direction),
                UNUSED_PARAM(parser_t *parser),
                UNUSED_PARAM(Node *node));
void then2_(UNUSED_PARAM(unsigned traversal_number),
                 UNUSED_PARAM(parse_direction_t direction),
                 UNUSED_PARAM(parser_t *parser),
                 UNUSED_PARAM(Node *node));
void else2_(UNUSED_PARAM(unsigned traversal_number),
                 UNUSED_PARAM(parse_direction_t direction),
                 UNUSED_PARAM(parser_t *parser),
                 UNUSED_PARAM(Node *node));
// Node action function pointers.
static parser_t::nact_func_t nact_funcs_[17] = {
   goal_,
   program_,
   store_,
   if_,
   target_,
   eq_,
   ne_,
   add_,
   sub_,
   mul_,
   div_,
   pwr_,
   int_,
   ident_,
   then_,
   then2_,
   else2_,
};

parser_t *
new_parser(const char *input_path,
           char       *input_text,
           unsigned    max_symbols)
{
   return new parser_t(/* input path   */   input_path,
                       /* input text   */   input_text,
                       /* max symbols  */   max_symbols,
                       /* init_func    */   &init_funcs_[0],
                       /* tact_func    */   &tact_funcs_[0],
                       /* nact_func    */   &nact_funcs_[0]);
}


};   /* namespace Calc */
