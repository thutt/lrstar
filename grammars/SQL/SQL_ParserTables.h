
////////////////////////////////////////////////////////////////////////////////
//
//    SQL_ParserTables.h (generated by LRSTAR 24.0.017)

      #pragma once

      #include "lrstar_library_defs.h"


      class lrstar_parser_tables
      {
         friend class lrstar_parser;
         public:
         static const char *term_symb[   138]; // Terminal symbols of the grammar.
         static const char *head_symb[   154]; // Nonterminal symbols of the grammar.
         static const char *tact_name[     2]; // Terminal action names found in the grammar.
         static const uint8  head_numb[   399]; // Head symbol number for a production.
         static const uint16 f_tail   [   400]; // First tail in a production.
         static const int16  tail     [  1063]; // Tail symbol number.
         static const int8   arga     [   138]; // Arguments for terminal actions.

         private:
         static const uint8  Bm[   736]       ; // Boolean matrix.
         static const uint16 Br[   532]       ; // Boolean matrix row.
         static const uint8  Bc[   138]       ; // Boolean matrix column.
         static const uint8 Bf[   138]       ; // Boolean matrix filter/mask.
         static const int16  Tm[  1073]       ; // Terminal transition matrix.
         static const uint16 Tr[   532]       ; // Terminal transition matrix row.
         static const uint8  Tc[   138]       ; // Terminal transition matrix column.
         static const int16  Nm[   981]       ; // Nonterminal transition matrix.
         static const uint16 Nr[   532]       ; // Nonterminal transition matrix row.
         static const uint8  Nc[   399]       ; // Nonterminal transition matrix column.
         static const uint16 Rm[    28]       ; // Reduction matrix.
         static const int16  Rr[   532]       ; // Reduction matrix row.
         static const uint8  Rc[   138]       ; // Reduction matrix column.
         static const int8   PL[   399]       ; // Production length minus one.

         static const int8   tact_numb[   138]; // Terminal action numbers.

         static int    (*tact_func[    2])(void *parser, int &t); // Terminal action function pointers.
      };

//
////////////////////////////////////////////////////////////////////////////////

