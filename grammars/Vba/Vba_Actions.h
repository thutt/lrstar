#pragma once

#include "Vba_Parser.h"

class lrstar_parser;


void Vba_init_actions(lrstar_parser *parser);
void Vba_term_actions(lrstar_parser *parser);


#ifdef TERM_ACTIONS

int Vba_error(lrstar_parser *parser, int &t);
int Vba_lookup(lrstar_parser *parser, int &t);

#endif
