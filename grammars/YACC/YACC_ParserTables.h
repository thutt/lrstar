
////////////////////////////////////////////////////////////////////////////////
//
//    YACC_ParserTables.h (generated by LRSTAR 24.0.017)

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

      #define GRAMMAR      "YACC"
      #define PARSER        YACC_Parser
      #define PARSER_TABLES YACC_ParserTables
      #define LEXER         YACC_Lexer
      #define LOOKAHEADS    1
      #define EXPECTING


      #define TOP_DOWN  0
      #define PASS_OVER 1
      #define BOTTOM_UP 2

      class YACC_ParserTables
      {
         friend class YACC_Parser;
         public:
         static const char *term_symb[    27]; // Terminal symbols of the grammar.
         static const char *head_symb[    17]; // Nonterminal symbols of the grammar.
         static const uchar  head_numb[    59]; // Head symbol number for a production.
         static const uchar  f_tail   [    60]; // First tail in a production.
         static const char   tail     [   110]; // Tail symbol number.

         private:
         static const uchar  Bm[    44]       ; // Boolean matrix.
         static const uchar  Br[    43]       ; // Boolean matrix row.
         static const uchar  Bc[    27]       ; // Boolean matrix column.
         static const uchar Bf[    27]       ; // Boolean matrix filter/mask.
         static const char   Tm[    86]       ; // Terminal transition matrix.
         static const uchar  Tr[    43]       ; // Terminal transition matrix row.
         static const uchar  Tc[    27]       ; // Terminal transition matrix column.
         static const char   Nm[    48]       ; // Nonterminal transition matrix.
         static const uchar  Nr[    43]       ; // Nonterminal transition matrix row.
         static const uchar  Nc[    59]       ; // Nonterminal transition matrix column.
         static const uchar  Rm[     1]       ; // Reduction matrix.
         static const uchar  Rr[    43]       ; // Reduction matrix row.
         static const uchar  Rc[    27]       ; // Reduction matrix column.
         static const char   PL[    59]       ; // Production length minus one.
      };

//
////////////////////////////////////////////////////////////////////////////////

