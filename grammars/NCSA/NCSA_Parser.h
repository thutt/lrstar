
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

      #define GRAMMAR      "NCSA"
      #define ACTIONS       NCSA_Actions
      #define TERM_ACTIONS  NCSA_TermActions
      #define NODE_ACTIONS  NCSA_NodeActions
      #define LOOKAHEADS    1
      #define MAKE_AST
      #define EXPECTING
      #define SEMANTICS
#include "NCSA_ParserTables.h"
#include "NCSA_ParserTables_typedef.h"
#include "lrstar_parser.h"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

