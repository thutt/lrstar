
////////////////////////////////////////////////////////////////////////////////
//
//    Java9_ParserTables.h (generated by LRSTAR 24.0.017)

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

      #define GRAMMAR      "Java9"
      #define PARSER        Java9_Parser
      #define PARSER_TABLES Java9_ParserTables
      #define LEXER         Java9_Lexer
      #define ACTIONS       Java9_Actions
      #define TERM_ACTIONS  Java9_TermActions
      #define NODE_ACTIONS  Java9_NodeActions
      #define LOOKAHEADS    1
      #define MAKE_AST
      #define EXPECTING

      enum nodecon
      {
         N_start = 0
      };

      #define uint   unsigned int
      #define uchar  unsigned char
      #define ushort unsigned short

      #define TOP_DOWN  0
      #define PASS_OVER 1
      #define BOTTOM_UP 2

      class Java9_ParserTables
      {
         friend class Java9_Parser;
         public:
         static char*  term_symb[   110]; // Terminal symbols of the grammar.
         static char*  head_symb[   366]; // Nonterminal symbols of the grammar.
         static char*  tact_name[     2]; // Terminal action names found in the grammar.
         static char*  node_name[     1]; // Node names found in the grammar.
         static ushort head_numb[   733]; // Head symbol number for a production.
         static ushort f_tail   [   734]; // First tail in a production.
         static short  tail     [  1440]; // Tail symbol number.
         static char   arga     [   110]; // Arguments for terminal actions.
         static char   argx     [   733]; // First arguments for productions.

         private:
         static uchar  Bm[   663]       ; // Boolean matrix.
         static ushort Br[   745]       ; // Boolean matrix row.
         static uchar  Bc[   110]       ; // Boolean matrix column.
         static uchar  Bf[   110]       ; // Boolean matrix filter/mask.
         static short  Tm[  1526]       ; // Terminal transition matrix.
         static ushort Tr[   745]       ; // Terminal transition matrix row.
         static uchar  Tc[   110]       ; // Terminal transition matrix column.
         static short  Nm[ 20133]       ; // Nonterminal transition matrix.
         static ushort Nr[   745]       ; // Nonterminal transition matrix row.
         static uchar  Nc[   733]       ; // Nonterminal transition matrix column.
         static ushort Rm[  4063]       ; // Reduction matrix.
         static short  Rr[   745]       ; // Reduction matrix row.
         static uchar  Rc[   110]       ; // Reduction matrix column.
         static char   PL[   733]       ; // Production length minus one.

         static char   tact_numb[   110]; // Terminal action numbers.
         static char   node_numb[   733]; // Node numbers for the productions.
         static char   nact_numb[   733]; // Node action numbers for the productions.

         static void   (*init_func[    2]) ()       ; // Init action function pointers.
         static int    (*tact_func[    2]) (int& t) ; // Terminal action function pointers.
         static int    (*nact_func[    1]) (void* v); // Node action function pointers.
      };

//
////////////////////////////////////////////////////////////////////////////////

