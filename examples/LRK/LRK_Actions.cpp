
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "LRK_LexerTables_typedef.h"
#include "LRK_Actions.h"
#include "LRK_Parser.h"
#include "lrstar_main.h"


void LRK_init_actions(LRK_parser_t *parser)
{
      /* Initialization code goes here */
}

void  LRK_term_actions(LRK_parser_t *parser)
{
      /* Termination code goes here */
}


int LRK_error(LRK_parser_t *parser, int &t)
{
      if (parser->lt.token.end == parser->lt.token.start)        // Illegal character?
      {
         parser->lt.token.end++;
      }
      return 0;
}

int LRK_lookup(LRK_parser_t *parser, int &t)              // Lookup in symbol table.
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


