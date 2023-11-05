
////////////////////////////////////////////////////////////////////////////////
//
//    verilog_ParserTables.h (generated by LRSTAR 24.0.017)

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

      #define GRAMMAR      "verilog"
      #define PARSER        verilog_Parser
      #define PARSER_TABLES verilog_ParserTables
      #define LEXER         verilog_Lexer
      #define ACTIONS       verilog_Actions
      #define TERM_ACTIONS  verilog_TermActions
      #define LOOKAHEADS    1
      #define EXPECTING


      #define TOP_DOWN  0
      #define PASS_OVER 1
      #define BOTTOM_UP 2

      class verilog_ParserTables
      {
         friend class verilog_Parser;
         public:
         static const char *term_symb[   177]; // Terminal symbols of the grammar.
         static const char *head_symb[   230]; // Nonterminal symbols of the grammar.
         static const char *tact_name[     2]; // Terminal action names found in the grammar.
         static const uchar  head_numb[   521]; // Head symbol number for a production.
         static const ushort f_tail   [   522]; // First tail in a production.
         static const short  tail     [  1093]; // Tail symbol number.
         static const char   arga     [   177]; // Arguments for terminal actions.

         private:
         static const uchar  Bm[   505]       ; // Boolean matrix.
         static const ushort Br[   569]       ; // Boolean matrix row.
         static const uchar  Bc[   177]       ; // Boolean matrix column.
         static const uchar Bf[   177]       ; // Boolean matrix filter/mask.
         static const short  Tm[  1592]       ; // Terminal transition matrix.
         static const ushort Tr[   569]       ; // Terminal transition matrix row.
         static const uchar  Tc[   177]       ; // Terminal transition matrix column.
         static const short  Nm[  3577]       ; // Nonterminal transition matrix.
         static const ushort Nr[   569]       ; // Nonterminal transition matrix row.
         static const uchar  Nc[   521]       ; // Nonterminal transition matrix column.
         static const ushort Rm[   153]       ; // Reduction matrix.
         static const short  Rr[   569]       ; // Reduction matrix row.
         static const uchar  Rc[   177]       ; // Reduction matrix column.
         static const char   PL[   521]       ; // Production length minus one.

         static const char   tact_numb[   177]; // Terminal action numbers.

         static void   (*init_func[    2]) ()       ; // Init action function pointers.
         static int    (*tact_func[    2]) (int& t) ; // Terminal action function pointers.
      };

//
////////////////////////////////////////////////////////////////////////////////

