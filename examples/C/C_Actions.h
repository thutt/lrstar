
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "C_Parser.h"

#ifdef ACTIONS

void C_init_actions(lrstar_parser *parser);
void C_term_actions(lrstar_parser *parser);

#endif
#ifdef TERM_ACTIONS

int C_error(lrstar_parser *parser, int &t);
int C_lookup(lrstar_parser *parser, int &t);

#endif
#ifdef NODE_ACTIONS

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

