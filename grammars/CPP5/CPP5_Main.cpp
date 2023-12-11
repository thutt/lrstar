#include "lrstar_basic_defs.h"
#include "CPP5_LexerTables_typedef.h"
#include "CPP5_Parser.h"


const char CPP5_grammar_name[] = "CPP5";


CPP5_parser_t *
CPP5_new_parser(const char *input_path,
                char       *input_text,
                unsigned    max_symbols)
{
   return new CPP5_parser_t(/* input path   */   input_path,
                            /* input text   */   input_text,
                            /* max symbols  */   max_symbols,
                            /* init_func    */   0,
                            /* tact_func    */   0,
                            /* nact_func    */   0);
}

