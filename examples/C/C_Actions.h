
////////////////////////////////////////////////////////////////////////////////
//
		#pragma once

		#include "C_Parser.h"

		#ifdef ACTIONS

      class lrstar_parser_actions : public lrstar_parser
      {
			public:
         static void init_actions(void *parser);
         static void term_actions(void *parser);
      };

		#endif

		#ifdef TERM_ACTIONS

		class lrstar_term_actions : public lrstar_parser_actions
		{
		public:
			static int error(void *parser, int &t);
			static int lookup(void *parser, int &t);
		};

		#endif

//
////////////////////////////////////////////////////////////////////////////////

/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
