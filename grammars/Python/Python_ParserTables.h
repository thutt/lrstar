
////////////////////////////////////////////////////////////////////////////////
//
//    Python_ParserTables.h (generated by LRSTAR 24.0.017)

      #pragma once



      #define TOP_DOWN  0
      #define PASS_OVER 1
      #define BOTTOM_UP 2

      class lrstar_parser_tables
      {
         friend class lrstar_parser;
         public:
         static const char *term_symb[    94]; // Terminal symbols of the grammar.
         static const char *head_symb[   220]; // Nonterminal symbols of the grammar.
         static const uchar  head_numb[   396]; // Head symbol number for a production.
         static const ushort f_tail   [   397]; // First tail in a production.
         static const short  tail     [   600]; // Tail symbol number.

         private:
         static const uchar  Bm[   249]       ; // Boolean matrix.
         static const uchar  Br[   257]       ; // Boolean matrix row.
         static const uchar  Bc[    94]       ; // Boolean matrix column.
         static const uchar Bf[    94]       ; // Boolean matrix filter/mask.
         static const short  Tm[   351]       ; // Terminal transition matrix.
         static const ushort Tr[   257]       ; // Terminal transition matrix row.
         static const uchar  Tc[    94]       ; // Terminal transition matrix column.
         static const short  Nm[  3046]       ; // Nonterminal transition matrix.
         static const ushort Nr[   257]       ; // Nonterminal transition matrix row.
         static const uchar  Nc[   396]       ; // Nonterminal transition matrix column.
         static const ushort Rm[   332]       ; // Reduction matrix.
         static const short  Rr[   257]       ; // Reduction matrix row.
         static const uchar  Rc[    94]       ; // Reduction matrix column.
         static const char   PL[   396]       ; // Production length minus one.
      };

//
////////////////////////////////////////////////////////////////////////////////

