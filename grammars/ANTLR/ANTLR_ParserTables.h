
////////////////////////////////////////////////////////////////////////////////
//
//    ANTLR_ParserTables.h (generated by LRSTAR 24.0.017)

      #pragma once

      #include "lrstar_library_defs.h"

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


class lrstar_parser;

      class lrstar_parser_tables
      {
         friend class lrstar_parser;
         public:
         static const char *term_symb[    43]; // Terminal symbols of the grammar.
         static const char *head_symb[   126]; // Nonterminal symbols of the grammar.
         static const char *tact_name[     2]; // Terminal action names found in the grammar.
         static const uint8  head_numb[   213]; // Head symbol number for a production.
         static const uint16 f_tail   [   214]; // First tail in a production.
         static const int8   tail     [   327]; // Tail symbol number.
         static const int8   arga     [    43]; // Arguments for terminal actions.

         private:
         static const uint8  Bm[   169]       ; // Boolean matrix.
         static const uint8  Br[   148]       ; // Boolean matrix row.
         static const uint8  Bc[    43]       ; // Boolean matrix column.
         static const uint8 Bf[    43]       ; // Boolean matrix filter/mask.
         static const int16  Tm[   201]       ; // Terminal transition matrix.
         static const uint8  Tr[   148]       ; // Terminal transition matrix row.
         static const uint8  Tc[    43]       ; // Terminal transition matrix column.
         static const int16  Nm[   519]       ; // Nonterminal transition matrix.
         static const uint16 Nr[   148]       ; // Nonterminal transition matrix row.
         static const uint8  Nc[   213]       ; // Nonterminal transition matrix column.
         static const uint8  Rm[   121]       ; // Reduction matrix.
         static const int16  Rr[   148]       ; // Reduction matrix row.
         static const uint8  Rc[    43]       ; // Reduction matrix column.
         static const int8   PL[   213]       ; // Production length minus one.

         static const int8   tact_numb[    43]; // Terminal action numbers.

         static int    (*tact_func[    2])(lrstar_parser *parser, int &t); // Terminal action function pointers.
      };

//
////////////////////////////////////////////////////////////////////////////////

