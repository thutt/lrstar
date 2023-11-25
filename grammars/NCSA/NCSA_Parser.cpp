#include "lrstar_basic_defs.h"
#include "lrstar_parser_tables.h"
#include "NCSA_LexerTables_typedef.h"
#include "NCSA_ParserTables_typedef.h"
#include "NCSA_Parser.h"

template<>
const int NCSA_parser_tables_t::n_term_symb = 24;

template<>
const int NCSA_parser_tables_t::n_head_symb = 25;

template<>
const int NCSA_parser_tables_t::n_tact_name = 2;

template<>
const int NCSA_parser_tables_t::n_node_name = 11;

template<>
const int NCSA_parser_tables_t::n_head_numb = 62;

template<>
const int NCSA_parser_tables_t::n_f_tail = 63;

template<>
const int NCSA_parser_tables_t::n_tail = 114;

template<>
const int NCSA_parser_tables_t::n_arga = 24;

template<>
const int NCSA_parser_tables_t::n_argx = 62;

template<>
const int NCSA_parser_tables_t::n_argy = 62;

template<>
const int NCSA_parser_tables_t::n_Bm = 57;

template<>
const int NCSA_parser_tables_t::n_Br = 38;

template<>
const int NCSA_parser_tables_t::n_Bc = 24;

template<>
const int NCSA_parser_tables_t::n_Bf = 24;

template<>
const int NCSA_parser_tables_t::n_Tm = 99;

template<>
const int NCSA_parser_tables_t::n_Tr = 38;

template<>
const int NCSA_parser_tables_t::n_Tc = 24;

template<>
const int NCSA_parser_tables_t::n_Nm = 72;

template<>
const int NCSA_parser_tables_t::n_Nr = 38;

template<>
const int NCSA_parser_tables_t::n_Nc = 62;

template<>
const int NCSA_parser_tables_t::n_Rm = 6;

template<>
const int NCSA_parser_tables_t::n_Rr = 38;

template<>
const int NCSA_parser_tables_t::n_Rc = 24;

template<>
const int NCSA_parser_tables_t::n_PL = 62;

template<>
const int NCSA_parser_tables_t::n_nd_fterm = 0;

template<>
const int NCSA_parser_tables_t::n_nd_term = 0;

template<>
const int NCSA_parser_tables_t::n_nd_faction = 0;

template<>
const int NCSA_parser_tables_t::n_nd_action = 0;

template<>
const int NCSA_parser_tables_t::n_tact_numb = 24;

template<>
const int NCSA_parser_tables_t::n_node_numb = 62;

template<>
const int NCSA_parser_tables_t::n_nact_numb = 62;

template<>
const int NCSA_parser_tables_t::n_reverse = 0;

template<>
const int NCSA_parser_tables_t::n_terms = 24; // Number of terminals.

template<>
const int NCSA_parser_tables_t::n_heads = 25; // Number of nonterminals.

template<>
const int NCSA_parser_tables_t::n_prods = 62; // Number of productions.

template<>
const int NCSA_parser_tables_t::n_states = 38; // Number of states.

template<>
const int NCSA_parser_tables_t::accept_state = 37; // Accept state.

template<>
const int NCSA_parser_tables_t::n_termactns = 2; // Number of terminal actions.

template<>
const int NCSA_parser_tables_t::n_nodenames = 11; // Number of node names.

template<>
const int NCSA_parser_tables_t::n_nodeactns = 11; // Number of node actions.

template<>
const int NCSA_parser_tables_t::eof_symb = 1; // <eof> symbol number.

template<>
const int NCSA_parser_tables_t::err_used = 1; // <error> used in grammar?


// Terminal symbols of the grammar.
static const char *term_symb_[24] = {
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
   "\';\'",
};

template<>
const char * const *NCSA_parser_tables_t::term_symb = &term_symb_[0];

// Nonterminal symbols of the grammar.
static const char *head_symb_[25] = {
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
   "Thing+",
};

template<>
const char * const *NCSA_parser_tables_t::head_symb = &head_symb_[0];

// Terninal action names found in the grammar ...
static const char *tact_name_[2] = {
   "error",
   "lookup",
};

template<>
const char * const *NCSA_parser_tables_t::tact_name = &tact_name_[0];

// Node names found in the grammar.
static const char * node_name_[11] = {
   "Report,"   "Day,"   "Client,"   "FullName,"   "Name,"   "Time,"   "File,"   "Code,"   "Size,"   "Source,"   "Query,"
};

template<>
const char * const *NCSA_parser_tables_t::node_name = &node_name_[0];

// Head symbol numbers for the productions.
static const uint8 head_numb_[62] = {
       0,     1,     2,     3,     3,     4,     4,     5,     5,     5, 
       5,     6,     6,     7,     7,     8,     9,     9,    10,    10, 
      10,    10,    10,    11,    12,    13,    13,    14,    14,    14, 
      14,    15,    15,    16,    16,    16,    17,    17,    17,    17, 
      17,    17,    17,    17,    17,    17,    17,    17,    18,    18, 
      19,    19,    20,    20,    21,    21,    22,    22,    23,    23, 
      24,    24, 
};

template<>
const uint8 *NCSA_parser_tables_t::head_numb = &head_numb_[0];

// First tail symbol index into the tail list ...
static const uint8 f_tail_[63] = {
       0,     2,     3,     4,    14,    25,    26,    27,    28,    30, 
      32,    33,    34,    35,    38,    41,    42,    46,    50,    51, 
      54,    57,    60,    63,    64,    65,    66,    67,    68,    69, 
      70,    71,    72,    73,    74,    76,    80,    81,    82,    83, 
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93, 
      96,    97,    99,   100,   102,   103,   105,   106,   108,   109, 
     111,   112,   114, 
};

template<>
const uint8 *NCSA_parser_tables_t::f_tail = &f_tail_[0];

// Tail symbol numbers ...
static const int8 tail_[114] = {
     -19,     1,   -20,   -21,    -4,    -5,    -7,    -9,   -10,   -12, 
     -13,   -14,   -16,    10,    -4,    -5,    -7,    -9,   -10,   -12, 
     -13,   -14,   -15,   -16,    10,     4,    11,    12,    12,    12, 
      12,   -22,   -22,     5,     6,    13,    -8,    14,    13,    15, 
      14,     7,     8,    12,     6,    16,     8,    17,     6,    16, 
      12,     5,   -11,     4,     5,   -11,   -23,     5,    18,     4, 
       5,    18,   -23,     3,     6,    12,     6,    12,     5,     2, 
      19,     9,    20,   -17,   -16,   -17,   -16,    21,   -18,    22, 
       2,     3,     4,     5,     6,     7,     8,     9,     0,    13, 
      16,    12,   -24,   -18,    23,   -24,    -1,   -19,    -1,    -2, 
     -20,    -2,    -3,   -21,    -3,    -6,   -22,    -6,     0,   -23, 
       0,   -17,   -24,   -17, 
};

template<>
const int8 *NCSA_parser_tables_t::tail = &tail_[0];

// Arguments for token actions ...
static const int8 arga_[24] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1, 
};

template<>
const int8 *NCSA_parser_tables_t::arga = &arga_[0];

// First arguments for productions ...
static const int8 argx_[62] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,     0,    -1,    -1,    -1,    -1,     0,     0, 
      -1,     0,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1, 
};

template<>
const int8 *NCSA_parser_tables_t::argx = &argx_[0];

// Second arguments for productions ...
static const int8 argy_[62] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1, 
};

template<>
const int8 *NCSA_parser_tables_t::argy = &argy_[0];

// Boolean matrix ...
static const uint8 Bm_[57] = {
       0,     0,     0,    16,     8,     0,    18,     8,     0,    96, 
      16,     0,    32,     0,    96,     0,     0,     1,   128,   128, 
       0,    32,    16,     0,    16,     2,     0,    64,     0,     0, 
       8,     0,     4,    64,    16,     0,    17,     0,     0,    36, 
      16,     8,     1,     0,     0,   253,    51,    17,   253,    55, 
       1,   253,    51,     1,     0,     0,    32, 
};

template<>
const uint8 *NCSA_parser_tables_t::Bm = &Bm_[0];

// Boolean matrix row (for state)...
static const uint8 Br_[38] = {
       3,     6,     3,     3,     9,    11,    14,     9,    16,    18, 
      14,    21,    23,    26,    26,    27,    30,    27,    27,    33, 
      36,    36,    15,    15,    39,    42,    42,    45,    48,    51, 
       0,    51,    48,    54,    51,    51,    51,     0, 
      };

template<>
const uint8 *NCSA_parser_tables_t::Br = &Br_[0];

// Boolean matrix column (displacement) ...
static const uint8 Bc_[24] = {
       0,     0,     0,     0,     0,     0,     0,     0,     1,     1, 
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2, 
       2,     1,     2,     2, 
      };

template<>
const uint8 *NCSA_parser_tables_t::Bc = &Bc_[0];

// Boolean matrix filter/mask value ...
static const uint8 Bf_[24] = {
       1,     2,     4,     8,    16,    32,    64,   128,     1,     2, 
       4,     8,    16,    32,    64,   128,     1,     2,     4,     8, 
      16,     4,    32,    32, 
};

template<>
const uint8 *NCSA_parser_tables_t::Bf = &Bf_[0];

// Terminal transition matrix ...
static const int8 Tm_[99] = {
       0,     0,     0,   -26,    22,     0,     0,   -25,    17,     0, 
       0,    18,   -21,    16,   -24,     0,     0,   -29,   -18,   -28, 
      23,   -58,     0,     0,   -27,   -19,   -11,   -12,     0,   -30, 
       0,    -8,     0,   -17,   -58,     0,     0,   -14,   -36,   -38, 
     -39,   -40,   -41,   -42,    30,   -47,   -45,   -46,   -44,     0, 
     -37,   -32,   -36,   -38,   -39,   -40,   -41,   -42,   -43,   -47, 
     -45,   -46,   -44,     0,   -37,    -3,    31,   -36,   -38,   -39, 
     -40,   -41,   -42,   -43,   -47,   -45,   -46,   -44,     0,   -37, 
      -4,    31,    37,    -5,   -11,   -12,   -15,    12,    -6,     7, 
       9,   -16,   -59,    21,   -23,   -13,    14,   -35,    35, 
};

template<>
const int8 *NCSA_parser_tables_t::Tm = &Tm_[0];

// Terminal transition matrix row ...
static const uint8 Tr_[38] = {
      82,    82,    82,    82,    82,    82,    82,    24,    82,    82, 
      82,    11,     1,    82,    24,    11,    82,     1,    17,     0, 
      24,    11,    82,    24,    17,    82,    82,    38,    52,    52, 
      82,    52,    67,    82,    52,    52,    52,    82, 
};

template<>
const uint8 *NCSA_parser_tables_t::Tr = &Tr_[0];

// Terminal transition matrix column ...
static const uint8 Tc_[24] = {
      10,     0,     0,    12,     1,     2,     3,     4,     5,     6, 
      13,     6,     7,     8,    13,    14,     9,    10,    11,    12, 
      13,    14,    15,    16, 
};

template<>
const uint8 *NCSA_parser_tables_t::Tc = &Tc_[0];

// Nonterminal transition matrix ...
static const int8 Nm_[72] = {
       0,     0,   -55,     4,     0,     0,   -54,     4,     0,   -56, 
       0,     0,     0,     0,   -61,   -60,   -60,    33,     0,    32, 
     -33,     0,    36,    34,     3,    10,     0,   -53,   -54,     4, 
       0,   -57,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,   -34,   -51,     0,     2,     3,     0,    26,   -52, 
     -54,     4,     5,   -56,     8,    13,    11,    15,    20,    19, 
      24,    27,    29,    28,   -33,   -50,     1,     2,     3,     6, 
      25,   -52, 
};

template<>
const int8 *NCSA_parser_tables_t::Nm = &Nm_[0];

// Nonterminal transition matrix row ...
static const uint8 Nr_[38] = {
   50,    28,     6,     2,    50,    50,    28,     6,    50,    50, 
   28,    50,    50,    50,    50,    50,    50,    50,    50,    50, 
   50,    28,    50,    50,    50,    50,    50,    50,    28,     6, 
   50,     2,    28,    50,     0,     1,     0,    50, 
};

template<>
const uint8 *NCSA_parser_tables_t::Nr = &Nr_[0];

// Nonterminal transition matrix column ...
static const uint8 Nc_[62] = {
   15,    15,    21,     0,     0,     1,     1,     2,     2,     2, 
    2,     3,     3,     4,     4,     5,     6,     6,     7,     7, 
    7,     7,     7,     8,     9,    10,    10,    11,    11,    11, 
   11,    12,    12,    13,    13,    13,    14,    14,    14,    14, 
   14,    14,    14,    14,    14,    14,    14,    14,    15,    15, 
   16,    16,    17,    17,    18,    18,    19,    19,    20,    20, 
   21,    21, 
};

template<>
const uint8 *NCSA_parser_tables_t::Nc = &Nc_[0];

// Reduction matrix ...
static const uint8 Rm_[6] = {
       0,     0,     0,    31,     0,    43, 
};

template<>
const uint8 *NCSA_parser_tables_t::Rm = &Rm_[0];

// Reduction matrix row ...
static const int8 Rr_[38] = {
       0,     0,     1,     2,     0,     0,    10,     7,     0,     0, 
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,    20,    22,     0,     0,     0, 
      -3,     0,     0,     0,    48,     0,    49,     0, 
};

template<>
const int8 *NCSA_parser_tables_t::Rr = &Rr_[0];

// Reduction matrix column ...
static const uint8 Rc_[24] = {
       0,     1,     0,     0,     0,     0,     0,     0,     0,     0, 
       2,     1,     0,     0,     1,     1,     0,     1,     1,     1, 
       1,     2,     1,     1, 
};

template<>
const uint8 *NCSA_parser_tables_t::Rc = &Rc_[0];

// Production lengths (minus one) ...
static const uint8 PL_[62] = {
       1,     0,     0,     9,    10,     0,     0,     0,     1,     1, 
       0,     0,     0,     2,     2,     0,     3,     3,     0,     2, 
       2,     2,     2,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     1,     3,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2, 
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1, 
       0,     1, 
};

template<>
const uint8 *NCSA_parser_tables_t::PL = &PL_[0];

template<>
const uint32 *NCSA_parser_tables_t::nd_fterm = 0;

template<>
const uint32 *NCSA_parser_tables_t::nd_term = 0;

template<>
const uint32 *NCSA_parser_tables_t::nd_faction = 0;

template<>
const uint32 *NCSA_parser_tables_t::nd_action = 0;

// Terminal action number ...
static const int8 tact_numb_[24] = {
       0,    -1,     1,     1,     1,     1,     1,     1,     1,     1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1, 
};

template<>
const int8 *NCSA_parser_tables_t::tact_numb = &tact_numb_[0];

// Node number for each production ...
static const int8 node_numb_[62] = {
       0,     1,     2,    -1,    -1,    -1,    -1,    -1,    -1,     3, 
       3,     4,     4,    -1,    -1,    -1,     5,     5,     6,    -1, 
      -1,     6,     6,    -1,     7,     8,     8,    -1,     9,     9, 
       9,    10,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1, 
};

template<>
const int8 *NCSA_parser_tables_t::node_numb = &node_numb_[0];

// Node action numbers ...
static const int8 nact_numb_[62] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1, 
};

template<>
const int8 *NCSA_parser_tables_t::nact_numb = &nact_numb_[0];

template<>
const uint32 *NCSA_parser_tables_t::reverse = 0;

