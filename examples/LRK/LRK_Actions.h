
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "LRK_Parser.h"

#ifdef ACTIONS

class ACTIONS : public PARSER
{
public:
    static void init_actions ();
    static void term_actions ();
};

#endif
#ifdef TERM_ACTIONS

class TERM_ACTIONS : public ACTIONS
{
public:
    static int  error              (int& t);
    static int  lookup      (int& t);
};

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
