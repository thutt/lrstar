#pragma once

#include "Dbase_Parser.h"

class lrstar_parser;


void Dbase_init_actions(lrstar_parser *parser);
void Dbase_term_actions(lrstar_parser *parser);


int Dbase_error(lrstar_parser *parser, int &t);
int Dbase_lookup(lrstar_parser *parser, int &t);
