#pragma once
#include "Calc_Parser.h"

int Calc_error(Calc_parser_t *parser, int &t);
int Calc_lookup(Calc_parser_t *parser, int &t);

int Calc_eq_      (Calc_parser_t *parser, Node *n);
int Calc_ne_      (Calc_parser_t *parser, Node *n);
int Calc_add_     (Calc_parser_t *parser, Node *n);
int Calc_sub_     (Calc_parser_t *parser, Node *n);
int Calc_mul_     (Calc_parser_t *parser, Node *n);
int Calc_div_     (Calc_parser_t *parser, Node *n);
int Calc_pwr_     (Calc_parser_t *parser, Node *n);
int Calc_goal_    (Calc_parser_t *parser, Node *n);
int Calc_ident_   (Calc_parser_t *parser, Node *n);
int Calc_if_      (Calc_parser_t *parser, Node *n);
int Calc_then_    (Calc_parser_t *parser, Node *n);
int Calc_then2_   (Calc_parser_t *parser, Node *n);
int Calc_else2_   (Calc_parser_t *parser, Node *n);
int Calc_program_ (Calc_parser_t *parser, Node *n);
int Calc_int_     (Calc_parser_t *parser, Node *n);
int Calc_store_   (Calc_parser_t *parser, Node *n);
int Calc_target_  (Calc_parser_t *parser, Node *n);

/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
