#include "lrstar_basic_defs.h"
#include "delphi_LexerTables_typedef.h"
#include "delphi_Parser.h"

const char delphi_grammar_name[] = "delphi";


delphi_parser_t
generated_parser(/* grammar      */   &delphi_grammar_name[0],
                 /* debug_parser */   false,
                 /* debug_trace  */   false,
                 /* expecting    */   true,
                 /* insensitive  */   false,
                 /* lookaheads   */   1,
                 /* make_ast     */   false,
                 /* nd_parsing   */   false,
                 /* nd_threads   */   0,
                 /* node_actions */   false,
                 /* reversable   */   false,
                 /* semantics    */   false,
                 /* stksize      */   100,
                 /* term_actions */   false,
                 /* init_func    */   0,
                 /* tact_func    */   0,
                 /* nact_func    */   0);

#include "lrstar_main.cpp"
