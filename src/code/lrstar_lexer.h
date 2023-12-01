//
//    DFA Lexer Header

#if !defined(__LRSTAR_LEXER_H__)
#define __LRSTAR_LEXER_H__

#include <assert.h>
#include "lrstar_basic_defs.h"

class Token
{
public:
   char *start;                 // Start of token.
   char *end;                   // End of token (character following token).
   int   sti;                   // Symbol table index.
   int   line;                  // Line number.
};

template<bool C_debug, typename T_term_numb, typename T_Tm, typename T_Tr, typename T_Tc>
class templ_lrstar_lexer
{
private:
    static const int n_term_numb;
    static const int n_Tm;
    static const int n_Tr;
    static const int n_Tc;

    static const T_term_numb *term_numb;
    static const T_Tm        *Tm;
    static const T_Tr        *Tr;
    static const T_Tc        *Tc;

public:
    Token   token;               // Token being read.
    Token   lookahead;           // Lookahead being read.
    int     tab;                 // Tab setting in input file.
    int     linenumb;            // Line number in input file.
    int     linenumb_printed;    // Line number already printed.
    int     lookahead_linenumb;  // Line number in input file.

   void
   init_lexer(char *input_start, int tab_setting)
   {
      linenumb          = 0;
      linenumb_printed  = 0;
      tab               = tab_setting; // Tab.
      token.start       = input_start; // Point at beginning of first line.
      token.end         = input_start; // Point at beginning of first line.
      lookahead.start   = 0;           // Not activated.
      lookahead.end     = 0;           // Not activated.
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
               prt_line();
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
               printf("%6d  %s\n", linenumb, ls);
               fprintf(stderr, "%6d  %s\n", linenumb, ls);
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
