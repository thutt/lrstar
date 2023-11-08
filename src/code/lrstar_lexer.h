//
//    DFA Lexer Header

#pragma once
#include <assert.h>
#include "lrstar_basic_defs.h"
#include "lrstar_library_defs.h"

class Token
{
public:
   char *start;                 // Start of token.
   char *end;                   // End of token (character following token).
   int   sti;                   // Symbol table index.
   int   line;                  // Line number.
};

class lrstar_lexer
{
public:
   static Token   token;               // Token being read.
   static Token   lookahead;           // Lookahead being read.
   static int     tab;                 // Tab setting in input file.
   static int     linenumb;            // Line number in input file.
   static int     linenumb_printed;    // Line number already printed.
   static int     lookahead_linenumb;  // Line number in input file.

   static void    init_lexer (char* input_start, int tab);
   static int     get_token ();
   static int     get_lookahead ();
   static void    prt_line ();
   static char*   untabify (char* ls);
   static char*   untabify (char* ls, char*& token);
};

/* templ_lrstar_lexer
 *
 *  This template is intended to be used to replace the suboptimal
 *  lrstar_lexer class.  Initially it will be fully static, like
 *  lrstar_lexer, but it will be converted to only non-static after
 *  the lrstar system is updated to use it.
 */

template<typename T_term_numb, typename T_Tm, typename T_Tr, typename T_Tc>
class templ_lrstar_lexer
{
private:
    static const int n_term_numb;
    static const int n_Tm;
    static const int n_Tr;
    static const int n_Tc;

public:
    static const T_term_numb *term_numb_;
    static const T_Tm        *Tm_;
    static const T_Tr        *Tr_;
    static const T_Tc        *Tc_;

public:
   static Token   token;               // Token being read.
   static Token   lookahead;           // Lookahead being read.
   static int     tab;                 // Tab setting in input file.
   static int     linenumb;            // Line number in input file.
   static int     linenumb_printed;    // Line number already printed.
   static int     lookahead_linenumb;  // Line number in input file.

   static void init_lexer(char *input_start, int tab_setting)
   {
      linenumb          = 0;
      linenumb_printed  = 0;
      tab               = tab_setting; // Tab.
      token.start       = input_start; // Point at beginning of first line.
      token.end         = input_start; // Point at beginning of first line.
      lookahead.start   = 0;           // Not activated.
      lookahead.end     = 0;           // Not activated.
   }


   static int get_token()
   {
      int x, y;                     // State, next state.
      do {
         x = 0;
         token.start = token.end;
         token.line  = linenumb;
         while ((y = Tm_[Tr_[x] + Tc_[*(uchar*)token.end]]) > 0) {
            x = y;
            if (*token.end == '\n') {
               linenumb++;
               if (debug_lexer_) {
                  prt_line();
               }
            }
            token.end++;
         }
      } while (term_numb_[x] < 0);  // Ignore whitespace.
      return term_numb_[x];       // Return token_number.
   }

   static char *untabify(char *ls)
   {
      if (debug_lexer_) {
         int          ns;
         int          col;
         char        *p;
         char        *s;
         static char  string [256];
         char        *stringend = string + 250;

         col = 0;
         for (p = ls, s = string; *p != '\n'; p++) {
            if (*p == '\t') {           // col = 0 1 2 3 4 5
               ns = 3 - (col % 3);
               switch (ns) {
               case 3:
                  *s++ = ' ';
                  LRSTAR_FALLTHROUGH();
               case 2:
                  *s++ = ' ';
                  LRSTAR_FALLTHROUGH();
               case 1:
                  *s++ = ' ';
               }
               col += ns;
            } else {
               *s++ = *p;
               col++;
            }
            if (s > stringend) {
               break;
            }
         }
         *s = 0;
         return string;
      } else {
         return ls;
      }
   }


   static char *untabify(char *ls, char *&ts)
   {
      // ls = line start.
      // ts = token start within this line.;
      static char  string[256];
      char        *stringend = string + 250;
      char        *p;
      char        *s;
      int          ns;
      int          col       = 0;
      int          incr      = 0;
      for (p = ls, s = string; *p != '\n'; p++) {
         if (*p == '\t') {           // col = 0 1 2 3 4 5
            ns = 3 - (col % 3);
            switch (ns) {
            case 3:
               *s++ = ' ';
               if (p < ts) {
                  incr++;
               }
               LRSTAR_FALLTHROUGH();

            case 2:
               *s++ = ' ';
               if (p < ts) {
                  incr++;
               }
               LRSTAR_FALLTHROUGH();

            case 1:
               *s++ = ' ';
            }
            col += ns;
         } else {
            *s++ = *p;
            col++;
         }
         if (s > stringend) {
            break;
         }
      }
      *s = 0;
      ts = string + (ts - ls) + incr;
      return string;
   }


   static void  prt_line()
   {
#if 1
      assert(0);                /* XXX test this function */
#else
      if (debug_lexer_) {
         char *str;
         char *ls;
         if (linenumb > linenumb_printed) {
            if (linenumb == 1) {
               printf  (        "\n");
               fprintf (stderr, "\nInput File ...\n\n");
            }
            ls = token.end + 1;
            linenumb_printed = linenumb;
            if (*ls != 26) { // Not end of file?
               str = untabify (ls);
               printf  (        "%6d  %s\n", linenumb, str);
               fprintf (stderr, "%6d  %s\n", linenumb, str);
            }
         }
      }
#endif
   }


   static int get_lookahead()
   {
      int x, y;                     // State, next state.
      do {
         x = 0;
         lookahead.start = lookahead.end;
         lookahead.line  = lookahead_linenumb;
         while ((y = Tm_[Tr_[x] + Tc_[*(uchar*)lookahead.end]]) > 0) {
            x = y;
            if (*lookahead.end == '\n') {
               lookahead_linenumb++;
            }
            lookahead.end++;
         }
      } while (term_numb_[x] < 0);  // Ignore whitespace.
      return term_numb_[x];       // Return token_number.
   }

};

/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
