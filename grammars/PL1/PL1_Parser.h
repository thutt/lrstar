// Generated by LRSTAR 24.0.017
// DO NOT EDIT.

#if !defined(__PL1_Parser_H)
#define __PL1_Parser_H

#include "lrstar_basic_defs.h"
#include "lrstar_lexer.h"

#include "PL1_ParserTables_typedef.h"
#include "lrstar_parser.h"

extern const char PL1_grammar_name[];

typedef lrstar_parser</* grammar      */   PL1_grammar_name,
                      /* actions      */   true,
                      /* debug_parser */   false,
                      /* debug_trace  */   false,
                      /* expecting    */   true,
                      /* insensitive  */   false,
                      /* lookaheads   */   1,
                      /* make_ast     */   false,
                      /* nd_parsing   */   false,
                      /* nd_threads   */   0,
                      /* node_actions */   false,
                      /* reversable   */   false,
                      /* semantics    */   false,
                      /* stksize      */   100,
                      /* term_actions */   true> PL1_parser_t;

#endif
