
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "Calc_LexerTables_typedef.h"
#include "Calc_Parser.h"

lrstar_parser generated_parser(/* user data    */   NULL,
                               /* actions      */   true,
                               /* debug_parser */   false,
                               /* insensitive  */   false,
                               /* make_ast     */   true,
                               /* node_actions */   true,
                               /* term_actions */   true);

#include "lrstar_main.cpp"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

