#include "lrstar_basic_defs.h"
#include "Python_LexerTables_typedef.h"
#include "Python_Parser.h"


const char Python_grammar_name[] = "Python";


Python_parser_t *
Python_new_parser()
{
   return new Python_parser_t(/* init_func    */   0,
                              /* tact_func    */   0,
                              /* nact_func    */   0);
}

Python_parser_t *generated_parser = Python_new_parser();

