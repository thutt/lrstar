
////////////////////////////////////////////////////////////////////////////////
//
//    Zeus_ParserTables.h (generated by LRSTAR 24.0.017)

      #pragma once

      #include "lrstar_library_defs.h"


      class lrstar_parser_tables
      {
         friend class lrstar_parser;
         public:
         static const char *term_symb[    71]; // Terminal symbols of the grammar.
         static const char *head_symb[   114]; // Nonterminal symbols of the grammar.
         static const char *tact_name[     2]; // Terminal action names found in the grammar.
         static const uint8  head_numb[   222]; // Head symbol number for a production.
         static const uint16 f_tail   [   223]; // First tail in a production.
         static const int8   tail     [   479]; // Tail symbol number.
         static const int8   arga     [    71]; // Arguments for terminal actions.

         private:
         static const uint8  Bm[   340]       ; // Boolean matrix.
         static const uint16 Br[   229]       ; // Boolean matrix row.
         static const uint8  Bc[    71]       ; // Boolean matrix column.
         static const uint8 Bf[    71]       ; // Boolean matrix filter/mask.
         static const int16  Tm[   400]       ; // Terminal transition matrix.
         static const uint16 Tr[   229]       ; // Terminal transition matrix row.
         static const uint8  Tc[    71]       ; // Terminal transition matrix column.
         static const int16  Nm[  1154]       ; // Nonterminal transition matrix.
         static const uint16 Nr[   229]       ; // Nonterminal transition matrix row.
         static const uint8  Nc[   222]       ; // Nonterminal transition matrix column.
         static const uint8  Rm[     1]       ; // Reduction matrix.
         static const uint8  Rr[   229]       ; // Reduction matrix row.
         static const uint8  Rc[    71]       ; // Reduction matrix column.
         static const int8   PL[   222]       ; // Production length minus one.

         static const int8   tact_numb[    71]; // Terminal action numbers.

         static int    (*tact_func[    2])(void *parser, int &t); // Terminal action function pointers.
      };

//
////////////////////////////////////////////////////////////////////////////////

