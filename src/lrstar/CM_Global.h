/* Copyright 2018, 2023 Paul B Mann.  BSD License. */

#ifndef COMGLOBAL_H
#define COMGLOBAL_H

      #ifdef MAIN
      #define EXTERN
      #else
      #define EXTERN extern
      #endif

      #define MAX_LENGTH 60

/////////////////////////////////////////////////////////////////////////////////////////////////////
//																																	//
//		Includes

      #include "sys/types.h"
      #include "sys/stat.h"
      #include "fcntl.h"
      #include "ctype.h"
      #include "stdio.h"

      #include <stdlib.h>
      #include <string.h>
      #include <time.h>
      #include <stdarg.h>

      #if defined(WINDOWS)
      #include "wtypes.h"
      #include <io.h>
      #include "malloc.h"
      #endif

      #ifdef LINUX
		#include <limits.h>
      #include <unistd.h>
      #endif

      #include "basic_defs.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
//																																	//
//		Defines

		enum options
		{
         PG_ARGPOINTATNT  ,
         PG_ASTCONST      ,
         PG_BACKSLASH     ,
			PG_BOOLMATRIX    ,
			PG_CLR           ,
         PG_CONFLICTS     ,
         PG_CONREDUCE     ,
         PG_CONSHIFT      ,
         PG_CONSTANTSUNUSED,
			PG_CONTRACEBACK  ,
			PG_DEBUG         ,
			PG_DEBUGTRACE    ,
			PG_DEFAULTRED    ,
			PG_DEFCONCHECK   ,
			PG_EOFINCLUDED   ,
			PG_EXPECTING     ,
			PG_FORCESHIFT    ,
			PG_GENERATE      ,
			PG_GRAMMAR       ,
			PG_GRAMMARFORMAT ,
			PG_GRAMMARHTML   ,
			PG_GRAMMARYACC   ,
			PG_INSENSITIVE   ,
			PG_KEYWORDUNDECL,
			PG_LALR          ,
			PG_LOOKAHEADS    ,
         PG_LR            ,
         PG_MINIMIZE      ,
         PG_MIXEDCASEUNDECL,
			PG_NODEACTIONS   ,
         PG_NONDETER      ,
         PG_OPTIMIZE      ,
			PG_HEADERFILES   ,
			PG_PARSERTABLES  ,
         PG_PARSETREE     ,
         PG_SHIFTREDUCE   ,
         PG_STATES        ,
         PG_STATESHTML    ,
         PG_SYMBOLS       ,
         PG_SYMTABLE      ,
         PG_TAB           ,
			PG_TERMACTIONS   ,
			PG_TERMINALCHECK ,
			PG_TRANSITIONS   ,
         PG_UPPERCASEUNDECL,
         PG_VERBOSE       ,
         PG_VERBOSEMORE   ,
         PG_WAIT          ,
         PG_WARNINGS      ,

			MAX_SYM,
			MAX_PRO,
			MAX_TAIL,
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

      #if defined(WINDOWS)
      #define read   _read
      #define write  _write
      #define open   _open
      #define close  _close
      #define chmod  _chmod
      #define unlink _unlink
		#endif


      #define MAX_DIR             160 // Maximum directory name length, 159.
      #define MAX_FILENAME         64 // Maximum file name length, 63.
      #define MAX_FILETYPE         32 // Maximum file type length, 31.

      #define EOF_CHAR             26
      #define EOL_CHAR             10

      #define UPPERCASE		   1
      #define LOWERCASE       2
      #define UNDERSCORE	   4
      #define DIGIT			   8
      #define QUOTE		     16

		#define ZERO_OR_MORE	   9	  // * 1.0.0.8
		#define ONE_OR_MORE	  10	  // + 0.2.0.8
		#define ZERO_OR_ONE	   5	  // ? 1.0.4.0

   // Function-call defines ...
		#define ALLOC(_x, _n_elem)                                        \
			do {                                                           \
         	char         **p_       = reinterpret_cast<char **>(&_x);   \
            const size_t   n_el_    = _n_elem;                          \
         	const size_t   el_size_ = sizeof(*_x);                      \
            const size_t   n_bytes_ = n_el_ * el_size_;                 \
				if (_debug) {																\
         		*p_ = alloc_debug(n_bytes_, __FILE__, __LINE__);			\
				} else {																		\
         		*p_ = alloc(n_bytes_);												\
            }																				\
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
							   no_bytes_, nn_bytes_);                          \
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

/////////////////////////////////////////////////////////////////////////////////////////////////////
//																																	//
//		Typedefs

		typedef struct OPTION
		{
			const char* name;
			const char* desc;
			int   numb;
			int   defvalue;
		}
		OPTION;

      typedef struct	ITEM
      {
         int symb;
         int prod;
         int dot;
      }
      ITEM;

      typedef struct	CLOSURE
      {
         int item;
         int next;
      }
      CLOSURE;

      typedef struct	SYMLIST
      {
         int symb;
         int start;
         int end;
      }
      SYMLIST;

      typedef struct	CHILD
      {
         int numb;
         int link;
      }
      CHILD;

		typedef struct	CODETABLE
		{
			char* keyword;
			char* operators;
			int   number;
			char* description;
		}
		CODETABLE;

		#define MAXTOP 10
		typedef struct	STAKTYPE
		{
			char*	groupstart;
			int	skipcode;
		}
		STAKTYPE;

/////////////////////////////////////////////////////////////////////////////////////////////////////

		class Symbol
		{
		   public:
			const char*  name;		// Pointer to symbol name (allocated).   							      4	 4
			const char*  original;	// Original name for those renamed symbols.								4	 8
			const char*  start;		// Pointer to symbol start address (in source code).					4	12
			int	 length;		// Length  of symbol.		      											4  16
			int	 origleng;	// Original length  of symbol.		      								4  20
         int    type;		// Type (e.g. integer, float, double, char, ...)						4  24
			int    line;		// Line of first encounter in grammar.	                           4  28
			int    numb;		// Number assigned to symbol (sequence number).		               4  32
			int    value;		// Value of symbol (for constants and integers).		            4  36
		};

		class Node
		{
		   public:
			int    id;		 // Node id number.	               					4	 4
			int    numb;	 // Node number.												4	 8
			int    prod;	 // Production number.										4	12
			int    sti;     // Symbol-table index (can be negative).   			4	16
			int    line;    // Line number.              							4	20
			int    oper;    // ZERO_OR_MORE, ONE_OR_MORE, ZERO_OR_ONE.       	4	24
         char*  start;   // Start of token in source line.						4  28
         char*  end;     // End of token in source line.							4  32
			Node*  next;	 // Next node.													4  36
			Node*  prev;	 // Previous node.			   							4  40
			Node*  child;   // Child node.                            			4  44
			Node*  parent;  // Parent node.                            			4  48
		};

      class PStack // Parser stack.
      {
         public:
         int    state;     // Parser state.                 4	 4
         char*  start;     // Token start address.          4	 8
         char*  end;       // Token end address.            4	12
         int    line;      // Input line number.            4	16
         int    sti;       // Symbol table index.           4	20
			int    sym;       // Symbol stacked, terminal (positive) or nonterminal (negative).
         Node*  node;      // Node pointer.                 4	24
         Node*  last;      // Last pointer.                 4	28	bytes
      };

      class RStack // Restore Stack.
      {
         public:
         PStack* ptr;		// Parse stack pointer.				4	 4
         int     state;    // State.								4	 8	bytes.
      };

      class Stack
      {
         public:
         int   id;      // Node id.                      2	 2
         int   counter; // Counter of node accesses.     2	 4
      };

/////////////////////////////////////////////////////////////////////////////////////////////////////
//																																	//
//		Global Variables

		extern const char*  program;
      extern const char*  version;
      extern const char*  bits;
      extern const char*  copywrt;

		extern uchar  numeric[256];
		extern uchar  alpha[256];
		extern uchar  upper[256];
		extern uchar  lower[256];

      EXTERN int    n_errors;
		EXTERN int    t_error;
		EXTERN int    n_warnings;

	   EXTERN char   exefid [PATH_MAX];
      EXTERN char   gdn [MAX_DIR];
      EXTERN char   gfn [MAX_FILENAME];
      EXTERN char   gft [MAX_FILETYPE];
	   EXTERN char   grmfid [PATH_MAX];

      EXTERN int    optn[N_OPTIONS];
      EXTERN int    optncount[N_OPTIONS];

      EXTERN FILE*  logfp;
      EXTERN FILE*  lstfp;
		EXTERN FILE*  confp;
		EXTERN FILE*  grmfp;
		EXTERN FILE*  outfp;
      EXTERN FILE*  stafp;

      EXTERN int    time1;
      EXTERN int    time2;
		EXTERN char   string [10000];

      EXTERN int    filesize;
  		EXTERN int	  filedesc;

      EXTERN char*  input_start;			/* First byte of input area.              */
      EXTERN char*  input_end;			/* Byte after input.                      */
      EXTERN int    LR1Activated;
      EXTERN int    n_lines;
      EXTERN char   spaces [256]
      #ifdef MAIN
      = "                                                                " //  64
        "                                                                "	// 128
        "                                                                "	// 192
        "                                                               "	// 255
      #endif
      ;
      extern OPTION PGOption[];
      extern OPTION MAOption[];

      EXTERN char** line_ptr;

		EXTERN int    memory_max;
		EXTERN int    memory_usage;
      EXTERN int    max_child;			// Option setting (rename this).
		EXTERN int    max_child_usage;	// Highest number found during processing.
      EXTERN int    max_lookah;
      EXTERN int    max_terml;
      EXTERN int    max_headl;
      EXTERN int    max_symbl;
      EXTERN int    max_errors;

		EXTERN int	  option_warnings;

      EXTERN CHILD* child;
      EXTERN int*   f_child;
      EXTERN int    n_childs;

void C_FIRST(int n_heads,
				 int N_terms,
				 int* f_prod,
				 int* f_tail,
				 int* tail,
				 char**& FIRST,
				 int* nullable);

void C_CAMEFROM(int 	N_states,
					 int *tt_start,
					 int *tt_action,
					 int *ntt_start,
					 int *ntt_action,
					 int *&f_camefrom,
					 int *&camefrom);

		extern int    close_con();
		extern int    close_log();
		extern int    close_sta();
		extern int    close_warn();

      #ifdef LINUX
		extern long   _filelength (int fd);
      #endif

      extern int    fastcmp (int*, int*, int);
      extern void   fastcpy (int*, int*, int);
      extern void   fastini (int, int *, int);
      extern int    fastmrg (int*, int*, int);
      extern void   fastor  (int*, int*, int);

      #define FASTCMP(a,b,n)  			fastcmp ((int*)a, (int*)b, n)
      #define FASTCPY(a,b,n)  			fastcpy ((int*)a, (int*)b, n)
      #define FASTINI(a,b,n)  			fastini (      a, (int*)b, n)
      #define FASTMRG(a,b,n)  			fastmrg ((int*)a, (int*)b, n)
      #define FASTOR(a,b,n)   			fastor  ((int*)a, (int*)b, n)

      extern char  *fix_backslash (const char *in);
      extern void   frea (char* x, int n_bytes);

      extern int    get_fid (char*arg, char*dir, char*fn, char*ft);
      extern char*  get_file (char* dir, char* fn, char* ft, int *nb, int flags);
		extern int    GetMaxValues  (char* dir);
		extern void   SaveMaxValues ();

		extern bool	  itsakeyword (const char* terminal);
      extern int    inputi (const char*);
      extern void   inputt ();

		extern void   MemCrash (const char* value, int n);

		extern char*  mystrlwr (char* s);

		extern void   number (int x, char* num);

		extern int    open_log (char*);
		extern int    open_grm (char*);
		extern int    open_con (char*);
		extern int    open_sta (char*);
		extern int    open_warn (char*);

      extern void   prt_error   (const char *msg, const char *start, const char *end, int linenumb);
		extern void   prt_warning (const char *msg, const char *start,
                                 const char *end, int linenumb);
		extern void   prt_message (const char *msgtype,
                                 const char *msg,
                                 const char *start,
                                 const char *end,
                                 int         linenumb);
      extern void   prt_warn    (const char* format, ...);
		extern void   prt_warnscreen(const char *format, ...);
      extern void   prt_log     (const char* format, ...);
      extern void   prt_logonly (const char* format, ...);
      extern void   prt_grm     (const char* format, ...);
		extern void   prt_con     (const char* format, ...);
		extern void   prt_sta     (const char* format, ...);
		extern void   PRT_ARGS    (int na, char** arg, int dest);
		extern void   prt_num     (const char* desc, int n, const char* name, int max);

		extern void   Quit ();

		char *ralloc (char *x, int no_bytes, int nn_bytes);

		extern void   SORT (int *start, int *end);
      extern void   SORT2 (int* first, int* second, int n);
		extern void   SORTNAMES(const char** start, int n, int* seq);

		extern int    set_optn (OPTION* option, char* opt);
		extern int    SET_OPTNS (int na, char** arg, OPTION* list);

		extern void   TRAVERSE (int x);

      extern char*  alloc_debug (int n_bytes, const char *fname, size_t lineno);
		extern char*  alloc (int n_bytes);

		extern int    ATTACH   (int x, int y);
		extern void   T_GRAPH  (char **graph, int nr, int nc);

		extern char   oper_char (Node* np);
		extern const char*  get_typestr  (int*, int);
		extern int    get_typesize (int*, int);

#endif
/* Local Variables:    */
/* mode: c             */
/* c-basic-offset: 3   */
/* tab-width: 3        */
/* indent-tabs-mode: t */
/* End:                */
