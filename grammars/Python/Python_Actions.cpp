
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "Python_LexerTables_typedef.h"
#include "Python_Actions.h"
#include "Python_Parser.h"
#include "lrstar_main.h"


void Python_init_actions(Python_parser_t *parser)
{
      /* Initialization code goes here */
}

void  Python_term_actions(Python_parser_t *parser)
{
      /* Termination code goes here */
}


int Python_error(Python_parser_t *parser, int &t)
{
      if (parser->lt.token.end == parser->lt.token.start)        // Illegal character?
      {
         parser->lt.token.end++;
      }
      return 0;
}

int Python_lookup(Python_parser_t *parser, int &t)              // Lookup in symbol table.
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


