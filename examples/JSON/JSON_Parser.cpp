#include "lrstar_basic_defs.h"
#include "lrstar_parser_tables.h"
#include "JSON_LexerTables_typedef.h"
#include "JSON_ParserTables_typedef.h"
#include "JSON_Parser.h"

template<>
const int JSON_parser_tables_t::n_term_symb = 13;

template<>
const int JSON_parser_tables_t::n_head_symb = 12;

template<>
const int JSON_parser_tables_t::n_tact_name = 2;

template<>
const int JSON_parser_tables_t::n_node_name = 10;

template<>
const int JSON_parser_tables_t::n_head_numb = 20;

template<>
const int JSON_parser_tables_t::n_f_tail = 21;

template<>
const int JSON_parser_tables_t::n_tail = 31;

template<>
const int JSON_parser_tables_t::n_arga = 13;

template<>
const int JSON_parser_tables_t::n_argx = 20;

template<>
const int JSON_parser_tables_t::n_argy = 0;

template<>
const int JSON_parser_tables_t::n_Bm = 7;

template<>
const int JSON_parser_tables_t::n_Br = 11;

template<>
const int JSON_parser_tables_t::n_Bc = 13;

template<>
const int JSON_parser_tables_t::n_Bf = 13;

template<>
const int JSON_parser_tables_t::n_Tm = 18;

template<>
const int JSON_parser_tables_t::n_Tr = 11;

template<>
const int JSON_parser_tables_t::n_Tc = 13;

template<>
const int JSON_parser_tables_t::n_Nm = 39;

template<>
const int JSON_parser_tables_t::n_Nr = 11;

template<>
const int JSON_parser_tables_t::n_Nc = 20;

template<>
const int JSON_parser_tables_t::n_Rm = 1;

template<>
const int JSON_parser_tables_t::n_Rr = 11;

template<>
const int JSON_parser_tables_t::n_Rc = 13;

template<>
const int JSON_parser_tables_t::n_PL = 20;

template<>
const int JSON_parser_tables_t::n_nd_fterm = 0;

template<>
const int JSON_parser_tables_t::n_nd_term = 0;

template<>
const int JSON_parser_tables_t::n_nd_faction = 0;

template<>
const int JSON_parser_tables_t::n_nd_action = 0;

template<>
const int JSON_parser_tables_t::n_tact_numb = 13;

template<>
const int JSON_parser_tables_t::n_node_numb = 20;

template<>
const int JSON_parser_tables_t::n_nact_numb = 20;

template<>
const int JSON_parser_tables_t::n_reverse = 0;

template<>
const int JSON_parser_tables_t::n_terms = 13; // Number of terminals.

template<>
const int JSON_parser_tables_t::n_heads = 12; // Number of nonterminals.

template<>
const int JSON_parser_tables_t::n_prods = 20; // Number of productions.

template<>
const int JSON_parser_tables_t::n_states = 11; // Number of states.

template<>
const int JSON_parser_tables_t::accept_state = 10; // Accept state.

template<>
const int JSON_parser_tables_t::n_termactns = 2; // Number of terminal actions.

template<>
const int JSON_parser_tables_t::n_nodenames = 10; // Number of node names.

template<>
const int JSON_parser_tables_t::n_nodeactns = 10; // Number of node actions.

template<>
const int JSON_parser_tables_t::eof_symb = 1; // <eof> symbol number.

template<>
const int JSON_parser_tables_t::err_used = 0; // <error> used in grammar?


// Terminal symbols of the grammar.
static const char *term_symb_[13] = {
   "<error>",
   "<eof>",
   "<string>",
   "<constant>",
   "\',\'",
   "\'[\'",
   "\']\'",
   "\'{\'",
   "\'}\'",
   "\':\'",
   "\'null\'",
   "\'true\'",
   "\'false\'",
};

template<>
const char * const *JSON_parser_tables_t::term_symb = &term_symb_[0];

// Nonterminal symbols of the grammar.
static const char *head_symb_[12] = {
   "Goal",
   "Array",
   "Object",
   "Member",
   "String",
   "Constant",
   "Null",
   "True",
   "False",
   "Value",
   "Value/','+",
   "Member/','+",
};

template<>
const char * const *JSON_parser_tables_t::head_symb = &head_symb_[0];

// Terninal action names found in the grammar ...
static const char *tact_name_[2] = {
   "error",
   "lookup",
};

template<>
const char * const *JSON_parser_tables_t::tact_name = &tact_name_[0];

// Node names found in the grammar.
static const char * node_name_[10] = {
   "goal_",
   "array_",
   "object_",
   "member_",
   "string_",
   "constant_",
   "null_",
   "true_",
   "false_",
   "value_",

};

template<>
const char * const *JSON_parser_tables_t::node_name = &node_name_[0];

// Head symbol numbers for the productions.
static const uint8 head_numb_[20] = {
       0,     1,     2,     3,     4,     5,     6,     7,     8,     9, 
       9,     9,     9,     9,     9,     9,    10,    10,    11,    11, 
};

template<>
const uint8 *JSON_parser_tables_t::head_numb = &head_numb_[0];

// First tail symbol index into the tail list ...
static const uint8 f_tail_[21] = {
       0,     2,     5,     8,    11,    12,    13,    14,    15,    16, 
      17,    18,    19,    20,    21,    22,    23,    24,    27,    28, 
      31, 
};

template<>
const uint8 *JSON_parser_tables_t::f_tail = &f_tail_[0];

// Tail symbol numbers ...
static const int8 tail_[31] = {
     -10,     1,     5,   -10,     6,     7,   -11,     8,     2,     9, 
      -9,     2,     3,    10,    11,    12,    -1,    -2,    -4,    -5, 
      -6,    -8,    -7,    -9,   -10,     4,    -9,    -3,   -11,     4, 
      -3, 
};

template<>
const int8 *JSON_parser_tables_t::tail = &tail_[0];

// Arguments for token actions ...
static const int8 arga_[13] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1, 
};

template<>
const int8 *JSON_parser_tables_t::arga = &arga_[0];

// First arguments for productions ...
static const int8 argx_[20] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
};

template<>
const int8 *JSON_parser_tables_t::argx = &argx_[0];

template<>
const int32 *JSON_parser_tables_t::argy = 0;

// Boolean matrix ...
static const uint8 Bm_[7] = {
       0,    12,    18,     4,    48,    80,   128, 
};

template<>
const uint8 *JSON_parser_tables_t::Bm = &Bm_[0];

// Boolean matrix row (for state)...
static const uint8 Br_[11] = {
       1,     2,     1,     3,     1,     4,     5,     6,     3,     1, 
       0, 
      };

template<>
const uint8 *JSON_parser_tables_t::Br = &Br_[0];

// Boolean matrix column (displacement) ...
static const uint8 Bc_[13] = {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0, 
      };

template<>
const uint8 *JSON_parser_tables_t::Bc = &Bc_[0];

// Boolean matrix filter/mask value ...
static const uint8 Bf_[13] = {
       1,     2,     4,     8,    16,     8,    32,     8,    64,   128, 
       8,     8,     8, 
};

template<>
const uint8 *JSON_parser_tables_t::Bf = &Bf_[0];

// Terminal transition matrix ...
static const int8 Tm_[18] = {
       7,     0,     8,     0,     0,     0,    -2,    -4,    -5,     4, 
       2,    -1,     3,    10,     9,    -6,    -7,    -8, 
};

template<>
const int8 *JSON_parser_tables_t::Tm = &Tm_[0];

// Terminal transition matrix row ...
static const uint8 Tr_[11] = {
       7,     7,     7,     0,     7,     7,     0,     7,     0,     7, 
       7, 
};

template<>
const uint8 *JSON_parser_tables_t::Tr = &Tr_[0];

// Terminal transition matrix column ...
static const uint8 Tc_[13] = {
       6,     6,     0,     1,     2,     3,     4,     5,     6,     7, 
       8,     9,    10, 
};

template<>
const uint8 *JSON_parser_tables_t::Tc = &Tc_[0];

// Nonterminal transition matrix ...
static const int8 Nm_[39] = {
      -9,   -10,     0,   -11,   -12,   -13,   -15,   -14,   -17,    -9, 
     -10,     0,   -11,   -12,   -13,   -15,   -14,    -3,    -9,   -10, 
     -19,   -11,   -12,   -13,   -15,   -14,   -16,     5,    -9,   -10, 
     -18,   -11,   -12,   -13,   -15,   -14,   -16,     1,     6, 
};

template<>
const int8 *JSON_parser_tables_t::Nm = &Nm_[0];

// Nonterminal transition matrix row ...
static const uint8 Nr_[11] = {
   28,    28,    18,    28,     0,    28,    28,    28,    18,     9, 
   28, 
};

template<>
const uint8 *JSON_parser_tables_t::Nr = &Nr_[0];

// Nonterminal transition matrix column ...
static const uint8 Nc_[20] = {
    0,     0,     1,     2,     3,     4,     5,     6,     7,     8, 
    8,     8,     8,     8,     8,     8,     9,     9,    10,    10, 
};

template<>
const uint8 *JSON_parser_tables_t::Nc = &Nc_[0];

// Reduction matrix ...
static const uint8 Rm_[1] = {
       0, 
};

template<>
const uint8 *JSON_parser_tables_t::Rm = &Rm_[0];

// Reduction matrix row ...
static const uint8 Rr_[11] = {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0, 
};

template<>
const uint8 *JSON_parser_tables_t::Rr = &Rr_[0];

// Reduction matrix column ...
static const uint8 Rc_[13] = {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0, 
};

template<>
const uint8 *JSON_parser_tables_t::Rc = &Rc_[0];

// Production lengths (minus one) ...
static const uint8 PL_[20] = {
       1,     2,     2,     2,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     2,     0,     2, 
};

template<>
const uint8 *JSON_parser_tables_t::PL = &PL_[0];

template<>
const int32 *JSON_parser_tables_t::nd_fterm = 0;

template<>
const int32 *JSON_parser_tables_t::nd_term = 0;

template<>
const int32 *JSON_parser_tables_t::nd_faction = 0;

template<>
const int32 *JSON_parser_tables_t::nd_action = 0;

// Terminal action number ...
static const int8 tact_numb_[13] = {
       0,    -1,     1,     1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1, 
};

template<>
const int8 *JSON_parser_tables_t::tact_numb = &tact_numb_[0];

// Node number for each production ...
static const int8 node_numb_[20] = {
       0,     1,     2,     3,     4,     5,     6,     7,     8,    -1, 
      -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1, 
};

template<>
const int8 *JSON_parser_tables_t::node_numb = &node_numb_[0];

// Node action numbers ...
static const int8 nact_numb_[20] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
};

template<>
const int8 *JSON_parser_tables_t::nact_numb = &nact_numb_[0];

template<>
const int32 *JSON_parser_tables_t::reverse = 0;

