#include "lrstar_basic_defs.h"
#include "Python_LexerTables_typedef.h"
#include "Python_Parser.h"


const char Python_grammar_name[] = "Python";


Python_parser_t *
Python_new_parser(const char *input_path,
                  char       *input_text,
                  unsigned    max_symbols)
{
   return new Python_parser_t(/* input path   */   input_path,
                              /* input text   */   input_text,
                              /* max symbols  */   max_symbols,
                              /* init_func    */   0,
                              /* tact_func    */   0,
                              /* nact_func    */   0);
}

