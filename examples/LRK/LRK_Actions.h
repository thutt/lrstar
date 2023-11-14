
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "LRK_Parser.h"

#ifdef ACTIONS

void LRK_init_actions(lrstar_parser *parser);
void LRK_term_actions(lrstar_parser *parser);

#endif
#ifdef TERM_ACTIONS

int LRK_error(lrstar_parser *parser, int &t);
int LRK_lookup(lrstar_parser *parser, int &t);

#endif
#ifdef NODE_ACTIONS

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

