#include "lrstar_basic_defs.h"
#include "lrstar_parser_tables.h"
#include "LRK_LexerTables_typedef.h"
#include "LRK_ParserTables_typedef.h"
#include "LRK_Parser.h"
#include "LRK_Actions.h"

template<>
const int LRK_parser_tables_t::n_term_symb = 19;

template<>
const int LRK_parser_tables_t::n_head_symb = 16;

template<>
const int LRK_parser_tables_t::n_tact_name = 2;

template<>
const int LRK_parser_tables_t::n_node_name = 8;

template<>
const int LRK_parser_tables_t::n_head_numb = 31;

template<>
const int LRK_parser_tables_t::n_f_tail = 32;

template<>
const int LRK_parser_tables_t::n_tail = 51;

template<>
const int LRK_parser_tables_t::n_arga = 19;

template<>
const int LRK_parser_tables_t::n_argx = 31;

template<>
const int LRK_parser_tables_t::n_argy = 31;

template<>
const int LRK_parser_tables_t::n_Bm = 22;

template<>
const int LRK_parser_tables_t::n_Br = 23;

template<>
const int LRK_parser_tables_t::n_Bc = 19;

template<>
const int LRK_parser_tables_t::n_Bf = 19;

template<>
const int LRK_parser_tables_t::n_Tm = 39;

template<>
const int LRK_parser_tables_t::n_Tr = 23;

template<>
const int LRK_parser_tables_t::n_Tc = 19;

template<>
const int LRK_parser_tables_t::n_Nm = 33;

template<>
const int LRK_parser_tables_t::n_Nr = 23;

template<>
const int LRK_parser_tables_t::n_Nc = 31;

template<>
const int LRK_parser_tables_t::n_Rm = 1;

template<>
const int LRK_parser_tables_t::n_Rr = 23;

template<>
const int LRK_parser_tables_t::n_Rc = 19;

template<>
const int LRK_parser_tables_t::n_PL = 31;

template<>
const int LRK_parser_tables_t::n_nd_fterm = 0;

template<>
const int LRK_parser_tables_t::n_nd_term = 0;

template<>
const int LRK_parser_tables_t::n_nd_faction = 0;

template<>
const int LRK_parser_tables_t::n_nd_action = 0;

template<>
const int LRK_parser_tables_t::n_tact_numb = 19;

template<>
const int LRK_parser_tables_t::n_node_numb = 31;

template<>
const int LRK_parser_tables_t::n_nact_numb = 31;

template<>
const int LRK_parser_tables_t::n_reverse = 0;

template<>
const int LRK_parser_tables_t::n_terms = 19; // Number of terminals.

template<>
const int LRK_parser_tables_t::n_heads = 16; // Number of nonterminals.

template<>
const int LRK_parser_tables_t::n_prods = 31; // Number of productions.

template<>
const int LRK_parser_tables_t::n_states = 23; // Number of states.

template<>
const int LRK_parser_tables_t::accept_state = 22; // Accept state.

template<>
const int LRK_parser_tables_t::n_termactns = 2; // Number of terminal actions.

template<>
const int LRK_parser_tables_t::n_nodenames = 8; // Number of node names.

template<>
const int LRK_parser_tables_t::n_nodeactns = 8; // Number of node actions.

template<>
const int LRK_parser_tables_t::eof_symb = 1; // <eof> symbol number.

template<>
const int LRK_parser_tables_t::err_used = 0; // <error> used in grammar?


// Terminal symbols of the grammar.
static const char *term_symb_[19] = {
   "<error>",
   "<eof>",
   "<identifier>",
   "\'typedef\'",
   "\';\'",
   "{typename}",
   "\'(\'",
   "\',\'",
   "\')\'",
   "\'{\'",
   "\'}\'",
   "\'int\'",
   "\'char\'",
   "\'long\'",
   "\'short\'",
   "\'unsigned\'",
   "\'*\'",
   "{function_name}",
   "\'...\'",
};

template<>
const char * const *LRK_parser_tables_t::term_symb = &term_symb_[0];

// Nonterminal symbols of the grammar.
static const char *head_symb_[16] = {
   "Goal",
   "TypedefDecl",
   "TypeIdent",
   "FunctionDecl",
   "FunctionDef",
   "TypeSpec",
   "FuncDecl",
   "FuncDef",
   "Arg",
   "ArgName",
   "FunctionName",
   "FuncBody",
   "(FunctionDecl | FunctionDef | TypedefDecl)",
   "(FunctionDecl | FunctionDef | TypedefDecl)+",
   "TypeSpec+",
   "Arg/','*",
};

template<>
const char * const *LRK_parser_tables_t::head_symb = &head_symb_[0];

// Terninal action names found in the grammar ...
static const char *tact_name_[2] = {
   "error",
   "lookup",
};

template<>
const char * const *LRK_parser_tables_t::tact_name = &tact_name_[0];

// Node names found in the grammar.
static const char * node_name_[8] = {
   "goal_,"   "function_decl_,"   "function_def_,"   "type_spec_,"   "function_,"   "arg_,"   "arg_name_,"   "function_body_,"
};

template<>
const char * const *LRK_parser_tables_t::node_name = &node_name_[0];

// Head symbol numbers for the productions.
static const uint8 head_numb_[31] = {
       0,     1,     2,     3,     4,     5,     5,     5,     5,     5, 
       5,     5,     6,     6,     7,     7,     8,     9,    10,    11, 
      11,    12,    12,    12,    13,    13,    14,    14,    15,    15, 
      15, 
};

template<>
const uint8 *LRK_parser_tables_t::head_numb = &head_numb_[0];

// First tail symbol index into the tail list ...
static const uint8 f_tail_[32] = {
       0,     2,     6,     7,    13,    21,    22,    23,    24,    25, 
      26,    27,    29,    30,    31,    32,    33,    35,    36,    37, 
      37,    38,    39,    40,    41,    42,    44,    45,    47,    47, 
      48,    51, 
};

template<>
const uint8 *LRK_parser_tables_t::f_tail = &f_tail_[0];

// Tail symbol numbers ...
static const int8 tail_[51] = {
     -13,     1,     3,   -14,    -2,     4,     2,    -5,    -6,     6, 
     -15,     8,     4,    -5,    -7,     6,   -15,     8,     9,   -11, 
      10,    11,    12,    13,    14,    15,     5,    -5,    16,   -10, 
      17,   -10,    17,    -5,    -9,     2,     2,    18,    -3,    -4, 
      -1,   -12,   -13,   -12,    -5,   -14,    -5,    -8,   -15,     7, 
      -8, 
};

template<>
const int8 *LRK_parser_tables_t::tail = &tail_[0];

// Arguments for token actions ...
static const int8 arga_[19] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
};

template<>
const int8 *LRK_parser_tables_t::arga = &arga_[0];

// First arguments for productions ...
static const int8 argx_[31] = {
      -1,    -1,     0,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1, 
};

template<>
const int8 *LRK_parser_tables_t::argx = &argx_[0];

// Second arguments for productions ...
static const int8 argy_[31] = {
      -1,    -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1, 
};

template<>
const int8 *LRK_parser_tables_t::argy = &argy_[0];

// Boolean matrix ...
static const uint8 Bm_[22] = {
       0,     0,    40,     0,    42,     0,     4,    12,    32,    64, 
       0,    36,     0,    16,   128,     0,     4,     4,     0,     1, 
       0,     2, 
};

template<>
const uint8 *LRK_parser_tables_t::Bm = &Bm_[0];

// Boolean matrix row (for state)...
static const uint8 Br_[23] = {
       2,     4,     6,     8,     9,     0,     9,     0,    11,     5, 
       8,     8,    13,     5,    14,    16,    14,    13,     8,    18, 
      12,    20,     0, 
      };

template<>
const uint8 *LRK_parser_tables_t::Br = &Br_[0];

// Boolean matrix column (displacement) ...
static const uint8 Bc_[19] = {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1, 
       1,     0,     0,     0,     0,     0,     1,     1,     1, 
      };

template<>
const uint8 *LRK_parser_tables_t::Bc = &Bc_[0];

// Boolean matrix filter/mask value ...
static const uint8 Bf_[19] = {
       1,     2,     4,     8,    16,    32,    64,   128,   128,     1, 
       2,    32,    32,    32,    32,    32,     4,     8,    16, 
};

template<>
const uint8 *LRK_parser_tables_t::Bf = &Bf_[0];

// Terminal transition matrix ...
static const int8 Tm_[39] = {
       0,   -17,     0,     0,     0,     0,     0,    -2,     0,    -3, 
     -10,    11,    18,    19,     0,   -11,    -5,    -6,    -7,    -8, 
      -9,    22,   -18,     3,    -1,   -10,    10,    18,    17,    20, 
      -4,    -5,    -6,    -7,    -8,    -9,   -11,     7,   -20, 
};

template<>
const int8 *LRK_parser_tables_t::Tm = &Tm_[0];

// Terminal transition matrix row ...
static const uint8 Tr_[23] = {
      21,    21,    21,    21,    21,    21,     6,    21,     6,    21, 
      21,    21,    21,    21,    21,     0,     6,     6,    21,    21, 
      21,    21,    21, 
};

template<>
const uint8 *LRK_parser_tables_t::Tr = &Tr_[0];

// Terminal transition matrix column ...
static const uint8 Tc_[19] = {
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8, 
       9,    10,    11,    12,    13,    14,    15,    16,    17, 
};

template<>
const uint8 *LRK_parser_tables_t::Tc = &Tc_[0];

// Nonterminal transition matrix ...
static const int8 Nm_[33] = {
       9,    13,    15,    15,    12,   -30,   -29,    15,     0,     8, 
     -29,     2,     0,    14,   -23,     0,     0,    16,   -25,     0, 
     -21,   -22,     2,     4,     6,   -23,   -16,     5,    21,   -24, 
       1,   -21,   -22, 
};

template<>
const int8 *LRK_parser_tables_t::Nm = &Nm_[0];

// Nonterminal transition matrix row ...
static const uint8 Nr_[23] = {
   22,    11,    22,     0,    22,    22,    22,    22,     1,    22, 
    3,     7,    22,    22,    22,    22,    22,    22,     2,    22, 
   22,    22,    22, 
};

template<>
const uint8 *LRK_parser_tables_t::Nr = &Nr_[0];

// Nonterminal transition matrix column ...
static const uint8 Nc_[31] = {
    3,     3,     3,     9,    10,     0,     0,     0,     0,     0, 
    0,     0,     1,     1,     2,     2,     3,     4,     5,     6, 
    6,     7,     7,     7,     8,     8,     9,     9,    10,    10, 
   10, 
};

template<>
const uint8 *LRK_parser_tables_t::Nc = &Nc_[0];

// Reduction matrix ...
static const uint8 Rm_[1] = {
       0, 
};

template<>
const uint8 *LRK_parser_tables_t::Rm = &Rm_[0];

// Reduction matrix row ...
static const uint8 Rr_[23] = {
       0,     0,     0,     0,     0,    12,     0,    13,     0,    26, 
      28,    28,     0,    27,     0,     0,     0,     0,     0,     0, 
      19,     0,     0, 
};

template<>
const uint8 *LRK_parser_tables_t::Rr = &Rr_[0];

// Reduction matrix column ...
static const uint8 Rc_[19] = {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0, 
};

template<>
const uint8 *LRK_parser_tables_t::Rc = &Rc_[0];

// Production lengths (minus one) ...
static const int8 PL_[31] = {
       1,     3,     0,     5,     7,     0,     0,     0,     0,     0, 
       0,     1,     0,     0,     0,     0,     1,     0,     0,    -1, 
       0,     0,     0,     0,     0,     1,     0,     1,    -1,     0, 
       2, 
};

template<>
const int8 *LRK_parser_tables_t::PL = &PL_[0];

template<>
const uint32 *LRK_parser_tables_t::nd_fterm = 0;

template<>
const uint32 *LRK_parser_tables_t::nd_term = 0;

template<>
const uint32 *LRK_parser_tables_t::nd_faction = 0;

template<>
const uint32 *LRK_parser_tables_t::nd_action = 0;

// Terminal action number ...
static const int8 tact_numb_[19] = {
       0,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
};

template<>
const int8 *LRK_parser_tables_t::tact_numb = &tact_numb_[0];

// Node number for each production ...
static const int8 node_numb_[31] = {
       0,    -1,    -1,     1,     2,     3,     3,     3,     3,     3, 
       3,     3,     4,     4,     4,     4,     5,     6,    -1,    -1, 
       7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1, 
};

template<>
const int8 *LRK_parser_tables_t::node_numb = &node_numb_[0];

// Node action numbers ...
static const int8 nact_numb_[31] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1, 
};

template<>
const int8 *LRK_parser_tables_t::nact_numb = &nact_numb_[0];

template<>
const uint32 *LRK_parser_tables_t::reverse = 0;

void LRK_init_actions(lrstar_parser *parser); /* User-supplied */
void LRK_term_actions(lrstar_parser *parser); /* User-supplied */
static init_func_t LRK_init_funcs_[2] = {
   LRK_init_actions,
   LRK_term_actions
};

// Init action function pointers ...
template<>
init_func_t *LRK_parser_tables_t::init_func = &LRK_init_funcs_[0];

int LRK_error(lrstar_parser *parser, int &t);
int LRK_lookup(lrstar_parser *parser, int &t);
// Terminal action function pointers ...
static tact_func_t LRK_tact_funcs_[2] = {
   LRK_error,
   LRK_lookup,
};

// Terminal action function pointers ...
template<>
tact_func_t *LRK_parser_tables_t::tact_func = &LRK_tact_funcs_[0];

// Node action function pointers ...
static nact_func_t LRK_nact_func_[8] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
};

// Node action function pointers ...
template<>
nact_func_t *LRK_parser_tables_t::nact_func = &LRK_nact_func_[0];


//                                                                           //
///////////////////////////////////////////////////////////////////////////////

