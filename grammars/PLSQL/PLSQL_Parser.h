// Generated by LRSTAR 24.0.017
// DO NOT EDIT.

#if !defined(__PLSQL_Parser_H)
#define __PLSQL_Parser_H

#include "lrstar_basic_defs.h"
#include "lrstar_lexer.h"

#include "PLSQL_ParserTables_typedef.h"
#include "lrstar_parser.h"

extern const char PLSQL_grammar_name[];

typedef lrstar_parser</* grammar      */   PLSQL_grammar_name,
                      /* actions      */   false,
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
                      /* term_actions */   false> PLSQL_parser_t;

#endif
