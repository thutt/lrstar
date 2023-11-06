
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
      #undef  GRAMMAR
      #undef  PARSER
      #undef  PARSER_TABLES
      #undef  LEXER
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

      #define GRAMMAR      "SQL"
      #define PARSER        SQL_Parser
      #define PARSER_TABLES SQL_ParserTables
      #define LEXER         SQL_Lexer
      #define ACTIONS       SQL_Actions
      #define TERM_ACTIONS  SQL_TermActions
      #define LOOKAHEADS    1
      #define EXPECTING
#include "SQL_ParserTables.h"
#include "lrstar_lexer.h"
#include "lrstar_parser.h"

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

