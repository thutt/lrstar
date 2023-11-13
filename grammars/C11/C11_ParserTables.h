
////////////////////////////////////////////////////////////////////////////////
//
//    C11_ParserTables.h (generated by LRSTAR 24.0.017)

      #pragma once

      #include "lrstar_library_defs.h"

      enum termcon
      {
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
         XOR_ASSIGN = 74
      };


      class lrstar_parser_tables
      {
         friend class lrstar_parser;
         public:
         static const char *term_symb[    99]; // Terminal symbols of the grammar.
         static const char *head_symb[    78]; // Nonterminal symbols of the grammar.
         static const char *tact_name[     2]; // Terminal action names found in the grammar.
         static const uint8  head_numb[   275]; // Head symbol number for a production.
         static const uint16 f_tail   [   276]; // First tail in a production.
         static const int8   tail     [   647]; // Tail symbol number.
         static const int8   arga     [    99]; // Arguments for terminal actions.

         private:
         static const uint8  Bm[   283]       ; // Boolean matrix.
         static const uint16 Br[   256]       ; // Boolean matrix row.
         static const uint8  Bc[    99]       ; // Boolean matrix column.
         static const uint8 Bf[    99]       ; // Boolean matrix filter/mask.
         static const int16  Tm[  1295]       ; // Terminal transition matrix.
         static const uint16 Tr[   256]       ; // Terminal transition matrix row.
         static const uint8  Tc[    99]       ; // Terminal transition matrix column.
         static const int16  Nm[  3182]       ; // Nonterminal transition matrix.
         static const uint16 Nr[   256]       ; // Nonterminal transition matrix row.
         static const uint8  Nc[   275]       ; // Nonterminal transition matrix column.
         static const uint8  Rm[     1]       ; // Reduction matrix.
         static const uint8  Rr[   256]       ; // Reduction matrix row.
         static const uint8  Rc[    99]       ; // Reduction matrix column.
         static const uint8  PL[   275]       ; // Production length minus one.

         static const int8   tact_numb[    99]; // Terminal action numbers.

         static int    (*tact_func[    2])(void *parser, int &t); // Terminal action function pointers.
      };

//
////////////////////////////////////////////////////////////////////////////////

