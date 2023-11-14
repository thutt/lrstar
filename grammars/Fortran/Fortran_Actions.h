
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "Fortran_Parser.h"

class lrstar_parser;

#ifdef ACTIONS

void Fortran_init_actions(lrstar_parser *parser);
void Fortran_term_actions(lrstar_parser *parser);

#endif
#ifdef TERM_ACTIONS

int Fortran_error(lrstar_parser *parser, int &t);
int Fortran_lookup(lrstar_parser *parser, int &t);

#endif
#ifdef NODE_ACTIONS

      class lrstar_node_actions : public lrstar_parser
      {
         public:
      };

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

