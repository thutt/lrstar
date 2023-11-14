
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "SQL_Parser.h"

class lrstar_parser;

#ifdef ACTIONS

void SQL_init_actions(lrstar_parser *parser);
void SQL_term_actions(lrstar_parser *parser);

#endif
#ifdef TERM_ACTIONS

int SQL_error(lrstar_parser *parser, int &t);
int SQL_lookup(lrstar_parser *parser, int &t);

#endif
#ifdef NODE_ACTIONS

      class lrstar_node_actions : public lrstar_parser
      {
         public:
      };

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

