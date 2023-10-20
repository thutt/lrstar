
////////////////////////////////////////////////////////////////////////////////
//
//    Kotlin_ParserTables.h (generated by LRSTAR 24.0.017)

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

      #define GRAMMAR      "Kotlin"
      #define PARSER        Kotlin_Parser
      #define PARSER_TABLES Kotlin_ParserTables
      #define LEXER         Kotlin_Lexer
      #define LOOKAHEADS    1
      #define EXPECTING

      enum termcon
      {
         ABSTRACT = 2,
         ACTUAL = 3,
         ADD = 4,
         ADD_ASSIGNMENT = 5,
         ANNOTATION = 6,
         ARROW = 7,
         AS = 8,
         ASSIGNMENT = 9,
         AS_SAFE = 10,
         AT_NO_WS = 11,
         BREAK = 12,
         BREAK_AT = 13,
         BY = 14,
         CATCH = 15,
         CLASS = 16,
         COLON = 17,
         COLONCOLON = 18,
         COMMA = 19,
         COMPANION = 20,
         CONJ = 21,
         CONST = 22,
         CONSTRUCTOR = 23,
         CONTINUE = 24,
         CONTINUE_AT = 25,
         CROSSINLINE = 26,
         DATA = 27,
         DECR = 28,
         DELEGATE = 29,
         DISJ = 30,
         DIV = 31,
         DIV_ASSIGNMENT = 32,
         DO = 33,
         DOT = 34,
         DOUBLE_ARROW = 35,
         DOUBLE_SEMICOLON = 36,
         DYNAMIC = 37,
         ELSE = 38,
         ENUM = 39,
         EQEQ = 40,
         EQEQEQ = 41,
         EXCL_EQ = 42,
         EXCL_EQEQ = 43,
         EXCL_NO_WS = 44,
         EXPECT = 45,
         EXTERNAL = 46,
         FIELD = 47,
         FILE_ = 48,
         FINAL = 49,
         FINALLY = 50,
         FOR = 51,
         FUN = 52,
         GE = 53,
         GET = 54,
         HASH = 55,
         IF = 56,
         IMPORT = 57,
         IN = 58,
         INCR = 59,
         INFIX = 60,
         INIT = 61,
         INLINE = 62,
         INNER = 63,
         INTERFACE = 64,
         INTERNAL = 65,
         IS = 66,
         LANGLE = 67,
         LATEINIT = 68,
         LCURL = 69,
         LE = 70,
         LPAREN = 71,
         LSQUARE = 72,
         MOD = 73,
         MOD_ASSIGNMENT = 74,
         MULT = 75,
         MULT_ASSIGNMENT = 76,
         NOINLINE = 77,
         OBJECT = 78,
         OPEN = 79,
         OPERATOR = 80,
         OUT = 81,
         OVERRIDE = 82,
         PACKAGE = 83,
         PARAM = 84,
         PRIVATE = 85,
         PROPERTY = 86,
         PROTECTED = 87,
         PUBLIC = 88,
         QUEST_NO_WS = 89,
         RANGE = 90,
         RANGLE = 91,
         RCURL = 92,
         RECEIVER = 93,
         REIFIED = 94,
         RESERVED = 95,
         RETURN = 96,
         RETURN_AT = 97,
         RPAREN = 98,
         RSQUARE = 99,
         SEALED = 100,
         SEMICOLON = 101,
         SET = 102,
         SETPARAM = 103,
         SINGLE_QUOTE = 104,
         SUB = 105,
         SUB_ASSIGNMENT = 106,
         SUPER = 107,
         SUPER_AT = 108,
         SUSPEND = 109,
         TAILREC = 110,
         THIS = 111,
         THIS_AT = 112,
         THROW = 113,
         TRY = 114,
         TYPEOF = 115,
         TYPE_ALIAS = 116,
         VAL = 117,
         VALUE = 118,
         VAR = 119,
         VARARG = 120,
         WHEN = 121,
         WHERE = 122,
         WHILE = 123
      };

      typedef unsigned int   uint;
      typedef unsigned char  uchar;
      typedef unsigned short ushort;

      #define TOP_DOWN  0
      #define PASS_OVER 1
      #define BOTTOM_UP 2

      class Kotlin_ParserTables
      {
         friend class Kotlin_Parser;
         public:
         static char*  term_symb[   155]; // Terminal symbols of the grammar.
         static char*  head_symb[   407]; // Nonterminal symbols of the grammar.
         static ushort head_numb[   753]; // Head symbol number for a production.
         static ushort f_tail   [   754]; // First tail in a production.
         static short  tail     [  1283]; // Tail symbol number.

         private:
         static uchar  Bm[   790]       ; // Boolean matrix.
         static ushort Br[   670]       ; // Boolean matrix row.
         static uchar  Bc[   155]       ; // Boolean matrix column.
         static uchar  Bf[   155]       ; // Boolean matrix filter/mask.
         static short  Tm[  1244]       ; // Terminal transition matrix.
         static ushort Tr[   670]       ; // Terminal transition matrix row.
         static uchar  Tc[   155]       ; // Terminal transition matrix column.
         static short  Nm[  4648]       ; // Nonterminal transition matrix.
         static ushort Nr[   670]       ; // Nonterminal transition matrix row.
         static uchar  Nc[   753]       ; // Nonterminal transition matrix column.
         static ushort Rm[  5540]       ; // Reduction matrix.
         static short  Rr[   670]       ; // Reduction matrix row.
         static uchar  Rc[   155]       ; // Reduction matrix column.
         static char   PL[   753]       ; // Production length minus one.
      };

//
////////////////////////////////////////////////////////////////////////////////
