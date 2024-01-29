//
//    DFA Lexer Header

#if !defined(__LRSTAR_LEXER_H__)
#define __LRSTAR_LEXER_H__

#include <stdio.h>
#include "lrstar_basic_defs.h"

class Token
{
public:
   char *start;                 // Start of token.
   char *end;                   // End of token (character following token).
   int   sti;                   // Symbol table index.
   int   line;                  // Line number.
   Token(char *input_start) :
      start(input_start),
      end(input_start),
      sti(~0),
      line(~0)
   {
   }
};

template<bool C_debug, typename T_term_numb, typename T_Tm, typename T_Tr, typename T_Tc>
class lrstar_lexer
{
protected:
   const T_term_numb *term_numb;
   const T_Tm        *Tm;
   const T_Tr        *Tr;
   const T_Tc        *Tc;

public:
    Token   token;               // Token being read.
    Token   lookahead;           // Lookahead being read.
    int     linenumb;            // Line number in input file.
    int     linenumb_printed;    // Line number already printed.
    int     lookahead_linenumb;  // Line number in input file.


   lrstar_lexer(
      const T_term_numb *term_numb_,
      const T_Tm        *Tm_,
      const T_Tr        *Tr_,
      const T_Tc        *Tc_,
      char              *input_start) :
      term_numb(term_numb_),
      Tm(Tm_),
      Tr(Tr_),
      Tc(Tc_),
      token(input_start),
      lookahead(0),
      linenumb(0),
      linenumb_printed(0),
      lookahead_linenumb(0)
   {
   }


   int
   get_token()
   {
      int x, y;                     // State, next state.
      do {
         x = 0;
         token.start = token.end;
         token.line  = linenumb;
         while ((y = Tm[Tr[x] +
                        Tc[*reinterpret_cast<uint8 *>(token.end)]]) > 0) {
            x = y;
            if (*token.end == '\n') {
               linenumb++;
#ifdef DEBUG_LEXER
               prt_line();
#endif
            }
            token.end++;
         }
      } while (term_numb[x] < 0);  // Ignore whitespace.
      return term_numb[x];       // Return token_number.
   }


   void
   prt_line()
   {
      if (C_debug) {
         char *ls;
         if (linenumb > linenumb_printed) {
            if (linenumb == 1) {
               printf  (        "\n");
               fprintf (stderr, "\nInput File ...\n\n");
            }

            ls               = token.end + 1;
            linenumb_printed = linenumb;

            if (*ls != 26) {    // Not end of file?
               fprintf(stderr, "%6d  ", linenumb);
               for(; *ls != '\n'; ++ls) {
                   fputc(*ls, stderr);
               }
               fprintf(stderr,"\n");
            }
         }
      }
   }


   int
   get_lookahead()
   {
      int x, y;                     // State, next state.
      do {
         x = 0;
         lookahead.start = lookahead.end;
         lookahead.line  = lookahead_linenumb;
         while ((y = Tm[Tr[x] +
                        Tc[*reinterpret_cast<uint8 *>(lookahead.end)]]) > 0) {
            x = y;
            if (*lookahead.end == '\n') {
               lookahead_linenumb++;
            }
            lookahead.end++;
         }
      } while (term_numb[x] < 0);  // Ignore whitespace.
      return term_numb[x];       // Return token_number.
   }
};
#endif
/* Local Variables:      */
/* mode: c++             */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
