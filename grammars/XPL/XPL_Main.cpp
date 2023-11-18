
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "XPL_LexerTables_typedef.h"
#include "XPL_Parser.h"

lrstar_parser generated_parser(/* grammar      */   "XPL",
                               /* user data    */   NULL,
                               /* actions      */   true,
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
                               /* term_actions */   true);

#include "lrstar_main.cpp"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

