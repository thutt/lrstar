#include "lrstar_basic_defs.h"
#include "C_LexerTables_typedef.h"
#include "C_Parser.h"

const char C_grammar_name[] = "C";


C_parser_t *
C_new_parser()
{
   return new C_parser_t(/* init_func    */   0,
                         /* tact_func    */   0,
                         /* nact_func    */   0);
}

C_parser_t *generated_parser = C_new_parser();

#include "lrstar_main.cpp"
