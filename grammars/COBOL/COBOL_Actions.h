
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "COBOL_Parser.h"

class lrstar_parser;

#ifdef ACTIONS

void COBOL_init_actions(lrstar_parser *parser);
void COBOL_term_actions(lrstar_parser *parser);

#endif
#ifdef TERM_ACTIONS

int COBOL_error(lrstar_parser *parser, int &t);
int COBOL_lookup(lrstar_parser *parser, int &t);

#endif
#ifdef NODE_ACTIONS

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

