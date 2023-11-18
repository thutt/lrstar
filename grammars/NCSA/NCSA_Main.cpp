
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "NCSA_LexerTables_typedef.h"
#include "NCSA_Parser.h"

lrstar_parser generated_parser(/* user data    */   NULL,
                               /* actions      */   true,
                               /* debug_parser */   false,
                               /* debug_trace  */   false,
                               /* expecting    */   true,
                               /* insensitive  */   false,
                               /* lookaheads   */   1,
                               /* make_ast     */   true,
                               /* nd_parsing   */   false,
                               /* nd_threads   */   0,
                               /* node_actions */   true,
                               /* reversable   */   false,
                               /* semantics    */   true,
                               /* term_actions */   true);

#include "lrstar_main.cpp"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

