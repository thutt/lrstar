
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "delphi_LexerTables_typedef.h"
#include "delphi_Parser.h"

lrstar_parser generated_parser(/* user data    */   NULL,
                               /* actions      */   false,
                               /* debug_parser */   false,
                               /* debug_trace  */   false,
                               /* insensitive  */   false,
                               /* make_ast     */   false,
                               /* node_actions */   false,
                               /* reversable   */   false,
                               /* semantics    */   false,
                               /* term_actions */   false);

#include "lrstar_main.cpp"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

