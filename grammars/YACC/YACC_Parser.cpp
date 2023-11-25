#include "lrstar_basic_defs.h"
#include "lrstar_parser_tables.h"
#include "YACC_LexerTables_typedef.h"
#include "YACC_ParserTables_typedef.h"
#include "YACC_Parser.h"

template<>
const int YACC_parser_tables_t::n_term_symb = 27;

template<>
const int YACC_parser_tables_t::n_head_symb = 17;

template<>
const int YACC_parser_tables_t::n_tact_name = 0;

template<>
const int YACC_parser_tables_t::n_node_name = 0;

template<>
const int YACC_parser_tables_t::n_head_numb = 59;

template<>
const int YACC_parser_tables_t::n_f_tail = 60;

template<>
const int YACC_parser_tables_t::n_tail = 110;

template<>
const int YACC_parser_tables_t::n_arga = 0;

template<>
const int YACC_parser_tables_t::n_argx = 0;

template<>
const int YACC_parser_tables_t::n_argy = 0;

template<>
const int YACC_parser_tables_t::n_Bm = 44;

template<>
const int YACC_parser_tables_t::n_Br = 43;

template<>
const int YACC_parser_tables_t::n_Bc = 27;

template<>
const int YACC_parser_tables_t::n_Bf = 27;

template<>
const int YACC_parser_tables_t::n_Tm = 86;

template<>
const int YACC_parser_tables_t::n_Tr = 43;

template<>
const int YACC_parser_tables_t::n_Tc = 27;

template<>
const int YACC_parser_tables_t::n_Nm = 48;

template<>
const int YACC_parser_tables_t::n_Nr = 43;

template<>
const int YACC_parser_tables_t::n_Nc = 59;

template<>
const int YACC_parser_tables_t::n_Rm = 1;

template<>
const int YACC_parser_tables_t::n_Rr = 43;

template<>
const int YACC_parser_tables_t::n_Rc = 27;

template<>
const int YACC_parser_tables_t::n_PL = 59;

template<>
const int YACC_parser_tables_t::n_nd_fterm = 0;

template<>
const int YACC_parser_tables_t::n_nd_term = 0;

template<>
const int YACC_parser_tables_t::n_nd_faction = 0;

template<>
const int YACC_parser_tables_t::n_nd_action = 0;

template<>
const int YACC_parser_tables_t::n_tact_numb = 0;

template<>
const int YACC_parser_tables_t::n_node_numb = 0;

template<>
const int YACC_parser_tables_t::n_nact_numb = 0;

template<>
const int YACC_parser_tables_t::n_reverse = 0;

template<>
const int YACC_parser_tables_t::n_terms = 27; // Number of terminals.

template<>
const int YACC_parser_tables_t::n_heads = 17; // Number of nonterminals.

template<>
const int YACC_parser_tables_t::n_prods = 59; // Number of productions.

template<>
const int YACC_parser_tables_t::n_states = 43; // Number of states.

template<>
const int YACC_parser_tables_t::accept_state = 42; // Accept state.

template<>
const int YACC_parser_tables_t::n_termactns = 0; // Number of terminal actions.

template<>
const int YACC_parser_tables_t::n_nodenames = 0; // Number of node names.

template<>
const int YACC_parser_tables_t::n_nodeactns = 0; // Number of node actions.

template<>
const int YACC_parser_tables_t::eof_symb = 1; // <eof> symbol number.

template<>
const int YACC_parser_tables_t::err_used = 0; // <error> used in grammar?


// Terminal symbols of the grammar.
static const char *term_symb_[27] = {
   "<error>",
   "<eof>",
   "\'pp\'",
   "\'error\'",
   "\'pstart\'",
   "\'id\'",
   "\'lcurl\'",
   "\'rcurl\'",
   "\'ptoken\'",
   "\'pleft\'",
   "\'pright\'",
   "\'pnonassoc\'",
   "\'ptype\'",
   "\'langle\'",
   "\'rangle\'",
   "\'comma\'",
   "\'literal\'",
   "\'litid\'",
   "\'number\'",
   "\'c_id\'",
   "\'colon\'",
   "\'bar\'",
   "\'lbrace\'",
   "\'rbrace\'",
   "\'eq\'",
   "\'pprec\'",
   "\'semicolon\'",
};

template<>
const char * const *YACC_parser_tables_t::term_symb = &term_symb_[0];

// Nonterminal symbols of the grammar.
static const char *head_symb_[17] = {
   "start",
   "grammar",
   "aux_procs",
   "defs",
   "def",
   "tag",
   "token_list",
   "token_num",
   "nonterm_list",
   "nonterm",
   "rules",
   "rule1",
   "rule",
   "body",
   "action",
   "prec",
   "opt_action",
};

template<>
const char * const *YACC_parser_tables_t::head_symb = &head_symb_[0];

template<>
const char * const *YACC_parser_tables_t::tact_name = 0;

template<>
const char * const *YACC_parser_tables_t::node_name = 0;

// Head symbol numbers for the productions.
static const uint8 head_numb_[59] = {
       0,     1,     2,     2,     3,     3,     3,     4,     4,     4, 
       4,     4,     4,     4,     4,     4,     5,     5,     6,     6, 
       6,     6,     6,     6,     7,     7,     7,     7,     7,     8, 
       8,     8,     8,     8,     8,     9,    10,    10,    10,    10, 
      10,    11,    12,    12,    13,    13,    13,    13,    13,    13, 
      14,    14,    15,    15,    15,    15,    15,    16,    16, 
};

template<>
const uint8 *YACC_parser_tables_t::head_numb = &head_numb_[0];

// First tail symbol index into the tail list ...
static const uint8 f_tail_[60] = {
       0,     2,     6,     6,     7,     7,     9,    11,    13,    15, 
      17,    20,    23,    26,    29,    32,    34,    34,    37,    38, 
      40,    43,    44,    46,    49,    50,    51,    52,    54,    56, 
      57,    59,    62,    63,    65,    68,    69,    69,    72,    74, 
      75,    77,    81,    82,    85,    85,    87,    89,    91,    93, 
      95,    97,    98,    98,   101,   104,   107,   109,   109,   110, 
};

template<>
const uint8 *YACC_parser_tables_t::f_tail = &f_tail_[0];

// Tail symbol numbers ...
static const int8 tail_[110] = {
      -1,     1,    -3,     2,   -10,    -2,     2,    -3,    -4,    -3, 
       3,     4,     5,     4,     3,     6,     7,     8,    -5,    -6, 
       9,    -5,    -6,    10,    -5,    -6,    11,    -5,    -6,    12, 
      -5,    -8,    12,    -5,    13,     5,    14,    -7,    -6,    -7, 
      -6,    15,    -7,     3,    -6,     3,    -6,    15,     3,    16, 
      17,     5,    17,    18,     5,    18,    -9,    -8,    -9,    -8, 
      15,    -9,     3,    -8,     3,    -8,    15,     3,     5,     6, 
       7,   -11,   -10,   -12,     3,   -10,     3,    19,    20,   -13, 
     -15,   -11,    21,   -13,   -15,   -13,    16,   -13,    17,   -13, 
       5,   -13,   -14,   -13,     3,    22,    23,    24,    25,    16, 
     -16,    25,    17,   -16,    25,     5,   -16,   -15,    26,   -14, 
};

template<>
const int8 *YACC_parser_tables_t::tail = &tail_[0];

template<>
const uint32 *YACC_parser_tables_t::arga = 0;

template<>
const uint32 *YACC_parser_tables_t::argx = 0;

template<>
const uint32 *YACC_parser_tables_t::argy = 0;

// Boolean matrix ...
static const uint8 Bm_[44] = {
       0,     0,     0,     2,     0,     0,    92,     0,     0,    72, 
       0,     0,    40,     0,   128,     0,     0,     1,     0,    12, 
     160,     0,    40,     8,    32,     0,    64,     0,    32,     0, 
      40,    12,     0,    16,     0,    40,     4,     0,    40,     8, 
       5,    32,     8,     0, 
};

template<>
const uint8 *YACC_parser_tables_t::Bm = &Bm_[0];

// Boolean matrix row (for state)...
static const uint8 Br_[43] = {
       0,     3,     6,     9,    12,    14,    16,    16,    16,    16, 
      16,    19,    14,    22,    24,    22,    22,    22,    12,    25, 
       0,    27,    30,    32,    32,     2,    30,    30,    30,    35, 
       0,    38,    22,    12,    38,     7,    41,     1,     7,    15, 
      15,    15,     0, 
      };

template<>
const uint8 *YACC_parser_tables_t::Br = &Br_[0];

// Boolean matrix column (displacement) ...
static const uint8 Bc_[27] = {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     1,     1,     1,     1,     1,     1,     1, 
       1,     1,     2,     2,     2,     2,     2, 
      };

template<>
const uint8 *YACC_parser_tables_t::Bc = &Bc_[0];

// Boolean matrix filter/mask value ...
static const uint8 Bf_[27] = {
       1,     2,     4,     8,    16,    32,    64,   128,    16,    16, 
      16,    16,    16,     1,     2,     4,     8,     8,    16,    32, 
      64,   128,     1,     2,     1,     4,     8, 
};

template<>
const uint8 *YACC_parser_tables_t::Bf = &Bf_[0];

// Terminal transition matrix ...
static const int8 Tm_[86] = {
      -8,   -32,   -34,   -33,     0,     0,     0,     0,     0,   -40, 
     -21,     0,    33,     0,     0,    -7,   -35,   -35,   -35,    -3, 
     -24,    23,    19,   -23,    20,    24,   -22,     0,     0,     0, 
       0,     0,     0,   -24,    23,    32,   -24,    23,    24,   -39, 
      21,    24,     0,     0,     0,   -49,     0,     0,     0,    39, 
      40,   -28,     0,     0,    41,   -45,   -46,     0,    12,     0, 
     -47,    37,     0,   -51,    36,    -6,    -9,     6,     7,     8, 
       9,    10,    14,   -17,    42,     3,     4,   -27,    19,    30, 
      25,    37,   -50,   -51,     5,   -56, 
};

template<>
const int8 *YACC_parser_tables_t::Tm = &Tm_[0];

// Terminal transition matrix row ...
static const uint8 Tr_[43] = {
      65,    65,    65,    39,     0,    65,    65,    65,    65,    65, 
      65,     9,    39,    10,    65,    10,    10,    10,     1,    65, 
      65,    65,    26,    65,    39,    65,    26,    26,    26,     3, 
      65,    45,    23,     2,    45,    65,    39,    65,    65,    65, 
      65,    65,    65, 
};

template<>
const uint8 *YACC_parser_tables_t::Tr = &Tr_[0];

// Terminal transition matrix column ...
static const uint8 Tc_[27] = {
       9,     9,    10,     0,    11,    15,    19,     1,     2,     3, 
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13, 
      14,    15,    16,    17,    18,    19,    20, 
};

template<>
const uint8 *YACC_parser_tables_t::Tc = &Tc_[0];

// Nonterminal transition matrix ...
static const int8 Nm_[48] = {
       0,     0,     0,     0,    18,   -20,   -19,    17,    28,   -18, 
      16,    27,   -18,   -58,   -31,   -55,   -58,     0,   -54,   -58, 
       0,   -53,    15,    26,   -18,     0,   -30,     0,   -37,     0, 
      34,   -48,    38,    -1,     2,    -5,    13,    22,   -18,    29, 
     -29,    11,   -42,   -38,    31,   -48,    35,     1, 
};

template<>
const int8 *YACC_parser_tables_t::Nm = &Nm_[0];

// Nonterminal transition matrix row ...
static const uint8 Nr_[43] = {
   33,    33,    33,    33,    33,    33,    33,    19,     7,     4, 
    1,    33,    33,    33,    33,    19,     7,     4,    33,    33, 
   33,    19,     1,    33,    33,    33,     1,     1,     1,    19, 
   19,    33,     0,     7,    19,    33,    33,    33,    33,     7, 
    4,     1,    33, 
};

template<>
const uint8 *YACC_parser_tables_t::Nr = &Nr_[0];

// Nonterminal transition matrix column ...
static const uint8 Nc_[59] = {
   14,    14,     0,     0,     1,     1,     1,     2,     2,     2, 
    2,     2,     2,     2,     2,     2,     3,     3,     4,     4, 
    4,     4,     4,     4,     5,     5,     5,     5,     5,     6, 
    6,     6,     6,     6,     6,     7,     8,     8,     8,     8, 
    8,     9,    10,    10,    11,    11,    11,    11,    11,    11, 
   12,    12,    13,    13,    13,    13,    13,    14,    14, 
};

template<>
const uint8 *YACC_parser_tables_t::Nc = &Nc_[0];

// Reduction matrix ...
static const uint8 Rm_[1] = {
       0, 
};

template<>
const uint8 *YACC_parser_tables_t::Rm = &Rm_[0];

// Reduction matrix row ...
static const uint8 Rr_[43] = {
       4,     0,     0,    36,     0,     0,    16,    16,    16,    16, 
      16,     2,     0,     0,     0,     0,     0,     0,    15,     0, 
      44,     0,    10,    25,    26,     0,    11,    12,    13,    14, 
      44,    52,     0,     0,    52,    43,     0,     0,    41,    57, 
      57,    57,     0, 
};

template<>
const uint8 *YACC_parser_tables_t::Rr = &Rr_[0];

// Reduction matrix column ...
static const uint8 Rc_[27] = {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0, 
};

template<>
const uint8 *YACC_parser_tables_t::Rc = &Rc_[0];

// Production lengths (minus one) ...
static const int8 PL_[59] = {
       1,     3,    -1,     0,    -1,     1,     1,     1,     1,     1, 
       2,     2,     2,     2,     2,     1,    -1,     2,     0,     1, 
       2,     0,     1,     2,     0,     0,     0,     1,     1,     0, 
       1,     2,     0,     1,     2,     0,    -1,     2,     1,     0, 
       1,     3,     0,     2,    -1,     1,     1,     1,     1,     1, 
       1,     0,    -1,     2,     2,     2,     1,    -1,     0, 
};

template<>
const int8 *YACC_parser_tables_t::PL = &PL_[0];

template<>
const uint32 *YACC_parser_tables_t::nd_fterm = 0;

template<>
const uint32 *YACC_parser_tables_t::nd_term = 0;

template<>
const uint32 *YACC_parser_tables_t::nd_faction = 0;

template<>
const uint32 *YACC_parser_tables_t::nd_action = 0;

template<>
const uint32 *YACC_parser_tables_t::tact_numb = 0;

template<>
const uint32 *YACC_parser_tables_t::node_numb = 0;

template<>
const uint32 *YACC_parser_tables_t::nact_numb = 0;

template<>
const uint32 *YACC_parser_tables_t::reverse = 0;

