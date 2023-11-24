
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "Vba_LexerTables_typedef.h"
#include "Vba_Actions.h"
#include "Vba_Parser.h"
#include "lrstar_main.h"


void Vba_init_actions(Vba_parser_t *parser)
{
      /* Initialization code goes here */
}

void  Vba_term_actions(Vba_parser_t *parser)
{
      /* Termination code goes here */
}


int Vba_error(Vba_parser_t *parser, int &t)
{
      if (parser->lt.token.end == parser->lt.token.start)        // Illegal character?
      {
         parser->lt.token.end++;
      }
      return 0;
}

int Vba_lookup(Vba_parser_t *parser, int &t)              // Lookup in symbol table.
{
      int sti;
      if (parser->opt_nd_parsing() && parser->lt.lookahead.start != 0)             // In lookahead mode?
      {
         sti = parser->add_symbol(t, parser->lt.lookahead.start, parser->lt.lookahead.end);
      } else {                             // Regular mode of parsing.
         sti = parser->add_symbol(t, parser->lt.token.start, parser->lt.token.end);
      }
      if (parser->opt_semantics()) {
         t = parser->symbol[sti].term;        // Redefine terminal number?
      }
    return sti;
}


