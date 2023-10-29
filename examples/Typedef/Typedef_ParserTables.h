
////////////////////////////////////////////////////////////////////////////////
//
//    Typedef_ParserTables.h (generated by LRSTAR 24.0.017)

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

      #define GRAMMAR      "Typedef"
      #define PARSER        Typedef_Parser
      #define PARSER_TABLES Typedef_ParserTables
      #define LEXER         Typedef_Lexer
      #define ACTIONS       Typedef_Actions
      #define TERM_ACTIONS  Typedef_TermActions
      #define NODE_ACTIONS  Typedef_NodeActions
      #define LOOKAHEADS    1
      #define MAKE_AST
      #define EXPECTING
      #define SEMANTICS

      enum nodecon
      {
         N_hello_ = 0
      };


      #define TOP_DOWN  0
      #define PASS_OVER 1
      #define BOTTOM_UP 2

      class Typedef_ParserTables
      {
         friend class Typedef_Parser;
         public:
         static const char *term_symb[    12]; // Terminal symbols of the grammar.
         static const char *head_symb[    14]; // Nonterminal symbols of the grammar.
         static const char *tact_name[     2]; // Terminal action names found in the grammar.
         static const char *node_name[     1]; // Node names found in the grammar.
         static uchar  head_numb[    24]; // Head symbol number for a production.
         static uchar  f_tail   [    25]; // First tail in a production.
         static char   tail     [    37]; // Tail symbol number.
         static char   arga     [    12]; // Arguments for terminal actions.
         static char   argx     [    24]; // First arguments for productions.
         static char   argy     [    24]; // Second arguments for productions.

         private:
         static uchar  Bm[     6]       ; // Boolean matrix.
         static uchar  Br[    14]       ; // Boolean matrix row.
         static uchar  Bc[    12]       ; // Boolean matrix column.
         static uchar  Bf[    12]       ; // Boolean matrix filter/mask.
         static char   Tm[    18]       ; // Terminal transition matrix.
         static uchar  Tr[    14]       ; // Terminal transition matrix row.
         static uchar  Tc[    12]       ; // Terminal transition matrix column.
         static char   Nm[    32]       ; // Nonterminal transition matrix.
         static uchar  Nr[    14]       ; // Nonterminal transition matrix row.
         static uchar  Nc[    24]       ; // Nonterminal transition matrix column.
         static uchar  Rm[     1]       ; // Reduction matrix.
         static uchar  Rr[    14]       ; // Reduction matrix row.
         static uchar  Rc[    12]       ; // Reduction matrix column.
         static char   PL[    24]       ; // Production length minus one.

         static char   tact_numb[    12]; // Terminal action numbers.
         static char   node_numb[    24]; // Node numbers for the productions.
         static char   nact_numb[    24]; // Node action numbers for the productions.

         static void   (*init_func[    2]) ()       ; // Init action function pointers.
         static int    (*tact_func[    2]) (int& t) ; // Terminal action function pointers.
         static int    (*nact_func[    1]) (void* v); // Node action function pointers.
      };

//
////////////////////////////////////////////////////////////////////////////////
