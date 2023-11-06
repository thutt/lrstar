
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

      #define GRAMMAR      "Java9"
      #define ACTIONS       Java9_Actions
      #define TERM_ACTIONS  Java9_TermActions
      #define NODE_ACTIONS  Java9_NodeActions
      #define LOOKAHEADS    1
      #define MAKE_AST
      #define EXPECTING
#include "Java9_ParserTables.h"
#include "lrstar_lexer.h"
#include "lrstar_parser.h"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

