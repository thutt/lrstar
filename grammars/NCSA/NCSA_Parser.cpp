#include "lrstar_basic_defs.h"
#include "lrstar_parser_tables.h"
#include "NCSA_LexerTables_typedef.h"
#include "NCSA_ParserTables_typedef.h"
#include "NCSA_Parser.h"

namespace NCSA {
    extern const char * grm_term_symb[24];  /* gcc can elide unreferenced constants. */
    const char * grm_term_symb[24] = {  /* Terminal symbols of the grammar. */
        "<error>",
        "<eof>",
        "<url>",
        "<path>",
        "<file>",
        "<word>",
        "<numb>",
        "<date>",
        "<time>",
        "<query>",
        "<eol>",
        "{Client}",
        "\'-\'",
        "\'[\'",
        "\':\'",
        "{Date}",
        "\']\'",
        "\'+\'",
        "{Path}",
        "{Source}",
        "{Query}",
        "\'(\'",
        "\')\'",
        "\';\'",
    };

    extern const char * grm_head_symb[25];  /* gcc can elide unreferenced constants. */
    const char * grm_head_symb[25] = {  /* Nonterminal symbols of the grammar. */
        "Start",
        "Day",
        "Session",
        "Record",
        "Client",
        "User",
        "Name",
        "Date",
        "Date_",
        "Time",
        "Cmd",
        "Path_",
        "Code",
        "Size",
        "Source",
        "Query",
        "Browser",
        "Thing",
        "ItemList",
        "Day+",
        "Session+",
        "Record+",
        "Name+",
        "<error>+",
        "Thing+",
    };

    extern const char * grm_tact_name[2];  /* gcc can elide unreferenced constants. */
    const char * grm_tact_name[2] = {  /* Terminal action names found in the grammar. */
        "error",
        "lookup",
    };

    extern const char * grm_node_name[11];  /* gcc can elide unreferenced constants. */
    const char * grm_node_name[11] = {  /* Node names found in the grammar. */
        "Report",
        "Day",
        "Client",
        "FullName",
        "Name",
        "Time",
        "File",
        "Code",
        "Size",
        "Source",
        "Query",
    };

    extern const uint8 grm_head_numb[62];  /* gcc can elide unreferenced constants. */
    const uint8 grm_head_numb[62] = {  /* Head symbol numbers for the productions. */

            0,     1,     2,     3,     3,     4,     4,     5,     5,     5, 
            5,     6,     6,     7,     7,     8,     9,     9,    10,    10, 
           10,    10,    10,    11,    12,    13,    13,    14,    14,    14, 
           14,    15,    15,    16,    16,    16,    17,    17,    17,    17, 
           17,    17,    17,    17,    17,    17,    17,    17,    18,    18, 
           19,    19,    20,    20,    21,    21,    22,    22,    23,    23, 
           24,    24, 
    };

    extern const uint8 grm_f_tail[63];  /* gcc can elide unreferenced constants. */
    const uint8 grm_f_tail[63] = {  /* First tail symbol index into the tail list. */

            0,     2,     3,     4,    14,    25,    26,    27,    28,    30, 
           32,    33,    34,    35,    38,    41,    42,    46,    50,    51, 
           54,    57,    60,    63,    64,    65,    66,    67,    68,    69, 
           70,    71,    72,    73,    74,    76,    80,    81,    82,    83, 
           84,    85,    86,    87,    88,    89,    90,    91,    92,    93, 
           96,    97,    99,   100,   102,   103,   105,   106,   108,   109, 
          111,   112,   114, 
    };

    extern const int8 grm_tail[114];  /* gcc can elide unreferenced constants. */
    const int8 grm_tail[114] = {  /* Tail symbol numbers. */

          -19,     1,   -20,   -21,    -4,    -5,    -7,    -9,   -10,   -12, 
          -13,   -14,   -16,    10,    -4,    -5,    -7,    -9,   -10,   -12, 
          -13,   -14,   -15,   -16,    10,     4,    11,    12,    12,    12, 
           12,   -22,   -22,     5,     6,    13,    -8,    14,    13,    15, 
           14,     7,     8,    12,     6,    16,     8,    17,     6,    16, 
           12,     5,   -11,     4,     5,   -11,   -23,     5,    18,     4, 
            5,    18,   -23,     3,     6,    12,     6,    12,     5,     2, 
           19,     9,    20,   -17,   -16,   -17,   -16,    21,   -18,    22, 
            2,     3,     4,     5,     6,     7,     8,     9,     0,    13, 
           16,    12,   -24,   -18,    23,   -24,    -1,   -19,    -1,    -2, 
          -20,    -2,    -3,   -21,    -3,    -6,   -22,    -6,     0,   -23, 
            0,   -17,   -24,   -17, 
    };

    extern const int8 grm_arga[24];  /* gcc can elide unreferenced constants. */
    const int8 grm_arga[24] = {  /* Arguments for token actions. */

           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1, 
    };

    extern const int8 grm_argx[62];  /* gcc can elide unreferenced constants. */
    const int8 grm_argx[62] = {  /* First arguments for productions. */

           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,     0,    -1,    -1,    -1,    -1,     0,     0, 
           -1,     0,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1, 
    };

    extern const int8 grm_argy[62];  /* gcc can elide unreferenced constants. */
    const int8 grm_argy[62] = {  /* Second arguments for productions. */

           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1, 
    };

    extern const uint8 grm_Bm[57];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Bm[57] = {  /* Boolean matrix. */

            0,     0,     0,    16,     8,     0,    18,     8,     0,    96, 
           16,     0,    32,     0,    96,     0,     0,     1,   128,   128, 
            0,    32,    16,     0,    16,     2,     0,    64,     0,     0, 
            8,     0,     4,    64,    16,     0,    17,     0,     0,    36, 
           16,     8,     1,     0,     0,   253,    51,    17,   253,    55, 
            1,   253,    51,     1,     0,     0,    32, 
    };

    extern const uint8 grm_Br[38];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Br[38] = {  /* Boolean matrix row (for state). */

            3,     6,     3,     3,     9,    11,    14,     9,    16,    18, 
           14,    21,    23,    26,    26,    27,    30,    27,    27,    33, 
           36,    36,    15,    15,    39,    42,    42,    45,    48,    51, 
            0,    51,    48,    54,    51,    51,    51,     0, 
    };

    extern const uint8 grm_Bc[24];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Bc[24] = {  /* Boolean matrix column (displacement). */

            0,     0,     0,     0,     0,     0,     0,     0,     1,     1, 
            1,     1,     1,     1,     1,     1,     2,     2,     2,     2, 
            2,     1,     2,     2, 
    };

    extern const uint8 grm_Bf[24];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Bf[24] = {  /* Boolean matrix filter/mask value. */

            1,     2,     4,     8,    16,    32,    64,   128,     1,     2, 
            4,     8,    16,    32,    64,   128,     1,     2,     4,     8, 
           16,     4,    32,    32, 
    };

    extern const int8 grm_Tm[99];  /* gcc can elide unreferenced constants. */
    const int8 grm_Tm[99] = {  /* Terminal transition matrix. */

            0,     0,     0,   -26,    22,     0,     0,   -25,    17,     0, 
            0,    18,   -21,    16,   -24,     0,     0,   -29,   -18,   -28, 
           23,   -58,     0,     0,   -27,   -19,   -11,   -12,     0,   -30, 
            0,    -8,     0,   -17,   -58,     0,     0,   -14,   -36,   -38, 
          -39,   -40,   -41,   -42,    30,   -47,   -45,   -46,   -44,     0, 
          -37,   -32,   -36,   -38,   -39,   -40,   -41,   -42,   -43,   -47, 
          -45,   -46,   -44,     0,   -37,    -3,    31,   -36,   -38,   -39, 
          -40,   -41,   -42,   -43,   -47,   -45,   -46,   -44,     0,   -37, 
           -4,    31,    37,    -5,   -11,   -12,   -15,    12,    -6,     7, 
            9,   -16,   -59,    21,   -23,   -13,    14,   -35,    35, 
    };

    extern const uint8 grm_Tr[38];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Tr[38] = {  /* Terminal transition matrix row. */

           82,    82,    82,    82,    82,    82,    82,    24,    82,    82, 
           82,    11,     1,    82,    24,    11,    82,     1,    17,     0, 
           24,    11,    82,    24,    17,    82,    82,    38,    52,    52, 
           82,    52,    67,    82,    52,    52,    52,    82, 
    };

    extern const uint8 grm_Tc[24];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Tc[24] = {  /* Terminal transition matrix column. */

           10,     0,     0,    12,     1,     2,     3,     4,     5,     6, 
           13,     6,     7,     8,    13,    14,     9,    10,    11,    12, 
           13,    14,    15,    16, 
    };

    extern const int8 grm_Nm[72];  /* gcc can elide unreferenced constants. */
    const int8 grm_Nm[72] = {  /* Nonterminal transition matrix. */

            0,     0,   -55,     4,     0,     0,   -54,     4,     0,   -56, 
            0,     0,     0,     0,   -61,   -60,   -60,    33,     0,    32, 
          -33,     0,    36,    34,     3,    10,     0,   -53,   -54,     4, 
            0,   -57,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,   -34,   -51,     0,     2,     3,     0,    26,   -52, 
          -54,     4,     5,   -56,     8,    13,    11,    15,    20,    19, 
           24,    27,    29,    28,   -33,   -50,     1,     2,     3,     6, 
           25,   -52, 
    };

    extern const uint8 grm_Nr[38];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Nr[38] = {  /* Nonterminal transition matrix row. */

           50,    28,     6,     2,    50,    50,    28,     6,    50,    50, 
           28,    50,    50,    50,    50,    50,    50,    50,    50,    50, 
           50,    28,    50,    50,    50,    50,    50,    50,    28,     6, 
           50,     2,    28,    50,     0,     1,     0,    50, 
    };

    extern const uint8 grm_Nc[62];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Nc[62] = {  /* Nonterminal transition matrix column. */

           15,    15,    21,     0,     0,     1,     1,     2,     2,     2, 
            2,     3,     3,     4,     4,     5,     6,     6,     7,     7, 
            7,     7,     7,     8,     9,    10,    10,    11,    11,    11, 
           11,    12,    12,    13,    13,    13,    14,    14,    14,    14, 
           14,    14,    14,    14,    14,    14,    14,    14,    15,    15, 
           16,    16,    17,    17,    18,    18,    19,    19,    20,    20, 
           21,    21, 
    };

    extern const uint8 grm_Rm[6];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Rm[6] = {  /* Reduction matrix. */

            0,     0,     0,    31,     0,    43, 
    };

    extern const int8 grm_Rr[38];  /* gcc can elide unreferenced constants. */
    const int8 grm_Rr[38] = {  /* Reduction matrix row. */

            0,     0,     1,     2,     0,     0,    10,     7,     0,     0, 
            9,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,    20,    22,     0,     0,     0, 
           -3,     0,     0,     0,    48,     0,    49,     0, 
    };

    extern const uint8 grm_Rc[24];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Rc[24] = {  /* Reduction matrix column. */

            0,     1,     0,     0,     0,     0,     0,     0,     0,     0, 
            2,     1,     0,     0,     1,     1,     0,     1,     1,     1, 
            1,     2,     1,     1, 
    };

    extern const uint8 grm_PL[62];  /* gcc can elide unreferenced constants. */
    const uint8 grm_PL[62] = {  /* Production lengths (minus one). */

            1,     0,     0,     9,    10,     0,     0,     0,     1,     1, 
            0,     0,     0,     2,     2,     0,     3,     3,     0,     2, 
            2,     2,     2,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     1,     3,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     2, 
            0,     1,     0,     1,     0,     1,     0,     1,     0,     1, 
            0,     1, 
    };

    extern const int8 grm_tact_numb[24];  /* gcc can elide unreferenced constants. */
    const int8 grm_tact_numb[24] = {  /* Terminal action number. */

            0,    -1,     1,     1,     1,     1,     1,     1,     1,     1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1, 
    };

    extern const int8 grm_node_numb[62];  /* gcc can elide unreferenced constants. */
    const int8 grm_node_numb[62] = {  /* Node number for each production. */

            0,     1,     2,    -1,    -1,    -1,    -1,    -1,    -1,     3, 
            3,     4,     4,    -1,    -1,    -1,     5,     5,     6,    -1, 
           -1,     6,     6,    -1,     7,     8,     8,    -1,     9,     9, 
            9,    10,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1, 
    };

    extern const int8 grm_nact_numb[62];  /* gcc can elide unreferenced constants. */
    const int8 grm_nact_numb[62] = {  /* Node action numbers. */

           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1, 
    };


};   /* namespace NCSA */
