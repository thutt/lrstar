#include "lrstar_basic_defs.h"
#include "delphi_LexerTables_typedef.h"
#include "delphi_Parser.h"


const char delphi_grammar_name[] = "delphi";


delphi_parser_t *
delphi_new_parser(const char *input_path,
                  char       *input_text,
                  unsigned    max_symbols)
{
   return new delphi_parser_t(/* input path   */   input_path,
                              /* input text   */   input_text,
                              /* max symbols  */   max_symbols,
                              /* init_func    */   0,
                              /* tact_func    */   0,
                              /* nact_func    */   0);
}

