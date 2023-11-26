/* This file is created by lrstar.
 *
 *
 *  NOTE: lrstar will never rewrite or delete this file.
 *        It can be safely edited to add user-supplied code.
 */

int
LRK_error(UNUSED_PARAM(LRK_parser_t *parser), UNUSED_PARAM(int &t))
{
   if (parser->lt.token.end == parser->lt.token.start) {
      // An illegal character.
      parser->lt.token.end++;
   }
   return 0;
}
