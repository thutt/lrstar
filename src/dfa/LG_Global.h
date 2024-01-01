
/* Copyright 2018, 2023 Paul B Mann.  BSD License. */

#pragma once
#include "LG_CreateTables.h"
#include "LG_PrintStates.h"

// State Types.
#define TT_STATE        1  // State has terminal transitions.
#define NT_STATE        2  // State has nonterminal transitions.
#define MR_STATE        4  // State has multiple reductions.
#define RO_STATE        8  // State is a reduce-only state.
#define UN_STATE       16  // State is unused, remove it.
#define RR_CONFL       32  // State has reduce-reduce conflict(s).

// Symbol Types.
#define TOKEN           1
#define TERMINAL        2
#define NONTERMINAL     4
#define SETNAME         8
#define SETNAMEREF     16
#define LEXICON        32
#define CONSTANT       64
#define GENERATED     128
#define STRING        256
#define UNREACHABLE   512
#define LEXFILE      1024
#define IGNORESYM    2048
#define OUTPUTSYM    4096
#define ACTIONCODE   8192

#define MAXPRODLENG   256  // Maximum number of symbols per production.

enum prodtype
{
   PRODARROW,
   PRODADD,
   PRODSUB,
   PRODTO
};

class LG : public LG_CreateTables, public LG_PrintStates
{
public:
   static int  Main ();
   static int  Start ();
   static int  GetFile(const char*, const char*);
   static int  FreeFile();
   static int  CheckOptions ();
   static void PrintStats ();
   static void Terminate ();
   static void GenerateLexerDefines();
   static void GenerateLexerTables (char*);
   static void GenerateLexerCode   (char*);
   static void DELETE_LEX_FILE     ();
   static void instantiate_lexer(const char *dname,
                                 const char *fname,
                                 const char *cname);
};

/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
