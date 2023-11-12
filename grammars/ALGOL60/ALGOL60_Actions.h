
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "ALGOL60_Parser.h"

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
         static int  error(void *parser, int &t);
         static int  lookup(void *parser, int &t);
      };

#endif
#ifdef NODE_ACTIONS

      class lrstar_node_actions : public lrstar_parser_actions
      {
         public:
      };

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

