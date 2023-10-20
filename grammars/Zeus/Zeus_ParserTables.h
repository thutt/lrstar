
////////////////////////////////////////////////////////////////////////////////
//
//    Zeus_ParserTables.h (generated by LRSTAR 24.0.017)

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

      #define GRAMMAR      "Zeus"
      #define PARSER        Zeus_Parser
      #define PARSER_TABLES Zeus_ParserTables
      #define LEXER         Zeus_Lexer
      #define ACTIONS       Zeus_Actions
      #define TERM_ACTIONS  Zeus_TermActions
      #define LOOKAHEADS    1
      #define EXPECTING

      #define uint   unsigned int
      #define uchar  unsigned char
      #define ushort unsigned short

      #define TOP_DOWN  0
      #define PASS_OVER 1
      #define BOTTOM_UP 2

      class Zeus_ParserTables
      {
         friend class Zeus_Parser;
         public:
         static char*  term_symb[    71]; // Terminal symbols of the grammar.
         static char*  head_symb[   114]; // Nonterminal symbols of the grammar.
         static char*  tact_name[     2]; // Terminal action names found in the grammar.
         static uchar  head_numb[   222]; // Head symbol number for a production.
         static ushort f_tail   [   223]; // First tail in a production.
         static char   tail     [   479]; // Tail symbol number.
         static char   arga     [    71]; // Arguments for terminal actions.

         private:
         static uchar  Bm[   340]       ; // Boolean matrix.
         static ushort Br[   229]       ; // Boolean matrix row.
         static uchar  Bc[    71]       ; // Boolean matrix column.
         static uchar  Bf[    71]       ; // Boolean matrix filter/mask.
         static short  Tm[   400]       ; // Terminal transition matrix.
         static ushort Tr[   229]       ; // Terminal transition matrix row.
         static uchar  Tc[    71]       ; // Terminal transition matrix column.
         static short  Nm[  1154]       ; // Nonterminal transition matrix.
         static ushort Nr[   229]       ; // Nonterminal transition matrix row.
         static uchar  Nc[   222]       ; // Nonterminal transition matrix column.
         static uchar  Rm[     1]       ; // Reduction matrix.
         static uchar  Rr[   229]       ; // Reduction matrix row.
         static uchar  Rc[    71]       ; // Reduction matrix column.
         static char   PL[   222]       ; // Production length minus one.

         static char   tact_numb[    71]; // Terminal action numbers.

         static void   (*init_func[    2]) ()       ; // Init action function pointers.
         static int    (*tact_func[    2]) (int& t) ; // Terminal action function pointers.
      };

//
////////////////////////////////////////////////////////////////////////////////

