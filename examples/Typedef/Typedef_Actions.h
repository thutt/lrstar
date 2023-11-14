
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "Typedef_Parser.h"

#ifdef ACTIONS

void Typedef_init_actions(lrstar_parser *parser);
void Typedef_term_actions(lrstar_parser *parser);

#endif
#ifdef TERM_ACTIONS

int Typedef_error(lrstar_parser *parser, int &t);
int Typedef_lookup(lrstar_parser *parser, int &t);

#endif
#ifdef NODE_ACTIONS

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

