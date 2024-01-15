#include "lrstar_basic_defs.h"
#include "lrstar_parser_tables.h"
#include "Goodbye_LexerTables_typedef.h"
#include "Goodbye_ParserTables_typedef.h"
#include "Goodbye_Parser.h"

namespace Goodbye {
// Terminal symbols of the grammar.
const char *grm_term_symb[5] = {
   "<error>",
   "<eof>",
   "<identifier>",
   "\'GOODBYE\'",
   "\'.\'",
};

// Nonterminal symbols of the grammar.
const char *grm_head_symb[2] = {
   "Goal",
   "Mumble",
};

// Terninal action names found in the grammar ...
const char *grm_tact_name[2] = {
   "error",
   "lookup",
};

// Node names found in the grammar.
const char *grm_node_name[1] = {
   "goal",

};

// Head symbol numbers for the productions.
const uint8 grm_head_numb[2] = {
       0,     1, 
};

// First tail symbol index into the tail list ...
const uint8 grm_f_tail[3] = {
       0,     2,     5, 
};

// Tail symbol numbers ...
const int8 grm_tail[5] = {
      -1,     1,     3,     2,     4, 
};

// Arguments for token actions ...
const int8 grm_arga[5] = {
      -1,    -1,    -1,    -1,    -1, 
};

// First arguments for productions ...
const int8 grm_argx[2] = {
      -1,    -1, 
};

// Boolean matrix ...
const uint8 grm_Bm[5] = {
       0,     8,     2,     4,    16, 
};

// Boolean matrix row (for state)...
const uint8 grm_Br[5] = {
       1,     2,     3,     4,     0, 
      };

// Boolean matrix column (displacement) ...
extern const uint8 grm_Bc[5];
const uint8 grm_Bc[5] = {
       0,     0,     0,     0,     0, 
      };

// Boolean matrix filter/mask value ...
const uint8 grm_Bf[5] = {
       1,     2,     4,     8,    16, 
};

// Terminal transition matrix ...
const int8 grm_Tm[4] = {
       4,     3,     2,    -1, 
};

// Terminal transition matrix row ...
const uint8 grm_Tr[5] = {
       0,     0,     0,     0,     0, 
};

// Terminal transition matrix column ...
const uint8 grm_Tc[5] = {
       0,     0,     1,     2,     3, 
};

// Nonterminal transition matrix ...
const uint8 grm_Nm[1] = {
       1, 
};

// Nonterminal transition matrix row ...
const uint8 grm_Nr[5] = {
    0,     0,     0,     0,     0, 
};

// Nonterminal transition matrix column ...
const uint8 grm_Nc[2] = {
    0,     0, 
};

// Reduction matrix ...
const uint8 grm_Rm[1] = {
       0, 
};

// Reduction matrix row ...
const uint8 grm_Rr[5] = {
       0,     0,     0,     0,     0, 
};

// Reduction matrix column ...
const uint8 grm_Rc[5] = {
       0,     0,     0,     0,     0, 
};

// Production lengths (minus one) ...
const uint8 grm_PL[2] = {
       1,     2, 
};

// Terminal action number ...
const int8 grm_tact_numb[5] = {
       0,    -1,     1,    -1,    -1, 
};

// Node number for each production ...
const int8 grm_node_numb[2] = {
       0,    -1, 
};

// Node action numbers ...
const int8 grm_nact_numb[2] = {
      -1,    -1, 
};


};   /* namespace Goodbye */
