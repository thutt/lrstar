#include "lrstar_basic_defs.h"
#include "CPP5_LexerTables_typedef.h"
#include "CPP5_Parser.h"


const char CPP5_grammar_name[] = "CPP5";


CPP5_parser_t *
CPP5_new_parser()
{
   return new CPP5_parser_t(/* init_func    */   0,
                            /* tact_func    */   0,
                            /* nact_func    */   0);
}

CPP5_parser_t *generated_parser = CPP5_new_parser();

