
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "ANTLR_LexerTables_typedef.h"
#include "ANTLR_Actions.h"
#include "ANTLR_Parser.h"
#include "lrstar_main.h"


void ANTLR_init_actions(ANTLR_parser_t *parser)
{
      /* Initialization code goes here */
}

void  ANTLR_term_actions(ANTLR_parser_t *parser)
{
      /* Termination code goes here */
}


int ANTLR_error(ANTLR_parser_t *parser, int &t)
{
   if (parser->lt.token.end == parser->lt.token.start) {      // Illegal character?
      parser->lt.token.end++;
   }
   return 0;
}

int ANTLR_lookup(ANTLR_parser_t *parser, int &t)              // Lookup in symbol table.
{
   int sti;
   if (parser->opt_nd_parsing() &&
       parser->lt.lookahead.start != 0) {           // In lookahead mode?
       sti = parser->add_symbol(t, parser->lt.lookahead.start, parser->lt.lookahead.end);
   } else {                             // Regular mode of parsing.
       sti = parser->add_symbol(t, parser->lt.token.start, parser->lt.token.end);
   }
   if (parser->opt_semantics()) {
      t = parser->symbol[sti].term;        // Redefine terminal number?
   }
   return sti;
}


