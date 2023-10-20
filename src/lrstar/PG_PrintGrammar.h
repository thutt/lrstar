
/* Copyright 2018, 2023 Paul B Mann.  BSD License. */

#include "PG_CheckGrammar.h"

class PG_PrintGrammar : public PG_CheckGrammar
{
public:
   static void  PrintGrammar();
   static void  PrintHtml();

private:
   static int   p_head    (const char* before, int s, const char *after);
   static int   p_tail    (const char* before, int s, const char *after);
   static void  print_struc ();

   static int   ph_nont   (const char* before, int s, const char *after);
   static int   ph_head   (const char* before, int s, const char *after);
   static int   ph_tail   (const char* before, int s, const char *after);
   static int   ph_sym    (int nont_on, int tail_on,
                           const char* before, int s, const char *after);
   static void  ph_spaces (int ns);
   static void  ph_arg    (int i);
//       static int   ph_gensym (int h, const char *sp);

};

/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
