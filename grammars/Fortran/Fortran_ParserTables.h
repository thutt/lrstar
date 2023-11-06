
////////////////////////////////////////////////////////////////////////////////
//
//    Fortran_ParserTables.h (generated by LRSTAR 24.0.017)

      #pragma once



      #define TOP_DOWN  0
      #define PASS_OVER 1
      #define BOTTOM_UP 2

      class lrstar_parser_tables
      {
         friend class lrstar_parser;
         public:
         static const char *term_symb[   268]; // Terminal symbols of the grammar.
         static const char *head_symb[   572]; // Nonterminal symbols of the grammar.
         static const char *tact_name[     2]; // Terminal action names found in the grammar.
         static const ushort head_numb[  1133]; // Head symbol number for a production.
         static const ushort f_tail   [  1134]; // First tail in a production.
         static const short  tail     [  1911]; // Tail symbol number.
         static const char   arga     [   268]; // Arguments for terminal actions.

         private:
         static const uchar  Bm[   762]       ; // Boolean matrix.
         static const ushort Br[   724]       ; // Boolean matrix row.
         static const uchar  Bc[   268]       ; // Boolean matrix column.
         static const uchar Bf[   268]       ; // Boolean matrix filter/mask.
         static const short  Tm[  1750]       ; // Terminal transition matrix.
         static const ushort Tr[   724]       ; // Terminal transition matrix row.
         static const uchar  Tc[   268]       ; // Terminal transition matrix column.
         static const short  Nm[  3405]       ; // Nonterminal transition matrix.
         static const ushort Nr[   724]       ; // Nonterminal transition matrix row.
         static const ushort Nc[  1133]       ; // Nonterminal transition matrix column.
         static const ushort Rm[   298]       ; // Reduction matrix.
         static const short  Rr[   724]       ; // Reduction matrix row.
         static const uchar  Rc[   268]       ; // Reduction matrix column.
         static const char   PL[  1133]       ; // Production length minus one.

         static const char   tact_numb[   268]; // Terminal action numbers.

         static void   (*init_func[    2]) ()       ; // Init action function pointers.
         static int    (*tact_func[    2]) (int& t) ; // Terminal action function pointers.
      };

//
////////////////////////////////////////////////////////////////////////////////

