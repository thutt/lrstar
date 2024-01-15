#include "lrstar_basic_defs.h"
#include "lrstar_parser_tables.h"
#include "JSON_LexerTables_typedef.h"
#include "JSON_ParserTables_typedef.h"
#include "JSON_Parser.h"

namespace JSON {
// Terminal symbols of the grammar.
const char *grm_term_symb[14] = {
   "<error>",
   "<eof>",
   "<string>",
   "<integer>",
   "<real>",
   "\',\'",
   "\'null\'",
   "\'false\'",
   "\'true\'",
   "\'[\'",
   "\']\'",
   "\'{\'",
   "\'}\'",
   "\':\'",
};

// Nonterminal symbols of the grammar.
const char *grm_head_symb[8] = {
   "Goal",
   "Value",
   "Array",
   "Object",
   "Member",
   "String",
   "Value/','+",
   "Member/','+",
};

// Terninal action names found in the grammar ...
const char *grm_tact_name[2] = {
   "error",
   "lookup",
};

// Node names found in the grammar.
const char *grm_node_name[10] = {
   "goal_",
   "string_",
   "integer_",
   "real_",
   "null_",
   "false_",
   "true_",
   "array_",
   "object_",
   "member_",

};

// Head symbol numbers for the productions.
const uint8 grm_head_numb[17] = {
       0,     1,     1,     1,     1,     1,     1,     1,     1,     2, 
       3,     4,     5,     6,     6,     7,     7, 
};

// First tail symbol index into the tail list ...
const uint8 grm_f_tail[18] = {
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10, 
      13,    16,    19,    20,    21,    24,    25,    28, 
};

// Tail symbol numbers ...
const int8 grm_tail[28] = {
      -6,     1,    -2,    -3,     2,     3,     4,     6,     7,     8, 
       9,    -6,    10,    11,    -7,    12,    -5,    13,    -1,     2, 
      -1,    -6,     5,    -1,    -4,    -7,     5,    -4, 
};

// Arguments for token actions ...
const int8 grm_arga[14] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1, 
};

// First arguments for productions ...
const int8 grm_argx[17] = {
      -1,    -1,    -1,     0,     0,     0,    -1,    -1,    -1,    -1, 
      -1,    -1,     0,    -1,    -1,    -1,    -1, 
};

// Boolean matrix ...
const uint8 grm_Bm[7] = {
       0,    12,    18,     4,    48,    80,   128, 
};

// Boolean matrix row (for state)...
const uint8 grm_Br[11] = {
       1,     2,     1,     3,     1,     4,     5,     6,     3,     1, 
       0, 
      };

// Boolean matrix column (displacement) ...
extern const uint8 grm_Bc[14];
const uint8 grm_Bc[14] = {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0, 
      };

// Boolean matrix filter/mask value ...
const uint8 grm_Bf[14] = {
       1,     2,     4,     8,     8,    16,     8,     8,     8,     8, 
      32,     8,    64,   128, 
};

// Terminal transition matrix ...
const int8 grm_Tm[23] = {
     -12,     0,     0,     8,     0,     0,     0,     0,     0,     0, 
     -10,    -3,    -4,    -5,     4,    -6,    -7,    -8,     2,    -9, 
       3,    10,     9, 
};

// Terminal transition matrix row ...
const uint8 grm_Tr[11] = {
      11,    11,    11,     0,    11,    11,     0,    11,     0,    11, 
      11, 
};

// Terminal transition matrix column ...
const uint8 grm_Tc[14] = {
      10,    10,     0,     1,     2,     3,     4,     5,     6,     7, 
       8,     9,    10,    11, 
};

// Nonterminal transition matrix ...
const int8 grm_Nm[19] = {
     -14,    -1,    -2,   -11,    -1,    -2,   -13,    -1,    -2,   -16, 
       7,     5,   -13,    -1,    -2,   -15,     7,     1,     6, 
};

// Nonterminal transition matrix row ...
const uint8 grm_Nr[11] = {
   12,    12,     6,    12,     0,    12,    12,    12,     6,     3, 
   12, 
};

// Nonterminal transition matrix column ...
const uint8 grm_Nc[17] = {
    0,     0,     0,     0,     0,     0,     0,     0,     0,     1, 
    2,     3,     4,     5,     5,     6,     6, 
};

// Reduction matrix ...
const uint8 grm_Rm[1] = {
       0, 
};

// Reduction matrix row ...
const uint8 grm_Rr[11] = {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0, 
};

// Reduction matrix column ...
const uint8 grm_Rc[14] = {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0, 
};

// Production lengths (minus one) ...
const uint8 grm_PL[17] = {
       1,     0,     0,     0,     0,     0,     0,     0,     0,     2, 
       2,     2,     0,     0,     2,     0,     2, 
};

// Terminal action number ...
const int8 grm_tact_numb[14] = {
       0,    -1,     1,     1,     1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1, 
};

// Node number for each production ...
const int8 grm_node_numb[17] = {
       0,    -1,    -1,     1,     2,     3,     4,     5,     6,     7, 
       8,     9,     1,    -1,    -1,    -1,    -1, 
};

// Node action numbers ...
const int8 grm_nact_numb[17] = {
       0,    -1,    -1,     1,     2,     3,     4,     5,     6,     7, 
       8,     9,     1,    -1,    -1,    -1,    -1, 
};


};   /* namespace JSON */
