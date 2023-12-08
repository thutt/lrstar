#include "lrstar_basic_defs.h"
#include "ALGOL60_LexerTables_typedef.h"
#include "ALGOL60_Parser.h"

const char ALGOL60_grammar_name[] = "ALGOL60";


ALGOL60_parser_t *
ALGOL60_new_parser()
{
   return new ALGOL60_parser_t(/* init_func    */   0,
                               /* tact_func    */   0,
                               /* nact_func    */   0);
}

ALGOL60_parser_t *generated_parser = ALGOL60_new_parser();

#include "lrstar_main.cpp"
