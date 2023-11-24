#include "lrstar_basic_defs.h"
#include "ALGOL60_LexerTables_typedef.h"
#include "ALGOL60_Parser.h"


lrstar_parser generated_parser(/* grammar      */   "ALGOL60",
                               /* user data    */   NULL,
                               /* actions      */   false,
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
                               /* init_func    */   NULL,
                               /* tact_func    */   NULL,
                               /* nact_func    */   NULL);

#include "lrstar_main.cpp"
