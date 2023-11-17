#pragma once

#include "delphi_Parser.h"

class lrstar_parser;


void delphi_init_actions(lrstar_parser *parser);
void delphi_term_actions(lrstar_parser *parser);


#ifdef TERM_ACTIONS

int delphi_error(lrstar_parser *parser, int &t);
int delphi_lookup(lrstar_parser *parser, int &t);

#endif
