#pragma once

#include "Fortran_Parser.h"

class lrstar_parser;


void Fortran_init_actions(lrstar_parser *parser);
void Fortran_term_actions(lrstar_parser *parser);


int Fortran_error(lrstar_parser *parser, int &t);
int Fortran_lookup(lrstar_parser *parser, int &t);
