#include "lrstar_basic_defs.h"
#include "PLSQL_LexerTables_typedef.h"
#include "PLSQL_Parser.h"

const char PLSQL_grammar_name[] = "PLSQL";


PLSQL_parser_t *
PLSQL_new_parser()
{
   return new PLSQL_parser_t(/* init_func    */   0,
                             /* tact_func    */   0,
                             /* nact_func    */   0);
}

PLSQL_parser_t *generated_parser = PLSQL_new_parser();

#include "lrstar_main.cpp"
