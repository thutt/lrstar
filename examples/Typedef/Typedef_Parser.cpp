#include "lrstar_basic_defs.h"
#include "lrstar_parser_tables.h"
#include "Typedef_LexerTables_typedef.h"
#include "Typedef_ParserTables_typedef.h"
#include "Typedef_Parser.h"

namespace Typedef {
    extern const char * grm_term_symb[12];  /* gcc can elide unreferenced constants. */
    const char * grm_term_symb[12] = {  /* Terminal symbols of the grammar. */
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

    extern const char * grm_head_symb[14];  /* gcc can elide unreferenced constants. */
    const char * grm_head_symb[14] = {  /* Nonterminal symbols of the grammar. */
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

    extern const char * grm_tact_name[2];  /* gcc can elide unreferenced constants. */
    const char * grm_tact_name[2] = {  /* Terminal action names found in the grammar. */
        "error",
        "lookup",
    };

    extern const char * grm_node_name[1];  /* gcc can elide unreferenced constants. */
    const char * grm_node_name[1] = {  /* Node names found in the grammar. */
        "hello_",
    };

    extern const uint8 grm_head_numb[24];  /* gcc can elide unreferenced constants. */
    const uint8 grm_head_numb[24] = {  /* Head symbol numbers for the productions. */

            0,     1,     1,     2,     3,     4,     5,     6,     7,     8, 
            8,     8,     8,     8,     9,     9,    10,    10,    11,    11, 
           12,    12,    13,    13, 
    };

    extern const uint8 grm_f_tail[25];  /* gcc can elide unreferenced constants. */
    const uint8 grm_f_tail[25] = {  /* First tail symbol index into the tail list. */

            0,     2,     5,     9,    10,    11,    13,    15,    16,    17, 
           18,    19,    20,    21,    22,    22,    24,    25,    27,    28, 
           31,    32,    35,    35,    37, 
    };

    extern const int8 grm_tail[37];  /* gcc can elide unreferenced constants. */
    const int8 grm_tail[37] = {  /* Tail symbol numbers. */

           -9,     1,   -10,    -2,     3,     4,   -10,    -3,     3,   -11, 
          -12,   -13,     2,   -13,    -6,     2,     7,     8,     9,    10, 
           11,     6,    -9,    -1,    -8,   -10,    -8,    -4,   -11,     5, 
           -4,    -5,   -12,     5,    -5,   -13,    -7, 
    };

    extern const int8 grm_arga[12];  /* gcc can elide unreferenced constants. */
    const int8 grm_arga[12] = {  /* Arguments for token actions. */

           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1, 
    };

    extern const int8 grm_argx[24];  /* gcc can elide unreferenced constants. */
    const int8 grm_argx[24] = {  /* First arguments for productions. */

           -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1, 
    };

    extern const int8 grm_argy[24];  /* gcc can elide unreferenced constants. */
    const int8 grm_argy[24] = {  /* Second arguments for productions. */

           -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1, 
    };

    extern const uint8 grm_Bm[6];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Bm[6] = {  /* Boolean matrix. */

            0,    34,    32,     8,    16,     4, 
    };

    extern const uint8 grm_Br[14];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Br[14] = {  /* Boolean matrix row (for state). */

            0,     1,     2,     2,     3,     4,     5,     2,     0,     3, 
            4,     5,     0,     0, 
    };

    extern const uint8 grm_Bc[12];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Bc[12] = {  /* Boolean matrix column (displacement). */

            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0, 
    };

    extern const uint8 grm_Bf[12];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Bf[12] = {  /* Boolean matrix filter/mask value. */

            1,     2,     4,     8,     2,    16,    32,     4,    32,    32, 
           32,    32, 
    };

    extern const int8 grm_Tm[18];  /* gcc can elide unreferenced constants. */
    const int8 grm_Tm[18] = {  /* Terminal transition matrix. */

            0,    -7,    -2,     0,    12,     0,    -8,    13,    -5,    -1, 
            3,     8,   -13,    -8,    -9,   -10,   -11,   -12, 
    };

    extern const uint8 grm_Tr[14];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Tr[14] = {  /* Terminal transition matrix row. */

            7,     7,     7,     7,     7,     7,     7,     7,     7,     0, 
            0,     0,     7,     7, 
    };

    extern const uint8 grm_Tc[12];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Tc[12] = {  /* Terminal transition matrix column. */

            0,     0,     1,     2,     3,     4,     5,     6,     7,     8, 
            9,    10, 
    };

    extern const int8 grm_Nm[32];  /* gcc can elide unreferenced constants. */
    const int8 grm_Nm[32] = {  /* Nonterminal transition matrix. */

            0,   -21,   -16,     0,     7,     0,     0,    11,     4,   -18, 
          -17,     0,     0,     5,     0,     6,     9,   -20,   -17,     0, 
            0,     0,    10,    11,   -15,   -19,   -16,     1,     2,    -6, 
          -23,     6, 
    };

    extern const uint8 grm_Nr[14];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Nr[14] = {  /* Nonterminal transition matrix row. */

           24,    24,     8,     0,    24,    24,    24,    16,    24,    24, 
           24,    24,     0,    24, 
    };

    extern const uint8 grm_Nc[24];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Nc[24] = {  /* Nonterminal transition matrix column. */

            0,     0,     0,     0,     0,     1,     1,     5,     6,     2, 
            2,     2,     2,     2,     3,     3,     4,     4,     5,     5, 
            6,     6,     7,     7, 
    };

    extern const uint8 grm_Rm[1];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Rm[1] = {  /* Reduction matrix. */

            0, 
    };

    extern const uint8 grm_Rr[14];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Rr[14] = {  /* Reduction matrix row. */

           14,     0,    22,     0,     0,     3,     0,    22,    22,     0, 
            4,     0,    22,     0, 
    };

    extern const uint8 grm_Rc[12];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Rc[12] = {  /* Reduction matrix column. */

            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0, 
    };

    extern const int8 grm_PL[24];  /* gcc can elide unreferenced constants. */
    const int8 grm_PL[24] = {  /* Production lengths (minus one). */

            1,     2,     3,     0,     0,     1,     1,     0,     0,     0, 
            0,     0,     0,     0,    -1,     1,     0,     1,     0,     2, 
            0,     2,    -1,     1, 
    };

    extern const int8 grm_tact_numb[12];  /* gcc can elide unreferenced constants. */
    const int8 grm_tact_numb[12] = {  /* Terminal action number. */

            0,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1, 
    };

    extern const int8 grm_node_numb[24];  /* gcc can elide unreferenced constants. */
    const int8 grm_node_numb[24] = {  /* Node number for each production. */

           -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1, 
    };

    extern const int8 grm_nact_numb[24];  /* gcc can elide unreferenced constants. */
    const int8 grm_nact_numb[24] = {  /* Node action numbers. */

           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
           -1,    -1,    -1,    -1, 
    };


};   /* namespace Typedef */
