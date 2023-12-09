#include "lrstar_basic_defs.h"
#include "delphi_LexerTables_typedef.h"
#include "delphi_Parser.h"


const char delphi_grammar_name[] = "delphi";


delphi_parser_t *
delphi_new_parser()
{
   return new delphi_parser_t(/* init_func    */   0,
                              /* tact_func    */   0,
                              /* nact_func    */   0);
}

delphi_parser_t *generated_parser = delphi_new_parser();

