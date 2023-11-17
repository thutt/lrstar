#pragma once

#include "LRK_Parser.h"

class lrstar_parser;


void LRK_init_actions(lrstar_parser *parser);
void LRK_term_actions(lrstar_parser *parser);


int LRK_error(lrstar_parser *parser, int &t);
int LRK_lookup(lrstar_parser *parser, int &t);
