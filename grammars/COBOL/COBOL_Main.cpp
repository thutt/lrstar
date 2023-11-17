
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "COBOL_LexerTables_typedef.h"
#include "COBOL_Parser.h"

lrstar_parser generated_parser(/* user data    */   NULL,
                               /* actions      */   true,
                               /* debug_parser */   false,
                               /* insensitive  */   false,
                               /* make_ast     */   false,
                               /* node_actions */   false,
                               /* term_actions */   true);

#include "lrstar_main.cpp"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

