#include "lrstar_basic_defs.h"
#include "YACC_LexerTables_typedef.h"
#include "YACC_Parser.h"

const char YACC_grammar_name[] = "YACC";


YACC_parser_t
generated_parser(/* grammar      */   &YACC_grammar_name[0],
                 /* init_func    */   0,
                 /* tact_func    */   0,
                 /* nact_func    */   0);

#include "lrstar_main.cpp"
