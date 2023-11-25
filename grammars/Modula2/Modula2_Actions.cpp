
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "Modula2_LexerTables_typedef.h"
#include "Modula2_Parser.h"
#include "lrstar_main.h"


void Modula2_init_actions(Modula2_parser_t *parser)
{
      /* Initialization code goes here */
}

void  Modula2_term_actions(Modula2_parser_t *parser)
{
      /* Termination code goes here */
}


int Modula2_error(Modula2_parser_t *parser, int &t)
{
      if (parser->lt.token.end == parser->lt.token.start)        // Illegal character?
      {
         parser->lt.token.end++;
      }
      return 0;
}

int Modula2_lookup(Modula2_parser_t *parser, int &t)              // Lookup in symbol table.
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


