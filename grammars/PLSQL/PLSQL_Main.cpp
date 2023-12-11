#include "lrstar_basic_defs.h"
#include "PLSQL_LexerTables_typedef.h"
#include "PLSQL_Parser.h"


const char PLSQL_grammar_name[] = "PLSQL";


PLSQL_parser_t *
PLSQL_new_parser(const char *input_path,
                 char       *input_text,
                 unsigned    max_symbols)
{
   return new PLSQL_parser_t(/* input path   */   input_path,
                             /* input text   */   input_text,
                             /* max symbols  */   max_symbols,
                             /* init_func    */   0,
                             /* tact_func    */   0,
                             /* nact_func    */   0);
}

