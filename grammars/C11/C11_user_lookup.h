/* This file is created by lrstar.
 *
 *
 *  NOTE: lrstar will never rewrite or delete this file.
 *        It can be safely edited to add user-supplied code.
 */

int
C11_lookup(C11_parser_t *parser, int &t)
{
   // Lookup in symbol table.

   int sti;

   if (parser->opt_nd_parsing() &&
       parser->lt.lookahead.start != 0) {
      // In lookahead mode.
      sti = parser->add_symbol(t, parser->lt.lookahead.start,
                               parser->lt.lookahead.end);
   } else {
      // Regular mode of parsing
      sti = parser->add_symbol(t, parser->lt.token.start,
                               parser->lt.token.end);
   }

   if (parser->opt_semantics()) {
      // Redefine terminal number?
      t = parser->symbol[sti].term;
   }

   return sti; // Return symbol-table index.
}
