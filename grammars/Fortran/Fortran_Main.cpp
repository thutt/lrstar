
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "Fortran_LexerTables_typedef.h"
#include "Fortran_Parser.h"

lrstar_parser generated_parser(/* user data   */   NULL,
                               /* actions      */   true,
                               /* insensitive  */   false,
                               /* make_ast     */   false,
                               /* node_actions */   false);

#include "lrstar_main.cpp"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

