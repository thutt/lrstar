
////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    Typedef_ParserTables.hpp (generated by LRSTAR 24.0.017)

      #include "lrstar_basic_defs.h"
      #include "lrstar_parser_tables.h"
      #include "Typedef_ParserTables.h"
      #include "Typedef_Actions.h"

      static int n_terms      =   12; // Number of terminals.
      static int n_heads      =   14; // Number of nonterminals.
      static int n_prods      =   24; // Number of productions.
      static int n_states     =   14; // Number of states.
      static int accept_state =   13; // Accept state.
      static int n_termactns  =    2; // Number of terminal actions.
      static int n_nodenames  =    1; // Number of node names.
      static int n_nodeactns  =    1; // Number of node actions.
      static int eof_symb     =    1; // <eof> symbol number.
      static int err_used     =    0; // <error> used in grammar?

   // Terminal symbols of the grammar ...
      const char* lrstar_parser_tables::term_symb[12] = 
      {
         "<error>",
         "<eof>",
         "<identifier>",
         "\';\'",
         "\'typedef\'",
         "\',\'",
         "{typename}",
         "\'*\'",
         "\'char\'",
         "\'int\'",
         "\'short\'",
         "\'unsigned\'"
      };

   // Nonterminal symbols of the grammar ...
      const char *lrstar_parser_tables::head_symb[14] = 
      {
         "Goal",
         "Declaration",
         "VarList",
         "TypeVarList",
         "Var",
         "TypeVar",
         "TypeIdent",
         "Ptr",
         "Type",
         "Declaration*",
         "Type+",
         "Var/','+",
         "TypeVar/','+",
         "Ptr*"
      };

   // Terninal action names found in the grammar ...
      const char *lrstar_parser_tables::tact_name[2] = 
      {
         "error",
         "lookup"
      };

   // Node names found in the grammar ...
      const char * lrstar_parser_tables::node_name[1] = 
      {
         "hello_"
      };

   // Head symbol numbers for the productions ...
      const uint8 lrstar_parser_tables::head_numb[24] = 
      {
          0,    1,    1,    2,    3,    4,    5,    6,    7,    8,    8,    8,    8,    8,    9,    9,   10,   10,   11,   11,
         12,   12,   13,   13
      };

   // First tail symbol index into the tail list ...
      const uint8 lrstar_parser_tables::f_tail[25] = 
      {
          0,    2,    5,    9,   10,   11,   13,   15,   16,   17,   18,   19,   20,   21,   22,   22,   24,   25,   27,   28,
         31,   32,   35,   35,   37
      };

   // Tail symbol numbers ...
      const int8 lrstar_parser_tables::tail[37] = 
      {
         -9,    1,  -10,   -2,    3,    4,  -10,   -3,    3,  -11,  -12,  -13,    2,  -13,   -6,    2,    7,    8,    9,   10,
         11,    6,   -9,   -1,   -8,  -10,   -8,   -4,  -11,    5,   -4,   -5,  -12,    5,   -5,  -13,   -7
      };

   // Arguments for token actions ...
      const int8 lrstar_parser_tables::arga[12] = 
      {
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1
      };

   // First arguments for productions ...
      int8 lrstar_parser_tables::argx[24] = 
      {
         -1,   -1,   -1,   -1,   -1,   -1,   -1,    0,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   -1
      };

   // Second arguments for productions ...
      int8 lrstar_parser_tables::argy[24] = 
      {
         -1,   -1,   -1,   -1,   -1,   -1,   -1,    6,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   -1
      };

   // Boolean matrix ...
      const uint8 lrstar_parser_tables::Bm[6] = 
      {
          0,   34,   32,    8,   16,    4
      };

   // Boolean matrix row (for state)...
      const uint8 lrstar_parser_tables::Br[14] = 
      {
          0,    1,    2,    2,    3,    4,    5,    2,    0,    3,    4,    5,    0,    0
      };

   // Boolean matrix column (displacement) ...
      const uint8 lrstar_parser_tables::Bc[12] = 
      {
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
      };

   // Boolean matrix filter/mask value ...
      const uint8 lrstar_parser_tables::Bf[12] = 
      {
          1,    2,    4,    8,    2,   16,   32,    4,   32,   32,   32,   32
      };

   // Terminal transition matrix ...
      const int8 lrstar_parser_tables::Tm[18] = 
      {
          0,   -7,   -2,    0,   12,    0,   -8,   13,   -5,   -1,    3,    8,  -13,   -8,   -9,  -10,  -11,  -12
      };

   // Terminal transition matrix row ...
      const uint8 lrstar_parser_tables::Tr[14] = 
      {
          7,    7,    7,    7,    7,    7,    7,    7,    7,    0,    0,    0,    7,    7
      };

   // Terminal transition matrix column ...
      const uint8 lrstar_parser_tables::Tc[12] = 
      {
          0,    0,    1,    2,    3,    4,    5,    6,    7,    8,    9,   10
      };

   // Nonterminal transition matrix ...
      const int8 lrstar_parser_tables::Nm[32] = 
      {
          0,  -21,  -16,    0,    7,    0,    0,   11,    4,  -18,  -17,    0,    0,    5,    0,    6,    9,  -20,  -17,    0,
          0,    0,   10,   11,  -15,  -19,  -16,    1,    2,   -6,  -23,    6
      };

   // Nonterminal transition matrix row ...
      const uint8 lrstar_parser_tables::Nr[14] = 
      {
         24,   24,    8,    0,   24,   24,   24,   16,   24,   24,   24,   24,    0,   24
      };

   // Nonterminal transition matrix column ...
      const uint8 lrstar_parser_tables::Nc[24] = 
      {
          0,    0,    0,    0,    0,    1,    1,    5,    6,    2,    2,    2,    2,    2,    3,    3,    4,    4,    5,    5,
          6,    6,    7,    7
      };

   // Reduction matrix ...
      const uint8 lrstar_parser_tables::Rm[1] = 
      {
          0
      };

   // Reduction matrix row ...
      const uint8 lrstar_parser_tables::Rr[14] = 
      {
         14,    0,   22,    0,    0,    3,    0,   22,   22,    0,    4,    0,   22,    0
      };

   // Reduction matrix column ...
      const uint8 lrstar_parser_tables::Rc[12] = 
      {
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
      };

   // Production lengths (minus one) ...
      const int8 lrstar_parser_tables::PL[24] = 
      {
          1,    2,    3,    0,    0,    1,    1,    0,    0,    0,    0,    0,    0,    0,   -1,    1,    0,    1,    0,    2,
          0,    2,   -1,    1
      };

   // Terminal action number ...
      const int8 lrstar_parser_tables::tact_numb[12] = 
      {
          0,   -1,    1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1
      };

   // Node number for each production ...
      const int8 lrstar_parser_tables::node_numb[24] = 
      {
         -1,   -1,   -1,   -1,   -1,   -1,   -1,    0,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   -1
      };

   // Node action numbers ...
      const int8 lrstar_parser_tables::nact_numb[24] = 
      {
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   -1
      };

   // Terminal action function pointers ...
      int (*lrstar_parser_tables::tact_func[2])(void *parser, int &t) =
      {
         lrstar_term_actions::error,
         lrstar_term_actions::lookup
      };

   // Node action function pointers ...
      int (*lrstar_parser_tables::nact_func[1]) (void* v) = 
      {
         0
      };

//
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Typedef_ParserTables_instantiate.h"
