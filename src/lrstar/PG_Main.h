
/* Copyright 2018, 2023 Paul B Mann.  BSD License. */

#pragma once

#include "PG_CreateTables.h"
#include "PG_PrintGrammar.h"
#include "PG_PrintStates.h"

#define PARSER_FIELDS                           \
   PF(term_symb)                                \
   PF(head_symb)                                \
   PF(tact_name)                                \
   PF(node_name)                                \
   PF(text_str)                                 \
   PF(head_numb)                                \
   PF(f_tail)                                   \
   PF(tail)                                     \
   PF(arga)                                     \
   PF(argx)                                     \
   PF(argy)                                     \
   PF(Bm)                                       \
   PF(Br)                                       \
   PF(Bc)                                       \
   PF(Bf)                                       \
   PF(Tm)                                       \
   PF(Tr)                                       \
   PF(Tc)                                       \
   PF(Nm)                                       \
   PF(Nr)                                       \
   PF(Nc)                                       \
   PF(Rm)                                       \
   PF(Rr)                                       \
   PF(Rc)                                       \
   PF(PL)                                       \
   PF(nd_fterm)                                 \
   PF(nd_term)                                  \
   PF(nd_faction)                               \
   PF(nd_action)                                \
   PF(tact_numb)                                \
   PF(node_numb)                                \
   PF(nact_numb)                                \
   PFL(reverse) /* Last element in list. */


class PG_Main : public PGCreateTables, public PG_PrintStates, public PG_PrintGrammar
{
public:
   static int    Main (int na, char** arg);
   static void   Terminate ();
   static void   prt_prod (FILE* tables, int p, char* before, char* after);
   static void   nd_optimize();

private:
   static void   PrintStats ();
   static int    SetOptions   (int na, char** arg);
   static void   ShowOptions  ();
   static int    Start        (int na, char** arg );
   static char*  slash_inside (char* term_name);
   static char*  make_term    (const char* s);
   static char*  slash_inside_keyword  (char* term_name, char quote);
   static void   GenerateParserTables  ();
   static void   GenerateOtherFiles    ();
   static void   DeleteLexFile ();
   static void   OutputLexFile ();

private:
   static void generate_tables(const char *dname,
                               const char *fname,
                               const char *cname);
   static void instantiate_tables(const char *dname,
                                  const char *fname,
                                  const char *cname,
                                  const char *parser);
   static void typedef_tables(const char *dname,
                              const char *fname,
                              const char *cname,
                              const char *parser);
   static void instantiate_fields(FILE *fp);
   static void instantiate_constants(FILE *fp);
#define PFL(pfl_) PF(pfl_)
#define PF(pf_) static void instantiate_##pf_##_data(FILE *fp);
   PARSER_FIELDS
#undef PF
#undef PFL
};


/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
