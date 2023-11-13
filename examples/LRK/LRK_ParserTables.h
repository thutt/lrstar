
////////////////////////////////////////////////////////////////////////////////
//
//    LRK_ParserTables.h (generated by LRSTAR 24.0.017)

      #pragma once

      #include "lrstar_library_defs.h"

      enum nodecon
      {
         N_goal_ = 0,
         N_function_decl_ = 1,
         N_function_def_ = 2,
         N_type_spec_ = 3,
         N_function_ = 4,
         N_arg_ = 5,
         N_arg_name_ = 6,
         N_function_body_ = 7
      };


class lrstar_parser;

      class lrstar_parser_tables
      {
         friend class lrstar_parser;
         public:
         static const char *term_symb[    19]; // Terminal symbols of the grammar.
         static const char *head_symb[    16]; // Nonterminal symbols of the grammar.
         static const char *tact_name[     2]; // Terminal action names found in the grammar.
         static const char *node_name[     8]; // Node names found in the grammar.
         static const uint8  head_numb[    31]; // Head symbol number for a production.
         static const uint8  f_tail   [    32]; // First tail in a production.
         static const int8   tail     [    51]; // Tail symbol number.
         static const int8   arga     [    19]; // Arguments for terminal actions.
         static int8   argx     [    31]; // First arguments for productions.
         static int8   argy     [    31]; // Second arguments for productions.

         private:
         static const uint8  Bm[    22]       ; // Boolean matrix.
         static const uint8  Br[    23]       ; // Boolean matrix row.
         static const uint8  Bc[    19]       ; // Boolean matrix column.
         static const uint8 Bf[    19]       ; // Boolean matrix filter/mask.
         static const int8   Tm[    39]       ; // Terminal transition matrix.
         static const uint8  Tr[    23]       ; // Terminal transition matrix row.
         static const uint8  Tc[    19]       ; // Terminal transition matrix column.
         static const int8   Nm[    33]       ; // Nonterminal transition matrix.
         static const uint8  Nr[    23]       ; // Nonterminal transition matrix row.
         static const uint8  Nc[    31]       ; // Nonterminal transition matrix column.
         static const uint8  Rm[     1]       ; // Reduction matrix.
         static const uint8  Rr[    23]       ; // Reduction matrix row.
         static const uint8  Rc[    19]       ; // Reduction matrix column.
         static const int8   PL[    31]       ; // Production length minus one.

         static const int8   tact_numb[    19]; // Terminal action numbers.
         static const int8   node_numb[    31]; // Node numbers for the productions.
         static const int8   nact_numb[    31]; // Node action numbers for the productions.

         static int    (*tact_func[    2])(lrstar_parser *parser, int &t); // Terminal action function pointers.
         static int    (*nact_func[    8]) (void* v); // Node action function pointers.
      };

//
////////////////////////////////////////////////////////////////////////////////

