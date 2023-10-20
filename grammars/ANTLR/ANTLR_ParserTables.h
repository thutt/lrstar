
////////////////////////////////////////////////////////////////////////////////
//
//    ANTLR_ParserTables.h (generated by LRSTAR 24.0.017)

      #pragma once

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

      #define GRAMMAR      "ANTLR"
      #define PARSER        ANTLR_Parser
      #define PARSER_TABLES ANTLR_ParserTables
      #define LEXER         ANTLR_Lexer
      #define ACTIONS       ANTLR_Actions
      #define TERM_ACTIONS  ANTLR_TermActions
      #define LOOKAHEADS    1
      #define EXPECTING

      enum termcon
      {
         ERR = 0,
         EOF = 1,
         INT = 2,
         STRING_LITERAL = 3,
         LEXER_CHAR_SET = 4,
         RULE_REF = 5,
         TOKEN_REF = 6,
         GRAMMAR_ = 7,
         PARSER_ = 8,
         LEXER_ = 9,
         OPTIONS = 10,
         TOKENS = 11,
         CHANNELS = 12,
         IMPORT = 13,
         FRAGMENT = 14,
         RETURNS = 15,
         LOCALS = 16,
         THROWS = 17,
         CATCH = 18,
         FINALLY = 19,
         MODE = 20,
         SEMI = 21,
         COLON = 22,
         COLONCOLON = 23,
         COMMA = 24,
         LPAREN = 25,
         RPAREN = 26,
         RARROW = 27,
         LT = 28,
         GT = 29,
         ASSIGN = 30,
         QUESTION = 31,
         STAR = 32,
         PLUS_ASSIGN = 33,
         PLUS = 34,
         OR = 35,
         RANGE = 36,
         DOT = 37,
         AT = 38,
         POUND = 39,
         NOT = 40,
         LBRACE = 41,
         RBRACE = 42
      };

      #define uint   unsigned int
      #define uchar  unsigned char
      #define ushort unsigned short

      #define TOP_DOWN  0
      #define PASS_OVER 1
      #define BOTTOM_UP 2

      class ANTLR_ParserTables
      {
         friend class ANTLR_Parser;
         public:
         static char*  term_symb[    43]; // Terminal symbols of the grammar.
         static char*  head_symb[   126]; // Nonterminal symbols of the grammar.
         static char*  tact_name[     2]; // Terminal action names found in the grammar.
         static uchar  head_numb[   213]; // Head symbol number for a production.
         static ushort f_tail   [   214]; // First tail in a production.
         static char   tail     [   327]; // Tail symbol number.
         static char   arga     [    43]; // Arguments for terminal actions.

         private:
         static uchar  Bm[   169]       ; // Boolean matrix.
         static uchar  Br[   148]       ; // Boolean matrix row.
         static uchar  Bc[    43]       ; // Boolean matrix column.
         static uchar  Bf[    43]       ; // Boolean matrix filter/mask.
         static short  Tm[   201]       ; // Terminal transition matrix.
         static uchar  Tr[   148]       ; // Terminal transition matrix row.
         static uchar  Tc[    43]       ; // Terminal transition matrix column.
         static short  Nm[   519]       ; // Nonterminal transition matrix.
         static ushort Nr[   148]       ; // Nonterminal transition matrix row.
         static uchar  Nc[   213]       ; // Nonterminal transition matrix column.
         static uchar  Rm[   121]       ; // Reduction matrix.
         static short  Rr[   148]       ; // Reduction matrix row.
         static uchar  Rc[    43]       ; // Reduction matrix column.
         static char   PL[   213]       ; // Production length minus one.

         static char   tact_numb[    43]; // Terminal action numbers.

         static void   (*init_func[    2]) ()       ; // Init action function pointers.
         static int    (*tact_func[    2]) (int& t) ; // Terminal action function pointers.
      };

//
////////////////////////////////////////////////////////////////////////////////

