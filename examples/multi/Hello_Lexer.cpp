#include "lrstar_basic_defs.h"
#include "lrstar_lexer.h"
#include "Hello_LexerTables_typedef.h"

#define MAX    0x80000000

namespace Hello {
    extern const int8 lgr_term_numb[11];  /* gcc can elide unreferenced constants. */
    const int8 lgr_term_numb[11] = {  /* Terminal number. */

            0,     2,    -1,     2,     2,     2,     2,     3,     4,     1, 
            0, 
    };

    extern const uint8 lgr_Tm[90];  /* gcc can elide unreferenced constants. */
    const uint8 lgr_Tm[90] = {  /* Terminal transition matrix. */

           10,     2,     9,     8,    10,     1,     1,     3,     1,     1, 
            0,     0,     0,     0,     1,     1,     1,     1,     1,     1, 
            0,     2,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     1,     1,     1,     1,     4,     1, 
            0,     0,     0,     0,     1,     1,     5,     1,     1,     1, 
            0,     0,     0,     0,     1,     1,     6,     1,     1,     1, 
            0,     0,     0,     0,     1,     1,     1,     1,     1,     7, 
            0,     0,     0,     0,     1,     1,     1,     1,     1,     1, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
    };

    extern const uint8 lgr_Tr[11];  /* gcc can elide unreferenced constants. */
    const uint8 lgr_Tr[11] = {  /* Terminal transition matrix row. */

            0,    10,    20,    30,    40,    50,    60,    70,    80,    80, 
           80, 
    };

    extern const uint8 lgr_Tc[256];  /* gcc can elide unreferenced constants. */
    const uint8 lgr_Tc[256] = {  /* Terminal transition matrix column. */

            0,     0,     0,     0,     0,     0,     0,     0,     0,     1, 
            1,     1,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     2,     0,     0,     0, 
            0,     0,     1,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     3,     0,     4,     4, 
            4,     4,     4,     4,     4,     4,     4,     4,     0,     0, 
            0,     0,     0,     0,     0,     5,     5,     5,     5,     6, 
            5,     7,     5,     5,     5,     5,     5,     5,     5,     5, 
            5,     5,     8,     5,     9,     5,     5,     5,     5,     5, 
            5,     0,     0,     0,     0,     5,     0,     5,     5,     5, 
            5,     5,     5,     5,     5,     5,     5,     5,     5,     5, 
            5,     5,     5,     5,     5,     5,     5,     5,     5,     5, 
            5,     5,     5,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
            0,     0,     0,     0,     0,     0, 
    };


};   /* namespace Hello */
