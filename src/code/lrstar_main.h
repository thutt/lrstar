
/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//    LRSTAR Main Header

#pragma once
#include <stdio.h>
#include "lrstar_basic_defs.h"

#if defined(LRSTAR_LINUX)
#define _read     read
#define _write    write
#define _open     open
#define _close    close
#define _chmod    chmod
#define _unlink   unlink
#endif

extern FILE *output;
extern void  quit(int rc);

//
////////////////////////////////////////////////////////////////////////////////////////////////////
/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
