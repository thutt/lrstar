
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "PL1_Parser.h"

class lrstar_parser;

#ifdef ACTIONS

void PL1_init_actions(lrstar_parser *parser);
void PL1_term_actions(lrstar_parser *parser);

#endif
#ifdef TERM_ACTIONS

int PL1_error(lrstar_parser *parser, int &t);
int PL1_lookup(lrstar_parser *parser, int &t);

#endif
#ifdef NODE_ACTIONS

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

