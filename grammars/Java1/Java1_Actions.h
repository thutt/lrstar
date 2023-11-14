
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "Java1_Parser.h"

class lrstar_parser;

#ifdef ACTIONS

void Java1_init_actions(lrstar_parser *parser);
void Java1_term_actions(lrstar_parser *parser);

#endif
#ifdef TERM_ACTIONS

int Java1_error(lrstar_parser *parser, int &t);
int Java1_lookup(lrstar_parser *parser, int &t);

#endif
#ifdef NODE_ACTIONS

      class lrstar_node_actions : public lrstar_parser
      {
         public:
      };

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

