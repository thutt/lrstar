
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "LRK_LexerTables_typedef.h"
#include "LRK_Actions.h"
#include "lrstar_main.h"

///////////////////////////////////////////////////////////////////////////////

#ifdef ACTIONS

void  lrstar_parser_actions::init_actions(void *parser)
{
   /* Initialization code goes here */
}

void  lrstar_parser_actions::term_actions(void *parser)
{
   /* Termination code goes here */
}

#endif

///////////////////////////////////////////////////////////////////////////////

#ifdef TERM_ACTIONS

int   lrstar_term_actions::error(void *parser, int &t)
{
   if (lt.token.end == lt.token.start) // Illegal character?
   {
      lt.token.end++;
   }
   return 0;
}

int   lrstar_term_actions::lookup(void *parser, int &t)       // Lookup in symbol table.
{
   int sti;
#ifdef ND_PARSING
   if (lt.lookahead.start != 0)              // In lookahead mode?
   {
      sti = add_symbol (t, lt.lookahead.start, lt.lookahead.end);
   }
   else                                   // Regular mode of parsing.
#endif
   {
      sti = add_symbol (t, lt.token.start, lt.token.end);
   }
#ifdef SEMANTICS
   t = symbol[sti].term;                  // Redefine terminal number?
#endif
   return sti;                            // Return symbol-table index.
}

#endif

///////////////////////////////////////////////////////////////////////////////

#ifdef NODE_ACTIONS

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
