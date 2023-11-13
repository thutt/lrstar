
////////////////////////////////////////////////////////////////////////////////
//
//    Calc_ParserTables.h (generated by LRSTAR 24.0.017)

      #pragma once

      #include "lrstar_library_defs.h"

      enum termcon
      {
         EOF = 1,
         ERR = 0,
         ID = 2,
         INT = 3
      };

      enum nodecon
      {
         N_goal_ = 0,
         N_program_ = 1,
         N_store_ = 2,
         N_if_ = 3,
         N_target_ = 4,
         N_eq_ = 5,
         N_ne_ = 6,
         N_add_ = 7,
         N_sub_ = 8,
         N_mul_ = 9,
         N_div_ = 10,
         N_pwr_ = 11,
         N_int_ = 12,
         N_ident_ = 13,
         N_then_ = 14,
         N_then2_ = 15,
         N_else2_ = 16
      };


      class lrstar_parser_tables
      {
         friend class lrstar_parser;
         public:
         static const char *term_symb[    22]; // Terminal symbols of the grammar.
         static const char *head_symb[    13]; // Nonterminal symbols of the grammar.
         static const char *tact_name[     2]; // Terminal action names found in the grammar.
         static const char *node_name[    17]; // Node names found in the grammar.
         static const uint8  head_numb[    26]; // Head symbol number for a production.
         static const uint8  f_tail   [    27]; // First tail in a production.
         static const int8   tail     [    61]; // Tail symbol number.
         static const int8   arga     [    22]; // Arguments for terminal actions.
         static int8   argx     [    26]; // First arguments for productions.

         private:
         static const uint8  Bm[    30]       ; // Boolean matrix.
         static const uint8  Br[    36]       ; // Boolean matrix row.
         static const uint8  Bc[    22]       ; // Boolean matrix column.
         static const uint8 Bf[    22]       ; // Boolean matrix filter/mask.
         static const int8   Tm[    33]       ; // Terminal transition matrix.
         static const uint8  Tr[    36]       ; // Terminal transition matrix row.
         static const uint8  Tc[    22]       ; // Terminal transition matrix column.
         static const int8   Nm[    47]       ; // Nonterminal transition matrix.
         static const uint8  Nr[    36]       ; // Nonterminal transition matrix row.
         static const uint8  Nc[    26]       ; // Nonterminal transition matrix column.
         static const uint8  Rm[     5]       ; // Reduction matrix.
         static const int8   Rr[    36]       ; // Reduction matrix row.
         static const uint8  Rc[    22]       ; // Reduction matrix column.
         static const int8   PL[    26]       ; // Production length minus one.

         static const int8   tact_numb[    22]; // Terminal action numbers.
         static const int8   node_numb[    26]; // Node numbers for the productions.
         static const int8   nact_numb[    26]; // Node action numbers for the productions.
         static const uint8  reverse  [    26]; // Reverse the child nodes.

         static void   (*init_func[    2])(lrstar_parser *parser); // Init action function pointers.
         static int    (*tact_func[    2])(lrstar_parser *parser, int &t); // Terminal action function pointers.
         static int    (*nact_func[   17]) (void* v); // Node action function pointers.
      };

//
////////////////////////////////////////////////////////////////////////////////

