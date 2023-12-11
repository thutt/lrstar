#include "lrstar_basic_defs.h"
#include "C_LexerTables_typedef.h"
#include "C_Parser.h"


const char C_grammar_name[] = "C";


C_parser_t *
C_new_parser(const char *input_path,
             char       *input_text,
             unsigned    max_symbols)
{
   return new C_parser_t(/* input path   */   input_path,
                         /* input text   */   input_text,
                         /* max symbols  */   max_symbols,
                         /* init_func    */   0,
                         /* tact_func    */   0,
                         /* nact_func    */   0);
}

