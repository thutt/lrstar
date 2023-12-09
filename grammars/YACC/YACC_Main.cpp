#include "lrstar_basic_defs.h"
#include "YACC_LexerTables_typedef.h"
#include "YACC_Parser.h"


const char YACC_grammar_name[] = "YACC";


YACC_parser_t *
YACC_new_parser()
{
   return new YACC_parser_t(/* init_func    */   0,
                            /* tact_func    */   0,
                            /* nact_func    */   0);
}

YACC_parser_t *generated_parser = YACC_new_parser();

