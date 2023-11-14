
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "verilog_Parser.h"

class lrstar_parser;

#ifdef ACTIONS

void verilog_init_actions(lrstar_parser *parser);
void verilog_term_actions(lrstar_parser *parser);

#endif
#ifdef TERM_ACTIONS

int verilog_error(lrstar_parser *parser, int &t);
int verilog_lookup(lrstar_parser *parser, int &t);

#endif
#ifdef NODE_ACTIONS

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

