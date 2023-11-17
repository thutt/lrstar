
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "Pascal_Parser.h"

class lrstar_parser;


void Pascal_init_actions(lrstar_parser *parser);
void Pascal_term_actions(lrstar_parser *parser);


#ifdef TERM_ACTIONS

int Pascal_error(lrstar_parser *parser, int &t);
int Pascal_lookup(lrstar_parser *parser, int &t);

#endif
#ifdef NODE_ACTIONS

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

