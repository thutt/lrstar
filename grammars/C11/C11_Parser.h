// Generated by LRSTAR 24.0.017
// DO NOT EDIT.

#if !defined(__C11_Parser_H)
#define __C11_Parser_H

#include "lrstar_basic_defs.h"
#include "lrstar_lexer.h"

enum termcon {
   ERROR = 0,
   F_CONSTANT = 2,
   IDENTIFIER = 3,
   I_CONSTANT = 4,
   STRING_LITERAL = 5,
   ADD_ASSIGN = 6,
   ALIGNAS = 7,
   ALIGNOF = 8,
   AND_ASSIGN = 9,
   AND_OP = 10,
   ATOMIC = 11,
   AUTO = 12,
   BOOL = 13,
   BREAK = 14,
   CASE = 15,
   CHAR = 16,
   COMPLEX = 17,
   CONST = 18,
   CONTINUE = 19,
   DEC_OP = 20,
   DEFAULT = 21,
   DIV_ASSIGN = 22,
   DO = 23,
   DOUBLE = 24,
   ELLIPSIS = 25,
   ELSE = 26,
   ENUM = 27,
   ENUM_CONSTANT = 28,
   EQ_OP = 29,
   EXTERN = 30,
   FLOAT = 31,
   FOR = 32,
   FUNC_NAME = 33,
   GENERIC = 34,
   GE_OP = 35,
   GOTO = 36,
   IF = 37,
   IMAGINARY = 38,
   INC_OP = 39,
   INLINE = 40,
   INT = 41,
   LEFT_ASSIGN = 42,
   LEFT_OP = 43,
   LE_OP = 44,
   LONG = 45,
   MOD_ASSIGN = 46,
   MUL_ASSIGN = 47,
   NE_OP = 48,
   NORETURN = 49,
   OR_ASSIGN = 50,
   OR_OP = 51,
   PTR_OP = 52,
   REGISTER = 53,
   RESTRICT = 54,
   RETURN = 55,
   RIGHT_ASSIGN = 56,
   RIGHT_OP = 57,
   SHORT = 58,
   SIGNED = 59,
   SIZEOF = 60,
   STATIC = 61,
   STATIC_ASSERT = 62,
   STRUCT = 63,
   SUB_ASSIGN = 64,
   SWITCH = 65,
   THREAD_LOCAL = 66,
   TYPEDEF = 67,
   TYPEDEF_NAME = 68,
   UNION = 69,
   UNSIGNED = 70,
   VOID = 71,
   VOLATILE = 72,
   WHILE = 73,
   XOR_ASSIGN = 74,
};

#include "C11_ParserTables_typedef.h"
#include "lrstar_parser.h"

extern const char C11_grammar_name[];

typedef lrstar_parser</* grammar           */   C11_grammar_name,
                      /* AST traversals    */   1,
                      /* actions           */   true,
                      /* debug_parser      */   false,
                      /* debug_trace       */   false,
                      /* expecting         */   true,
                      /* insensitive       */   false,
                      /* lookaheads        */   10,
                      /* make_ast          */   false,
                      /* nd_parsing        */   true,
                      /* nd_threads        */   2,
                      /* node_actions      */   false,
                      /* reversable        */   false,
                      /* semantics         */   false,
                      /* stksize           */   100,
                      /* term_actions      */   true,
                      /* lexer table type  */   C11_lexer_t,
                      /* parser table type */   C11_parser_tables_t> C11_parser_t;

#endif
