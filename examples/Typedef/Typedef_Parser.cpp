#include "lrstar_basic_defs.h"
#include "lrstar_parser_tables.h"
#include "Typedef_LexerTables_typedef.h"
#include "Typedef_ParserTables_typedef.h"
#include "Typedef_Parser.h"

namespace Typedef {
// Terminal symbols of the grammar.
const char *grm_term_symb[12] = {
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

// Nonterminal symbols of the grammar.
const char *grm_head_symb[14] = {
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

// Terninal action names found in the grammar ...
const char *grm_tact_name[2] = {
   "error",
   "lookup",
};

// Node names found in the grammar.
const char *grm_node_name[1] = {
   "hello_",

};

// Head symbol numbers for the productions.
const uint8 grm_head_numb[24] = {
       0,     1,     1,     2,     3,     4,     5,     6,     7,     8, 
       8,     8,     8,     8,     9,     9,    10,    10,    11,    11, 
      12,    12,    13,    13, 
};

// First tail symbol index into the tail list ...
const uint8 grm_f_tail[25] = {
       0,     2,     5,     9,    10,    11,    13,    15,    16,    17, 
      18,    19,    20,    21,    22,    22,    24,    25,    27,    28, 
      31,    32,    35,    35,    37, 
};

// Tail symbol numbers ...
const int8 grm_tail[37] = {
      -9,     1,   -10,    -2,     3,     4,   -10,    -3,     3,   -11, 
     -12,   -13,     2,   -13,    -6,     2,     7,     8,     9,    10, 
      11,     6,    -9,    -1,    -8,   -10,    -8,    -4,   -11,     5, 
      -4,    -5,   -12,     5,    -5,   -13,    -7, 
};

// Arguments for token actions ...
const int8 grm_arga[12] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1, 
};

// First arguments for productions ...
const int8 grm_argx[24] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1, 
};

// Second arguments for productions ...
const int8 grm_argy[24] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1, 
};

// Boolean matrix ...
const uint8 grm_Bm[6] = {
       0,    34,    32,     8,    16,     4, 
};

// Boolean matrix row (for state)...
const uint8 grm_Br[14] = {
       0,     1,     2,     2,     3,     4,     5,     2,     0,     3, 
       4,     5,     0,     0, 
      };

// Boolean matrix column (displacement) ...
extern const uint8 grm_Bc[12];
const uint8 grm_Bc[12] = {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0, 
      };

// Boolean matrix filter/mask value ...
const uint8 grm_Bf[12] = {
       1,     2,     4,     8,     2,    16,    32,     4,    32,    32, 
      32,    32, 
};

// Terminal transition matrix ...
const int8 grm_Tm[18] = {
       0,    -7,    -2,     0,    12,     0,    -8,    13,    -5,    -1, 
       3,     8,   -13,    -8,    -9,   -10,   -11,   -12, 
};

// Terminal transition matrix row ...
const uint8 grm_Tr[14] = {
       7,     7,     7,     7,     7,     7,     7,     7,     7,     0, 
       0,     0,     7,     7, 
};

// Terminal transition matrix column ...
const uint8 grm_Tc[12] = {
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8, 
       9,    10, 
};

// Nonterminal transition matrix ...
const int8 grm_Nm[32] = {
       0,   -21,   -16,     0,     7,     0,     0,    11,     4,   -18, 
     -17,     0,     0,     5,     0,     6,     9,   -20,   -17,     0, 
       0,     0,    10,    11,   -15,   -19,   -16,     1,     2,    -6, 
     -23,     6, 
};

// Nonterminal transition matrix row ...
const uint8 grm_Nr[14] = {
   24,    24,     8,     0,    24,    24,    24,    16,    24,    24, 
   24,    24,     0,    24, 
};

// Nonterminal transition matrix column ...
const uint8 grm_Nc[24] = {
    0,     0,     0,     0,     0,     1,     1,     5,     6,     2, 
    2,     2,     2,     2,     3,     3,     4,     4,     5,     5, 
    6,     6,     7,     7, 
};

// Reduction matrix ...
const uint8 grm_Rm[1] = {
       0, 
};

// Reduction matrix row ...
const uint8 grm_Rr[14] = {
      14,     0,    22,     0,     0,     3,     0,    22,    22,     0, 
       4,     0,    22,     0, 
};

// Reduction matrix column ...
const uint8 grm_Rc[12] = {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0, 
};

// Production lengths (minus one) ...
const int8 grm_PL[24] = {
       1,     2,     3,     0,     0,     1,     1,     0,     0,     0, 
       0,     0,     0,     0,    -1,     1,     0,     1,     0,     2, 
       0,     2,    -1,     1, 
};

// Terminal action number ...
const int8 grm_tact_numb[12] = {
       0,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1, 
};

// Node number for each production ...
const int8 grm_node_numb[24] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1, 
};

// Node action numbers ...
const int8 grm_nact_numb[24] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1, 
};


};   /* namespace Typedef */
