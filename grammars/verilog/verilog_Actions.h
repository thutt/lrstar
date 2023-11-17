#pragma once

#include "verilog_Parser.h"

class lrstar_parser;


void verilog_init_actions(lrstar_parser *parser);
void verilog_term_actions(lrstar_parser *parser);


int verilog_error(lrstar_parser *parser, int &t);
int verilog_lookup(lrstar_parser *parser, int &t);
