#pragma once

#include "SQL_Parser.h"

class lrstar_parser;


void SQL_init_actions(lrstar_parser *parser);
void SQL_term_actions(lrstar_parser *parser);


#ifdef TERM_ACTIONS

int SQL_error(lrstar_parser *parser, int &t);
int SQL_lookup(lrstar_parser *parser, int &t);

#endif
