
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "PLSQL_Parser.h"

#ifdef ACTIONS

void PLSQL_init_actions(void *parser);
void PLSQL_term_actions(void *parser);

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

