//
//    DFA Lexer Header

#pragma once

class Token
{
public:
   char*  start;     // Start of token.
   char*  end;       // End of token (character following token).
   int    sti;       // Symbol table index.
   int    line;      // Line number.
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
    static const T_term_numb *term_numb;
    static const T_Tm        *Tm;
    static const T_Tr        *Tr;
    static const T_Tc        *Tc;

public:
   static Token   token;               // Token being read.
   static Token   lookahead;           // Lookahead being read.
   static int     tab;                 // Tab setting in input file.
   static int     linenumb;            // Line number in input file.
   static int     linenumb_printed;    // Line number already printed.
   static int     lookahead_linenumb;  // Line number in input file.

   static void  init_lexer(const char *input_start, int tab);
   static int   get_token();
   static int   get_lookahead();
   static void  prt_line();
   static char *untabify(char *ls);
   static char *untabify(char *ls, char *&token);
};

/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
