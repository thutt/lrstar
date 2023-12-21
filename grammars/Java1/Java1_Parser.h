// Generated by LRSTAR 24.0.017
// DO NOT EDIT.

#if !defined(__Java1_Parser_H)
#define __Java1_Parser_H

#include "lrstar_basic_defs.h"
#include "lrstar_lexer.h"

enum termcon {
   BOOLEAN = 4,
   CHAR = 5,
   BYTE = 6,
   SHORT = 7,
   INT = 8,
   LONG = 9,
   FLOAT = 10,
   DOUBLE = 11,
   VOID = 12,
   ENUM = 13,
   PACKAGE = 14,
   IMPORT = 15,
   ABSTRACT = 16,
   FINAL = 17,
   PUBLIC = 18,
   PROTECTED = 19,
   PRIVATE = 20,
   STATIC = 21,
   TRANSIENT = 22,
   VOLATILE = 23,
   NATIVE = 24,
   SYNCHRONIZED = 25,
   CLASS = 26,
   INTERFACE = 27,
   IMPLEMENTS = 28,
   OP_DIM = 29,
   THROWS = 30,
   EXTENDS = 31,
   CASE = 32,
   DEFAULT = 33,
   IF = 34,
   ELSE = 35,
   SWITCH = 36,
   WHILE = 37,
   DO = 38,
   FOR = 39,
   BREAK = 40,
   CONTINUE = 41,
   RETURN = 42,
   THROW = 43,
   TRY = 44,
   CATCH = 45,
   FINALLY = 46,
   THIS = 47,
   SUPER = 48,
   JNULL = 49,
   NEW = 50,
   INSTANCEOF = 51,
};

#include "Java1_ParserTables_typedef.h"
#include "lrstar_parser.h"

extern const char Java1_grammar_name[];

typedef lrstar_parser</* grammar           */   Java1_grammar_name,
                      /* AST traversals    */   1,
                      /* actions           */   true,
                      /* debug_parser      */   false,
                      /* debug_trace       */   false,
                      /* expecting         */   true,
                      /* insensitive       */   false,
                      /* lookaheads        */   1,
                      /* make_ast          */   false,
                      /* nd_parsing        */   false,
                      /* nd_threads        */   0,
                      /* node_actions      */   false,
                      /* reversable        */   false,
                      /* semantics         */   false,
                      /* stksize           */   100,
                      /* term_actions      */   true,
                      /* lexer table type  */   Java1_lexer_t,
                      /* parser table type */   Java1_parser_tables_t> Java1_parser_t;

#endif
