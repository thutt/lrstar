#include "lrstar_basic_defs.h"
#include "lrstar_parser_tables.h"
#include "Calc_LexerTables_typedef.h"
#include "Calc_ParserTables_typedef.h"
#include "Calc_Parser.h"

namespace Calc {
    extern const char * grm_term_symb[22];  /* gcc can elide unreferenced constants. */
    const char * grm_term_symb[22] = {  /* Terminal symbols of the grammar. */
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

    extern const char * grm_head_symb[13];  /* gcc can elide unreferenced constants. */
    const char * grm_head_symb[13] = {  /* Nonterminal symbols of the grammar. */
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

    extern const char * grm_tact_name[2];  /* gcc can elide unreferenced constants. */
    const char * grm_tact_name[2] = {  /* Terminal action names found in the grammar. */
        "error",
        "lookup",
    };

    extern const char * grm_node_name[17];  /* gcc can elide unreferenced constants. */
    const char * grm_node_name[17] = {  /* Node names found in the grammar. */
        "goal_",
        "program_",
        "store_",
        "if_",
        "target_",
        "eq_",
        "ne_",
        "add_",
        "sub_",
        "mul_",
        "div_",
        "pwr_",
        "int_",
        "ident_",
        "then_",
        "then2_",
        "else2_",
    };

    extern const uint8 grm_head_numb[26];  /* gcc can elide unreferenced constants. */
    const uint8 grm_head_numb[26] = {  /* Head symbol numbers for the productions. */

            0,     1,     2,     2,     2,     3,     4,     4,     5,     5, 
            5,     5,     5,     5,     6,     6,     6,     7,     8,     9, 
           10,    10,    11,    11,    12,    12, 
    };

    extern const uint8 grm_f_tail[27];  /* gcc can elide unreferenced constants. */
    const uint8 grm_f_tail[27] = {  /* First tail symbol index into the tail list. */

            0,     2,     7,    11,    15,    20,    21,    24,    27,    28, 
           31,    34,    37,    40,    43,    44,    45,    48,    50,    52, 
           54,    54,    56,    56,    58,    59,    61, 
    };

    extern const int8 grm_tail[61];  /* gcc can elide unreferenced constants. */
    const int8 grm_tail[61] = {  /* Tail symbol numbers. */

          -10,     1,    11,     2,    12,   -11,    13,    -3,    14,    -5, 
           15,    16,    -4,    -7,    17,    16,    -4,    -8,    -9,    17, 
            2,    -5,     4,    -5,    -5,     5,    -5,    -6,    -5,     6, 
           -5,    -5,     7,    -5,    -5,     8,    -5,    -5,     9,    -5, 
           -5,    10,    -5,     3,     2,    18,    -5,    19,    20,   -12, 
           20,   -12,    21,   -12,   -10,    -1,   -11,    -2,    -2,   -12, 
           -2, 
    };

    extern const int8 grm_arga[22];  /* gcc can elide unreferenced constants. */
    const int8 grm_arga[22] = {  /* Arguments for token actions. */

           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1, 
    };

    extern const int8 grm_argx[26];  /* gcc can elide unreferenced constants. */
    const int8 grm_argx[26] = {  /* First arguments for productions. */

           -1,     1,    -1,    -1,    -1,     0,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,     0,     0,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1, 
    };

    extern const uint8 grm_Bm[30];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Bm[30] = {  /* Boolean matrix. */

            0,     0,     2,     0,     4,     0,     0,     1,     4,    18, 
           12,     0,   128,   240,     0,   224,     8,     0,    32,     4, 
           16,   224,    64,   224,     0,   192,     0,   128,     0,     0, 
    };

    extern const uint8 grm_Br[36];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Br[36] = {  /* Boolean matrix row (for state). */

            0,     2,     4,     6,     0,     8,     3,    10,    10,    11, 
           13,    10,    15,    17,     5,    19,    10,    10,    10,    10, 
           10,    10,    10,    21,    17,    19,    19,    23,    23,    25, 
           25,    27,    27,    27,    19,     0, 
    };

    extern const uint8 grm_Bc[22];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Bc[22] = {  /* Boolean matrix column (displacement). */

            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     1,     1,     1,     1,     1,     1,     0,     1, 
            1,     2, 
    };

    extern const uint8 grm_Bf[22];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Bf[22] = {  /* Boolean matrix filter/mask value. */

            1,     2,     4,     8,    16,    16,    32,    32,    64,    64, 
          128,     2,     1,     2,     4,     8,    16,    32,     8,    64, 
          128,     1, 
    };

    extern const int8 grm_Tm[33];  /* gcc can elide unreferenced constants. */
    const int8 grm_Tm[33] = {  /* Terminal transition matrix. */

          -15,     0,     0,    -5,     0,     0,     0,     0,   -14,     0, 
            0,    -1,     0,    11,     7,    -4,     3,    18,    19,    20, 
           21,    22,     2,     4,    35,     8,    -2,    16,    -3,    17, 
          -16,    15,    25, 
    };

    extern const uint8 grm_Tr[36];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Tr[36] = {  /* Terminal transition matrix row. */

           16,    16,    16,    16,    16,     3,    16,     0,     0,    16, 
           16,     0,    16,    16,    16,     3,     0,     0,     0,     0, 
            0,     0,     0,    16,     3,     3,     3,    16,    16,    16, 
           16,    16,    16,    16,     3,    16, 
    };

    extern const uint8 grm_Tc[22];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Tc[22] = {  /* Terminal transition matrix column. */

            8,     8,     0,     8,    11,    13,     1,     2,     3,     4, 
            5,     6,     7,     8,     9,    10,    11,    12,    13,    14, 
           15,    16, 
    };

    extern const int8 grm_Nm[47];  /* gcc can elide unreferenced constants. */
    const int8 grm_Nm[47] = {  /* Nonterminal transition matrix. */

            0,     0,     0,    28,    -8,    29,    -8,    30,    -8,    31, 
           -8,    32,    -8,    33,    -8,   -25,     6,     0,    27,    -8, 
          -24,     6,     0,    12,    -8,   -24,     6,     0,    23,    -8, 
           26,     0,     0,     0,     0,    34,   -23,     6,     9,    10, 
           -8,    13,    14,    24,     1,     5,   -21, 
    };

    extern const uint8 grm_Nr[36];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Nr[36] = {  /* Nonterminal transition matrix row. */

           36,    36,    36,    36,    36,    36,    36,    36,    20,    36, 
           36,    25,    36,    36,    36,    20,    15,     0,     2,     4, 
            6,     8,    10,    36,    36,    25,    15,    36,    36,    36, 
           36,    36,    36,    36,    15,    36, 
    };

    extern const uint8 grm_Nc[26];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Nc[26] = {  /* Nonterminal transition matrix column. */

           10,    10,     0,     0,     0,     1,     2,     2,     3,     3, 
            3,     3,     3,     3,     4,     4,     4,     5,     6,     7, 
            8,     8,     9,     9,    10,    10, 
    };

    extern const uint8 grm_Rm[5];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Rm[5] = {  /* Reduction matrix. */

            0,     0,     0,    17,    18, 
    };

    extern const int8 grm_Rr[36];  /* gcc can elide unreferenced constants. */
    const int8 grm_Rr[36] = {  /* Reduction matrix row. */

           20,     0,     0,     0,    22,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,    -2,     6,     7,     9, 
           10,    11,    12,    13,    19,     0, 
    };

    extern const uint8 grm_Rc[22];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Rc[22] = {  /* Reduction matrix column. */

            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     1,     0,     0, 
            0,     2, 
    };

    extern const int8 grm_PL[26];  /* gcc can elide unreferenced constants. */
    const int8 grm_PL[26] = {  /* Production lengths (minus one). */

            1,     4,     3,     3,     4,     0,     2,     2,     0,     2, 
            2,     2,     2,     2,     0,     0,     2,     1,     1,     1, 
           -1,     1,    -1,     1,     0,     1, 
    };

    extern const int8 grm_tact_numb[22];  /* gcc can elide unreferenced constants. */
    const int8 grm_tact_numb[22] = {  /* Terminal action number. */

            0,    -1,     1,     1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1, 
    };

    extern const int8 grm_node_numb[26];  /* gcc can elide unreferenced constants. */
    const int8 grm_node_numb[26] = {  /* Node number for each production. */

            0,     1,     2,     3,     3,     4,     5,     6,    -1,     7, 
            8,     9,    10,    11,    12,    13,    -1,    14,    15,    16, 
           -1,    -1,    -1,    -1,    -1,    -1, 
    };

    extern const int8 grm_nact_numb[26];  /* gcc can elide unreferenced constants. */
    const int8 grm_nact_numb[26] = {  /* Node action numbers. */

            0,     1,     2,     3,     3,     4,     5,     6,    -1,     7, 
            8,     9,    10,    11,    12,    13,    -1,    14,    15,    16, 
           -1,    -1,    -1,    -1,    -1,    -1, 
    };

    extern const uint8 grm_reverse[26];  /* gcc can elide unreferenced constants. */
    const uint8 grm_reverse[26] = {  /* Reverse the order of nodes. */

            0,     0,     1,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0, 
    };


};   /* namespace Calc */
