
////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    NCSA_ParserTables.hpp (generated by LRSTAR 24.0.017)

      #include "NCSA_ParserTables.h"
      #include "NCSA_Actions.h"

      static int n_terms      =   24; // Number of terminals.
      static int n_heads      =   25; // Number of nonterminals.
      static int n_prods      =   62; // Number of productions.
      static int n_states     =   38; // Number of states.
      static int accept_state =   37; // Accept state.
      static int n_termactns  =    2; // Number of terminal actions.
      static int n_nodenames  =   11; // Number of node names.
      static int n_nodeactns  =   11; // Number of node actions.
      static int eof_symb     =    1; // <eof> symbol number.
      static int err_used     =    1; // <error> used in grammar?

   // Terminal symbols of the grammar ...
      char* NCSA_ParserTables::term_symb[24] = 
      {
         "<error>",
         "<eof>",
         "<url>",
         "<path>",
         "<file>",
         "<word>",
         "<numb>",
         "<date>",
         "<time>",
         "<query>",
         "<eol>",
         "{Client}",
         "\'-\'",
         "\'[\'",
         "\':\'",
         "{Date}",
         "\']\'",
         "\'+\'",
         "{Path}",
         "{Source}",
         "{Query}",
         "\'(\'",
         "\')\'",
         "\';\'"
      };

   // Nonterminal symbols of the grammar ...
      char* NCSA_ParserTables::head_symb[25] = 
      {
         "Start",
         "Day",
         "Session",
         "Record",
         "Client",
         "User",
         "Name",
         "Date",
         "Date_",
         "Time",
         "Cmd",
         "Path_",
         "Code",
         "Size",
         "Source",
         "Query",
         "Browser",
         "Thing",
         "ItemList",
         "Day+",
         "Session+",
         "Record+",
         "Name+",
         "<error>+",
         "Thing+"
      };

   // Terninal action names found in the grammar ...
      char* NCSA_ParserTables::tact_name[2] = 
      {
         "error",
         "lookup"
      };

   // Node names found in the grammar ...
      char* NCSA_ParserTables::node_name[11] = 
      {
         "Report",
         "Day",
         "Client",
         "FullName",
         "Name",
         "Time",
         "File",
         "Code",
         "Size",
         "Source",
         "Query"
      };

   // Head symbol numbers for the productions ...
      uchar NCSA_ParserTables::head_numb[62] = 
      {
          0,    1,    2,    3,    3,    4,    4,    5,    5,    5,    5,    6,    6,    7,    7,    8,    9,    9,   10,   10,
         10,   10,   10,   11,   12,   13,   13,   14,   14,   14,   14,   15,   15,   16,   16,   16,   17,   17,   17,   17,
         17,   17,   17,   17,   17,   17,   17,   17,   18,   18,   19,   19,   20,   20,   21,   21,   22,   22,   23,   23,
         24,   24
      };

   // First tail symbol index into the tail list ...
      uchar NCSA_ParserTables::f_tail[63] = 
      {
          0,    2,    3,    4,   14,   25,   26,   27,   28,   30,   32,   33,   34,   35,   38,   41,   42,   46,   50,   51,
         54,   57,   60,   63,   64,   65,   66,   67,   68,   69,   70,   71,   72,   73,   74,   76,   80,   81,   82,   83,
         84,   85,   86,   87,   88,   89,   90,   91,   92,   93,   96,   97,   99,  100,  102,  103,  105,  106,  108,  109,
        111,  112,  114
      };

   // Tail symbol numbers ...
      char NCSA_ParserTables::tail[114] = 
      {
        -19,    1,  -20,  -21,   -4,   -5,   -7,   -9,  -10,  -12,  -13,  -14,  -16,   10,   -4,   -5,   -7,   -9,  -10,  -12,
        -13,  -14,  -15,  -16,   10,    4,   11,   12,   12,   12,   12,  -22,  -22,    5,    6,   13,   -8,   14,   13,   15,
         14,    7,    8,   12,    6,   16,    8,   17,    6,   16,   12,    5,  -11,    4,    5,  -11,  -23,    5,   18,    4,
          5,   18,  -23,    3,    6,   12,    6,   12,    5,    2,   19,    9,   20,  -17,  -16,  -17,  -16,   21,  -18,   22,
          2,    3,    4,    5,    6,    7,    8,    9,    0,   13,   16,   12,  -24,  -18,   23,  -24,   -1,  -19,   -1,   -2,
        -20,   -2,   -3,  -21,   -3,   -6,  -22,   -6,    0,  -23,    0,  -17,  -24,  -17
      };

   // Arguments for token actions ...
      char NCSA_ParserTables::arga[24] = 
      {
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   -1
      };

   // First arguments for productions ...
      char NCSA_ParserTables::argx[62] = 
      {
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,    0,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,    0,   -1,   -1,   -1,   -1,    0,    0,   -1,    0,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1
      };

   // Second arguments for productions ...
      char NCSA_ParserTables::argy[62] = 
      {
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   15,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   18,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1
      };

   // Boolean matrix ...
      uchar NCSA_ParserTables::Bm[57] = 
      {
          0,    0,    0,   16,    8,    0,   18,    8,    0,   96,   16,    0,   32,    0,   96,    0,    0,    1,  128,  128,
          0,   32,   16,    0,   16,    2,    0,   64,    0,    0,    8,    0,    4,   64,   16,    0,   17,    0,    0,   36,
         16,    8,    1,    0,    0,  253,   51,   17,  253,   55,    1,  253,   51,    1,    0,    0,   32
      };

   // Booeal matrix row (for state)...
      uchar NCSA_ParserTables::Br[38] = 
      {
          3,    6,    3,    3,    9,   11,   14,    9,   16,   18,   14,   21,   23,   26,   26,   27,   30,   27,   27,   33,
         36,   36,   15,   15,   39,   42,   42,   45,   48,   51,    0,   51,   48,   54,   51,   51,   51,    0
      };

   // Booolean matrix column (displacement) ...
      uchar NCSA_ParserTables::Bc[24] = 
      {
          0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    1,    1,    1,    1,    2,    2,    2,    2,
          2,    1,    2,    2
      };

   // Boolean matrix filter/mask value ...
      uchar NCSA_ParserTables::Bf[24] = 
      {
          1,    2,    4,    8,   16,   32,   64,  128,    1,    2,    4,    8,   16,   32,   64,  128,    1,    2,    4,    8,
         16,    4,   32,   32
      };

   // Terminal transition matrix ...
      char NCSA_ParserTables::Tm[99] = 
      {
          0,    0,    0,  -26,   22,    0,    0,  -25,   17,    0,    0,   18,  -21,   16,  -24,    0,    0,  -29,  -18,  -28,
         23,  -58,    0,    0,  -27,  -19,  -11,  -12,    0,  -30,    0,   -8,    0,  -17,  -58,    0,    0,  -14,  -36,  -38,
        -39,  -40,  -41,  -42,   30,  -47,  -45,  -46,  -44,    0,  -37,  -32,  -36,  -38,  -39,  -40,  -41,  -42,  -43,  -47,
        -45,  -46,  -44,    0,  -37,   -3,   31,  -36,  -38,  -39,  -40,  -41,  -42,  -43,  -47,  -45,  -46,  -44,    0,  -37,
         -4,   31,   37,   -5,  -11,  -12,  -15,   12,   -6,    7,    9,  -16,  -59,   21,  -23,  -13,   14,  -35,   35
      };

   // Terminal transition matrix row ...
      uchar NCSA_ParserTables::Tr[38] = 
      {
         82,   82,   82,   82,   82,   82,   82,   24,   82,   82,   82,   11,    1,   82,   24,   11,   82,    1,   17,    0,
         24,   11,   82,   24,   17,   82,   82,   38,   52,   52,   82,   52,   67,   82,   52,   52,   52,   82
      };

   // Terminal transition matrix column ...
      uchar NCSA_ParserTables::Tc[24] = 
      {
         10,    0,    0,   12,    1,    2,    3,    4,    5,    6,   13,    6,    7,    8,   13,   14,    9,   10,   11,   12,
         13,   14,   15,   16
      };

   // Nonterminal transition matrix ...
      char NCSA_ParserTables::Nm[72] = 
      {
          0,    0,  -55,    4,    0,    0,  -54,    4,    0,  -56,    0,    0,    0,    0,  -61,  -60,  -60,   33,    0,   32,
        -33,    0,   36,   34,    3,   10,    0,  -53,  -54,    4,    0,  -57,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,  -34,  -51,    0,    2,    3,    0,   26,  -52,  -54,    4,    5,  -56,    8,   13,   11,   15,   20,   19,
         24,   27,   29,   28,  -33,  -50,    1,    2,    3,    6,   25,  -52
      };

   // Nonterminal transition matrix row ...
      uchar NCSA_ParserTables::Nr[38] = 
      {
         50,   28,    6,    2,   50,   50,   28,    6,   50,   50,   28,   50,   50,   50,   50,   50,   50,   50,   50,   50,
         50,   28,   50,   50,   50,   50,   50,   50,   28,    6,   50,    2,   28,   50,    0,    1,    0,   50
      };

   // Nonterminal transition matrix column ...
      uchar NCSA_ParserTables::Nc[62] = 
      {
         15,   15,   21,    0,    0,    1,    1,    2,    2,    2,    2,    3,    3,    4,    4,    5,    6,    6,    7,    7,
          7,    7,    7,    8,    9,   10,   10,   11,   11,   11,   11,   12,   12,   13,   13,   13,   14,   14,   14,   14,
         14,   14,   14,   14,   14,   14,   14,   14,   15,   15,   16,   16,   17,   17,   18,   18,   19,   19,   20,   20,
         21,   21
      };

   // Reduction matrix ...
      uchar NCSA_ParserTables::Rm[6] = 
      {
          0,    0,    0,   31,    0,   43
      };

   // Reduction matrix row ...
      char NCSA_ParserTables::Rr[38] = 
      {
          0,    0,    1,    2,    0,    0,   10,    7,    0,    0,    9,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,   20,   22,    0,    0,    0,   -3,    0,    0,    0,   48,    0,   49,    0
      };

   // Reduction matrix column ...
      uchar NCSA_ParserTables::Rc[24] = 
      {
          0,    1,    0,    0,    0,    0,    0,    0,    0,    0,    2,    1,    0,    0,    1,    1,    0,    1,    1,    1,
          1,    2,    1,    1
      };

   // Production lengths (minus one) ...
      uchar NCSA_ParserTables::PL[62] = 
      {
          1,    0,    0,    9,   10,    0,    0,    0,    1,    1,    0,    0,    0,    2,    2,    0,    3,    3,    0,    2,
          2,    2,    2,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    3,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    0,    0,    0,    0,    2,    0,    1,    0,    1,    0,    1,    0,    1,    0,    1,
          0,    1
      };

   // Terminal action number ...
      char NCSA_ParserTables::tact_numb[24] = 
      {
          0,   -1,    1,    1,    1,    1,    1,    1,    1,    1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   -1
      };

   // Node number for each production ...
      char NCSA_ParserTables::node_numb[62] = 
      {
          0,    1,    2,   -1,   -1,   -1,   -1,   -1,   -1,    3,    3,    4,    4,   -1,   -1,   -1,    5,    5,    6,   -1,
         -1,    6,    6,   -1,    7,    8,    8,   -1,    9,    9,    9,   10,   10,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1
      };

   // Node action numbers ...
      char NCSA_ParserTables::nact_numb[62] = 
      {
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1
      };

   // Init action function pointers ...
      void (*NCSA_ParserTables::init_func[2]) () =
      {
         NCSA_Actions::init_actions,
         NCSA_Actions::term_actions
      };

   // Terminal action function pointers ...
      int (*NCSA_ParserTables::tact_func[2]) (int& t) =
      {
         NCSA_TermActions::error,
         NCSA_TermActions::lookup
      };

   // Node action function pointers ...
      int (*NCSA_ParserTables::nact_func[11]) (void* v) = 
      {
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0
      };

//
////////////////////////////////////////////////////////////////////////////////////////////////////

