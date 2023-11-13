
////////////////////////////////////////////////////////////////////////////////
//
//    delphi_ParserTables.h (generated by LRSTAR 24.0.017)

      #pragma once

      #include "lrstar_library_defs.h"


class lrstar_parser;

      class lrstar_parser_tables
      {
         friend class lrstar_parser;
         public:
         static const char *term_symb[   101]; // Terminal symbols of the grammar.
         static const char *head_symb[   166]; // Nonterminal symbols of the grammar.
         static const uint8  head_numb[   355]; // Head symbol number for a production.
         static const uint16 f_tail   [   356]; // First tail in a production.
         static const int16  tail     [   678]; // Tail symbol number.

         private:
         static const uint8  Bm[   394]       ; // Boolean matrix.
         static const uint16 Br[   343]       ; // Boolean matrix row.
         static const uint8  Bc[   101]       ; // Boolean matrix column.
         static const uint8 Bf[   101]       ; // Boolean matrix filter/mask.
         static const int16  Tm[   580]       ; // Terminal transition matrix.
         static const uint16 Tr[   343]       ; // Terminal transition matrix row.
         static const uint8  Tc[   101]       ; // Terminal transition matrix column.
         static const int16  Nm[  2246]       ; // Nonterminal transition matrix.
         static const uint16 Nr[   343]       ; // Nonterminal transition matrix row.
         static const uint8  Nc[   355]       ; // Nonterminal transition matrix column.
         static const uint16 Rm[    91]       ; // Reduction matrix.
         static const int16  Rr[   343]       ; // Reduction matrix row.
         static const uint8  Rc[   101]       ; // Reduction matrix column.
         static const int8   PL[   355]       ; // Production length minus one.
      };

//
////////////////////////////////////////////////////////////////////////////////

