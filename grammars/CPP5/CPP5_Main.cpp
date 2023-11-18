
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "CPP5_LexerTables_typedef.h"
#include "CPP5_Parser.h"

lrstar_parser generated_parser(/* user data    */   NULL,
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
                               /* term_actions */   false);

#include "lrstar_main.cpp"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

