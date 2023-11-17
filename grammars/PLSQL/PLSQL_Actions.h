#pragma once

#include "PLSQL_Parser.h"

class lrstar_parser;


void PLSQL_init_actions(lrstar_parser *parser);
void PLSQL_term_actions(lrstar_parser *parser);


#ifdef TERM_ACTIONS

int PLSQL_error(lrstar_parser *parser, int &t);
int PLSQL_lookup(lrstar_parser *parser, int &t);

#endif
