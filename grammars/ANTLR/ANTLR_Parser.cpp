#include "lrstar_basic_defs.h"
#include "lrstar_parser_tables.h"
#include "ANTLR_LexerTables_typedef.h"
#include "ANTLR_ParserTables_typedef.h"
#include "ANTLR_Parser.h"

template<>
const int ANTLR_parser_tables_t::n_term_symb = 43;

template<>
const int ANTLR_parser_tables_t::n_head_symb = 126;

template<>
const int ANTLR_parser_tables_t::n_tact_name = 2;

template<>
const int ANTLR_parser_tables_t::n_node_name = 0;

template<>
const int ANTLR_parser_tables_t::n_head_numb = 213;

template<>
const int ANTLR_parser_tables_t::n_f_tail = 214;

template<>
const int ANTLR_parser_tables_t::n_tail = 327;

template<>
const int ANTLR_parser_tables_t::n_arga = 43;

template<>
const int ANTLR_parser_tables_t::n_argx = 0;

template<>
const int ANTLR_parser_tables_t::n_argy = 0;

template<>
const int ANTLR_parser_tables_t::n_Bm = 163;

template<>
const int ANTLR_parser_tables_t::n_Br = 148;

template<>
const int ANTLR_parser_tables_t::n_Bc = 43;

template<>
const int ANTLR_parser_tables_t::n_Bf = 43;

template<>
const int ANTLR_parser_tables_t::n_Tm = 176;

template<>
const int ANTLR_parser_tables_t::n_Tr = 148;

template<>
const int ANTLR_parser_tables_t::n_Tc = 43;

template<>
const int ANTLR_parser_tables_t::n_Nm = 394;

template<>
const int ANTLR_parser_tables_t::n_Nr = 148;

template<>
const int ANTLR_parser_tables_t::n_Nc = 213;

template<>
const int ANTLR_parser_tables_t::n_Rm = 121;

template<>
const int ANTLR_parser_tables_t::n_Rr = 148;

template<>
const int ANTLR_parser_tables_t::n_Rc = 43;

template<>
const int ANTLR_parser_tables_t::n_PL = 213;

template<>
const int ANTLR_parser_tables_t::n_nd_fterm = 0;

template<>
const int ANTLR_parser_tables_t::n_nd_term = 0;

template<>
const int ANTLR_parser_tables_t::n_nd_faction = 0;

template<>
const int ANTLR_parser_tables_t::n_nd_action = 0;

template<>
const int ANTLR_parser_tables_t::n_tact_numb = 43;

template<>
const int ANTLR_parser_tables_t::n_node_numb = 0;

template<>
const int ANTLR_parser_tables_t::n_nact_numb = 0;

template<>
const int ANTLR_parser_tables_t::n_reverse = 0;

template<>
const int ANTLR_parser_tables_t::n_terms = 43; // Number of terminals.

template<>
const int ANTLR_parser_tables_t::n_heads = 126; // Number of nonterminals.

template<>
const int ANTLR_parser_tables_t::n_prods = 213; // Number of productions.

template<>
const int ANTLR_parser_tables_t::n_states = 148; // Number of states.

template<>
const int ANTLR_parser_tables_t::accept_state = 147; // Accept state.

template<>
const int ANTLR_parser_tables_t::n_termactns = 2; // Number of terminal actions.

template<>
const int ANTLR_parser_tables_t::n_nodenames = 0; // Number of node names.

template<>
const int ANTLR_parser_tables_t::n_nodeactns = 0; // Number of node actions.

template<>
const int ANTLR_parser_tables_t::eof_symb = 1; // <eof> symbol number.

template<>
const int ANTLR_parser_tables_t::err_used = 1; // <error> used in grammar?


// Terminal symbols of the grammar.
static const char *term_symb_[43] = {
   "<error>",
   "<eof>",
   "<integer>",
   "<string_literal>",
   "<lexer_char_set>",
   "<rule_ref>",
   "<token_ref>",
   "\'grammar\'",
   "\'parser\'",
   "\'lexer\'",
   "\'options\'",
   "\'tokens\'",
   "\'channels\'",
   "\'import\'",
   "\'fragment\'",
   "\'returns\'",
   "\'locals\'",
   "\'throws\'",
   "\'catch\'",
   "\'finally\'",
   "\'mode\'",
   "\';\'",
   "\':\'",
   "\'::\'",
   "\',\'",
   "\'(\'",
   "\')\'",
   "\'->\'",
   "\'<\'",
   "\'>\'",
   "\'=\'",
   "\'?\'",
   "\'*\'",
   "\'+=\'",
   "\'+\'",
   "\'|\'",
   "\'..\'",
   "\'.\'",
   "\'@\'",
   "\'#\'",
   "\'~\'",
   "\'{\'",
   "\'}\'",
};

template<>
const char * const *ANTLR_parser_tables_t::term_symb = &term_symb_[0];

// Nonterminal symbols of the grammar.
static const char *head_symb_[126] = {
   "Goal",
   "grammarSpec",
   "grammarType",
   "prequelConstruct",
   "optionsSpec",
   "option",
   "optionValue",
   "delegateGrammars",
   "delegateGrammar",
   "tokensSpec",
   "channelsSpec",
   "idList",
   "action",
   "actionScopeName",
   "actionBlock",
   "argActionBlock",
   "modeSpec",
   "rules",
   "ruleSpec",
   "parserRuleSpec",
   "exceptionGroup",
   "exceptionHandler",
   "finallyClause",
   "rulePrequel",
   "ruleReturns",
   "throwsSpec",
   "localsSpec",
   "ruleAction",
   "ruleBlock",
   "ruleAltList",
   "labeledAlt",
   "lexerRule",
   "lexerRuleBlock",
   "lexerAltList",
   "lexerAlt",
   "lexerElements",
   "lexerElement",
   "labeledLexerElement",
   "lexerBlock",
   "lexerCommands",
   "lexerCommand",
   "lexerCommandName",
   "lexerCommandExpr",
   "altList",
   "alternative",
   "element",
   "actionElement",
   "argActionElement",
   "labeledElement",
   "ebnf",
   "blockSuffix",
   "ebnfSuffix",
   "lexerAtom",
   "atom",
   "notSet",
   "blockSet",
   "setElement",
   "block",
   "ruleref",
   "range",
   "terminal",
   "elementOptions",
   "elementOption",
   "identifier",
   "qid",
   "ACTION_CONTENT",
   "ARGUMENT_CONTENT",
   "prequelConstruct*",
   "modeSpec*",
   "('lexer' 'grammar' | 'parser' 'grammar' | 'grammar')",
   "(option ';')",
   "(option ';')*",
   "('.' identifier)",
   "('.' identifier)*",
   "(',' delegateGrammar)",
   "(',' delegateGrammar)*",
   "idList?",
   "(',' identifier)",
   "(',' identifier)*",
   "','?",
   "(actionScopeName '::')",
   "(actionScopeName '::')?",
   "ACTION_CONTENT*",
   "ARGUMENT_CONTENT*",
   "lexerRule*",
   "ruleSpec*",
   "argActionBlock?",
   "ruleReturns?",
   "throwsSpec?",
   "localsSpec?",
   "rulePrequel*",
   "exceptionHandler*",
   "finallyClause?",
   "(',' qid)",
   "(',' qid)*",
   "('|' labeledAlt)",
   "('|' labeledAlt)*",
   "('#' identifier)",
   "('#' identifier)?",
   "'fragment'?",
   "optionsSpec?",
   "('|' lexerAlt)",
   "('|' lexerAlt)*",
   "lexerCommands?",
   "lexerElement+",
   "ebnfSuffix?",
   "('=' | '+=')",
   "(lexerAtom | lexerBlock)",
   "(optionsSpec ':')",
   "(optionsSpec ':')?",
   "(',' lexerCommand)",
   "(',' lexerCommand)*",
   "('|' alternative)",
   "('|' alternative)*",
   "elementOptions?",
   "element+",
   "'?'?",
   "(atom | block)",
   "blockSuffix?",
   "('|' setElement)",
   "('|' setElement)*",
   "ruleAction*",
   "(optionsSpec? ruleAction* ':')",
   "(optionsSpec? ruleAction* ':')?",
   "(',' elementOption)",
   "(',' elementOption)*",
};

template<>
const char * const *ANTLR_parser_tables_t::head_symb = &head_symb_[0];

// Terninal action names found in the grammar ...
static const char *tact_name_[2] = {
   "error",
   "lookup",
};

template<>
const char * const *ANTLR_parser_tables_t::tact_name = &tact_name_[0];

template<>
const char * const *ANTLR_parser_tables_t::node_name = 0;

// Head symbol numbers for the productions.
static const uint8 head_numb_[213] = {
       0,     1,     2,     3,     3,     3,     3,     3,     4,     5, 
       6,     6,     6,     6,     7,     8,     8,     9,    10,    11, 
      12,    13,    13,    13,    14,    15,    16,    17,    18,    18, 
      19,    20,    21,    22,    23,    23,    24,    25,    26,    27, 
      28,    29,    30,    31,    32,    33,    34,    34,    35,    36, 
      36,    36,    36,    37,    38,    39,    40,    40,    41,    41, 
      42,    42,    43,    44,    44,    45,    45,    45,    45,    45, 
      46,    47,    48,    49,    50,    51,    51,    51,    52,    52, 
      52,    52,    52,    52,    53,    53,    53,    53,    53,    54, 
      54,    55,    56,    56,    56,    56,    57,    58,    59,    60, 
      60,    61,    62,    62,    63,    63,    64,    65,    66,    67, 
      67,    68,    68,    69,    69,    69,    70,    71,    71,    72, 
      73,    73,    74,    75,    75,    76,    76,    77,    78,    78, 
      79,    79,    80,    81,    81,    82,    82,    83,    83,    84, 
      84,    85,    85,    86,    86,    87,    87,    88,    88,    89, 
      89,    90,    90,    91,    91,    92,    92,    93,    94,    94, 
      95,    96,    96,    97,    98,    98,    99,    99,   100,   100, 
     101,   102,   102,   103,   103,   104,   104,   105,   105,   106, 
     106,   107,   107,   108,   109,   109,   110,   111,   111,   112, 
     113,   113,   114,   114,   115,   115,   116,   116,   117,   117, 
     118,   118,   119,   120,   120,   121,   121,   122,   123,   123, 
     124,   125,   125, 
};

template<>
const uint8 *ANTLR_parser_tables_t::head_numb = &head_numb_[0];

// First tail symbol index into the tail list ...
static const uint16 f_tail_[214] = {
       0,     2,     8,     9,    10,    11,    12,    13,    14,    18, 
      21,    23,    24,    25,    26,    30,    33,    34,    38,    42, 
      45,    49,    50,    51,    52,    55,    58,    62,    63,    64, 
      65,    75,    77,    80,    82,    83,    84,    86,    89,    91, 
      94,    95,    97,    99,   105,   106,   108,   110,   110,   111, 
     113,   115,   117,   118,   121,   125,   128,   132,   133,   134, 
     135,   136,   137,   139,   141,   141,   143,   145,   146,   147, 
     148,   151,   154,   157,   159,   160,   162,   164,   166,   167, 
     168,   169,   170,   171,   173,   174,   175,   176,   177,   179, 
     181,   183,   187,   189,   191,   192,   193,   197,   200,   203, 
     205,   207,   211,   212,   215,   216,   217,   219,   220,   221, 
     221,   223,   223,   225,   227,   229,   230,   232,   232,   234, 
     236,   236,   238,   240,   240,   242,   242,   243,   245,   245, 
     247,   247,   248,   250,   250,   251,   251,   253,   253,   255, 
     255,   257,   257,   259,   259,   260,   260,   261,   261,   262, 
     262,   263,   263,   265,   265,   267,   267,   268,   270,   270, 
     272,   274,   274,   276,   278,   278,   279,   279,   280,   280, 
     281,   283,   283,   285,   285,   286,   287,   289,   289,   290, 
     291,   292,   293,   294,   296,   296,   297,   299,   299,   301, 
     303,   303,   305,   305,   306,   307,   309,   309,   310,   311, 
     312,   312,   313,   315,   315,   317,   317,   319,   322,   322, 
     323,   325,   325,   327, 
};

template<>
const uint16 *ANTLR_parser_tables_t::f_tail = &f_tail_[0];

// Tail symbol numbers ...
static const int8 tail_[327] = {
      -1,     1,    -2,   -63,    21,   -67,   -17,   -68,   -69,    -4, 
      -7,    -9,   -10,   -12,    10,    41,   -71,    42,   -63,    30, 
      -6,   -63,   -73,     3,   -14,     2,    13,    -8,   -75,    21, 
     -63,    30,   -63,   -63,    11,    41,   -76,    42,    12,    41, 
     -76,    42,   -63,   -78,   -79,    38,   -81,   -63,   -14,   -63, 
       9,     8,    41,   -82,    42,    41,   -83,    42,    20,   -63, 
      21,   -84,   -85,   -19,   -31,     5,   -86,   -87,   -88,   -89, 
     -90,    22,   -28,    21,   -20,   -91,   -92,    18,   -15,   -14, 
      19,   -14,    -4,   -27,    15,   -15,    17,   -64,   -94,    16, 
     -15,    38,   -63,   -14,   -29,   -30,   -96,   -44,   -98,   -99, 
       6,  -100,    22,   -32,    21,   -33,   -34,  -102,   -35,  -103, 
    -104,   -37,  -105,   -52,  -105,   -38,  -105,   -46,   -63,  -106, 
    -107,    25,  -109,   -33,    26,    27,   -40,  -111,   -41,    25, 
     -42,    26,   -41,   -63,    20,   -63,     2,   -44,  -113,  -114, 
    -115,   -48,  -105,   -53,  -105,   -49,   -46,   -47,   -14,  -116, 
    -114,   -15,  -116,  -114,   -63,  -106,  -117,   -57,  -118,   -51, 
      31,  -116,    32,  -116,    34,  -116,   -59,   -60,     5,   -54, 
       4,    37,  -114,   -59,   -60,   -58,   -54,    37,  -114,    40, 
     -56,    40,   -55,    25,   -56,  -120,    26,     6,  -114,     3, 
    -114,   -59,     4,    25,  -123,   -43,    26,     5,   -86,  -114, 
       3,    36,     3,     6,  -114,     3,  -114,    28,   -62,  -125, 
      29,   -64,   -63,    30,    -6,     5,     6,   -63,   -73,     0, 
       0,   -67,    -3,   -68,   -16,     9,     7,     8,     7,     7, 
      -5,    21,   -71,   -70,    37,   -63,   -73,   -72,    24,    -8, 
     -75,   -74,   -11,    24,   -63,   -78,   -77,    24,   -13,    23, 
     -80,   -82,   -65,   -83,   -66,   -84,   -31,   -85,   -18,   -15, 
     -24,   -25,   -26,   -90,   -23,   -91,   -21,   -22,    24,   -64, 
     -94,   -93,    35,   -30,   -96,   -95,    39,   -63,   -97,    14, 
      -4,    35,   -34,  -102,  -101,   -39,   -36,  -104,   -36,   -51, 
      30,    33,   -52,   -38,    -4,    22,  -108,    24,   -40,  -111, 
    -110,    35,   -44,  -113,  -112,   -61,   -45,  -115,   -45,    31, 
     -53,   -57,   -50,    35,   -56,  -120,  -119,  -121,   -27,  -100, 
    -121,    22,  -122,    24,   -62,  -125,  -124, 
};

template<>
const int8 *ANTLR_parser_tables_t::tail = &tail_[0];

// Arguments for token actions ...
static const int8 arga_[43] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1, 
};

template<>
const int8 *ANTLR_parser_tables_t::arga = &arga_[0];

template<>
const int32 *ANTLR_parser_tables_t::argx = 0;

template<>
const int32 *ANTLR_parser_tables_t::argy = 0;

// Boolean matrix ...
static const uint8 Bm_[163] = {
     120,     0,    32,     0,    25,   120,     0,    32,     0,     9, 
     104,     0,    32,     0,    25,   104,     0,    32,     0,     9, 
     108,     0,     0,     0,    16,    88,     0,    32,     0,     0, 
       6,     0,     0,     2,    96,     1,     0,     0,     0,    96, 
       0,     0,     0,    96,     0,     1,     0,     0,    88,     0, 
       0,     0,     0,     2,     4,     0,     2,   100,     0,     0, 
       0,   128,     1,     0,     0,     0,    96,     0,     0,     0, 
       0,    32,     8,     0,     0,     0,    18,     0,     0,     0, 
      24,     0,     0,     0,    36,     0,     0,     0,   129,     0, 
       0,    16,     2,     0,     0,    64,    64,     0,     0,     4, 
       0,     2,     0,     0,     0,   128,     0,     0,     0,     0, 
       2,     0,     0,     0,     0,    16,     0,     0,     1,     0, 
      64,     0,     0,     0,     0,     4,     0,     0,     8,     0, 
       0,    16,     0,     0,     0,    32,     0,     0,     0,     8, 
       0,     0,     0,     1,     0,     0,     0,    64,     0,     8, 
       0,     0,     0,     0,     1,     0,     0,    64,     0,     0, 
       0,     0,     0, 
};

template<>
const uint8 *ANTLR_parser_tables_t::Bm = &Bm_[0];

// Boolean matrix row (for state)...
static const uint8 Br_[148] = {
      61,   101,    66,   105,   105,   108,   158,    29,   158,    71, 
     111,    66,   111,   111,    34,   116,   120,   111,   158,   158, 
     122,    66,    66,    66,   126,    66,   100,   130,   158,    39, 
      74,    66,    67,   158,    67,   111,   108,   123,   119,   111, 
      35,   108,   122,    66,   113,   158,   158,     0,   134,    66, 
      20,    66,    35,   138,   108,   158,   103,     0,    77,    81, 
      77,    77,   136,   158,   140,    85,    25,   140,   100,   158, 
     111,   158,   158,   158,   144,    43,   136,   136,   136,     5, 
     140,    66,   149,   140,    85,    48,     0,   123,    52,   113, 
     150,   150,     0,   158,   133,   140,   158,   122,   158,   155, 
     140,    66,    66,    66,   113,    57,    89,    20,    93,   108, 
     158,   121,    10,   111,    43,   155,    66,    48,   158,   144, 
      66,    10,    77,    81,    77,    77,   136,   111,   140,   100, 
     158,   104,   140,    15,   140,   140,   140,   158,   111,   111, 
     111,   155,   158,    97,   111,   144,   140,   158, 
      };

template<>
const uint8 *ANTLR_parser_tables_t::Br = &Br_[0];

// Boolean matrix column (displacement) ...
static const uint8 Bc_[43] = {
       0,     0,     0,     0,     0,     0,     0,     0,     1,     1, 
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1, 
       2,     2,     2,     2,     2,     2,     2,     2,     3,     3, 
       3,     3,     3,     3,     3,     3,     3,     4,     4,     4, 
       4,     4,     4, 
      };

template<>
const uint8 *ANTLR_parser_tables_t::Bc = &Bc_[0];

// Boolean matrix filter/mask value ...
static const uint8 Bf_[43] = {
       1,     2,     4,     8,    16,    32,    64,   128,     1,     1, 
       2,     4,     4,     4,     8,    16,    32,    64,   128,   128, 
       1,     2,     4,     8,    16,    32,    64,   128,     1,     2, 
       4,     8,    16,    32,    16,    64,   128,     1,     2,     4, 
       8,    16,    32, 
};

template<>
const uint8 *ANTLR_parser_tables_t::Bf = &Bf_[0];

// Terminal transition matrix ...
static const int16 Tm_[176] = {
     147,   105,    17,    26,   103,    10,    12,    13,    11,  -167, 
      39,    70,    49,   139,   138,     6,    47,  -132,    51,   -54, 
      75,    81,  -113,    31,  -197,   -98,    25,    14,    92,    82, 
     120,    18,   -17,    66,   129,   140,    95,   128,    10,  -107, 
       0,     0,     0,     0,     0,     0,     0,     0,   -43,   100, 
       0,   116,   -91,     0,     0,  -101,  -179,     0,    65,  -180, 
     101,   117,     0,     0,    28,   -24,   -22,   -61,  -104,  -105, 
     -23,     0,     0,     0,     0,     0,    66,   129,   127,    64, 
     128,    46,  -183,     0,   102,   -56,     0,     0,  -114,    50, 
      76,    77,   -59,    78,   132,     0,     0,    21,   -18,     3, 
      85,    65,    83,     4,   -95,  -108,     0,   130,     0,     0, 
       0,     0,     0,     0,  -116,  -207,     0,   114,   -96,     0, 
       0,  -115,   107,     0,    84,     0,   101,   146,     0,     0, 
      22,   -25,    66,    68,   -80,    95,    67,   -82,    66,    68, 
      63,    64,    67,   -82,   -13,  -104,  -105,   -14,     0,     0, 
      43,     0,     0,     0,     0,     0,     0,    65,   118,     0, 
       0,     0,     0,    65,     0,     0,     0,     0,   -11,    45, 
       0,     0,     0,     0,    45,    -8, 
};

template<>
const int16 *ANTLR_parser_tables_t::Tm = &Tm_[0];

// Terminal transition matrix row ...
static const uint8 Tr_[148] = {
      99,     0,    66,     0,    66,     0,     0,     0,     0,     0, 
       0,    66,    66,    99,    66,     0,     0,    33,     0,     0, 
       0,    66,    66,    66,     0,    66,     0,     0,     0,   143, 
     132,    66,     0,     0,    66,   143,    66,     0,     0,    33, 
      99,    99,    66,    66,     0,     0,     0,   138,     0,    66, 
     143,    66,    33,     0,    33,     0,     0,   138,    66,    33, 
      66,    66,     0,     0,     0,     0,    99,     0,     0,     0, 
      33,     0,     0,     0,     0,    66,     0,     0,     0,   132, 
       0,    66,     0,     0,     0,    99,   138,    66,    33,    66, 
       0,     0,   138,     0,     0,     0,     0,    99,     0,     0, 
       0,    66,    66,    66,    99,    66,    33,   143,    33,   143, 
       0,     0,    76,   143,    66,    66,    66,    99,     0,    66, 
      66,    76,    66,    33,    66,    66,     0,    33,     0,     0, 
       0,     0,     0,    33,     0,     0,     0,     0,   143,    33, 
      33,    99,     0,    99,   143,    99,     0,     0, 
};

template<>
const uint8 *ANTLR_parser_tables_t::Tr = &Tr_[0];

// Terminal transition matrix column ...
static const uint8 Tc_[43] = {
       6,     0,     1,    25,     5,     2,     3,    22,     4,     0, 
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14, 
      26,    15,    16,    17,    18,     1,    19,    20,    21,    22, 
      23,    24,    25,    26,    27,    28,    29,     4,    27,    30, 
       0,    31,    32, 
};

template<>
const uint8 *ANTLR_parser_tables_t::Tc = &Tc_[0];

// Nonterminal transition matrix ...
static const int16 Nm_[394] = {
       5,  -178,    37,   -30,  -146,  -148,  -150,  -169,   -49,    80, 
    -174,   -36,   -94,     1,     2,  -136,  -138,     7,    15,    -2, 
     -99,    29,  -121,  -124,    30,  -129,    44,   -19,   -20,  -193, 
      52,    40,    53,  -156,    38,    48,    69,    88,   131,   -31, 
    -159,    89,  -162,   119,  -165,   -42,  -172,    74,   -46,  -140, 
    -206,  -112,  -188,   104,  -191,   145,    90,    79,    98,  -204, 
     108,   143,    16,  -154,  -212,   106,  -127,  -178,  -199,   135, 
       0,     0,     0,    -3,   -66,   134,     0,  -144,   -84,   -87, 
     -85,    35,  -178,  -142,    59,  -119,   -92,     0,    87,   -50, 
     -75,   -52,   -38,   -94,  -110,  -193,   -78,   -81,   -79,     9, 
       0,  -100,     0,     0,    58,   -88,   113,   -74,     0,   -39, 
    -193,     0,    62,  -176,  -193,    -6,    -5,  -198,     0,  -201, 
    -163,    20,    -7,   -72,    -4,     0,   -93,     0,     8,   -86, 
     -29,  -185,    86,    19,    60,  -193,     0,    91,   133,  -202, 
     -71,   -97,    61,    16,   -28,   -15,  -178,   137,    27,  -193, 
    -193,     0,  -169,   -65,   -77,     0,  -144,   -78,   -81,   -79, 
       0,   -21,    24,     0,   -73,   -70,   -58,     0,    59,   -44, 
       0,    72,     0,   -32,  -193,   -52,     0,    54,    94,    56, 
     -78,   -81,   -79,   141,   142,  -157,    93,     0,    58,  -134, 
      23,   112,     0,     0,   -53,  -181,    62,  -175,     0,   123, 
    -193,   125,     0,  -182,     0,    73,   -68,  -209,   136,    33, 
     126,   -84,   -87,   -85,     0,    42,     0,    55,    60,  -194, 
    -126,     0,    32,    33,    57,    -9,    61,    62,   -69,     0, 
       0,    36,  -178,   -12,  -126,  -118,    34,     0,   -34,   -51, 
     -76,   -58,   144,   -94,    41,   -90,     0,     0,     0,   -67, 
     124,   -83,    73,    94,     0,   121,     0,   122,   -60,   -33, 
    -193,  -186,   -86,    59,    99,   109,   -40,   110,     0,   115, 
     -52,   111,  -103,    20,    56,   -78,   -81,   -79,   112,     0, 
     -12,   -35,     0,    58,     0,  -122,  -189,  -193,  -152,   -89, 
       0,    62,  -175,   112,   123,     0,   125,     0,     0,     0, 
       0,   -68,  -193,     0,    59,   126,   -84,   -87,   -85,     0, 
       0,   -52,    55,    60,  -195,    56,   -78,   -81,   -79,    57, 
       0,    61,    62,   -69,    58,     0,    72,    97,    97,     0, 
       0,     0,    62,  -175,     0,  -160,     0,     0,     0,   111, 
      71,  -102,  -102,     0,   -67,   124,   112,    96,  -210,     0, 
       0,     0,   122,  -170,    60,  -193,     0,   -86,     0,     0, 
      57,     0,    61,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0, 
};

template<>
const int16 *ANTLR_parser_tables_t::Nm = &Nm_[0];

// Nonterminal transition matrix row ...
static const uint16 Nr_[148] = {
    0,     0,     0,     0,     0,     0,     0,    66,     0,    81, 
    0,   121,     0,     0,   161,     0,     0,   145,     0,     0, 
    0,   209,   223,    81,     0,   231,     0,     0,     0,   215, 
    0,   145,     0,     0,     0,     0,     0,     0,     0,     0, 
    0,     0,     0,   273,     0,     0,     0,   168,     0,   326, 
  205,    66,     0,     0,     0,     0,     0,    84,     0,     0, 
   81,   231,     0,     0,     0,    81,   231,   231,    81,     0, 
   81,     0,     0,    81,     0,   166,    81,   231,   145,   145, 
  145,   327,     0,    66,   106,     0,   263,     0,   231,     0, 
    0,     0,   304,     0,     0,     0,     0,     0,     0,     0, 
  258,   106,   171,    85,     0,   258,     0,   252,     0,     0, 
    0,     0,   199,    81,   241,     0,   328,    81,     0,     0, 
  120,   294,   145,    81,    66,   106,    66,    66,    85,   145, 
    0,     0,   326,    66,   120,   121,   171,     0,   231,   231, 
   66,     0,     0,     0,   145,     0,   273,     0, 
};

template<>
const uint16 *ANTLR_parser_tables_t::Nr = &Nr_[0];

// Nonterminal transition matrix column ...
static const uint8 Nc_[213] = {
    0,    13,    14,    28,    28,    28,    28,    28,     7,    29, 
   20,    20,    20,    20,    58,    12,    12,    50,    49,    11, 
   56,     1,     1,     1,    28,    11,    51,    62,     2,     2, 
   63,     3,    63,    33,    57,    57,     4,     5,     6,    50, 
    7,     8,     9,    49,     9,     1,    49,    49,    11,    29, 
   29,    29,    29,    20,    58,    10,    20,    20,    12,    12, 
   11,    11,    12,    13,    13,    20,    20,    20,    20,    20, 
    7,    29,    58,    50,    13,     1,     1,     1,    50,    50, 
   50,    50,    50,    50,    51,    51,    51,    51,    51,    13, 
   13,    14,    58,    58,    58,    58,     2,    63,    12,    14, 
   14,    29,    20,    20,     0,     0,    14,    15,    16,    17, 
   17,    18,    18,    19,    19,    19,    20,    21,    21,    22, 
   56,    56,    23,    24,    24,    13,    13,    25,    26,    26, 
   27,    27,    28,    29,    29,    30,    30,    31,    31,    32, 
   32,    33,    33,     3,     3,    34,    34,    35,    35,    36, 
   36,    37,    37,    38,    38,    39,    39,    40,    41,    41, 
   42,    43,    43,    44,    45,    45,    62,    62,     2,     2, 
   46,    47,    47,    48,    48,    56,    56,     8,     8,    57, 
   57,    49,    49,    50,    51,    51,    52,    53,    53,    54, 
   55,    55,    20,    20,    56,    56,     9,     9,    57,    57, 
   58,    58,    59,    60,    60,    61,    61,    62,    63,    63, 
   64,    65,    65, 
};

template<>
const uint8 *ANTLR_parser_tables_t::Nc = &Nc_[0];

// Reduction matrix ...
static const uint8 Rm_[121] = {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,    27,     0,     0,   166,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,    26,     0,     0, 
     166,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
      80,    80,    80,    80,     0,    80,     0,   104,    80,    80, 
       0,    80,     0,     0,   192,   192,   192,   192,     0,   192, 
       0,   105,   192,   192,   192,   192,     0,     0,   192,     0, 
     192,    64,     0,     0,     0,     0,     0,    64,    64,   192, 
       0,     0,   143,     0,   143,   143,     0,   143,   143,   104, 
     143,   143,   143,     0,     0,   208,     0,   208,     0,   168, 
     208,   208,     0,     0,   208,     0,   208,     0,     0,   192, 
       0,   192,     0,     0,    64,     0,     0,     0,    64,     0, 
     192, 
};

template<>
const uint8 *ANTLR_parser_tables_t::Rm = &Rm_[0];

// Reduction matrix row ...
static const int16 Rr_[148] = {
       0,     0,     0,     0,     0,     0,   109,   141,   111,   -13, 
       0,     0,     0,     0,     0,     1,     0,   143,   117,   123, 
      16,   125,   125,     0,     0,     0,   168,   145,   137,     0, 
       0,     0,     0,   128,     0,     0,     0,     0,   147,     0, 
       0,     0,     0,     0,   130,   135,   139,    47,   149,     0, 
       0,   131,     0,   -26,     0,   171,   173,    48,   177,     0, 
     177,   177,   196,   -38,   -52,   192,     0,   192,   184,   151, 
       0,   158,   120,   120,    45,     0,   196,   196,   196,     0, 
     192,     0,     0,   192,   192,     0,    47,     0,     0,    37, 
     106,    10,    47,   187,    57,   192,   211,   120,   203,     0, 
     -66,     0,     0,     0,    55,     0,     0,     0,     0,     0, 
     161,   164,     0,     0,     0,     0,     0,     0,   153,    41, 
       0,    63,   177,     0,   177,   200,   196,   -80,   192,   -93, 
     135,   155,   -66,     0,   192,   192,  -107,   205,     0,     0, 
     143,     0,   190,     0,     0,    62,  -107,     0, 
};

template<>
const int16 *ANTLR_parser_tables_t::Rr = &Rr_[0];

// Reduction matrix column ...
static const uint8 Rc_[43] = {
       0,     1,     0,     2,     3,     2,     4,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       1,     5,     6,     0,     0,     2,     7,     3,     8,     0, 
       9,    10,    10,     9,    10,    11,     0,     2,     6,    12, 
       2,    13,     0, 
};

template<>
const uint8 *ANTLR_parser_tables_t::Rc = &Rc_[0];

// Production lengths (minus one) ...
static const int8 PL_[213] = {
       1,     5,     0,     0,     0,     0,     0,     0,     3,     2, 
       1,     0,     0,     0,     3,     2,     0,     3,     3,     2, 
       3,     0,     0,     0,     2,     2,     3,     0,     0,     0, 
       9,     1,     2,     1,     0,     0,     1,     2,     1,     2, 
       0,     1,     1,     5,     0,     1,     1,    -1,     0,     1, 
       1,     1,     0,     2,     3,     2,     3,     0,     0,     0, 
       0,     0,     1,     1,    -1,     1,     1,     0,     0,     0, 
       2,     2,     2,     1,     0,     1,     1,     1,     0,     0, 
       0,     0,     0,     1,     0,     0,     0,     0,     1,     1, 
       1,     3,     1,     1,     0,     0,     3,     2,     2,     1, 
       1,     3,     0,     2,     0,     0,     1,     0,     0,    -1, 
       1,    -1,     1,     1,     1,     0,     1,    -1,     1,     1, 
      -1,     1,     1,    -1,     1,    -1,     0,     1,    -1,     1, 
      -1,     0,     1,    -1,     0,    -1,     1,    -1,     1,    -1, 
       1,    -1,     1,    -1,     0,    -1,     0,    -1,     0,    -1, 
       0,    -1,     1,    -1,     1,    -1,     0,     1,    -1,     1, 
       1,    -1,     1,     1,    -1,     0,    -1,     0,    -1,     0, 
       1,    -1,     1,    -1,     0,     0,     1,    -1,     0,     0, 
       0,     0,     0,     1,    -1,     0,     1,    -1,     1,     1, 
      -1,     1,    -1,     0,     0,     1,    -1,     0,     0,     0, 
      -1,     0,     1,    -1,     1,    -1,     1,     2,    -1,     0, 
       1,    -1,     1, 
};

template<>
const int8 *ANTLR_parser_tables_t::PL = &PL_[0];

template<>
const int32 *ANTLR_parser_tables_t::nd_fterm = 0;

template<>
const int32 *ANTLR_parser_tables_t::nd_term = 0;

template<>
const int32 *ANTLR_parser_tables_t::nd_faction = 0;

template<>
const int32 *ANTLR_parser_tables_t::nd_action = 0;

// Terminal action number ...
static const int8 tact_numb_[43] = {
       0,    -1,     1,     1,     1,     1,     1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1, 
};

template<>
const int8 *ANTLR_parser_tables_t::tact_numb = &tact_numb_[0];

template<>
const int32 *ANTLR_parser_tables_t::node_numb = 0;

template<>
const int32 *ANTLR_parser_tables_t::nact_numb = 0;

template<>
const int32 *ANTLR_parser_tables_t::reverse = 0;

