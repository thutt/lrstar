
/* Copyright 2018, 2023 Paul B Mann.  BSD License. */

#pragma once
#include "LG_ComputeLA.h"

class LG_PrintStates : public LG_ComputeLA
{
public:
   static void  PrintStates (int type);

private:
   static void  PRT_STA (int s);
   static void  P_SYMBOL (int s);
   static void  P_RANGE (int s1, int s2);
   static int   p_sym (int s, const char *sp);
   static void  p_prod (int p, int dot, const char *before, const char* after);
};

/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
