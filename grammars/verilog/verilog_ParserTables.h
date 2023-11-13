
////////////////////////////////////////////////////////////////////////////////
//
//    verilog_ParserTables.h (generated by LRSTAR 24.0.017)

      #pragma once

      #include "lrstar_library_defs.h"


      class lrstar_parser_tables
      {
         friend class lrstar_parser;
         public:
         static const char *term_symb[   177]; // Terminal symbols of the grammar.
         static const char *head_symb[   230]; // Nonterminal symbols of the grammar.
         static const char *tact_name[     2]; // Terminal action names found in the grammar.
         static const uint8  head_numb[   521]; // Head symbol number for a production.
         static const uint16 f_tail   [   522]; // First tail in a production.
         static const int16  tail     [  1093]; // Tail symbol number.
         static const int8   arga     [   177]; // Arguments for terminal actions.

         private:
         static const uint8  Bm[   505]       ; // Boolean matrix.
         static const uint16 Br[   569]       ; // Boolean matrix row.
         static const uint8  Bc[   177]       ; // Boolean matrix column.
         static const uint8 Bf[   177]       ; // Boolean matrix filter/mask.
         static const int16  Tm[  1592]       ; // Terminal transition matrix.
         static const uint16 Tr[   569]       ; // Terminal transition matrix row.
         static const uint8  Tc[   177]       ; // Terminal transition matrix column.
         static const int16  Nm[  3577]       ; // Nonterminal transition matrix.
         static const uint16 Nr[   569]       ; // Nonterminal transition matrix row.
         static const uint8  Nc[   521]       ; // Nonterminal transition matrix column.
         static const uint16 Rm[   153]       ; // Reduction matrix.
         static const int16  Rr[   569]       ; // Reduction matrix row.
         static const uint8  Rc[   177]       ; // Reduction matrix column.
         static const int8   PL[   521]       ; // Production length minus one.

         static const int8   tact_numb[   177]; // Terminal action numbers.

         static int    (*tact_func[    2])(void *parser, int &t); // Terminal action function pointers.
      };

//
////////////////////////////////////////////////////////////////////////////////

