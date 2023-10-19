
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

      #pragma once

class Symbol		   // Symbol in Symbol Table.
{
	public:
	char*  start;     // Start of symbol in input file or ?.
	int    length;    // Length of symbol.
	int    cell;      // Cell number in hash vector (if need to delete later).
	int    type;      // Type of symbol: int, char, float, short, ...
	int    term;      // Terminal number for lookup function.
	int    scope;     // Scope: global, local, inner loop, ...
};

class Node				// AST Node.
{
	public:
	int    id;			// Production number.  								4
	int    sti;			// Symbol-table index (perm or temp var).		4
	int    line;		// Line number in input file.                4
	char*  start;		// Start of symbol in input area.            4
	Node*  prev;		// Previous node.			   						4
	Node*  next;		// Next node.											4
	Node*  child;		// Child node.                              	4
	Node*  parent;		// Parent node.                             	4  32 bytes
};

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

