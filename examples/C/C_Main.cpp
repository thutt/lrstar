
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "C_LexerTables_typedef.h"
#include "C_Parser.h"

lrstar_parser generated_parser(/* user data   */   NULL,
                               /* actions      */   true,
                               /* insensitive  */   false,
                               /* make_ast     */   true,
                               /* node_actions */   true);

#include "lrstar_main.cpp"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

