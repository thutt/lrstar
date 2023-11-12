
////////////////////////////////////////////////////////////////////////////////
//
//    Fortran_ParserTables.h (generated by LRSTAR 24.0.017)

      #pragma once

      #include "lrstar_library_defs.h"


      class lrstar_parser_tables
      {
         friend class lrstar_parser;
         public:
         static const char *term_symb[   268]; // Terminal symbols of the grammar.
         static const char *head_symb[   572]; // Nonterminal symbols of the grammar.
         static const char *tact_name[     2]; // Terminal action names found in the grammar.
         static const uint16 head_numb[  1133]; // Head symbol number for a production.
         static const uint16 f_tail   [  1134]; // First tail in a production.
         static const int16  tail     [  1911]; // Tail symbol number.
         static const int8   arga     [   268]; // Arguments for terminal actions.

         private:
         static const uint8  Bm[   762]       ; // Boolean matrix.
         static const uint16 Br[   724]       ; // Boolean matrix row.
         static const uint8  Bc[   268]       ; // Boolean matrix column.
         static const uint8 Bf[   268]       ; // Boolean matrix filter/mask.
         static const int16  Tm[  1750]       ; // Terminal transition matrix.
         static const uint16 Tr[   724]       ; // Terminal transition matrix row.
         static const uint8  Tc[   268]       ; // Terminal transition matrix column.
         static const int16  Nm[  3405]       ; // Nonterminal transition matrix.
         static const uint16 Nr[   724]       ; // Nonterminal transition matrix row.
         static const uint16 Nc[  1133]       ; // Nonterminal transition matrix column.
         static const uint16 Rm[   298]       ; // Reduction matrix.
         static const int16  Rr[   724]       ; // Reduction matrix row.
         static const uint8  Rc[   268]       ; // Reduction matrix column.
         static const int8   PL[  1133]       ; // Production length minus one.

         static const int8   tact_numb[   268]; // Terminal action numbers.

         static void   (*init_func[    2])(void *parser); // Init action function pointers.
         static int    (*tact_func[    2])(void *parser, int &t); // Terminal action function pointers.
      };

//
////////////////////////////////////////////////////////////////////////////////

