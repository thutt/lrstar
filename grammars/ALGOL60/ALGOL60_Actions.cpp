
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "ALGOL60_LexerTables_typedef.h"
#include "ALGOL60_Actions.h"
#include "lrstar_main.h"

///////////////////////////////////////////////////////////////////////////////

#ifdef ACTIONS

void ALGOL60_init_actions(lrstar_parser *parser)
{
      /* Initialization code goes here */
}

void  ALGOL60_term_actions(lrstar_parser *parser)
{
      /* Termination code goes here */
}

#endif

///////////////////////////////////////////////////////////////////////////////

#ifdef TERM_ACTIONS

int   lrstar_term_actions::error(lrstar_parser *parser, int &t)
{
      if (lt.token.end == lt.token.start)        // Illegal character?
      {
         lt.token.end++;
      }
      return 0;
}

int   lrstar_term_actions::lookup(lrstar_parser *parser, int &t)             // Lookup in symbol table.
{
      int sti;
      #ifdef ND_PARSING
      if (lt.lookahead.start > 0)             // In lookahead mode?
      {
         sti = add_symbol (t, lt.lookahead.start, lt.lookahead.end);
      }
      else                                 // Regular mode of parsing.
      #endif
      {
         sti = add_symbol (t, lt.token.start, lt.token.end);
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

