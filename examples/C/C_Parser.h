// Generated by LRSTAR 24.0.017
// DO NOT EDIT.

#if !defined(__C_Parser_H)
#define __C_Parser_H

#include "lrstar_basic_defs.h"
#include "lrstar_lexer.h"

#include "C_ParserTables_typedef.h"
#include "lrstar_parser.h"

extern const char C_grammar_name[];

typedef lrstar_parser</* grammar           */   C_grammar_name,
                      /* actions           */   false,
                      /* debug_parser      */   false,
                      /* debug_trace       */   false,
                      /* expecting         */   false,
                      /* insensitive       */   false,
                      /* lookaheads        */   1,
                      /* make_ast          */   false,
                      /* nd_parsing        */   false,
                      /* nd_threads        */   0,
                      /* node_actions      */   false,
                      /* reversable        */   false,
                      /* semantics         */   true,
                      /* stksize           */   100,
                      /* term_actions      */   false,
                      /* lexer table type  */   C_lexer_t,
                      /* parser table type */   C_parser_tables_t> C_parser_t;

#endif
