#include "lrstar_basic_defs.h"
#include "ALGOL60_LexerTables_typedef.h"
#include "ALGOL60_Parser.h"

const char ALGOL60_grammar_name[] = "ALGOL60";


ALGOL60_parser_t
generated_parser(/* grammar      */   &ALGOL60_grammar_name[0],
                 /* term_actions */   false,
                 /* init_func    */   0,
                 /* tact_func    */   0,
                 /* nact_func    */   0);

#include "lrstar_main.cpp"
