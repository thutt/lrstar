#include "lrstar_basic_defs.h"
#include "lrstar_parser_tables.h"
#include "Goodbye_LexerTables_typedef.h"
#include "Goodbye_ParserTables_typedef.h"
#include "Goodbye_Parser.h"

namespace Goodbye {
    extern const char * grm_term_symb[5];  /* gcc can elide unreferenced constants. */
    const char * grm_term_symb[5] = {  /* Terminal symbols of the grammar. */
        "<error>",
        "<eof>",
        "<identifier>",
        "\'GOODBYE\'",
        "\'.\'",
    };

    extern const char * grm_head_symb[2];  /* gcc can elide unreferenced constants. */
    const char * grm_head_symb[2] = {  /* Nonterminal symbols of the grammar. */
        "Goal",
        "Mumble",
    };

    extern const char * grm_tact_name[2];  /* gcc can elide unreferenced constants. */
    const char * grm_tact_name[2] = {  /* Terminal action names found in the grammar. */
        "error",
        "lookup",
    };

    extern const char * grm_node_name[1];  /* gcc can elide unreferenced constants. */
    const char * grm_node_name[1] = {  /* Node names found in the grammar. */
        "goal",
    };

    extern const uint8 grm_head_numb[2];  /* gcc can elide unreferenced constants. */
    const uint8 grm_head_numb[2] = {  /* Head symbol numbers for the productions. */

            0,     1, 
    };

    extern const uint8 grm_f_tail[3];  /* gcc can elide unreferenced constants. */
    const uint8 grm_f_tail[3] = {  /* First tail symbol index into the tail list. */

            0,     2,     5, 
    };

    extern const int8 grm_tail[5];  /* gcc can elide unreferenced constants. */
    const int8 grm_tail[5] = {  /* Tail symbol numbers. */

           -1,     1,     3,     2,     4, 
    };

    extern const int8 grm_arga[5];  /* gcc can elide unreferenced constants. */
    const int8 grm_arga[5] = {  /* Arguments for token actions. */

           -1,    -1,    -1,    -1,    -1, 
    };

    extern const int8 grm_argx[2];  /* gcc can elide unreferenced constants. */
    const int8 grm_argx[2] = {  /* First arguments for productions. */

           -1,    -1, 
    };

    extern const uint8 grm_Bm[5];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Bm[5] = {  /* Boolean matrix. */

            0,     8,     2,     4,    16, 
    };

    extern const uint8 grm_Br[5];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Br[5] = {  /* Boolean matrix row (for state). */

            1,     2,     3,     4,     0, 
    };

    extern const uint8 grm_Bc[5];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Bc[5] = {  /* Boolean matrix column (displacement). */

            0,     0,     0,     0,     0, 
    };

    extern const uint8 grm_Bf[5];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Bf[5] = {  /* Boolean matrix filter/mask value. */

            1,     2,     4,     8,    16, 
    };

    extern const int8 grm_Tm[4];  /* gcc can elide unreferenced constants. */
    const int8 grm_Tm[4] = {  /* Terminal transition matrix. */

            4,     3,     2,    -1, 
    };

    extern const uint8 grm_Tr[5];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Tr[5] = {  /* Terminal transition matrix row. */

            0,     0,     0,     0,     0, 
    };

    extern const uint8 grm_Tc[5];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Tc[5] = {  /* Terminal transition matrix column. */

            0,     0,     1,     2,     3, 
    };

    extern const uint8 grm_Nm[1];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Nm[1] = {  /* Nonterminal transition matrix. */

            1, 
    };

    extern const uint8 grm_Nr[5];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Nr[5] = {  /* Nonterminal transition matrix row. */

            0,     0,     0,     0,     0, 
    };

    extern const uint8 grm_Nc[2];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Nc[2] = {  /* Nonterminal transition matrix column. */

            0,     0, 
    };

    extern const uint8 grm_Rm[1];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Rm[1] = {  /* Reduction matrix. */

            0, 
    };

    extern const uint8 grm_Rr[5];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Rr[5] = {  /* Reduction matrix row. */

            0,     0,     0,     0,     0, 
    };

    extern const uint8 grm_Rc[5];  /* gcc can elide unreferenced constants. */
    const uint8 grm_Rc[5] = {  /* Reduction matrix column. */

            0,     0,     0,     0,     0, 
    };

    extern const uint8 grm_PL[2];  /* gcc can elide unreferenced constants. */
    const uint8 grm_PL[2] = {  /* Production lengths (minus one). */

            1,     2, 
    };

    extern const int8 grm_tact_numb[5];  /* gcc can elide unreferenced constants. */
    const int8 grm_tact_numb[5] = {  /* Terminal action number. */

            0,    -1,     1,    -1,    -1, 
    };

    extern const int8 grm_node_numb[2];  /* gcc can elide unreferenced constants. */
    const int8 grm_node_numb[2] = {  /* Node number for each production. */

            0,    -1, 
    };

    extern const int8 grm_nact_numb[2];  /* gcc can elide unreferenced constants. */
    const int8 grm_nact_numb[2] = {  /* Node action numbers. */

           -1,    -1, 
    };


};   /* namespace Goodbye */
