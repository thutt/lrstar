
////////////////////////////////////////////////////////////////////////////////
//
//    delphi_ParserTables.h (generated by LRSTAR 24.0.017)

      #pragma once



      #define TOP_DOWN  0
      #define PASS_OVER 1
      #define BOTTOM_UP 2

      class lrstar_parser_tables
      {
         friend class lrstar_parser;
         public:
         static const char *term_symb[   101]; // Terminal symbols of the grammar.
         static const char *head_symb[   166]; // Nonterminal symbols of the grammar.
         static const uchar  head_numb[   355]; // Head symbol number for a production.
         static const ushort f_tail   [   356]; // First tail in a production.
         static const short  tail     [   678]; // Tail symbol number.

         private:
         static const uchar  Bm[   394]       ; // Boolean matrix.
         static const ushort Br[   343]       ; // Boolean matrix row.
         static const uchar  Bc[   101]       ; // Boolean matrix column.
         static const uchar Bf[   101]       ; // Boolean matrix filter/mask.
         static const short  Tm[   580]       ; // Terminal transition matrix.
         static const ushort Tr[   343]       ; // Terminal transition matrix row.
         static const uchar  Tc[   101]       ; // Terminal transition matrix column.
         static const short  Nm[  2246]       ; // Nonterminal transition matrix.
         static const ushort Nr[   343]       ; // Nonterminal transition matrix row.
         static const uchar  Nc[   355]       ; // Nonterminal transition matrix column.
         static const ushort Rm[    91]       ; // Reduction matrix.
         static const short  Rr[   343]       ; // Reduction matrix row.
         static const uchar  Rc[   101]       ; // Reduction matrix column.
         static const char   PL[   355]       ; // Production length minus one.
      };

//
////////////////////////////////////////////////////////////////////////////////

