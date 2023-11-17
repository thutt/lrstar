
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "C_Parser.h"


void C_init_actions(lrstar_parser *parser);
void C_term_actions(lrstar_parser *parser);


#ifdef TERM_ACTIONS

int C_error(lrstar_parser *parser, int &t);
int C_lookup(lrstar_parser *parser, int &t);

#endif
#ifdef NODE_ACTIONS

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

