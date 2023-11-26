/* Copyright (c) 2023 Logic Magicians Software
 *
 * BSD 3 Clause license.
 */


#if !defined(_LRSTAR_BASIC_DEFS_H)
#define _LRSTAR_BASIC_DEFS_H
#include <stdlib.h>

#if !defined(__GNUC__)
   #error Compiler not recognized.
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

#if defined(_DEBUG)
#define _debug (1)
#else
#define _debug (0)
#endif


#define LRSTAR_FALLTHROUGH()                    \
   __attribute__((fallthrough))


#define NO_RETURN                               \
   __attribute__((noreturn))


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


#if defined(LRSTAR_DEBUG)
#define lrstar_debug   (1)
#define lrstar_release (0)
#define UNREACHABLE_CODE()                                              \
   do {                                                                 \
      fprintf(stderr, "%s:%d: unreachable code\n", __FILE__, __LINE__); \
      exit(1);                                                          \
   } while (0)
#elif defined(LRSTAR_RELEASE)
#define lrstar_debug   (0)
#define lrstar_release (1)
#define UNREACHABLE_CODE()                      \
   __builtin_unreachable()
#else
#warning Unknown build type; LRSTAR_DEBUG nor LRSTAR_RELEASE set
#error Unable to define UNREACHABLE_CODE.
#endif


#if defined(__GNUC__) && (__GNUC__ >= 9)
typedef unsigned char      uint8;
typedef signed char        int8;

#if __SIZEOF_SHORT__ == 2
typedef unsigned short int uint16;
typedef signed short int   int16;
#else
#error A short integer is not 16-bits with this Gcc.
#endif

#if __SIZEOF_INT__ == 4
typedef unsigned long int  uint32;
typedef signed long int    int32;
#else
#error An integer is not 32-bits with this Gcc.
#endif

#if __SIZEOF_LONG__ == 8
typedef unsigned long int  uint64;
typedef signed long int    int64;
#else
#error A long integer is not 64-bits with this Gcc.
#endif
#else
#error Unknown compiler; Sized integer types not defined.
#endif
#endif
/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
