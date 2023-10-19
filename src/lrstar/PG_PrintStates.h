
/* Copyright 2018, 2023 Paul B Mann.  BSD License. */

		#pragma once

		#include "PG_ComputeLA.h"

		class PG_PrintStates : public PG_ComputeLA
		{
			public:
			static void  PrintStates ();

			private:
         static int   C_max_symbl (int s);
			static void  PRT_STA (int s);
			static void  P_HEAD  (int s);
			static void  P_SYMBOL (int s);
			static void  P_SYMBOL (int s, const char* prefix);
			static int   p_head (int s, const char *sp);
			static int   p_sym (int s, const char* sp);
			static int   p_sym60 (int s, const char* sp);
			static void  p_prod (int p, int dot, const char *before, const char* after);
		};


/* Local Variables:    */
/* mode: c             */
/* c-basic-offset: 3   */
/* tab-width: 3        */
/* indent-tabs-mode: t */
/* End:                */
