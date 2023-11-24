#include "lrstar_basic_defs.h"
#include "Python_LexerTables_typedef.h"
#include "Python_Parser.h"

const char Python_grammar_name[] = "Python";


Python_parser_t
generated_parser(/* grammar      */   &Python_grammar_name[0],
                 /* init_func    */   0,
                 /* tact_func    */   0,
                 /* nact_func    */   0);

#include "lrstar_main.cpp"
