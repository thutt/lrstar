#include "lrstar_basic_defs.h"
#include "PLSQL_LexerTables_typedef.h"
#include "PLSQL_Parser.h"

const char PLSQL_grammar_name[] = "PLSQL";


PLSQL_parser_t
generated_parser(/* grammar      */   &PLSQL_grammar_name[0],
                 /* init_func    */   0,
                 /* tact_func    */   0,
                 /* nact_func    */   0);

#include "lrstar_main.cpp"
