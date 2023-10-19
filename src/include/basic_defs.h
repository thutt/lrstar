/* Copyright (c) 2023 Logic Magicians Software
 *
 * BSD 3 Clause license.
 */


#if !defined(_BASIC_DEFS_H)
#define _BASIC_DEFS_H

#if !defined(__GNUC__)
   #error Compiler not recognized.
#endif

#if defined(__linux)
   #define LRSTAR_LINUX
   #define lrstar_linux   (1)
   #define lrstar_windows (0)
#else
   #undef LRSTAR_LINUX
   #define lrstar_linux   (0)
#endif

#if defined(WINDOWS)
   #define LRSTAR_WINDOWS
   #define lrstar_linux   (0)
   #define lrstar_windows (1)
#endif

#if defined(_DEBUG)
#define _debug (1)
#else
#define _debug (0)
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
    } while (0);


typedef unsigned char       uchar;
typedef unsigned int        uint;
typedef unsigned short int  ushort;


#endif
/* Local Variables:  */
/* mode: c         */
/* c-basic-offset: 3 */
/* tab-width: 3      */
/* End:              */
