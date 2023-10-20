
/* Copyright 2018, 2023 Paul B Mann.  BSD License. */

#pragma once

/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//    LG_Lexer.h

#define  ushort unsigned short
#define  uchar  unsigned char

class LG_Lexer
{
public:
   static Token  token;
   static int    line_numb;
   static int    col_numb;
   static int    line_pos;
   static char*  line_start;
   static int    max_char_set;
   static int	  tab;

   static int    get_token ();
   static int    get_lookahead (int&);
   static void   init_lexer ();
   static void   term_lexer ();
   static void   prt_line ();

   static char* token_name[1];
};

/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
