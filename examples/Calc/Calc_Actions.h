
///////////////////////////////////////////////////////////////////////////////
//                                                                           // 
		#pragma once
		#include "Calc_Parser.h"

		#ifdef ACTIONS

		class ACTIONS : public PARSER 
      {
			public:
         static void init_actions ();
         static void term_actions ();
      };

		#endif
		#ifdef TERM_ACTIONS

		class TERM_ACTIONS : public ACTIONS 
      {
			public:
         static int  error		(int& t);
			static int  lookup	(int& t);
      };
         
		#endif
		#ifdef NODE_ACTIONS

		class NODE_ACTIONS : public ACTIONS 
      {
			public:
         static int	eq_      (void* v);
         static int	ne_      (void* v);
         static int	add_		(void* v);
         static int	sub_     (void* v);
         static int	mul_     (void* v);
         static int	div_     (void* v);
         static int	pwr_     (void* v);
         static int	goal_    (void* v);
         static int	ident_   (void* v);
         static int	if_      (void* v);
         static int	then_    (void* v);
         static int	then2_   (void* v);
         static int	else2_   (void* v);
         static int	program_ (void* v);
         static int	int_     (void* v);
         static int	store_   (void* v);
         static int	target_  (void* v);
      };

		#endif

//                                                                           // 
///////////////////////////////////////////////////////////////////////////////

