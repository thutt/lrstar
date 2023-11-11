
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "lrstar_lexer.h"
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

      #define GRAMMAR      "C"
      #define ACTIONS       C_Actions
      #define TERM_ACTIONS  C_TermActions
      #define NODE_ACTIONS  C_NodeActions
      #define LOOKAHEADS    1
      #define MAKE_AST
      #define EXPECTING
      #define SEMANTICS
#include "C_ParserTables.h"
#include "C_ParserTables_typedef.h"
#include "lrstar_parser.h"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

