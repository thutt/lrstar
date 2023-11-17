#pragma once

#include "Java9_Parser.h"

class lrstar_parser;


void Java9_init_actions(lrstar_parser *parser);
void Java9_term_actions(lrstar_parser *parser);


int Java9_error(lrstar_parser *parser, int &t);
int Java9_lookup(lrstar_parser *parser, int &t);
