
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "Java9_LexerTables_typedef.h"
#include "Java9_Actions.h"
#include "Java9_Parser.h"
#include "lrstar_main.h"


void Java9_init_actions(Java9_parser_t *parser)
{
      /* Initialization code goes here */
}

void  Java9_term_actions(Java9_parser_t *parser)
{
      /* Termination code goes here */
}


int Java9_error(Java9_parser_t *parser, int &t)
{
      if (parser->lt.token.end == parser->lt.token.start)        // Illegal character?
      {
         parser->lt.token.end++;
      }
      return 0;
}

int Java9_lookup(Java9_parser_t *parser, int &t)              // Lookup in symbol table.
{
      int sti;
      if (parser->opt_nd_parsing && parser->lt.lookahead.start != 0)             // In lookahead mode?
      {
         sti = parser->add_symbol(t, parser->lt.lookahead.start, parser->lt.lookahead.end);
      } else {                             // Regular mode of parsing.
         sti = parser->add_symbol(t, parser->lt.token.start, parser->lt.token.end);
      }
      if (parser->opt_semantics) {
         t = parser->symbol[sti].term;        // Redefine terminal number?
      }
    return sti;
}


