
///////////////////////////////////////////////////////////////////////////////
//                                                                           // 

#include "Calc_Actions.h"
#include "../../code/main.h"

///////////////////////////////////////////////////////////////////////////////

#ifdef ACTIONS

void	ACTIONS::init_actions ()
{
		/* Initialization code goes here */
}

void	ACTIONS::term_actions ()
{
		/* Termination code goes here */
}

#endif

///////////////////////////////////////////////////////////////////////////////

#ifdef TERM_ACTIONS

int   TERM_ACTIONS::error (int& t)
{
		if (token.end == token.start) // Illegal character?
		{
			token.end++;
		}
      return 0; 
}

int   TERM_ACTIONS::lookup (int& t)				// Lookup in symbol table.
{
		int sti;
		#ifdef ND_PARSING
		if (lookahead.start > 0)					// In lookahead mode?
		{
			sti = add_symbol (t, lookahead.start, lookahead.end); 
		}
		else												// Regular mode of parsing.  
		#endif	
		{
			sti = add_symbol (t, token.start, token.end); 
		}
		#ifdef SEMANTICS
		t = symbol[sti].term;						//	Redefine terminal number? 
		#endif
		return sti;										// Return symbol-table index. 
}

#endif

///////////////////////////////////////////////////////////////////////////////

#ifdef NODE_ACTIONS

int	NODE_ACTIONS::goal_ (void* v)
{
		Node* n = (Node*)v;
		if (traversal == FIRST_PASS)	   
			switch (direction)				      
			{
				case TOP_DOWN:	 
					fprintf (output, "\t\tSTART\n"); 
					break;
				case BOTTOM_UP: 
					fprintf (output, "\t\tEOF\n"); 
					break;
			}
      return 1; // OK
}

int	NODE_ACTIONS::program_ (void* v)
{
		Node* n = (Node*)v;
		if (traversal == FIRST_PASS)	   
			switch (direction)
			{
				case TOP_DOWN:	
					fprintf (output, "\t\tPROGRAM %s\n", symbol_name (n->sti));
					break;
				case BOTTOM_UP: 
					fprintf (output, "\t\tEND PROGRAM %s\n", symbol_name (n->sti));
					break;
			}
      return 1; // OK
}

int	NODE_ACTIONS::ident_ (void* v)
{
		Node* n = (Node*)v;
		if (traversal == FIRST_PASS)	   
			switch (direction)
			{
				case TOP_DOWN:	 
					break;
				case BOTTOM_UP: 
					fprintf (output, "\t\tLOAD %s\n", symbol_name (n->sti)); 
					break;
			}
      return 1; // OK
}

int	NODE_ACTIONS::int_ (void* v)
{
		Node* n = (Node*)v;
		if (traversal == FIRST_PASS)	   
			switch (direction)
			{
				case TOP_DOWN:	 
					break;
				case BOTTOM_UP: 
					fprintf (output, "\t\tLOAD %s\n", symbol_name (n->sti)); 
					break;
			}
      return 1; // OK
}

int	NODE_ACTIONS::add_ (void* v)
{
		Node* n = (Node*)v;
		if (traversal == FIRST_PASS)	   
			switch (direction)
			{
				case TOP_DOWN:	 
					break;
				case BOTTOM_UP: 
					fprintf (output, "\t\tADD\n"); 
					break;
			}
      return 1; // OK
}

int	NODE_ACTIONS::sub_ (void* v)
{
		Node* n = (Node*)v;
		if (traversal == FIRST_PASS)	   
			switch (direction)
			{
				case TOP_DOWN:	 
					break;
				case BOTTOM_UP: 
					fprintf (output, "\t\tSUB\n");
					break;
			}
      return 1; // OK
}

int	NODE_ACTIONS::mul_ (void* v)
{
		Node* n = (Node*)v;
		if (traversal == FIRST_PASS)	   
			switch (direction)
			{
				case TOP_DOWN:	 
					break;
				case BOTTOM_UP: 
					fprintf (output, "\t\tMUL\n"); 
					break;
			}
      return 1; // OK
}

int	NODE_ACTIONS::div_ (void* v)
{
		Node* n = (Node*)v;
		if (traversal == FIRST_PASS)	   
			switch (direction)
			{
				case TOP_DOWN:	 
					break;
				case BOTTOM_UP: 
					fprintf (output, "\t\tDIV\n"); 
					break;
			}
      return 1; // OK
}

int	NODE_ACTIONS::pwr_ (void* v)
{
		Node* n = (Node*)v;
		if (traversal == FIRST_PASS)	   
			switch (direction)
			{
				case TOP_DOWN:	 
					break;
				case BOTTOM_UP: 
					fprintf (output, "\t\tPWR\n"); 
					break;
			}
      return 1; // OK
}

int	NODE_ACTIONS::if_ (void* v)
{
		Node* n = (Node*)v;
		if (traversal == FIRST_PASS)	   
			switch (direction)
			{
				case TOP_DOWN:	 
   				fprintf (output, "if%d:\n", stack[stacki].counter); 
					break;
				case BOTTOM_UP: 
   				fprintf (output, "endif%d:\n", stack[stacki].counter); 
					break;
			}
      return 1; // OK
}

int	NODE_ACTIONS::then_ (void* v)
{												
		Node* n = (Node*)v;
		if (traversal == FIRST_PASS)	   
			switch (direction)
			{
				case TOP_DOWN:	 
					fprintf (output, "\t\tBR NZ endif%d\n", stack[stacki-1].counter); 
					fprintf (output, "then%d:\n",           stack[stacki-1].counter); 
					break;						
				case BOTTOM_UP: 
					break;
			}
      return 1; // OK
}

int	NODE_ACTIONS::then2_ (void* v)
{												
		Node* n = (Node*)v;
		if (traversal == FIRST_PASS)	   
			switch (direction)
			{
				case TOP_DOWN:	 
   				fprintf (output, "\t\tBR NZ else%d\n", stack[stacki-1].counter); 
   				fprintf (output, "then%d:\n",          stack[stacki-1].counter); 
					break;
				case BOTTOM_UP: 
					break;
			}
      return 1; // OK
}

int	NODE_ACTIONS::else2_ (void* v)
{
		Node* n = (Node*)v;
		if (traversal == FIRST_PASS)	   
			switch (direction)
			{
				case TOP_DOWN:	 
   				fprintf (output, "\t\tBR endif%d\n", stack[stacki-1].counter); 
   				fprintf (output, "else%d:\n",        stack[stacki-1].counter); 
					break;
				case BOTTOM_UP: 
					break;
			}
      return 1; // OK
}

int	NODE_ACTIONS::eq_ (void* v)
{
		Node* n = (Node*)v;
		if (traversal == FIRST_PASS)	   
			switch (direction)
			{
				case TOP_DOWN:	 
					break;
				case BOTTOM_UP: 
					fprintf (output, "\t\tEQ\n"); 
					break;
			}
      return 1; // OK
}

int	NODE_ACTIONS::ne_ (void* v)
{
		Node* n = (Node*)v;
		if (traversal == FIRST_PASS)	   
			switch (direction)
			{
				case TOP_DOWN:	 
					break;
				case BOTTOM_UP: 
					fprintf (output, "\t\tNE\n"); 
					break;
			}
      return 1; // OK
}

int	NODE_ACTIONS::store_ (void* v)
{
		Node* n = (Node*)v;
		if (traversal == FIRST_PASS)	   
			switch (direction)
			{
				case TOP_DOWN:	 
					break;
				case BOTTOM_UP: 
					fprintf (output, "\t\tSTORE\n");
					break;
			}
      return 1; // OK
}

int	NODE_ACTIONS::target_ (void* v)
{
		Node* n = (Node*)v;
		if (traversal == FIRST_PASS)	   
			switch (direction)
			{
				case TOP_DOWN:	 
					break;
				case BOTTOM_UP: 
					fprintf (output, "\t\tLADR %s\n", symbol_name (n->sti));
					break;
			}
      return 1; // OK
}

#endif

//                                                                           // 
///////////////////////////////////////////////////////////////////////////////

