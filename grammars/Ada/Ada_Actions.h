
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "Ada_Parser.h"

class lrstar_parser;

void Ada_init_actions(lrstar_parser *parser);
void Ada_term_actions(lrstar_parser *parser);

#ifdef TERM_ACTIONS

int Ada_error(lrstar_parser *parser, int &t);
int Ada_lookup(lrstar_parser *parser, int &t);

#endif
#ifdef NODE_ACTIONS

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

