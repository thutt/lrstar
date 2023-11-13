
////////////////////////////////////////////////////////////////////////////////
//
//    CICS_ParserTables.h (generated by LRSTAR 24.0.017)

      #pragma once

      #include "lrstar_library_defs.h"


      class lrstar_parser_tables
      {
         friend class lrstar_parser;
         public:
         static const char *term_symb[   216]; // Terminal symbols of the grammar.
         static const char *head_symb[   369]; // Nonterminal symbols of the grammar.
         static const char *tact_name[     2]; // Terminal action names found in the grammar.
         static const uint16 head_numb[   821]; // Head symbol number for a production.
         static const uint16 f_tail   [   822]; // First tail in a production.
         static const int16  tail     [  1488]; // Tail symbol number.
         static const int8   arga     [   216]; // Arguments for terminal actions.

         private:
         static const uint8  Bm[   310]       ; // Boolean matrix.
         static const uint16 Br[   668]       ; // Boolean matrix row.
         static const uint8  Bc[   216]       ; // Boolean matrix column.
         static const uint8 Bf[   216]       ; // Boolean matrix filter/mask.
         static const int16  Tm[  1304]       ; // Terminal transition matrix.
         static const uint16 Tr[   668]       ; // Terminal transition matrix row.
         static const uint8  Tc[   216]       ; // Terminal transition matrix column.
         static const int16  Nm[   733]       ; // Nonterminal transition matrix.
         static const uint16 Nr[   668]       ; // Nonterminal transition matrix row.
         static const uint16 Nc[   821]       ; // Nonterminal transition matrix column.
         static const uint8  Rm[     1]       ; // Reduction matrix.
         static const uint16 Rr[   668]       ; // Reduction matrix row.
         static const uint8  Rc[   216]       ; // Reduction matrix column.
         static const int8   PL[   821]       ; // Production length minus one.

         static const int8   tact_numb[   216]; // Terminal action numbers.

         static int    (*tact_func[    2])(void *parser, int &t); // Terminal action function pointers.
      };

//
////////////////////////////////////////////////////////////////////////////////

