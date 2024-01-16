#include "lrstar_basic_defs.h"
#include "lrstar_parser_tables.h"
#include "LRK_LexerTables_typedef.h"
#include "LRK_ParserTables_typedef.h"
#include "LRK_Parser.h"

namespace LRK {
    extern const char * grm_term_symb[19];  /* gcc can elide unreferenced constants. */
    const char * grm_term_symb[19] = {  /* Terminal symbols of the grammar. */
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

    extern const char * grm_head_symb[16];  /* gcc can elide unreferenced constants. */
    const char * grm_head_symb[16] = {  /* Nonterminal symbols of the grammar. */
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

    extern const char * grm_tact_name[2];  /* gcc can elide unreferenced constants. */
    const char * grm_tact_name[2] = {  /* Terminal action names found in the grammar. */
        "error",
        "lookup",
    };

    extern const char * grm_node_name[8];  /* gcc can elide unreferenced constants. */
    const char * grm_node_name[8] = {  /* Node names found in the grammar. */
        "goal_",
        "function_decl_",
        "function_def_",
        "type_spec_",
        "function_",
        "arg_",
        "arg_name_",
        "function_body_",
    };

    extern const uint8 grm_head_numb[31];  /* gcc can elide unreferenced constants. */
    const uint8 grm_head_numb[31] = {  /* Head symbol numbers for the productions. */

            0,     1,     2,     3,     4,     5,     5,     5,     5,     5, 
            5,     5,     6,     6,     7,     7,     8,     9,    10,    11, 
           11,    12,    12,    12,    13,    13,    14,    14,    15,    15, 
           15, 
    };

    extern const uint8 grm_f_tail[32];  /* gcc can elide unreferenced constants. */
    const uint8 grm_f_tail[32] = {  /* First tail symbol index into the tail list. */

            0,     2,     6,     7,    13,    21,    22,    23,    24,    25, 
           26,    27,    29,    30,    31,    32,    33,    35,    36,    37, 
           37,    38,    39,    40,    41,    42,    44,    45,    47,    47, 
           48,    51, 
    };

    extern const int8 grm_tail[51];  /* gcc can elide unreferenced constants. */
    const int8 grm_tail[51] = {  /* Tail symbol numbers. */

          -13,     1,     3,   -14,    -2,     4,     2,    -5,    -6,     6, 
          -15,     8,     4,    -5,    -7,     6,   -15,     8,     9,   -11, 
           10,    11,    12,    13,    14,    15,     5,    -5,    16,   -10, 
           17,   -10,    17,    -5,    -9,     2,     2,    18,    -3,    -4, 
           -1,   -12,   -13,   -12,    -5,   -14,    -5,    -8,   -15,     7, 
           -8, 
    };

    extern const int8 grm_arga[19];  /* gcc can elide unreferenced constants. */
    const int8 grm_arga[19] = {  /* Arguments for token actions. */

           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
    };

    extern const int8 grm_argx[31];  /* gcc can elide unreferenced constants. */
    const int8 grm_argx[31] = {  /* First arguments for productions. */

           -1,    -1,     0,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1, 
    };

    extern const int8 grm_argy[31];  /* gcc can elide unreferenced constants. */
    const int8 grm_argy[31] = {  /* Second arguments for productions. */

           -1,    -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1, 
    };

    extern const uint8 grm_Bm[22];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Bm[22] = {  /* Boolean matrix. */

            0,     0,    40,     0,    42,     0,     4,    12,    32,    64, 
            0,    36,     0,    16,   128,     0,     4,     4,     0,     1, 
            0,     2, 
    };

    extern const uint8 grm_Br[23];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Br[23] = {  /* Boolean matrix row (for state). */

            2,     4,     6,     8,     9,     0,     9,     0,    11,     5, 
            8,     8,    13,     5,    14,    16,    14,    13,     8,    18, 
           12,    20,     0, 
    };

    extern const uint8 grm_Bc[19];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Bc[19] = {  /* Boolean matrix column (displacement). */

            0,     0,     0,     0,     0,     0,     0,     0,     0,     1, 
            1,     0,     0,     0,     0,     0,     1,     1,     1, 
    };

    extern const uint8 grm_Bf[19];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Bf[19] = {  /* Boolean matrix filter/mask value. */

            1,     2,     4,     8,    16,    32,    64,   128,   128,     1, 
            2,    32,    32,    32,    32,    32,     4,     8,    16, 
    };

    extern const int8 grm_Tm[39];  /* gcc can elide unreferenced constants. */
    const int8 grm_Tm[39] = {  /* Terminal transition matrix. */

            0,   -17,     0,     0,     0,     0,     0,    -2,     0,    -3, 
          -10,    11,    18,    19,     0,   -11,    -5,    -6,    -7,    -8, 
           -9,    22,   -18,     3,    -1,   -10,    10,    18,    17,    20, 
           -4,    -5,    -6,    -7,    -8,    -9,   -11,     7,   -20, 
    };

    extern const uint8 grm_Tr[23];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Tr[23] = {  /* Terminal transition matrix row. */

           21,    21,    21,    21,    21,    21,     6,    21,     6,    21, 
           21,    21,    21,    21,    21,     0,     6,     6,    21,    21, 
           21,    21,    21, 
    };

    extern const uint8 grm_Tc[19];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Tc[19] = {  /* Terminal transition matrix column. */

            0,     0,     1,     2,     3,     4,     5,     6,     7,     8, 
            9,    10,    11,    12,    13,    14,    15,    16,    17, 
    };

    extern const int8 grm_Nm[33];  /* gcc can elide unreferenced constants. */
    const int8 grm_Nm[33] = {  /* Nonterminal transition matrix. */

            9,    13,    15,    15,    12,   -30,   -29,    15,     0,     8, 
          -29,     2,     0,    14,   -23,     0,     0,    16,   -25,     0, 
          -21,   -22,     2,     4,     6,   -23,   -16,     5,    21,   -24, 
            1,   -21,   -22, 
    };

    extern const uint8 grm_Nr[23];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Nr[23] = {  /* Nonterminal transition matrix row. */

           22,    11,    22,     0,    22,    22,    22,    22,     1,    22, 
            3,     7,    22,    22,    22,    22,    22,    22,     2,    22, 
           22,    22,    22, 
    };

    extern const uint8 grm_Nc[31];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Nc[31] = {  /* Nonterminal transition matrix column. */

            3,     3,     3,     9,    10,     0,     0,     0,     0,     0, 
            0,     0,     1,     1,     2,     2,     3,     4,     5,     6, 
            6,     7,     7,     7,     8,     8,     9,     9,    10,    10, 
           10, 
    };

    extern const uint8 grm_Rm[1];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Rm[1] = {  /* Reduction matrix. */

            0, 
    };

    extern const uint8 grm_Rr[23];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Rr[23] = {  /* Reduction matrix row. */

            0,     0,     0,     0,     0,     0,     0,     0,     0,    26, 
           28,    28,     0,    27,     0,     0,     0,     0,     0,     0, 
           19,     0,     0, 
    };

    extern const uint8 grm_Rc[19];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Rc[19] = {  /* Reduction matrix column. */

            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0, 
    };

    extern const int8 grm_PL[31];  /* gcc can elide unreferenced constants. */
    const int8 grm_PL[31] = {  /* Production lengths (minus one). */

            1,     3,     0,     5,     7,     0,     0,     0,     0,     0, 
            0,     1,     0,     0,     0,     0,     1,     0,     0,    -1, 
            0,     0,     0,     0,     0,     1,     0,     1,    -1,     0, 
            2, 
    };

    extern const uint8 grm_nd_fterm[24];  /* gcc can elide unreferenced constants. */
    const uint8 grm_nd_fterm[24] = {  /* Nondeterministic first terminal in the list. */

            0,     0,     0,     0,     0,     0,     1,     1,     2,     2, 
            2,     2,     2,     2,     2,     2,     2,     2,     2,     2, 
            2,     2,     2,     2, 
    };

    extern const uint8 grm_nd_term[2];  /* gcc can elide unreferenced constants. */
    const uint8 grm_nd_term[2] = {  /* Nondeterministic terminal list. */

            6,     6, 
    };

    extern const uint8 grm_nd_faction[3];  /* gcc can elide unreferenced constants. */
    const uint8 grm_nd_faction[3] = {  /* Nondeterministic first action in the list. */

            0,     2,     4, 
    };

    extern const int8 grm_nd_action[4];  /* gcc can elide unreferenced constants. */
    const int8 grm_nd_action[4] = {  /* Nondeterministic actions list. */

          -12,   -14,   -13,   -15, 
    };

    extern const int8 grm_tact_numb[19];  /* gcc can elide unreferenced constants. */
    const int8 grm_tact_numb[19] = {  /* Terminal action number. */

            0,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
    };

    extern const int8 grm_node_numb[31];  /* gcc can elide unreferenced constants. */
    const int8 grm_node_numb[31] = {  /* Node number for each production. */

            0,    -1,    -1,     1,     2,     3,     3,     3,     3,     3, 
            3,     3,     4,     4,     4,     4,     5,     6,    -1,    -1, 
            7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1, 
    };

    extern const int8 grm_nact_numb[31];  /* gcc can elide unreferenced constants. */
    const int8 grm_nact_numb[31] = {  /* Node action numbers. */

           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1, 
    };


};   /* namespace LRK */
