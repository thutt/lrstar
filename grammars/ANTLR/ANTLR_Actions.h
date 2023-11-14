
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "ANTLR_Parser.h"

class lrstar_parser;

#ifdef ACTIONS

void ANTLR_init_actions(lrstar_parser *parser);
void ANTLR_term_actions(lrstar_parser *parser);

#endif
#ifdef TERM_ACTIONS

int ANTLR_error(lrstar_parser *parser, int &t);
int ANTLR_lookup(lrstar_parser *parser, int &t);

#endif
#ifdef NODE_ACTIONS

      class lrstar_node_actions : public lrstar_parser
      {
         public:
      };

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

