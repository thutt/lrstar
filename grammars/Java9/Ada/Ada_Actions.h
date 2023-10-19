
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

      #pragma once

      #include "Ada_Parser.h"

      #ifdef ACTIONS

      class ACTIONS : public PARSER
      {
         public:
         static void init_actions ();
         static void term_actions ();

         static int  error  (int& t);
         static int  lookup	(int& t);

      };

      #endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

