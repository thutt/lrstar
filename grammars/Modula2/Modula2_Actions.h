
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "Modula2_Parser.h"

class lrstar_parser;

#ifdef ACTIONS

void Modula2_init_actions(lrstar_parser *parser);
void Modula2_term_actions(lrstar_parser *parser);

#endif
#ifdef TERM_ACTIONS

int Modula2_error(lrstar_parser *parser, int &t);
int Modula2_lookup(lrstar_parser *parser, int &t);

#endif
#ifdef NODE_ACTIONS

      class lrstar_node_actions : public lrstar_parser
      {
         public:
      };

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

