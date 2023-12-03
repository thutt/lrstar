/* Copyright (c) 2023 Logic Magicians Software
 *
 * BSD 3 Clause license.
 */
#if !defined(_LRSTAR_BASIC_DEFS_H)
#define _LRSTAR_BASIC_DEFS_H

#include <stdlib.h>
#include <stdio.h>

#if defined(__GNUC__)
#include "lrstar_basic_defs_gcc.h"
#else
#error Compiler not recognized.
#endif

#if defined(_DEBUG)
#define _debug (1)
#else
#define _debug (0)
#endif


#if defined(LRSTAR_LINUX)
   #define lrstar_linux   (1)
   #define lrstar_windows (0)
#elif defined(LRSTAR_WINDOWS)
   #define lrstar_linux   (0)
   #define lrstar_windows (1)
#else
#error The host operating system is not { Linux, Windows }.
#endif


/* COMPILE_TIME_ASSERT
 *
 *  Compile-time assert.  Checks if _expr, which must be a
 *  compile-time constant, is 'true'.  If it evalues to 'false', a
 *  compiler error will result.
 */
#define COMPILE_TIME_ASSERT(_expr)              \
    do {                                        \
        char _cta[(_expr) ? 1 : -1];            \
        (void)_cta;                             \
    } while (0)


#define NOT_IMPLEMENTED()                                       \
    do {                                                        \
        fprintf(stderr, "%s: not implemented\n", __func__);     \
        exit(1);                                                \
    } while (0)



#if !defined(UNREACHABLE_CODE)
#error UNREACHABLE_CODE is not defined.
#endif


#if !defined(LRSTAR_FALLTHROUGH)
#error LRSTAR_FALLTHROUGH is not defined.
#endif


#if !defined(UNUSED_PARAM)
#error UNUSED_PARAM is not defined.
#endif
#endif
/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
