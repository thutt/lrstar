
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "PL1_Actions.h"
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
      if (lexer.token.end == lexer.token.start)        // Illegal character?
      {
         lexer.token.end++;
      }
      return 0;
}

int   lrstar_term_actions::lookup (int& t)             // Lookup in symbol table.
{
      int sti;
      #ifdef ND_PARSING
      if (lexer.lookahead.start > 0)             // In lookahead mode?
      {
         sti = add_symbol (t, lexer.lookahead.start, lexer.lookahead.end);
      }
      else                                 // Regular mode of parsing.
      #endif
      {
         sti = add_symbol (t, lexer.token.start, lexer.token.end);
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

