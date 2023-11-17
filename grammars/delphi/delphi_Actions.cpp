#include "lrstar_basic_defs.h"
#include "delphi_LexerTables_typedef.h"
#include "delphi_Actions.h"
#include "lrstar_main.h"


void delphi_init_actions(lrstar_parser *parser)
{
      /* Initialization code goes here */
}

void  delphi_term_actions(lrstar_parser *parser)
{
      /* Termination code goes here */
}


int delphi_error(lrstar_parser *parser, int &t)
{
      if (parser->lt.token.end == parser->lt.token.start)        // Illegal character?
      {
         parser->lt.token.end++;
      }
      return 0;
}

int delphi_lookup(lrstar_parser *parser, int &t)             // Lookup in symbol table.
{
      int sti;
      #ifdef ND_PARSING
      if (parser->lt.lookahead.start > 0)             // In lookahead mode?
      {
         sti = parser->add_symbol(t, parser->lt.lookahead.start, parser->lt.lookahead.end);
      }
      else                                 // Regular mode of parsing.
      #endif
      {
         sti = parser->add_symbol(t, parser->lt.token.start, parser->lt.token.end);
      }
      if (parser->opt_semantics) {
          t = parser->symbol[sti].term;        // Redefine terminal number?
      }
    return sti;
}
