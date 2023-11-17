
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "XPL_Parser.h"

class lrstar_parser;


void XPL_init_actions(lrstar_parser *parser);
void XPL_term_actions(lrstar_parser *parser);


#ifdef TERM_ACTIONS

int XPL_error(lrstar_parser *parser, int &t);
int XPL_lookup(lrstar_parser *parser, int &t);

#endif
#ifdef NODE_ACTIONS

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

