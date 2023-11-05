
////////////////////////////////////////////////////////////////////////////////
//
//    NCSA_ParserTables.h (generated by LRSTAR 24.0.017)

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

      #define GRAMMAR      "NCSA"
      #define PARSER        NCSA_Parser
      #define PARSER_TABLES NCSA_ParserTables
      #define LEXER         NCSA_Lexer
      #define ACTIONS       NCSA_Actions
      #define TERM_ACTIONS  NCSA_TermActions
      #define NODE_ACTIONS  NCSA_NodeActions
      #define LOOKAHEADS    1
      #define MAKE_AST
      #define EXPECTING
      #define SEMANTICS

      enum nodecon
      {
         N_Report = 0,
         N_Day = 1,
         N_Client = 2,
         N_FullName = 3,
         N_Name = 4,
         N_Time = 5,
         N_File = 6,
         N_Code = 7,
         N_Size = 8,
         N_Source = 9,
         N_Query = 10
      };


      #define TOP_DOWN  0
      #define PASS_OVER 1
      #define BOTTOM_UP 2

      class NCSA_ParserTables
      {
         friend class NCSA_Parser;
         public:
         static const char *term_symb[    24]; // Terminal symbols of the grammar.
         static const char *head_symb[    25]; // Nonterminal symbols of the grammar.
         static const char *tact_name[     2]; // Terminal action names found in the grammar.
         static const char *node_name[    11]; // Node names found in the grammar.
         static const uchar  head_numb[    62]; // Head symbol number for a production.
         static const uchar  f_tail   [    63]; // First tail in a production.
         static const char   tail     [   114]; // Tail symbol number.
         static const char   arga     [    24]; // Arguments for terminal actions.
         static char   argx     [    62]; // First arguments for productions.
         static char   argy     [    62]; // Second arguments for productions.

         private:
         static const uchar  Bm[    57]       ; // Boolean matrix.
         static const uchar  Br[    38]       ; // Boolean matrix row.
         static const uchar  Bc[    24]       ; // Boolean matrix column.
         static const uchar Bf[    24]       ; // Boolean matrix filter/mask.
         static const char   Tm[    99]       ; // Terminal transition matrix.
         static const uchar  Tr[    38]       ; // Terminal transition matrix row.
         static const uchar  Tc[    24]       ; // Terminal transition matrix column.
         static const char   Nm[    72]       ; // Nonterminal transition matrix.
         static const uchar  Nr[    38]       ; // Nonterminal transition matrix row.
         static const uchar  Nc[    62]       ; // Nonterminal transition matrix column.
         static const uchar  Rm[     6]       ; // Reduction matrix.
         static const char   Rr[    38]       ; // Reduction matrix row.
         static const uchar  Rc[    24]       ; // Reduction matrix column.
         static const uchar  PL[    62]       ; // Production length minus one.

         static const char   tact_numb[    24]; // Terminal action numbers.
         static const char   node_numb[    62]; // Node numbers for the productions.
         static const char   nact_numb[    62]; // Node action numbers for the productions.

         static void   (*init_func[    2]) ()       ; // Init action function pointers.
         static int    (*tact_func[    2]) (int& t) ; // Terminal action function pointers.
         static int    (*nact_func[   11]) (void* v); // Node action function pointers.
      };

//
////////////////////////////////////////////////////////////////////////////////

