
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "ALGOL60_Parser.h"

class lrstar_parser;

void ALGOL60_init_actions(lrstar_parser *parser);
void ALGOL60_term_actions(lrstar_parser *parser);

#ifdef TERM_ACTIONS

int ALGOL60_error(lrstar_parser *parser, int &t);
int ALGOL60_lookup(lrstar_parser *parser, int &t);

#endif
#ifdef NODE_ACTIONS

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

