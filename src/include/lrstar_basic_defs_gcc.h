/* Copyright (c) 2023 Logic Magicians Software
 *
 * BSD 3 Clause license.
 */
#if !defined(_LRSTAR_BASIC_DEFS_GCC_H)
#define _LRSTAR_BASIC_DEFS_GCC_H

#if !defined(__GNUC__)
#error This file can only be used with GCC.
#endif


#define LRSTAR_FALLTHROUGH()                    \
   __attribute__((fallthrough))


#define NO_RETURN                               \
   __attribute__((noreturn))

#define UNUSED_PARAM(v_) v_ __attribute__((unused))


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


typedef unsigned char      uint8;
typedef signed char        int8;

#if __SIZEOF_SHORT__ == 2
typedef unsigned short int uint16;
typedef signed short int   int16;
#else
#error A short integer is not 16-bits with this Gcc.
#endif

#if __SIZEOF_INT__ == 4
typedef unsigned int       uint32;
typedef signed int         int32;
#else
#error An integer is not 32-bits with this Gcc.
#endif

#if __SIZEOF_LONG__ == 8
typedef unsigned long int  uint64;
typedef signed long int    int64;
#elif __SIZEOF_LONG_LONG__ == 8
typedef unsigned long long int  uint64;
typedef signed long long int    int64;
#else
#error A long integer is not 64-bits with this Gcc.
#endif

#endif
/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
