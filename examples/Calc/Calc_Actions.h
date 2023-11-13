///////////////////////////////////////////////////////////////////////////////
//                                                                           //
#pragma once
#include "Calc_Parser.h"

#ifdef ACTIONS

#endif
#ifdef TERM_ACTIONS

class lrstar_term_actions : public lrstar_parser
{
public:
   static int error(lrstar_parser *parser, int &t);
   static int lookup(lrstar_parser *parser, int &t);
};

#endif
#ifdef NODE_ACTIONS

class lrstar_node_actions : public lrstar_parser
{
public:
    static int  eq_      (void* v);
    static int  ne_      (void* v);
    static int  add_     (void* v);
    static int  sub_     (void* v);
    static int  mul_     (void* v);
    static int  div_     (void* v);
    static int  pwr_     (void* v);
    static int  goal_    (void* v);
    static int  ident_   (void* v);
    static int  if_      (void* v);
    static int  then_    (void* v);
    static int  then2_   (void* v);
    static int  else2_   (void* v);
    static int  program_ (void* v);
    static int  int_     (void* v);
    static int  store_   (void* v);
    static int  target_  (void* v);
};

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
