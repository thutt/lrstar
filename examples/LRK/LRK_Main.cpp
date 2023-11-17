
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "LRK_LexerTables_typedef.h"
#include "LRK_Parser.h"

lrstar_parser generated_parser(/* user data    */   NULL,
                               /* actions      */   true,
                               /* debug_parser */   false,
                               /* debug_trace  */   false,
                               /* insensitive  */   false,
                               /* make_ast     */   true,
                               /* node_actions */   true,
                               /* reversable   */   false,
                               /* semantics    */   true,
                               /* term_actions */   true);

#include "lrstar_main.cpp"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

