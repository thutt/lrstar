///////////////////////////////////////////////////////////////////////////////
//                                                                           //
#pragma once
#include "Calc_Parser.h"

#ifdef TERM_ACTIONS

int Calc_error(lrstar_parser *parser, int &t);
int Calc_lookup(lrstar_parser *parser, int &t);

#endif
#ifdef NODE_ACTIONS

int Calc_eq_      (lrstar_parser *parser, Node *n);
int Calc_ne_      (lrstar_parser *parser, Node *n);
int Calc_add_     (lrstar_parser *parser, Node *n);
int Calc_sub_     (lrstar_parser *parser, Node *n);
int Calc_mul_     (lrstar_parser *parser, Node *n);
int Calc_div_     (lrstar_parser *parser, Node *n);
int Calc_pwr_     (lrstar_parser *parser, Node *n);
int Calc_goal_    (lrstar_parser *parser, Node *n);
int Calc_ident_   (lrstar_parser *parser, Node *n);
int Calc_if_      (lrstar_parser *parser, Node *n);
int Calc_then_    (lrstar_parser *parser, Node *n);
int Calc_then2_   (lrstar_parser *parser, Node *n);
int Calc_else2_   (lrstar_parser *parser, Node *n);
int Calc_program_ (lrstar_parser *parser, Node *n);
int Calc_int_     (lrstar_parser *parser, Node *n);
int Calc_store_   (lrstar_parser *parser, Node *n);
int Calc_target_  (lrstar_parser *parser, Node *n);

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
