
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "Python_Parser.h"

class lrstar_parser;

#ifdef ACTIONS

void Python_init_actions(lrstar_parser *parser);
void Python_term_actions(lrstar_parser *parser);

#endif
#ifdef TERM_ACTIONS

int Python_error(lrstar_parser *parser, int &t);
int Python_lookup(lrstar_parser *parser, int &t);

#endif
#ifdef NODE_ACTIONS

      class lrstar_node_actions : public lrstar_parser
      {
         public:
      };

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

