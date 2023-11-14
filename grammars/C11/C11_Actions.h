
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "C11_Parser.h"

class lrstar_parser;

#ifdef ACTIONS

void C11_init_actions(lrstar_parser *parser);
void C11_term_actions(lrstar_parser *parser);

#endif
#ifdef TERM_ACTIONS

int C11_error(lrstar_parser *parser, int &t);
int C11_lookup(lrstar_parser *parser, int &t);

#endif
#ifdef NODE_ACTIONS

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

