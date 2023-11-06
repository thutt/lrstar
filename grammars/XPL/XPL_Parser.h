
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
      #undef  GRAMMAR
      #undef  ACTIONS
      #undef  TERM_ACTIONS
      #undef  NODE_ACTIONS
      #undef  INSENSITIVE
      #undef  LOOKAHEADS
      #undef  DEBUG_PARSER
      #undef  DEBUG_TRACE
      #undef  MAKE_AST
      #undef  EXPECTING
      #undef  REVERSABLE
      #undef  SEMANTICS
      #undef  ND_PARSING
      #undef  ND_THREADS

      #define GRAMMAR      "XPL"
      #define ACTIONS       XPL_Actions
      #define TERM_ACTIONS  XPL_TermActions
      #define LOOKAHEADS    1
      #define EXPECTING
#include "XPL_ParserTables.h"
#include "lrstar_lexer.h"
#include "lrstar_parser.h"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

