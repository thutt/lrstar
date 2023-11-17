#pragma once

#include "Java1_Parser.h"

class lrstar_parser;


void Java1_init_actions(lrstar_parser *parser);
void Java1_term_actions(lrstar_parser *parser);

int Java1_error(lrstar_parser *parser, int &t);
int Java1_lookup(lrstar_parser *parser, int &t);
