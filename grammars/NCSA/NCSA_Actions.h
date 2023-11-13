
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "NCSA_Parser.h"

#ifdef ACTIONS

void NCSA_init_actions(void *parser);
void NCSA_term_actions(void *parser);

#endif
#ifdef TERM_ACTIONS

      class lrstar_term_actions : public lrstar_parser
      {
         public:
         static int error(void *parser, int &t);
         static int lookup(void *parser, int &t);
      };

#endif
#ifdef NODE_ACTIONS

      class lrstar_node_actions : public lrstar_parser
      {
         public:
      };

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

