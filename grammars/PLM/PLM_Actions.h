
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "PLM_Parser.h"

class lrstar_parser;

#ifdef ACTIONS

void PLM_init_actions(lrstar_parser *parser);
void PLM_term_actions(lrstar_parser *parser);

#endif
#ifdef TERM_ACTIONS

int PLM_error(lrstar_parser *parser, int &t);
int PLM_lookup(lrstar_parser *parser, int &t);

#endif
#ifdef NODE_ACTIONS

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

