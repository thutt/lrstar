// Generated by LRSTAR 24.0.017
// DO NOT EDIT.

#if !defined(__Calc_Parser_H)
#define __Calc_Parser_H

#include "lrstar_basic_defs.h"
#include "lrstar_lexer.h"

enum termcon {
   END_OF_FILE = 1,
   ERR = 0,
   ID = 2,
   INT = 3,
};

enum nodecon {
   N_goal_ = 0,
   N_program_ = 1,
   N_store_ = 2,
   N_if_ = 3,
   N_target_ = 4,
   N_eq_ = 5,
   N_ne_ = 6,
   N_add_ = 7,
   N_sub_ = 8,
   N_mul_ = 9,
   N_div_ = 10,
   N_pwr_ = 11,
   N_int_ = 12,
   N_ident_ = 13,
   N_then_ = 14,
   N_then2_ = 15,
   N_else2_ = 16,
};

#include "Calc_ParserTables_typedef.h"
#include "lrstar_parser.h"

extern const char Calc_grammar_name[];

typedef lrstar_parser</* grammar           */   Calc_grammar_name,
                      /* actions           */   true,
                      /* debug_parser      */   true,
                      /* debug_trace       */   true,
                      /* expecting         */   true,
                      /* insensitive       */   false,
                      /* lookaheads        */   1,
                      /* make_ast          */   true,
                      /* nd_parsing        */   false,
                      /* nd_threads        */   0,
                      /* node_actions      */   true,
                      /* reversable        */   true,
                      /* semantics         */   false,
                      /* stksize           */   100,
                      /* term_actions      */   true,
                      /* lexer table type  */   Calc_lexer_t,
                      /* parser table type */   Calc_parser_tables_t> Calc_parser_t;

#endif
