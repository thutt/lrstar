
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "NCSA_Parser.h"

class lrstar_parser;

#ifdef ACTIONS

void NCSA_init_actions(lrstar_parser *parser);
void NCSA_term_actions(lrstar_parser *parser);

#endif
#ifdef TERM_ACTIONS

int NCSA_error(lrstar_parser *parser, int &t);
int NCSA_lookup(lrstar_parser *parser, int &t);

#endif
#ifdef NODE_ACTIONS

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

