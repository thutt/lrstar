
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "XPL_Parser.h"

#ifdef ACTIONS

void XPL_init_actions(lrstar_parser *parser);
void XPL_term_actions(lrstar_parser *parser);

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
      };

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

