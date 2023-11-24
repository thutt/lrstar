#include "lrstar_basic_defs.h"
#include "CPP5_LexerTables_typedef.h"
#include "CPP5_Parser.h"

const char CPP5_grammar_name[] = "CPP5";


CPP5_parser_t
generated_parser(/* grammar      */   &CPP5_grammar_name[0],
                 /* init_func    */   0,
                 /* tact_func    */   0,
                 /* nact_func    */   0);

#include "lrstar_main.cpp"
