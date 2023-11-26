#include "lrstar_basic_defs.h"
#include "lrstar_parser_tables.h"
#include "Calc_LexerTables_typedef.h"
#include "Calc_ParserTables_typedef.h"
#include "Calc_Parser.h"

template<>
const int Calc_parser_tables_t::n_term_symb = 22;

template<>
const int Calc_parser_tables_t::n_head_symb = 13;

template<>
const int Calc_parser_tables_t::n_tact_name = 2;

template<>
const int Calc_parser_tables_t::n_node_name = 17;

template<>
const int Calc_parser_tables_t::n_head_numb = 26;

template<>
const int Calc_parser_tables_t::n_f_tail = 27;

template<>
const int Calc_parser_tables_t::n_tail = 61;

template<>
const int Calc_parser_tables_t::n_arga = 22;

template<>
const int Calc_parser_tables_t::n_argx = 26;

template<>
const int Calc_parser_tables_t::n_argy = 0;

template<>
const int Calc_parser_tables_t::n_Bm = 30;

template<>
const int Calc_parser_tables_t::n_Br = 36;

template<>
const int Calc_parser_tables_t::n_Bc = 22;

template<>
const int Calc_parser_tables_t::n_Bf = 22;

template<>
const int Calc_parser_tables_t::n_Tm = 33;

template<>
const int Calc_parser_tables_t::n_Tr = 36;

template<>
const int Calc_parser_tables_t::n_Tc = 22;

template<>
const int Calc_parser_tables_t::n_Nm = 47;

template<>
const int Calc_parser_tables_t::n_Nr = 36;

template<>
const int Calc_parser_tables_t::n_Nc = 26;

template<>
const int Calc_parser_tables_t::n_Rm = 5;

template<>
const int Calc_parser_tables_t::n_Rr = 36;

template<>
const int Calc_parser_tables_t::n_Rc = 22;

template<>
const int Calc_parser_tables_t::n_PL = 26;

template<>
const int Calc_parser_tables_t::n_nd_fterm = 0;

template<>
const int Calc_parser_tables_t::n_nd_term = 0;

template<>
const int Calc_parser_tables_t::n_nd_faction = 0;

template<>
const int Calc_parser_tables_t::n_nd_action = 0;

template<>
const int Calc_parser_tables_t::n_tact_numb = 22;

template<>
const int Calc_parser_tables_t::n_node_numb = 26;

template<>
const int Calc_parser_tables_t::n_nact_numb = 26;

template<>
const int Calc_parser_tables_t::n_reverse = 26;

template<>
const int Calc_parser_tables_t::n_terms = 22; // Number of terminals.

template<>
const int Calc_parser_tables_t::n_heads = 13; // Number of nonterminals.

template<>
const int Calc_parser_tables_t::n_prods = 26; // Number of productions.

template<>
const int Calc_parser_tables_t::n_states = 36; // Number of states.

template<>
const int Calc_parser_tables_t::accept_state = 35; // Accept state.

template<>
const int Calc_parser_tables_t::n_termactns = 2; // Number of terminal actions.

template<>
const int Calc_parser_tables_t::n_nodenames = 17; // Number of node names.

template<>
const int Calc_parser_tables_t::n_nodeactns = 17; // Number of node actions.

template<>
const int Calc_parser_tables_t::eof_symb = 1; // <eof> symbol number.

template<>
const int Calc_parser_tables_t::err_used = 0; // <error> used in grammar?


// Terminal symbols of the grammar.
static const char *term_symb_[22] = {
   "<error>",
   "<eof>",
   "<identifier>",
   "<integer>",
   "\'==\'",
   "\'!=\'",
   "\'+\'",
   "\'-\'",
   "\'*\'",
   "\'/\'",
   "\'^\'",
   "\'program\'",
   "\'{\'",
   "\'}\'",
   "\'=\'",
   "\';\'",
   "\'if\'",
   "\'endif\'",
   "\'(\'",
   "\')\'",
   "\'then\'",
   "\'else\'",
};

template<>
const char * const *Calc_parser_tables_t::term_symb = &term_symb_[0];

// Nonterminal symbols of the grammar.
static const char *head_symb_[13] = {
   "Goal",
   "Program",
   "Stmt",
   "Target",
   "RelExp",
   "Exp",
   "Primary",
   "Then",
   "Then2",
   "Else2",
   "Program*",
   "Stmt*",
   "Stmt+",
};

template<>
const char * const *Calc_parser_tables_t::head_symb = &head_symb_[0];

// Terninal action names found in the grammar ...
static const char *tact_name_[2] = {
   "error",
   "lookup",
};

template<>
const char * const *Calc_parser_tables_t::tact_name = &tact_name_[0];

// Node names found in the grammar.
static const char * node_name_[17] = {
   "goal_,"
   "program_,"
   "store_,"
   "if_,"
   "target_,"
   "eq_,"
   "ne_,"
   "add_,"
   "sub_,"
   "mul_,"
   "div_,"
   "pwr_,"
   "int_,"
   "ident_,"
   "then_,"
   "then2_,"
   "else2_,"

};

template<>
const char * const *Calc_parser_tables_t::node_name = &node_name_[0];

// Head symbol numbers for the productions.
static const uint8 head_numb_[26] = {
       0,     1,     2,     2,     2,     3,     4,     4,     5,     5, 
       5,     5,     5,     5,     6,     6,     6,     7,     8,     9, 
      10,    10,    11,    11,    12,    12, 
};

template<>
const uint8 *Calc_parser_tables_t::head_numb = &head_numb_[0];

// First tail symbol index into the tail list ...
static const uint8 f_tail_[27] = {
       0,     2,     7,    11,    15,    20,    21,    24,    27,    28, 
      31,    34,    37,    40,    43,    44,    45,    48,    50,    52, 
      54,    54,    56,    56,    58,    59,    61, 
};

template<>
const uint8 *Calc_parser_tables_t::f_tail = &f_tail_[0];

// Tail symbol numbers ...
static const int8 tail_[61] = {
     -10,     1,    11,     2,    12,   -11,    13,    -3,    14,    -5, 
      15,    16,    -4,    -7,    17,    16,    -4,    -8,    -9,    17, 
       2,    -5,     4,    -5,    -5,     5,    -5,    -6,    -5,     6, 
      -5,    -5,     7,    -5,    -5,     8,    -5,    -5,     9,    -5, 
      -5,    10,    -5,     3,     2,    18,    -5,    19,    20,   -12, 
      20,   -12,    21,   -12,   -10,    -1,   -11,    -2,    -2,   -12, 
      -2, 
};

template<>
const int8 *Calc_parser_tables_t::tail = &tail_[0];

// Arguments for token actions ...
static const int8 arga_[22] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1, 
};

template<>
const int8 *Calc_parser_tables_t::arga = &arga_[0];

// First arguments for productions ...
static const int8 argx_[26] = {
      -1,     1,    -1,    -1,    -1,     0,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,     0,     0,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1, 
};

template<>
const int8 *Calc_parser_tables_t::argx = &argx_[0];

template<>
const int32 *Calc_parser_tables_t::argy = 0;

// Boolean matrix ...
static const uint8 Bm_[30] = {
       0,     0,     2,     0,     4,     0,     0,     1,     4,    18, 
      12,     0,   128,   240,     0,   224,     8,     0,    32,     4, 
      16,   224,    64,   224,     0,   192,     0,   128,     0,     0, 
};

template<>
const uint8 *Calc_parser_tables_t::Bm = &Bm_[0];

// Boolean matrix row (for state)...
static const uint8 Br_[36] = {
       0,     2,     4,     6,     0,     8,     3,    10,    10,    11, 
      13,    10,    15,    17,     5,    19,    10,    10,    10,    10, 
      10,    10,    10,    21,    17,    19,    19,    23,    23,    25, 
      25,    27,    27,    27,    19,     0, 
      };

template<>
const uint8 *Calc_parser_tables_t::Br = &Br_[0];

// Boolean matrix column (displacement) ...
static const uint8 Bc_[22] = {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     1,     1,     1,     1,     1,     1,     0,     1, 
       1,     2, 
      };

template<>
const uint8 *Calc_parser_tables_t::Bc = &Bc_[0];

// Boolean matrix filter/mask value ...
static const uint8 Bf_[22] = {
       1,     2,     4,     8,    16,    16,    32,    32,    64,    64, 
     128,     2,     1,     2,     4,     8,    16,    32,     8,    64, 
     128,     1, 
};

template<>
const uint8 *Calc_parser_tables_t::Bf = &Bf_[0];

// Terminal transition matrix ...
static const int8 Tm_[33] = {
     -15,     0,     0,    -5,     0,     0,     0,     0,   -14,     0, 
       0,    -1,     0,    11,     7,    -4,     3,    18,    19,    20, 
      21,    22,     2,     4,    35,     8,    -2,    16,    -3,    17, 
     -16,    15,    25, 
};

template<>
const int8 *Calc_parser_tables_t::Tm = &Tm_[0];

// Terminal transition matrix row ...
static const uint8 Tr_[36] = {
      16,    16,    16,    16,    16,     3,    16,     0,     0,    16, 
      16,     0,    16,    16,    16,     3,     0,     0,     0,     0, 
       0,     0,     0,    16,     3,     3,     3,    16,    16,    16, 
      16,    16,    16,    16,     3,    16, 
};

template<>
const uint8 *Calc_parser_tables_t::Tr = &Tr_[0];

// Terminal transition matrix column ...
static const uint8 Tc_[22] = {
       8,     8,     0,     8,    11,    13,     1,     2,     3,     4, 
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14, 
      15,    16, 
};

template<>
const uint8 *Calc_parser_tables_t::Tc = &Tc_[0];

// Nonterminal transition matrix ...
static const int8 Nm_[47] = {
       0,     0,     0,    28,    -8,    29,    -8,    30,    -8,    31, 
      -8,    32,    -8,    33,    -8,   -25,     6,     0,    27,    -8, 
     -24,     6,     0,    12,    -8,   -24,     6,     0,    23,    -8, 
      26,     0,     0,     0,     0,    34,   -23,     6,     9,    10, 
      -8,    13,    14,    24,     1,     5,   -21, 
};

template<>
const int8 *Calc_parser_tables_t::Nm = &Nm_[0];

// Nonterminal transition matrix row ...
static const uint8 Nr_[36] = {
   36,    36,    36,    36,    36,    36,    36,    36,    20,    36, 
   36,    25,    36,    36,    36,    20,    15,     0,     2,     4, 
    6,     8,    10,    36,    36,    25,    15,    36,    36,    36, 
   36,    36,    36,    36,    15,    36, 
};

template<>
const uint8 *Calc_parser_tables_t::Nr = &Nr_[0];

// Nonterminal transition matrix column ...
static const uint8 Nc_[26] = {
   10,    10,     0,     0,     0,     1,     2,     2,     3,     3, 
    3,     3,     3,     3,     4,     4,     4,     5,     6,     7, 
    8,     8,     9,     9,    10,    10, 
};

template<>
const uint8 *Calc_parser_tables_t::Nc = &Nc_[0];

// Reduction matrix ...
static const uint8 Rm_[5] = {
       0,     0,     0,    17,    18, 
};

template<>
const uint8 *Calc_parser_tables_t::Rm = &Rm_[0];

// Reduction matrix row ...
static const int8 Rr_[36] = {
      20,     0,     0,     0,    22,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,    -2,     6,     7,     9, 
      10,    11,    12,    13,    19,     0, 
};

template<>
const int8 *Calc_parser_tables_t::Rr = &Rr_[0];

// Reduction matrix column ...
static const uint8 Rc_[22] = {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     1,     0,     0, 
       0,     2, 
};

template<>
const uint8 *Calc_parser_tables_t::Rc = &Rc_[0];

// Production lengths (minus one) ...
static const int8 PL_[26] = {
       1,     4,     3,     3,     4,     0,     2,     2,     0,     2, 
       2,     2,     2,     2,     0,     0,     2,     1,     1,     1, 
      -1,     1,    -1,     1,     0,     1, 
};

template<>
const int8 *Calc_parser_tables_t::PL = &PL_[0];

template<>
const int32 *Calc_parser_tables_t::nd_fterm = 0;

template<>
const int32 *Calc_parser_tables_t::nd_term = 0;

template<>
const int32 *Calc_parser_tables_t::nd_faction = 0;

template<>
const int32 *Calc_parser_tables_t::nd_action = 0;

// Terminal action number ...
static const int8 tact_numb_[22] = {
       0,    -1,     1,     1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1, 
};

template<>
const int8 *Calc_parser_tables_t::tact_numb = &tact_numb_[0];

// Node number for each production ...
static const int8 node_numb_[26] = {
       0,     1,     2,     3,     3,     4,     5,     6,    -1,     7, 
       8,     9,    10,    11,    12,    13,    -1,    14,    15,    16, 
      -1,    -1,    -1,    -1,    -1,    -1, 
};

template<>
const int8 *Calc_parser_tables_t::node_numb = &node_numb_[0];

// Node action numbers ...
static const int8 nact_numb_[26] = {
       0,     1,     2,     3,     3,     4,     5,     6,    -1,     7, 
       8,     9,    10,    11,    12,    13,    -1,    14,    15,    16, 
      -1,    -1,    -1,    -1,    -1,    -1, 
};

template<>
const int8 *Calc_parser_tables_t::nact_numb = &nact_numb_[0];

// Reverse the order of nodes ...
static const uint8 reverse_[26] = {
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0, 
};

template<>
const uint8 *Calc_parser_tables_t::reverse = &reverse_[0];

