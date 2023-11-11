
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

      #define GRAMMAR      "Ada"
      #define ACTIONS       Ada_Actions
      #define TERM_ACTIONS  Ada_TermActions
      #define LOOKAHEADS    1
      #define EXPECTING
#include "Ada_ParserTables.h"
#include "Ada_ParserTables_typedef.h"
#include "lrstar_parser.h"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

