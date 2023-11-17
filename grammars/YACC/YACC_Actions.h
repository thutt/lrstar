#pragma once

#include "YACC_Parser.h"

class lrstar_parser;


void YACC_init_actions(lrstar_parser *parser);
void YACC_term_actions(lrstar_parser *parser);


#ifdef TERM_ACTIONS

int YACC_error(lrstar_parser *parser, int &t);
int YACC_lookup(lrstar_parser *parser, int &t);

#endif
