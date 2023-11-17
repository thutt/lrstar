#pragma once

#include "CPP5_Parser.h"

class lrstar_parser;


void CPP5_init_actions(lrstar_parser *parser);
void CPP5_term_actions(lrstar_parser *parser);


#ifdef TERM_ACTIONS

int CPP5_error(lrstar_parser *parser, int &t);
int CPP5_lookup(lrstar_parser *parser, int &t);

#endif
