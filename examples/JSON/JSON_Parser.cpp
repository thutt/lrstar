#include "lrstar_basic_defs.h"
#include "lrstar_parser_tables.h"
#include "JSON_LexerTables_typedef.h"
#include "JSON_ParserTables_typedef.h"
#include "JSON_Parser.h"

namespace JSON {
    extern const char * grm_term_symb[14];  /* gcc can elide unreferenced constants. */
    const char * grm_term_symb[14] = {  /* Terminal symbols of the grammar. */
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

    extern const char * grm_head_symb[8];  /* gcc can elide unreferenced constants. */
    const char * grm_head_symb[8] = {  /* Nonterminal symbols of the grammar. */
        "Goal",
        "Value",
        "Array",
        "Object",
        "Member",
        "String",
        "Value/','+",
        "Member/','+",
    };

    extern const char * grm_tact_name[2];  /* gcc can elide unreferenced constants. */
    const char * grm_tact_name[2] = {  /* Terminal action names found in the grammar. */
        "error",
        "lookup",
    };

    extern const char * grm_node_name[10];  /* gcc can elide unreferenced constants. */
    const char * grm_node_name[10] = {  /* Node names found in the grammar. */
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

    extern const uint8 grm_head_numb[17];  /* gcc can elide unreferenced constants. */
    const uint8 grm_head_numb[17] = {  /* Head symbol numbers for the productions. */

            0,     1,     1,     1,     1,     1,     1,     1,     1,     2, 
            3,     4,     5,     6,     6,     7,     7, 
    };

    extern const uint8 grm_f_tail[18];  /* gcc can elide unreferenced constants. */
    const uint8 grm_f_tail[18] = {  /* First tail symbol index into the tail list. */

            0,     2,     3,     4,     5,     6,     7,     8,     9,    10, 
           13,    16,    19,    20,    21,    24,    25,    28, 
    };

    extern const int8 grm_tail[28];  /* gcc can elide unreferenced constants. */
    const int8 grm_tail[28] = {  /* Tail symbol numbers. */

           -6,     1,    -2,    -3,     2,     3,     4,     6,     7,     8, 
            9,    -6,    10,    11,    -7,    12,    -5,    13,    -1,     2, 
           -1,    -6,     5,    -1,    -4,    -7,     5,    -4, 
    };

    extern const int8 grm_arga[14];  /* gcc can elide unreferenced constants. */
    const int8 grm_arga[14] = {  /* Arguments for token actions. */

           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1, 
    };

    extern const int8 grm_argx[17];  /* gcc can elide unreferenced constants. */
    const int8 grm_argx[17] = {  /* First arguments for productions. */

           -1,    -1,    -1,     0,     0,     0,    -1,    -1,    -1,    -1, 
           -1,    -1,     0,    -1,    -1,    -1,    -1, 
    };

    extern const uint8 grm_Bm[7];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Bm[7] = {  /* Boolean matrix. */

            0,    12,    18,     4,    48,    80,   128, 
    };

    extern const uint8 grm_Br[11];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Br[11] = {  /* Boolean matrix row (for state). */

            1,     2,     1,     3,     1,     4,     5,     6,     3,     1, 
            0, 
    };

    extern const uint8 grm_Bc[14];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Bc[14] = {  /* Boolean matrix column (displacement). */

            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0, 
    };

    extern const uint8 grm_Bf[14];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Bf[14] = {  /* Boolean matrix filter/mask value. */

            1,     2,     4,     8,     8,    16,     8,     8,     8,     8, 
           32,     8,    64,   128, 
    };

    extern const int8 grm_Tm[23];  /* gcc can elide unreferenced constants. */
    const int8 grm_Tm[23] = {  /* Terminal transition matrix. */

          -12,     0,     0,     8,     0,     0,     0,     0,     0,     0, 
          -10,    -3,    -4,    -5,     4,    -6,    -7,    -8,     2,    -9, 
            3,    10,     9, 
    };

    extern const uint8 grm_Tr[11];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Tr[11] = {  /* Terminal transition matrix row. */

           11,    11,    11,     0,    11,    11,     0,    11,     0,    11, 
           11, 
    };

    extern const uint8 grm_Tc[14];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Tc[14] = {  /* Terminal transition matrix column. */

           10,    10,     0,     1,     2,     3,     4,     5,     6,     7, 
            8,     9,    10,    11, 
    };

    extern const int8 grm_Nm[19];  /* gcc can elide unreferenced constants. */
    const int8 grm_Nm[19] = {  /* Nonterminal transition matrix. */

          -14,    -1,    -2,   -11,    -1,    -2,   -13,    -1,    -2,   -16, 
            7,     5,   -13,    -1,    -2,   -15,     7,     1,     6, 
    };

    extern const uint8 grm_Nr[11];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Nr[11] = {  /* Nonterminal transition matrix row. */

           12,    12,     6,    12,     0,    12,    12,    12,     6,     3, 
           12, 
    };

    extern const uint8 grm_Nc[17];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Nc[17] = {  /* Nonterminal transition matrix column. */

            0,     0,     0,     0,     0,     0,     0,     0,     0,     1, 
            2,     3,     4,     5,     5,     6,     6, 
    };

    extern const uint8 grm_Rm[1];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Rm[1] = {  /* Reduction matrix. */

            0, 
    };

    extern const uint8 grm_Rr[11];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Rr[11] = {  /* Reduction matrix row. */

            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0, 
    };

    extern const uint8 grm_Rc[14];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Rc[14] = {  /* Reduction matrix column. */

            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0, 
    };

    extern const uint8 grm_PL[17];  /* gcc can elide unreferenced constants. */
    const uint8 grm_PL[17] = {  /* Production lengths (minus one). */

            1,     0,     0,     0,     0,     0,     0,     0,     0,     2, 
            2,     2,     0,     0,     2,     0,     2, 
    };

    extern const int8 grm_tact_numb[14];  /* gcc can elide unreferenced constants. */
    const int8 grm_tact_numb[14] = {  /* Terminal action number. */

            0,    -1,     1,     1,     1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1, 
    };

    extern const int8 grm_node_numb[17];  /* gcc can elide unreferenced constants. */
    const int8 grm_node_numb[17] = {  /* Node number for each production. */

            0,    -1,    -1,     1,     2,     3,     4,     5,     6,     7, 
            8,     9,     1,    -1,    -1,    -1,    -1, 
    };

    extern const int8 grm_nact_numb[17];  /* gcc can elide unreferenced constants. */
    const int8 grm_nact_numb[17] = {  /* Node action numbers. */

            0,    -1,    -1,     1,     2,     3,     4,     5,     6,     7, 
            8,     9,     1,    -1,    -1,    -1,    -1, 
    };


};   /* namespace JSON */
