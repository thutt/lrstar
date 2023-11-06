
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "Java9_Parser.h"

#ifdef ACTIONS

      class lrstar_parser_actions : public lrstar_parser
      {
         public:
         static void init_actions ();
         static void term_actions ();
      };

#endif
#ifdef TERM_ACTIONS

      class lrstar_term_actions : public lrstar_parser_actions
      {
         public:
         static int  error     (int& t);
         static int  lookup (int& t);
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

