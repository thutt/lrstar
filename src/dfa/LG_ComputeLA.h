
/* Copyright 2018, 2023 Paul B Mann.  BSD License. */

#pragma once
#include "LG_AddExtra.h"

class LG_ComputeLA : public LG_AddExtra
{
public:
   static int     c_states;

   static int*    D_red;
   static int*    la_start;
   static int*    la_end;
   static int*    la_symb;
   static int*    la_red;

   static int     n_lookbacks;
   static int     n_lookah;
   static int     n_includes;

   static int     ComputeLA ();

private:
   static void    ANALYZE (int& nc, int s, int f);
   static void    IND_READ (int i, int s);
   static void    LOOK_BACK (int x, int p, int dot, int s);
   static int     NTX (int s, int h);
   static void    C_INCLUDE (int s, int y);
   static void    C_LALR ();
   static void    C_LOOKBACKS ();
   static void    C_READS ();
   static void    PRT_STA (int s);
   static int     p_sym (int s, const char *sp);
   static void    p_prod (int p, int dot, const char *before);
   static void    prt_rrcon (int& nc, int s, int t);
   static void    prt_srcon (int& nc, int s, int t, int p);
};

/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
