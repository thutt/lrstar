#include "lrstar_basic_defs.h"
#include "lrstar_parser_tables.h"
#include "Typedef_LexerTables_typedef.h"
#include "Typedef_ParserTables_typedef.h"
#include "Typedef_Parser.h"

template<>
const int Typedef_parser_tables_t::n_term_symb = 12;

template<>
const int Typedef_parser_tables_t::n_head_symb = 14;

template<>
const int Typedef_parser_tables_t::n_tact_name = 2;

template<>
const int Typedef_parser_tables_t::n_node_name = 1;

template<>
const int Typedef_parser_tables_t::n_head_numb = 24;

template<>
const int Typedef_parser_tables_t::n_f_tail = 25;

template<>
const int Typedef_parser_tables_t::n_tail = 37;

template<>
const int Typedef_parser_tables_t::n_arga = 12;

template<>
const int Typedef_parser_tables_t::n_argx = 24;

template<>
const int Typedef_parser_tables_t::n_argy = 24;

template<>
const int Typedef_parser_tables_t::n_Bm = 6;

template<>
const int Typedef_parser_tables_t::n_Br = 14;

template<>
const int Typedef_parser_tables_t::n_Bc = 12;

template<>
const int Typedef_parser_tables_t::n_Bf = 12;

template<>
const int Typedef_parser_tables_t::n_Tm = 18;

template<>
const int Typedef_parser_tables_t::n_Tr = 14;

template<>
const int Typedef_parser_tables_t::n_Tc = 12;

template<>
const int Typedef_parser_tables_t::n_Nm = 32;

template<>
const int Typedef_parser_tables_t::n_Nr = 14;

template<>
const int Typedef_parser_tables_t::n_Nc = 24;

template<>
const int Typedef_parser_tables_t::n_Rm = 1;

template<>
const int Typedef_parser_tables_t::n_Rr = 14;

template<>
const int Typedef_parser_tables_t::n_Rc = 12;

template<>
const int Typedef_parser_tables_t::n_PL = 24;

template<>
const int Typedef_parser_tables_t::n_nd_fterm = 0;

template<>
const int Typedef_parser_tables_t::n_nd_term = 0;

template<>
const int Typedef_parser_tables_t::n_nd_faction = 0;

template<>
const int Typedef_parser_tables_t::n_nd_action = 0;

template<>
const int Typedef_parser_tables_t::n_tact_numb = 12;

template<>
const int Typedef_parser_tables_t::n_node_numb = 24;

template<>
const int Typedef_parser_tables_t::n_nact_numb = 24;

template<>
const int Typedef_parser_tables_t::n_reverse = 0;

template<>
const int Typedef_parser_tables_t::n_terms = 12; // Number of terminals.

template<>
const int Typedef_parser_tables_t::n_heads = 14; // Number of nonterminals.

template<>
const int Typedef_parser_tables_t::n_prods = 24; // Number of productions.

template<>
const int Typedef_parser_tables_t::n_states = 14; // Number of states.

template<>
const int Typedef_parser_tables_t::accept_state = 13; // Accept state.

template<>
const int Typedef_parser_tables_t::n_termactns = 2; // Number of terminal actions.

template<>
const int Typedef_parser_tables_t::n_nodenames = 1; // Number of node names.

template<>
const int Typedef_parser_tables_t::n_nodeactns = 1; // Number of node actions.

template<>
const int Typedef_parser_tables_t::eof_symb = 1; // <eof> symbol number.

template<>
const int Typedef_parser_tables_t::err_used = 0; // <error> used in grammar?


// Terminal symbols of the grammar.
static const char *term_symb_[12] = {
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
   "\'unsigned\'",
};

template<>
const char * const *Typedef_parser_tables_t::term_symb = &term_symb_[0];

// Nonterminal symbols of the grammar.
static const char *head_symb_[14] = {
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
   "Ptr*",
};

template<>
const char * const *Typedef_parser_tables_t::head_symb = &head_symb_[0];

// Terninal action names found in the grammar ...
static const char *tact_name_[2] = {
   "error",
   "lookup",
};

template<>
const char * const *Typedef_parser_tables_t::tact_name = &tact_name_[0];

// Node names found in the grammar.
static const char * node_name_[1] = {
   "hello_",

};

template<>
const char * const *Typedef_parser_tables_t::node_name = &node_name_[0];

// Head symbol numbers for the productions.
static const uint8 head_numb_[24] = {
       0,     1,     1,     2,     3,     4,     5,     6,     7,     8, 
       8,     8,     8,     8,     9,     9,    10,    10,    11,    11, 
      12,    12,    13,    13, 
};

template<>
const uint8 *Typedef_parser_tables_t::head_numb = &head_numb_[0];

// First tail symbol index into the tail list ...
static const uint8 f_tail_[25] = {
       0,     2,     5,     9,    10,    11,    13,    15,    16,    17, 
      18,    19,    20,    21,    22,    22,    24,    25,    27,    28, 
      31,    32,    35,    35,    37, 
};

template<>
const uint8 *Typedef_parser_tables_t::f_tail = &f_tail_[0];

// Tail symbol numbers ...
static const int8 tail_[37] = {
      -9,     1,   -10,    -2,     3,     4,   -10,    -3,     3,   -11, 
     -12,   -13,     2,   -13,    -6,     2,     7,     8,     9,    10, 
      11,     6,    -9,    -1,    -8,   -10,    -8,    -4,   -11,     5, 
      -4,    -5,   -12,     5,    -5,   -13,    -7, 
};

template<>
const int8 *Typedef_parser_tables_t::tail = &tail_[0];

// Arguments for token actions ...
static const int8 arga_[12] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1, 
};

template<>
const int8 *Typedef_parser_tables_t::arga = &arga_[0];

// First arguments for productions ...
static const int8 argx_[24] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1, 
};

template<>
const int8 *Typedef_parser_tables_t::argx = &argx_[0];

// Second arguments for productions ...
static const int8 argy_[24] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1, 
};

template<>
const int8 *Typedef_parser_tables_t::argy = &argy_[0];

// Boolean matrix ...
static const uint8 Bm_[6] = {
       0,    34,    32,     8,    16,     4, 
};

template<>
const uint8 *Typedef_parser_tables_t::Bm = &Bm_[0];

// Boolean matrix row (for state)...
static const uint8 Br_[14] = {
       0,     1,     2,     2,     3,     4,     5,     2,     0,     3, 
       4,     5,     0,     0, 
      };

template<>
const uint8 *Typedef_parser_tables_t::Br = &Br_[0];

// Boolean matrix column (displacement) ...
static const uint8 Bc_[12] = {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0, 
      };

template<>
const uint8 *Typedef_parser_tables_t::Bc = &Bc_[0];

// Boolean matrix filter/mask value ...
static const uint8 Bf_[12] = {
       1,     2,     4,     8,     2,    16,    32,     4,    32,    32, 
      32,    32, 
};

template<>
const uint8 *Typedef_parser_tables_t::Bf = &Bf_[0];

// Terminal transition matrix ...
static const int8 Tm_[18] = {
       0,    -7,    -2,     0,    12,     0,    -8,    13,    -5,    -1, 
       3,     8,   -13,    -8,    -9,   -10,   -11,   -12, 
};

template<>
const int8 *Typedef_parser_tables_t::Tm = &Tm_[0];

// Terminal transition matrix row ...
static const uint8 Tr_[14] = {
       7,     7,     7,     7,     7,     7,     7,     7,     7,     0, 
       0,     0,     7,     7, 
};

template<>
const uint8 *Typedef_parser_tables_t::Tr = &Tr_[0];

// Terminal transition matrix column ...
static const uint8 Tc_[12] = {
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8, 
       9,    10, 
};

template<>
const uint8 *Typedef_parser_tables_t::Tc = &Tc_[0];

// Nonterminal transition matrix ...
static const int8 Nm_[32] = {
       0,   -21,   -16,     0,     7,     0,     0,    11,     4,   -18, 
     -17,     0,     0,     5,     0,     6,     9,   -20,   -17,     0, 
       0,     0,    10,    11,   -15,   -19,   -16,     1,     2,    -6, 
     -23,     6, 
};

template<>
const int8 *Typedef_parser_tables_t::Nm = &Nm_[0];

// Nonterminal transition matrix row ...
static const uint8 Nr_[14] = {
   24,    24,     8,     0,    24,    24,    24,    16,    24,    24, 
   24,    24,     0,    24, 
};

template<>
const uint8 *Typedef_parser_tables_t::Nr = &Nr_[0];

// Nonterminal transition matrix column ...
static const uint8 Nc_[24] = {
    0,     0,     0,     0,     0,     1,     1,     5,     6,     2, 
    2,     2,     2,     2,     3,     3,     4,     4,     5,     5, 
    6,     6,     7,     7, 
};

template<>
const uint8 *Typedef_parser_tables_t::Nc = &Nc_[0];

// Reduction matrix ...
static const uint8 Rm_[1] = {
       0, 
};

template<>
const uint8 *Typedef_parser_tables_t::Rm = &Rm_[0];

// Reduction matrix row ...
static const uint8 Rr_[14] = {
      14,     0,    22,     0,     0,     3,     0,    22,    22,     0, 
       4,     0,    22,     0, 
};

template<>
const uint8 *Typedef_parser_tables_t::Rr = &Rr_[0];

// Reduction matrix column ...
static const uint8 Rc_[12] = {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0, 
};

template<>
const uint8 *Typedef_parser_tables_t::Rc = &Rc_[0];

// Production lengths (minus one) ...
static const int8 PL_[24] = {
       1,     2,     3,     0,     0,     1,     1,     0,     0,     0, 
       0,     0,     0,     0,    -1,     1,     0,     1,     0,     2, 
       0,     2,    -1,     1, 
};

template<>
const int8 *Typedef_parser_tables_t::PL = &PL_[0];

template<>
const int32 *Typedef_parser_tables_t::nd_fterm = 0;

template<>
const int32 *Typedef_parser_tables_t::nd_term = 0;

template<>
const int32 *Typedef_parser_tables_t::nd_faction = 0;

template<>
const int32 *Typedef_parser_tables_t::nd_action = 0;

// Terminal action number ...
static const int8 tact_numb_[12] = {
       0,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1, 
};

template<>
const int8 *Typedef_parser_tables_t::tact_numb = &tact_numb_[0];

// Node number for each production ...
static const int8 node_numb_[24] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1, 
};

template<>
const int8 *Typedef_parser_tables_t::node_numb = &node_numb_[0];

// Node action numbers ...
static const int8 nact_numb_[24] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1, 
};

template<>
const int8 *Typedef_parser_tables_t::nact_numb = &nact_numb_[0];

template<>
const int32 *Typedef_parser_tables_t::reverse = 0;

