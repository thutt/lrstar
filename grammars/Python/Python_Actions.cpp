
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "Python_Actions.h"
#include "lrstar_main.h"

///////////////////////////////////////////////////////////////////////////////

#ifdef ACTIONS

void  lrstar_parser_actions::init_actions ()
{
      /* Initialization code goes here */
}

void  lrstar_parser_actions::term_actions ()
{
      /* Termination code goes here */
}

#endif

///////////////////////////////////////////////////////////////////////////////

#ifdef TERM_ACTIONS

int   lrstar_term_actions::error (int& t)
{
      if (token.end == token.start)        // Illegal character?
      {
         token.end++;
      }
      return 0;
}

int   lrstar_term_actions::lookup (int& t)             // Lookup in symbol table.
{
      int sti;
      #ifdef ND_PARSING
      if (lookahead.start > 0)             // In lookahead mode?
      {
         sti = add_symbol (t, lookahead.start, lookahead.end);
      }
      else                                 // Regular mode of parsing.
      #endif
      {
         sti = add_symbol (t, token.start, token.end);
      }
      #ifdef SEMANTICS
      t = symbol[sti].term;                // Redefine terminal number?
      #endif
    return sti;
}

#endif

///////////////////////////////////////////////////////////////////////////////

#ifdef NODE_ACTIONS



#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

