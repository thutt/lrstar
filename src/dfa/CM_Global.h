/* Copyright 2018, 2023 Paul B Mann.  BSD License. */

#ifndef COMGLOBAL_H
#define COMGLOBAL_H

#ifdef MAIN
#define EXTERN
#else
#define EXTERN extern
#endif

#define MAX_LENGTH 60 // Maximum generated symbol length, over this gets renamed to $0000x.

/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//    Includes

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>

#if defined(LRSTAR_WINDOWS)
#include <wtypes.h>
#include <io.h>
#include <malloc.h>
#endif

#if defined(LRSTAR_LINUX)
#include <unistd.h>
#include <limits.h>
#endif

#include "basic_defs.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//    Defines

enum options
{
   LG_ANALYZEONLY,
   LG_BACKSLASH,
   LG_BLANKGOTOS,
   LG_COLNUMB,
   LG_CONRR,
   LG_CONSR,
   LG_DEBUG,
   LG_GRAMMAR,
   LG_INSENSITIVE,
   LG_KEYWORDIDENT,
   LG_KEYWORDONLY,
   LG_LINENUMB,
   LG_MINIMIZE,
   LG_NUMBCHAR,
   LG_OPTIMIZE,
   LG_REMOVEDUP,
   LG_SORTACTIONS,
   LG_STATELIST,
   LG_STATELISTOPT,
   LG_TAB,
   LG_TABLES,
   LG_TABL_SMALL,
   LG_TABL_MEDIUM,
   LG_TABL_LARGE,
   LG_TRANSITIONS,
   LG_VERBOSE,
   LG_VERBOSEMORE,
   LG_WAIT,
   LG_WARNINGS,

   MAX_SYM,
   MAX_PRO,
   MAX_TAIL,
   MAX_EBNF,
   MAX_STA,
   MAX_FIN,
   MAX_KER,
   MAX_NTT,
   MAX_TT,
   MAX_TTA,
   MAX_LA,
   MAX_LB,
   MAX_INC,
   MAX_CH,
   MAX_ND,

   N_OPTIONS
};

#if defined(LRSTAR_WINDOWS)
#define read   _read
#define write  _write
#define open   _open
#define close  _close
#define chmod  _chmod
#define unlink _unlink
#endif

#define EOF_CHAR             26
#define EOL_CHAR             10

// TODO: This should be an enumeration, and uses should be logically
//       ORed in 'charcode'
#define UPPERCASE       1
#define LOWERCASE       2
#define UNDERSCORE      4
#define DIGIT           8
#define QUOTE          16

// Function-call defines ...
#define ALLOC(_x, _n_elem)                                        \
   do {                                                           \
      char         **p_       = reinterpret_cast<char **>(&_x);   \
      const size_t   n_el_    = _n_elem;                          \
      const size_t   el_size_ = sizeof(*_x);                      \
      const size_t   n_bytes_ = n_el_ * el_size_;                 \
      if (_debug) {                                               \
         *p_ = alloc_debug(n_bytes_, __FILE__, __LINE__);         \
      } else {                                                    \
         *p_ = alloc(n_bytes_);                                   \
      }                                                           \
   } while (0)

#define REALLOC(_x, _no_elem, _nn_elem)                           \
   do {                                                           \
      char         **p_        = reinterpret_cast<char **>(&_x);  \
      const size_t   no_el_    = _no_elem;                        \
      const size_t   nn_el_    = _nn_elem;                        \
      const size_t   el_size_  = sizeof(*_x);                     \
      const size_t   no_bytes_ = no_el_ * el_size_;               \
      const size_t   nn_bytes_ = nn_el_ * el_size_;               \
      *p_ = ralloc(reinterpret_cast<char *>(_x),                  \
                   no_bytes_, nn_bytes_);                         \
   } while (0)

#define FREE(_x, _n_elem)                                         \
   do {                                                           \
      char         **p_        = reinterpret_cast<char **>(&_x);  \
      const size_t   n_el_    = _n_elem;                          \
      const size_t   el_size_  = sizeof(*_x);                     \
      const size_t   n_bytes_ = (n_el_) * (el_size_);             \
      frea(*p_, n_bytes_);                                        \
      _x = 0;                                                     \
   } while (0)

#define FASTCMP(a,b,n)           fastcmp ((int*)a, (int*)b, n)
#define FASTCPY(a,b,n)           fastcpy ((int*)a, (int*)b, n)
#define FASTINI(a,b,n)           fastini (      a, (int*)b, n)
#define FASTMRG(a,b,n)           fastmrg ((int*)a, (int*)b, n)
#define FASTOR(a,b,n)            fastor  ((int*)a, (int*)b, n)

/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//    Typedefs

typedef struct OPTION
{
   const char* name;
   const char* desc;
   int   numb;
   int   defvalue;
}
   OPTION;

typedef struct ITEM
{
   int symb;
   int prod;
   int dot;
}
   ITEM;

typedef struct CLOSURE
{
   int item;
   int next;
}
   CLOSURE;

typedef struct SYMLIST
{
   int symb;
   int start;
   int end;
}
   SYMLIST;

typedef struct CHILD
{
   int numb;
   int link;
}
   CHILD;

typedef struct CODETABLE
{
   char* keyword;
   char* operators;
   int   number;
   char* description;
}
   CODETABLE;

#define MAXTOP 10
typedef struct STAKTYPE
{
   char* groupstart;
   int   skipcode;
}
   STAKTYPE;

/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//    Classes

class Token
{
public:
   char* start;      // Start of symbol.
   char* end;        // End of symbol.
   int   sti;        // Symbol table index.
   int   line;       // Input line number.
   int   column;     // Input column number.
};

class Symbol
{
public:
   char*  name;      // Pointer to symbol name (allocated).                            4   4
   char*  original;  // Original name for those renamed symbols.                       4   8
   char*  start;     // Pointer to symbol start address (in source code).              4  12
   int    length;    // Length  of symbol.                                             4  16
   int    origleng;  // Original length  of symbol.                                    4  20
   int    type;      // Type (e.g. integer, float, double, char, ...)                  4  24
   int    line;      // Line of first encounter in grammar.                            4  28
   int    numb;      // Number assigned to symbol (sequence number).                   4  32
   int    value;     // Value of symbol (for constants and integers).                  4  36
};

class Symtab
{
public:
   static Symbol*  symbol;          // Symbols.
   static int      n_symbols;       // Number of symbols.
   static short    length;          // Current length of symbol name.
   static int      cell;            // Current hash cell number.
   static int      sti;             // Current symbol-table index.
   static uint     hashdiv;         // Hash divisor.
   static int*     hashvec;         // Hash vector.
   static int      max_cells;       // Maximum number of cells in the hash vector = 2*max_symbols.
   static int      max_symbols;     // Maximum number of symbols.

   // Functions ...
   static void     init_symtab  (int);                            // Initialize the symbol table.
   static void     term_symtab  ();                               // Terminate the symbol table.
   static char*    symname      (int);                            // Get symbol name.
   static int      add_symbol   (char*, char*, int, int);   // Add symbol to symbol table.
   static void     rename_symbol(short, int);                     // Rename symbol.
   static int      get_symbol   (char*, char*, int);              // Get symbol number.
   static void     print_symtab (char**);                         // Print the symbol table.
};

class Node
{
public:
   int    id;      // Node id number.                             4   4
   int    numb;    // Node number.                                4   8
   int    prod;    // Production number.                          4  12
   int    sti;     // Symbol-table index (can be negative).       4  16
   int    line;    // Line number.                                4  20
   char*  start;   // Start of token in source line.              4  24
   char*  end;     // End of token in source line.                4  28
   Node*  next;    // Next node.                                  4  32
   Node*  prev;    // Previous node.                              4  36
   Node*  child;   // Child node.                                 4  40
   Node*  parent;  // Parent node.                                4  44
};

class PStack // Parser stack.
{
public:
   int    state;     // Parser state.                 4   4
   char*  start;     // Token start address.          4   8
   char*  end;       // Token end address.            4  12
   int    line;      // Input line number.            4  16
   int    sti;       // Symbol table index.           4  20
   int    sym;       // Symbol stacked, terminal (positive) or nonterminal (negative).
   Node*  node;      // Node pointer.                 4  24
   Node*  last;      // Last pointer.                 4  28 bytes
};

class RStack // Restore Stack.
{
public:
   PStack* ptr;      // Parse stack pointer.          4   4
   int     state;    // State.                        4   8 bytes.
};

class Stack
{
public:
   int   id;      // Node id.                      2   2
   int   counter; // Counter of node accesses.     2   4
};

class AST : public Symtab
{
public:
   static char     indent[256];     // Indentation for printing current node.
   static int*     counter;         // Node counter array.
   static short    stacki;          // AST stack index.
   static Stack*   stack;           // AST stack array.
   static Node*    node;            // AST node array.
   static Node*    root;            // Root node pointer.
   static Node*    currnode;        // Current node pointer.
   static int      n_nodes;         // Number of nodes created.
   static int      n_nodenames;     // Number of node names.
   static int      n_nodeactions;   // Number of node actions.
   static short    pass;            // Pass number when traversing the AST.
   static short    status;          // Status (TOP_DOWN | PASS_OVER | BOTTOM_UP).
   static char*    node_name[];     // Node names array.
   static char**   term_symb;       // Terminal symbols.
   static int      nact_numb[];     // Node action numbers.
   static char*    nact_name[];     // Node action names.

   // Functions ...
   static void     init_ast    ();
   static void     term_ast    ();
   static void     print_ast   (char**);
   static void     print_ast   (Node* np);
   static void     print_node  (char *indent, Node* np);
   static void     traverse    ();
   static void     traverse    (Node* np);
   static void     traverse    (char *indent, Node* np);
   static short    emitstr     (Node* np, char* str);
   static int      (*nact_func[])(Node*);
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//    Global Variables

extern const char*  program;
extern const char*  version;
extern const char*  bits;
extern const char*  copywrt;

extern const uchar charcode[256];
extern const uchar lower[256];
extern char   spaces[256];

EXTERN int    n_errors;
EXTERN int    n_warnings;

EXTERN char   exefid [PATH_MAX];
EXTERN char   gdn [PATH_MAX];
EXTERN char   gfn [PATH_MAX];
EXTERN char   gft [PATH_MAX];
EXTERN char   grmfid [PATH_MAX];

EXTERN int    optn[N_OPTIONS];
EXTERN int    optncount[N_OPTIONS];

EXTERN FILE*  logfp;
EXTERN FILE*  lstfp;
EXTERN FILE*  confp;
EXTERN FILE*  grmfp;
EXTERN FILE*  stafp;

EXTERN int    time1;
EXTERN int    time2;
EXTERN char   string [10000];

EXTERN int    filesize;
EXTERN int    filedesc;

EXTERN char*  input_start;       /* First byte of input area.              */
EXTERN char*  input_end;         /* Byte after input.                      */
EXTERN char*  lex_input_start;   /* First byte of input area.              */
EXTERN char*  lex_input_end;     /* Byte after input.                      */
EXTERN int    n_lines;

extern OPTION LGOption[];
extern OPTION MAOption[];

EXTERN char** line_ptr;
EXTERN char** lex_line_ptr;


EXTERN int    memory_max;
EXTERN int    memory_usage;
EXTERN int    max_child;         // Option setting (rename this).
EXTERN int    max_child_usage;   // Highest number found during processing.
EXTERN int    max_lookah;
EXTERN int    max_terml;
EXTERN int    max_headl;
EXTERN int    max_errors;

EXTERN int    option_warnings;
EXTERN int    option_grammar;

EXTERN CHILD* child;
EXTERN int*   f_child;
EXTERN int    n_childs;

#if defined(LRSTAR_LINUX)
long   _filelength (int fd);
#endif

int    fastcmp (int*, int*, int);
void   fastcpy (int*, int*, int);
void   fastini (int, int *, int);
int    fastmrg (int*, int*, int);
void   fastor  (int*, int*, int);

void   frea (char* x, int n_bytes);

int    get_fid (char*arg, char*dir, char*fn, char*ft);
int    GetMaxValues  (char* dir);
void   SaveMaxValues ();

int    inputi (const char*);
void   inputt ();
void   InternalError (int n);

void   MemCrash (const char* value, int n);

void   number (int x, char* num);

void   prt_error   (const char *msg, char *start, char *end, int linenumb);
void   prt_warning (const char *msg, char *start, char *end, int linenumb);
void   prt_warn    (const char* format, ...);
void   prt_log     (const char* format, ...);
void   prt_logonly (const char* format, ...);
void   prt_con     (const char* format, ...);
void   prt_sta     (const char* format, ...);
void   Quit ();
char *ralloc (char *x, int no_bytes, int nn_bytes);


int    SET_OPTNS (int na, char** arg);

char*  alloc_debug (int n_bytes, const char *fname, size_t lineno);
char*  alloc (int n_bytes);

int    ATTACH   (int x, int y);
void   T_GRAPH  (char **graph, int nr, int nc);
#endif
/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
