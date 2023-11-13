
////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    Zeus_ParserTables.hpp (generated by LRSTAR 24.0.017)

      #include "lrstar_basic_defs.h"
      #include "lrstar_parser_tables.h"
      #include "Zeus_ParserTables.h"
      #include "Zeus_Actions.h"

      static int n_terms      =   71; // Number of terminals.
      static int n_heads      =  114; // Number of nonterminals.
      static int n_prods      =  222; // Number of productions.
      static int n_states     =  229; // Number of states.
      static int accept_state =  228; // Accept state.
      static int n_termactns  =    2; // Number of terminal actions.
      static int n_nodenames  =    0; // Number of node names.
      static int n_nodeactns  =    0; // Number of node actions.
      static int eof_symb     =    1; // <eof> symbol number.
      static int err_used     =    0; // <error> used in grammar?

   // Terminal symbols of the grammar ...
      const char* lrstar_parser_tables::term_symb[71] = 
      {
         "<error>",
         "<eof>",
         "<identifier>",
         "\'DEFINITION\'",
         "\'HARDWARE_MODULE\'",
         "\';\'",
         "\'END\'",
         "\'.\'",
         "\'IMPLEMENTATION\'",
         "\'CONST\'",
         "\'SIGNAL_CONST\'",
         "\'IMPORT\'",
         "\'FROM\'",
         "\'EXPORT\'",
         "\'QUALIFIED\'",
         "\'..\'",
         "\'*\'",
         "\'(\'",
         "\')\'",
         "\',\'",
         "\'[\'",
         "\']\'",
         "\'NOT\'",
         "<number>",
         "\'DIV\'",
         "\'MOD\'",
         "\'AND\'",
         "\'+\'",
         "\'-\'",
         "\'OR\'",
         "\'=\'",
         "\'<>\'",
         "\'<\'",
         "\'<=\'",
         "\'>\'",
         "\'>=\'",
         "\'ARRAY\'",
         "\'OF\'",
         "\'IS\'",
         "\'TYPE\'",
         "\':\'",
         "\'IN\'",
         "\'OUT\'",
         "\'CLOCK\'",
         "\'PREDEFINED\'",
         "\'COMPONENT\'",
         "\'HARDWARE\'",
         "\'ELSEIF\'",
         "\'EXP\'",
         "\'THEN\'",
         "\'IF\'",
         "\'ELSE\'",
         "\'OTHERWISE_WHEN\'",
         "\'WHEN\'",
         "\'OTHERWISE\'",
         "\'CONNECT\'",
         "\'END.\'",
         "\'ORDER\'",
         "\'TOP\'",
         "\'RIGHT\'",
         "\'BOTTOM\'",
         "\'LEFT\'",
         "\'CONSTRAINTS\'",
         "\':=\'",
         "\'==\'",
         "\'TO\'",
         "\'BY\'",
         "\'FOR\'",
         "\'DO\'",
         "\'DOtherwiseWhenAltS\'",
         "\'RESULT\'"
      };

   // Nonterminal symbols of the grammar ...
      const char *lrstar_parser_tables::head_symb[114] = 
      {
         "Grammar",
         "HardwareCompilationUnit",
         "HardwareDefinitionModule",
         "HardwareImplementationModule",
         "HardwareModuleDecl",
         "DefinitionList",
         "Definition",
         "ConstDecl",
         "ControlConstDecl",
         "SignalConstDecl",
         "ImportList",
         "Import",
         "Export",
         "Period",
         "Qualident",
         "IndexRange",
         "Selector",
         "IndexRangeOrSelector",
         "IndexRangeOrSelectorList",
         "BrackIndexRangeOrSelectorList",
         "FieldSelector",
         "DesignatorSelector",
         "DesignatorSelectorList",
         "ProperDesignator",
         "Designator",
         "ParenConstExp",
         "NotConstFactor",
         "ExtendedDesignator",
         "ConstFactor",
         "MulOp",
         "HalfM",
         "MulExpList",
         "ConstTerm",
         "AddOp",
         "Sign",
         "HalfA",
         "AddExpList",
         "SimpleConstExp",
         "Relation",
         "RelationExp",
         "ConstExp",
         "ConstExpList",
         "BrackStrucConstExpList",
         "StrucConstExpList",
         "StrucConstExp",
         "SigConstExpList",
         "ParenSigConstExpList",
         "SigConstExp",
         "ConstCollection",
         "Cd",
         "SigConstExpOrConstCollection",
         "SignalCd",
         "Td",
         "Type",
         "ArrayDecl",
         "ExtendedQualident",
         "ArgumentsOrBody",
         "ComponentBody",
         "Body",
         "DStatement",
         "ParenStrucConstExpList",
         "TypeDecl",
         "Range",
         "RangeList",
         "SubRangeType",
         "IdList",
         "ParamKind",
         "FParam",
         "FParamList",
         "FP",
         "FPOrPredefined",
         "ComponentDecl",
         "ComponentHeading",
         "Hd",
         "HardwareDecl",
         "SimpleExp",
         "ExpList",
         "StrucExp",
         "ElseIfAlt",
         "ElseIfAltList",
         "IfExp",
         "OtherwiseWhenAlt",
         "OtherwiseWhenAltList",
         "WhenExp",
         "Exp",
         "Statement",
         "StatementList",
         "StatementSeq",
         "ConnectionSpec",
         "LCStatementSeq",
         "LCStatementList",
         "LCStatement",
         "Order",
         "Boundaries",
         "Boundary",
         "ConstraintSpec",
         "DesignatorList",
         "Basic",
         "AssignOp",
         "Assignment",
         "ElseIfAltS",
         "ElseIfAltSList",
         "IfStatement",
         "Connection",
         "VariableRange",
         "VariableRangeList",
         "ForConstDeclList",
         "ForStatement",
         "OtherwiseWhenAltS",
         "OtherwiseWhenAltSList",
         "WhenStatement",
         "DOtherwiseWhenAltSList",
         "DWhenStatement",
         "Result"
      };

   // Terninal action names found in the grammar ...
      const char *lrstar_parser_tables::tact_name[2] = 
      {
         "error",
         "lookup"
      };

   // Head symbol numbers for the productions ...
      const uint8 lrstar_parser_tables::head_numb[222] = 
      {
          0,    1,    1,    2,    3,    4,    4,    5,    5,    6,    6,    7,    7,    8,    8,    9,    9,   10,   10,   11,
         11,   12,   12,   13,   13,   14,   14,   15,   15,   16,   17,   17,   18,   18,   19,   20,   20,   21,   21,   22,
         22,   23,   24,   24,   25,   26,   27,   27,   28,   28,   28,   28,   29,   29,   29,   29,   30,   31,   31,   32,
         33,   33,   33,   34,   34,   35,   36,   36,   37,   37,   38,   38,   38,   38,   38,   38,   39,   40,   40,   41,
         41,   42,   43,   43,   44,   44,   45,   45,   46,   47,   47,   48,   49,   50,   50,   51,   52,   52,   53,   53,
         53,   54,   54,   55,   55,   56,   56,   57,   58,   58,   59,   59,   59,   59,   59,   59,   59,   60,   61,   61,
         62,   62,   63,   63,   64,   65,   65,   66,   66,   66,   66,   67,   67,   68,   68,   69,   69,   69,   69,   70,
         70,   71,   71,   72,   73,   74,   74,   75,   75,   75,   75,   76,   76,   77,   78,   79,   79,   80,   81,   82,
         82,   83,   84,   84,   84,   84,   85,   85,   85,   85,   85,   85,   85,   86,   86,   87,   87,   88,   89,   89,
         90,   90,   91,   91,   91,   91,   92,   93,   94,   94,   94,   94,   95,   96,   96,   97,   97,   98,   98,   99,
        100,  101,  101,  102,  102,  103,  103,  104,  104,  105,  105,  106,  106,  107,  108,  109,  109,  110,  111,  111,
        112,  113
      };

   // First tail symbol index into the tail list ...
      const uint16 lrstar_parser_tables::f_tail[223] = 
      {
          0,    2,    3,    4,   13,   15,   23,   32,   32,   34,   35,   36,   37,   38,   39,   42,   43,   46,   46,   48,
         51,   56,   59,   63,   64,   65,   66,   69,   70,   73,   78,   79,   80,   81,   84,   87,   89,   93,   94,   95,
         95,   97,   99,  100,  101,  104,  106,  107,  111,  112,  113,  114,  115,  116,  117,  118,  119,  121,  121,  123,
        125,  126,  127,  128,  129,  130,  132,  132,  134,  136,  139,  140,  141,  142,  143,  144,  145,  147,  148,  150,
        151,  154,  157,  158,  161,  162,  163,  164,  167,  170,  171,  172,  177,  180,  181,  182,  185,  188,  192,  193,
        194,  195,  198,  202,  203,  205,  206,  207,  210,  211,  213,  214,  215,  216,  217,  218,  219,  220,  225,  226,
        229,  232,  237,  238,  241,  244,  245,  248,  249,  250,  251,  252,  255,  259,  260,  263,  265,  268,  272,  277,
        278,  279,  280,  282,  284,  287,  288,  291,  292,  298,  300,  307,  308,  311,  315,  319,  319,  321,  329,  333,
        333,  335,  343,  344,  345,  346,  347,  348,  349,  350,  351,  352,  353,  354,  354,  356,  357,  360,  364,  365,
        368,  368,  370,  371,  372,  373,  375,  379,  382,  383,  384,  385,  386,  390,  391,  394,  395,  399,  400,  401,
        404,  408,  408,  410,  416,  424,  425,  427,  432,  439,  440,  443,  443,  447,  453,  457,  457,  459,  467,  467,
        469,  477,  479
      };

   // Tail symbol numbers ...
      const int8 lrstar_parser_tables::tail[479] = 
      {
         -1,    1,   -2,   -3,    3,    4,    2,    5,  -10,   -5,    6,    2,    7,    8,   -4,    4,    2,    5,  -10,  -58,
          6,    2,  -13,    4,    2,    5,  -10,  -12,  -58,    6,    2,  -13,   -5,   -6,   -7,  -61,   -8,   -9,    9,   -8,
        -49,    5,   10,   -9,  -51,    5,  -10,  -11,   11,  -65,    5,   12,    2,   11,  -65,    5,   13,  -65,    5,   13,
         14,  -65,    5,    7,    5,    2,  -14,    7,    2,  -40,  -40,   15,  -40,   16,    2,   17,  -24,   18,  -15,  -16,
        -17,  -18,   19,  -17,   20,  -18,   21,    7,    2,    7,    2,   15,    2,  -19,  -20,  -22,  -21,    2,  -22,  -23,
         16,   17,  -40,   18,   22,  -28,  -24,  -24,   17,  -41,   18,   23,  -25,  -26,  -27,   16,   24,   25,   26,  -29,
        -28,  -31,  -30,  -28,  -31,   27,   28,   29,   27,   28,  -33,  -32,  -36,  -35,  -32,  -36,  -34,  -32,  -36,   30,
         31,   32,   33,   34,   35,  -38,  -37,  -37,  -37,  -39,  -40,  -41,   19,  -40,   20,  -43,   21,  -44,  -43,   19,
        -44,  -40,  -42,  -47,  -45,   19,  -47,   17,  -45,   18,  -27,  -46,   17,    7,  -65,    7,   18,    2,   30,  -44,
        -47,  -48,    2,   30,  -50,    2,   30,  -53,    2,  -69,   30,  -53,  -54,  -71,  -55,   36,   37,  -53,   36,  -64,
         37,  -53,  -14,  -14,  -56,  -60,  -57,   38,  -58,    6,  -59,  -58,  -59,  -88,  -95, -112,   -7,  -61,  -74,   -4,
         17,    7,  -43,    7,   18,   39,  -61,  -52,    5,  -40,   15,  -40,  -40,   15,  -40,   40,    2,  -62,  -63,   19,
        -62,   20,  -63,   21,    2,  -65,   19,    2,   41,   42,   43,   39,  -65,   40,  -53,  -66,  -65,   40,  -53,  -67,
        -68,    5,  -67,   17,   18,   17,  -68,   18,   17,   18,   40,  -53,   17,  -68,   18,   40,  -53,  -69,   44,  -72,
        -72,  -57,   45,  -70,  -65,   40,  -53,   46,  -74,  -73,    5,  -24,  -24,   17,    7,  -43,    7,   18,  -24,  -84,
        -24,   17,    7,  -43,    7,   18,  -84,  -84,  -76,   19,  -84,   17,  -76,   18,  -22,   47,   48,   49,   48,  -79,
        -78,   50,  -84,   49,  -84,  -79,   51,  -84,    6,   52,  -40,   49,  -84,  -82,  -81,   53,  -40,   49,  -84,  -82,
         54,  -84,    6,  -75,  -77,  -80,  -83,  -99,  -97, -103, -102, -107, -110, -113,  -86,  -85,  -86,  -87,   19,  -86,
         55,  -87,   56,    5,  -90,  -89,    5,  -90,  -90,  -91,  -97, -107, -110,  -92,  -93,   57,    2,  -89,    6,  -94,
        -89,    6,   58,   59,   60,   61,   62,  -89,   56,    5,  -24,  -96,   19,  -24,  -96,   20,    2,   21,  -96,   63,
         64,  -24,  -98,  -84,   47,  -84,   49,  -87, -101, -100,   50,  -84,   49,  -87, -101,    6,   50,  -84,   49,  -87,
       -101,   51,  -87,    6,  -24,  -24,  -84,    2,   63,  -40,   65,  -40,    2,   63,  -40,   65,  -40,   66,  -40, -104,
       -105,   19, -104, -106,    9,  -49,    5,   67, -105,   68, -106,  -87,    6,   52,  -40,   49,  -87, -109, -108,   53,
        -40,   49,  -87, -109,   54,  -87,    6, -111,   69,   53,  -40,   49,  -58, -111,   54,  -58,    6,   70,  -84
      };

   // Arguments for token actions ...
      const int8 lrstar_parser_tables::arga[71] = 
      {
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1
      };

   // Boolean matrix ...
      const uint8 lrstar_parser_tables::Bm[340] = 
      {
          0,    0,    0,    0,    0,    0,    0,    8,    0,    0,    0,    0,    0,    0,    2,    0,    0,    0,    0,    0,
          0,   16,    0,    0,    0,    0,    0,    0,    4,    0,    0,    0,    0,    0,   32,    0,    0,    0,    0,    0,
          0,   12,    0,    0,    0,    0,    0,   16,   31,    0,   64,    4,    1,   64,    3,    0,   64,    0,    0,    0,
         80,    3,    0,   64,    4,    1,    0,   16,    3,    0,   64,    4,    1,    0,    4,  128,  161,    0,    0,    0,
          0,    4,   32,    0,    0,    0,    0,   32,    0,    4,    0,    0,    0,    0,    1,    2,    0,    0,    0,    4,
        128,    0,    0,    0,    4,    0,    0,    4,  128,    8,    0,   64,    1,   18,   32,    0,    0,    0,    0,    4,
        128,    8,    0,    0,    9,    2,    0,    0,    0,    6,    0,    0,    0,    1,    0,    0,    0,    0,    4,  128,
         33,    0,    0,    0,  128,    0,    0,    0,    0,    0,  160,    0,    0,    0,    0,    0,    0,    4,  128,  169,
          0,    0,    0,    0,    4,  128,    1,    0,    0,    0,    0,    4,    0,    0,    8,    0,    0,    0,    4,    0,
          2,   64,    1,    0,    0,    4,  128,    1,    0,   64,   97,    0,    4,  128,    1,    0,   64,    1,    0,    0,
        128,    1,    0,    0,  128,   64,    0,    0,    0,  128,    0,    8,    0,    0,    0,    0,  132,  128,    1,    0,
          0,    0,  128,    0,    1,   32,    0,    0,    0,    8,   16,    0,    0,    0,    1,    0,    2,    0,   32,    0,
          2,    0,    0,    0,    0,    4,  128,    0,    0,    0,    0,    0,    4,    0,    0,    0,    4,    0,    0,    6,
          0,    0,    0,    0,   20,    0,    0,    0,    0,    4,    0,    0,   64,    1,    0,    0,  132,  128,    1,    0,
         64,    1,   96,    0,    0,    0,    0,    0,    0,    2,    8,    0,   64,    0,    0,    0,    0,  128,    0,    4,
          0,    0,    0,    0,    1,    0,    0,    0,    0,    0,  128,   64,    0,    0,    0,    8,    0,   64,    0,    4,
          0,    0,    0,    0,  128,    2,    0,    0,    0,    0,    0,    0,    1,   64,    0,    0,    0,    0,    0,    0
      };

   // Boolean matrix row (for state)...
      const uint16 lrstar_parser_tables::Br[229] = 
      {
          7,   14,   21,   21,   28,   28,   34,   34,    0,    0,   40,   47,   53,   28,   28,   60,   28,   28,   28,   28,
         67,    0,    0,   74,   81,   28,   28,   87,   27,   28,   34,   11,   34,   11,   34,   92,   34,   97,   60,  102,
        107,  114,  119,   30,  126,    0,    0,  131,  138,   74,  138,    0,   87,   28,  144,   28,   28,  150,  157,  164,
         11,  171,  178,  171,   28,    0,   34,  185,   26,   28,  192,   28,   74,  192,    0,   34,   16,   28,   67,   74,
        198,  203,   74,    0,   12,  209,   87,   87,  157,  216,  171,   31,  222,  227,  232,  238,   97,   28,  141,  150,
        107,  192,  192,  192,  192,   74,  245,   19,   30,  250,   29,   30,  119,    0,    0,   67,  138,  138,  257,  198,
         74,   28,  262,  257,  164,   28,   67,   28,  144,   18,  171,   74,  269,  141,  171,   97,  171,  276,  257,   30,
         30,  245,    0,   28,    0,   74,    0,  282,  282,  284,   74,  262,  291,   28,  291,  157,  164,  297,   60,  157,
        171,  262,  291,  171,  171,  157,  192,    0,  192,  192,   26,   26,  303,  305,   26,   67,   74,   74,  131,   28,
         12,  297,   74,   74,  297,  209,    0,    0,  311,  317,   28,   74,  320,   60,  245,   12,  141,   12,    3,  320,
        192,    0,   34,  326,   74,    0,   12,   28,  192,   17,  192,   74,  192,   30,  317,   74,   30,  317,   30,  333,
         30,  333,    0,    0,   17,  192,   26,   26,    0
      };

   // Boolean matrix column (displacement) ...
      const uint8 lrstar_parser_tables::Bc[71] = 
      {
          0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    1,    1,    1,    1,    2,    2,    2,
          2,    2,    2,    2,    2,    2,    2,    2,    2,    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
          3,    4,    4,    4,    4,    3,    4,    4,    4,    4,    4,    4,    4,    5,    5,    4,    5,    5,    5,    5,
          5,    5,    4,    5,    5,    5,    6,    6,    6,    6,    6
      };

   // Boolean matrix filter/mask value ...
      const uint8 lrstar_parser_tables::Bf[71] = 
      {
          1,    2,    4,    8,   16,   32,   64,  128,    8,    1,    2,    4,    8,   16,   32,   64,  128,    1,    2,    4,
          8,   16,   32,   32,   64,   64,   64,  128,  128,    1,    2,    4,    4,    4,    4,    4,    8,   16,   32,   64,
        128,    1,    1,    1,    2,    8,    4,    8,   16,   32,   64,    8,  128,    1,    2,    4,    4,    8,   16,   16,
         16,   16,    4,   32,   64,  128,    1,    2,    4,    8,   16
      };

   // Terminal transition matrix ...
      const int16 lrstar_parser_tables::Tm[400] = 
      {
        110,  114,  154,  -26,  178,  -36, -121,  107,    0,   65, -126, -177,  176,   51,    0, -217,    0,  125,   57,  -24,
        166,    0,  -23,   51,  -22,   55,   51,    0,  -34,  -43,  124,    0,    0,  -25,  -20,   55,   99,  132,   65,  -43,
         89,   93,  -43,  137, -213,   35, -146,  155,  104,  195,   94,  105,    0, -157,  167,    0,   54,  -21,   55,    0,
        180,    0,    0,  -81, -161,    0,  223,   51,  164,    0,   50,  -48,  133,    0, -125,   74,  155,  225,  197,    0,
          0,    0, -186,  153,   49, -130,    0, -127, -128, -129,    0,    0,    0,    0,  -63,   51, -192,  182,   50,  -48,
          0,  -64,    0,    0,    0,    0,    0,    0,    0,    0,   98,  -43,   49, -124,    0,   51, -212,   65,    0,  165,
          0,    0,  -63, -204,    0,    0,   31,  -16,  143,  -64,    0,  -43,  103,    0, -203,   88,    0,  104,  207,  190,
        105,    0,    0,  194,    0,  200,    0,  169,    0,  201, -197, -198,    0,    0,    0,   90,   33, -119,  150,    5,
          0,    0,  -29,    0, -220,    0,  144, -118,    0,  -13,  -15,    0,    0,    0, -145,    0,    0,  222,    0,    0,
          0,   23,    0,   21,    0,   51,   74,  156,   50,  -48,   22,    0,  -47, -187,    0,    0,    0,    0,    0,    0,
          0,  -43,   49,    0,    0,    0,  224,   70,    0,    0,   72,    0,  -63,   75,   77,    0,    0,    0,    0,  -64,
          0,  -88,    0,    0,   71,   69,    0,   73, -125,  -19,   55,    5,  159,    0,    0,   53,   64,    0,    0, -118,
        134,  -13,  -15,  183,    0,   62, -145,    0,    0,  146,    0,    0,  211,   23,  212,   21,    0,   61,    0,    0,
          0,    0,   22,    0, -117,    0,    0,    0,    0,    0,   56,   28,  -14,  106,    5,  127,  -73,  -74,  -75, -107,
          0,  126, -118,  163,  -13,  -15,    0,    0,  128, -145,    0,    0,  168,    0,    0,    0,   23,    0,   21,    0,
        -70,    0,    0,    0,    0,   22,    0,  208,    0,    0,  -71,    0,    0,  -72,    7,    9,   65,    5,  121,   14,
         24,    0,   29,  160,    0, -118,  136,  -13,  -15,  179, -140,   62, -145,    0, -154,  142,    0,    0,  204,   23,
        205,   21,   66,   59,    0,    0,    0,    0,   22,    0,  -91,    0,    0,    0,  120,    0,   13,    6,    8,   55,
          4,   -3,   14,  228,    2,   26,  130,  126, -118,   63,  -13,  -15,  177,  -52,   82,  141,  209,  218,   78,  -53,
        210,  -54,  -55,  175,  -60,  -62,   58, -188, -189, -190, -191,  -61,  145,  -44,  191,  215,    3,  131, -219,   13
      };

   // Terminal transition matrix row ...
      const uint16 lrstar_parser_tables::Tr[229] = 
      {
        357,  357,  357,  314,  357,  314,  357,  314,  357,  357,  357,  314,  357,  228,  271,  314,  126,  156,   45,  228,
        314,  357,  357,  185,  228,   45,   56,  228,  228,   18,  271,  357,  126,  314,  156,  228,   45,  357,  228,  314,
        185,  185,  185,  357,  271,  357,  357,  357,  185,  185,  185,  357,   56,  228,  357,   10,  228,   18,   95,   23,
        126,   33,   74,   33,   36,  357,   10,  115,  271,    7,  115,    0,  185,  115,  357,   95,  357,    1,  314,  185,
        357,  357,  185,  357,  357,  314,   23,   33,   95,   13,   33,  357,  271,  357,  314,   36,  228,  228,  314,   18,
        185,  115,   26,  115,  115,  185,  185,  357,  314,  126,  357,  228,  185,  357,  357,  314,  185,  185,  156,  357,
         67,    2,   45,  185,   13,  228,  314,    3,  228,  314,   33,  185,   74,  271,   33,   56,   33,  115,   18,  271,
        126,  185,  357,    0,  357,  185,  357,  185,   74,  357,  185,   10,  357,    4,  314,   95,   13,   56,  271,   95,
         33,   95,  228,   33,   33,   95,  115,  357,  115,  115,  271,  314,  126,  357,  314,  314,   67,  185,  126,    5,
        314,   45,  185,  185,   74,  314,  357,  357,  126,   36,  126,  185,  314,  156,  185,  228,  126,  271,  357,  228,
        115,  357,  115,  357,  185,  357,  126,    6,  115,  357,  115,  185,  115,  156,  115,  185,   45,    7,  185,   45,
         56,   56,  357,  357,  314,  115,  314,  314,  357
      };

   // Terminal transition matrix column ...
      const uint8 lrstar_parser_tables::Tc[71] = 
      {
          6,    6,    0,    7,    3,    1,    8,    4,   39,   13,   14,   42,    5,    6,    7,   15,   16,   17,   36,    2,
         40,   18,    3,    4,   22,   24,   25,   27,   34,   28,   29,   39,   42,    5,    6,    7,    8,    9,   10,   11,
         12,   13,   14,   15,   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,
         32,   33,   34,   35,   36,   37,   38,   39,   40,   41,   42
      };

   // Nonterminal transition matrix ...
      const int16 lrstar_parser_tables::Nm[1154] = 
      {
        -42, -194,  -42,  206,  -42, -193,  -42,   47,    0,    0,  -90,  -87,  -42,   47,    0,  123,  -90,  -86,  -42,   47,
          0,  -42,  102,  -42,  102,    0,    0,    0,    0,    0,    0,    0,    0,  -89,  -42,  102,  -42,  102,    0,  -89,
        -49,    0,    0,  -50,    0,  -51,  -56,    0, -162,    0, -162,  170, -164,    0, -164, -165,  108, -165, -221,    0,
          0, -162,    0, -162,    0, -164,    0, -164, -165, -199, -165, -149,    0,  -42,  102,    0,    0,    0,    0,    0,
          0,    0,    0,    0, -163,    0, -163,  -42,   47,  -42,  102,    0,    0,    0,  -42,  102,    0, -163,    0, -163,
       -162,    0,    0,    0, -164,    0,    0, -165,  139,  -49,  -42,  102,  -50,    0,  -51,   46, -162,    0,  -65,    0,
       -164, -162,    0, -165, -152, -164,    0,    0, -165,  186,    0,  -42,  102,  -42,  102,    0, -163, -162,    0,    0,
          0, -164,    0,    0, -165,  187,    0,  -42,  102,  -42,  102,    0, -163,    0,    0,    0,    0, -163, -162,    0,
       -162,    0, -164,    0, -164, -165,  213, -165, -150,    0,  -42,  102,    0, -163, -162,    0, -162,    0, -164,    0,
       -164, -165,  219, -165,  221,    0,  -42,  102,    0,    0,    0,    0,    0,    0, -163,    0, -163, -162,    0,    0,
          0, -164,    0,    0, -165, -158,    0,  -42,   47,    0, -163,    0, -163, -162,  138,    0,    0, -164,    0,    0,
       -165, -151,    0,    0,    0,    0,  -42,   47,    0,  -49,    0,    0,  -50, -163,  -51,   46,    0,    0,   45,    0,
        -42,   47,   48,    0,    0,    0,    0,    0,  -49, -163,  -76,  -50,    0,  -51,   46,    0,    0,   45,    0,    0,
          0,   48,  -49,  -42,   47,  -50,    0,  -51,   46,   44,    0,   45,    0,  111,    0,   48,    0,  -42,   47,    0,
          0,    0,    0,   44,    0,  -49,    0,  140,  -50,    0,  -51,   46,    0,    0,   45,    0,    0,    0,   48,  -49,
        -42,   47,  -50,    0,  -51,   46,   44,    0,   45,    0,  173,    0,   48,    0,  -42,   47,    0,    0,    0,    0,
         44,    0,  -49,    0,  -80,  -50,    0,  -51,   46,    0,    0,   45,    0,    0,    0,   48,  -49,  -42,   47,  -50,
          0,  -51,   46,   44,    0,   45,    0,  -28,    0,   48,    0,  -42,   47,    0,    0,    0,    0,   44,    0,  -49,
          0,  196,  -50,    0,  -51,   46,    0,    0,   45,    0,    0,    0,   48,  -49,  -42,   47,  -50,    0,  -51,   46,
         44,    0,   45,    0,  203,    0,   48,    0,  -42,   47,    0,    0,    0,    0,   44,    0,  -49,    0,  216,  -50,
          0,  -51,   46,    0,    0,   45,    0,    0,    0,   48,  -49,  -42,   47,  -50,    0,  -51,   46,   44,    0,   45,
          0,  220,    0,   48,    0,    0,    0,    0,    0,    0,    0,   44,    0,  -49,    0, -208,  -50,    0,  -51,   46,
        -42,   47,   45,    0,    0,    0,   48,    0,    0,    0,    0,    0,    0,    0,   44,    0,    0, -123,  -79,  118,
          0,    0,  -49,  -42,   47,  -50,    0,  -51,   46,    0,    0,   45,    0,    0,    0,   48,    0,  -42,   47,    0,
       -122,  161,    0,   44,    0,  -49,    0,  162,  -50,    0,  -51,   46,    0,    0,   45,    0,    0,    0,   48,  -49,
          0,    0,  -50,    0,  -51,   46,   44,    0,   45,    0,  162,    0,   48,  -42,   47,  122,    0,    0,    0,    0,
         44,    0,    0,    0,  -84,    0,  -85,    0,    0,    0,  -42,   47,  181,    0,    0,  -49,    0,    0,  -50,  -83,
        -51,   46,    0,    0,   45,    0,    0,    0,   48,    0,    0,    0,  -49,    0,    0,  -50,   44,  -51,   46,    0,
        -84,   45,  -85,    0,    0,   48,  -42,   47,  184,    0,    0,    0,    0,   44,    0,  -82,    0,  -84,    0,  -85,
          0,    0,    0,    0,    0,    0,    0,    0,  -49,  -42,   47,  -50,  -82,  -51,   46,    0,    0,   45,    0,    0,
        -31,   48,    0,    0,    0,    0,    0,  -33,    0,   44,    0,  -49,    0,  -84,  -50,  -85,  -51,   46,    0,    0,
         45,    0,  -42,   47,   48,    0,    0,    0,  -82,    0,    0,    0,   44,  -31,    0,  151,  152,    0,    0,  -30,
        -32,    0,    0,    0,  -49,    0,    0,  -50,    0,  -51,   46,    0,    0,   45,  -42,   47,    0,   48,  -90,  -93,
        -94,    0, -138,  -98, -100,   44,    0,    0,    0,  152,    0,   92,  -30,  157,    0,    0,    0,  -99,   91,  -42,
        102,  -89,    0,    0,    0,    0,    0, -132,  -98, -100,    0,   40,  226,    0,    0,    0,   92,    0,   96, -134,
          0,    0,  -99,   91,  -95,    0, -162,    0,    0,    0, -164,    0,    0, -165, -206,    0,   40,  227,    0,    0,
          0,    0,    0,    0,    0,    0,    0,    0,  101,    0,    0,    0,    0,    0,    0,  -42,   47, -113,   16,   17,
         97,    0, -163, -101,  -98, -100,    0,    0,   38, -108,    0,   18,   92, -116,   86,    0,    0,  -49,  -99,   91,
        -50,   19,  -51,   46,    0,    0,   83,    0,    0,    0,    0,    0,   40,  174, -110,  148,   42,    0,    0,    0,
          0, -111,    0,  -42,   47, -113,   16,   17,    0,    0,    0, -137,  -98, -100,    0,    0,  158, -108, -112,   18,
         92, -116,   96, -133,    0,  -49,  -99,   91,  -50,   19,  -51,  -45,    0,    0,    0,    0,    0,    0,    0,    0,
         40,  214, -110,    0,    0,    0,    0,    0,    0, -111,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    0,   97,    0, -112,   95,  -42, -193, -113,   16,   17,    0,    0,    0,  -97,  -98, -100,    0,
          0,    0, -109,    0,   18,   92, -116,   52,    0,    0,    0,  -99,   91,    0,   19,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,   40,  171, -110,  147,   42, -181,   76,    0,    0, -111,   68, -182,    0,    0,    0,
          0,    0,    0,    0,    0,    0, -183,    0,    0, -184,  149, -112,  -42,   47, -113,   16,   17,    0,    0,    0,
       -131,  -98, -100,    0,    0,  115, -108,    0,   18,   92, -116,   87,    0,    0,  -49,  -99,   91,  -50,   19,  -51,
         46,    0,    0,   45,    0,    0,    0,   48,    0,   40,  189, -110,    0,    0,    0,   44,    0,    0, -111,   84,
        -42,   47, -113,   16,   17,    0,    0,    0, -102,  -98, -100,    0,    0,  193, -108, -112,   18,   92, -116,  135,
          0,    0,  -49,  -99,   91,  -50,   19,  -51,   46,    0,    0,   45,    0,    0,    0,   48,    0,   40,  217, -110,
          0,    0,    0,   44,    0,    0, -111,  -84,    0,  -85,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,  -92, -112,  -42,   67, -113,   16,   17,   20,   -6,  202, -144,  -98, -100, -104, -106,   15, -108, -105,
         18,   92, -116,   37,  185, -139, -143,  -99,   91,   36,   19,    0,    0,    0,    0,    0,    0,    0,    0,    0,
       -174,  100,    0, -110,    0,  112,  119,    0,    0,    0, -111,   68, -167,   11, -166,    0,    0, -169, -168, -210,
          0,    0, -170,    0,    0, -171,  -18, -112, -172,  -42,   47,   -9,   16,   17,    1,   -5,   30,  -96,  -98, -100,
         -2, -142,   12,  -37,  -38,   25,   92,   -4,   27,   85,   60,  -49,  -99,   91,  -50,  -58,  -51,   46, -156,  198,
         45, -160,  199,  116,   48,  -67,   40,   39,   79,   41,   42,   80,   44, -185,  113,  -78,   43,   -8,   10,   -1,
       -202,  188,   32,   34, -209,  109,  172,  129, -216,  192,  -40,  -18,   81,  117
      };

   // Nonterminal transition matrix row ...
      const uint16 lrstar_parser_tables::Nr[229] = 
      {
       1089, 1089, 1089, 1089, 1089, 1089, 1089, 1089, 1089, 1024, 1089, 1024, 1089, 1089, 1089,  848, 1089, 1089, 1089, 1024,
        735, 1089, 1089, 1089,  848, 1089, 1089, 1089, 1089, 1089, 1089, 1089, 1089, 1089, 1089, 1089, 1089, 1089,  848, 1089,
       1024, 1089,  848, 1089, 1089, 1089, 1089, 1089,  735,  912,  783, 1089, 1089,  735, 1089, 1089,  912, 1089,  960,  654,
       1089, 1089,  783, 1024, 1089, 1024, 1089,  679, 1089, 1089,   21, 1089,  226,   23, 1024, 1089, 1089, 1089,  912,  207,
       1089, 1089,  411, 1024, 1089, 1089, 1089, 1089,  513,   12,  848, 1089, 1024, 1089, 1024, 1089, 1089,  960, 1089, 1024,
       1024,   34,   36,  186,   73,  240,    0, 1089, 1089, 1089, 1089, 1089,  848,  848,  735,  848,   87,   18, 1089, 1089,
        622, 1089, 1089, 1089,   12,  654,  783, 1089, 1089, 1089,  735,  463,  679, 1089,  912, 1089,  783,  186, 1089, 1089,
       1089,    4,  848, 1024, 1089,  263,  735, 1089, 1089, 1089,  277, 1089, 1089, 1089, 1089,  477,    6, 1089,  848,  530,
        960, 1089, 1089,  654,  679,  566,   89, 1024,   94,  110, 1089, 1089,  912, 1089, 1089,  960,  589,  300, 1089, 1089,
       1089, 1089,  440,  314, 1089, 1089, 1089, 1089, 1089, 1089, 1024,  337, 1089,  848,    2, 1089, 1089, 1089, 1089, 1089,
        131,  783, 1089, 1089,  351,  960, 1089, 1089,  133, 1089,  147,  374,  149, 1089, 1089,  388, 1089, 1089, 1089, 1089,
       1089, 1089,  654,  679, 1089,  170, 1089, 1089, 1089
      };

   // Nonterminal transition matrix column ...
      const uint8 lrstar_parser_tables::Nc[222] = 
      {
          5,    5,    5,   50,   11,   18,   18,   13,   13,   48,   48,    2,    2,    3,    3,    4,    4,   49,   49,   62,
         62,    5,    5,    6,    6,   17,   17,   50,   50,   11,   18,   18,   13,   13,   14,   15,   15,   61,   61,   20,
         20,    0,    1,    1,   22,   25,   27,   27,   28,   28,   28,   28,   64,   64,   64,   64,   26,   63,   63,   31,
         34,   34,   34,   35,   35,   36,   42,   42,   43,   43,   39,   39,   39,   39,   39,   39,   46,   47,   47,   48,
         48,   49,    2,    2,   62,   62,    3,    3,    4,    5,    5,    6,    7,   50,   50,   53,   54,   54,    8,    8,
          8,    9,    9,   10,   10,   11,   11,   12,   13,   13,   14,   14,   14,   14,   14,   14,   14,   15,   16,   16,
         17,   17,   18,   18,   58,   19,   19,   61,   61,   61,   61,   20,   20,   64,   64,   21,   21,   21,   21,   22,
         22,   23,   23,   24,   25,   26,   26,   27,   27,   27,   27,   28,   28,   63,   29,   30,   30,   31,   32,   33,
         33,   34,   35,   35,   35,   35,   36,   36,   36,   36,   36,   36,   36,   37,   37,   38,   38,   39,   40,   40,
         41,   41,   42,   42,   42,   42,   43,   44,   45,   45,   45,   45,   46,   47,   47,   48,   48,   49,   49,   50,
         51,   52,   52,   53,   53,   54,   54,   55,   55,   56,   56,   57,   57,   58,   59,   60,   60,   61,   62,   62,
         63,   64
      };

   // Reduction matrix ...
      const uint8 lrstar_parser_tables::Rm[1] = 
      {
          0
      };

   // Reduction matrix row ...
      const uint8 lrstar_parser_tables::Rr[229] = 
      {
          0,    0,    0,    0,    0,    0,    0,    0,   17,   17,    7,    0,    0,    0,    0,    0,   11,   12,  114,  115,
          0,  173,  180,    0,    0,   10,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
        175,    0,  178,    0,   77,   66,   57,   46,    0,    0,    0,   39,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,  173,    0,  193,  195,    0,    0,    0,    0,    0,  180,    0,    0,    0,    0,    0,
         68,   59,    0,   66,    0,   41,    0,    0,    0,    0,    0,  141,  103,    0,    0,    0,    0,    0,  135,    0,
        176,    0,  147,    0,    0,    0,    0,    0,    0,    0,    0,    0,  179,  180,  180,  218,    0,    0,    0,   69,
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,  136,    0,    0,    0,    0,    0,    0,
          0,    0,  173,    0,  211,    0,  173,    0,    0,    0,    0,    0,   27,   43,   35,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    0,    0,   39,    0,    0,  196,  201,  173,    0,  215,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,  153,  155,  159,    0,    0,    0,    0,    0,    0,    0,    0,  120,    0,    0,    0,
          0,  173,    0,  207,    0,  173,    0,    0,  148,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,  173,  173,    0,    0,  200,  214,    0
      };

   // Reduction matrix column ...
      const uint8 lrstar_parser_tables::Rc[71] = 
      {
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
          0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
      };

   // Production lengths (minus one) ...
      const int8 lrstar_parser_tables::PL[222] = 
      {
          1,    0,    0,    8,    1,    7,    8,   -1,    1,    0,    0,    0,    0,    0,    2,    0,    2,   -1,    1,    2,
          4,    2,    3,    0,    0,    0,    2,    0,    2,    4,    0,    0,    0,    2,    2,    1,    3,    0,    0,   -1,
          1,    1,    0,    0,    2,    1,    0,    3,    0,    0,    0,    0,    0,    0,    0,    0,    1,   -1,    1,    1,
          0,    0,    0,    0,    0,    1,   -1,    1,    1,    2,    0,    0,    0,    0,    0,    0,    1,    0,    1,    0,
          2,    2,    0,    2,    0,    0,    0,    2,    2,    0,    0,    4,    2,    0,    0,    2,    2,    3,    0,    0,
          0,    2,    3,    0,    1,    0,    0,    2,    0,    1,    0,    0,    0,    0,    0,    0,    0,    4,    0,    2,
          2,    4,    0,    2,    2,    0,    2,    0,    0,    0,    0,    2,    3,    0,    2,    1,    2,    3,    4,    0,
          0,    0,    1,    1,    2,    0,    2,    0,    5,    1,    6,    0,    2,    3,    3,   -1,    1,    7,    3,   -1,
          1,    7,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,   -1,    1,    0,    2,    3,    0,    2,
         -1,    1,    0,    0,    0,    1,    3,    2,    0,    0,    0,    0,    3,    0,    2,    0,    3,    0,    0,    2,
          3,   -1,    1,    5,    7,    0,    1,    4,    6,    0,    2,   -1,    3,    5,    3,   -1,    1,    7,   -1,    1,
          7,    1
      };

   // Terminal action number ...
      const int8 lrstar_parser_tables::tact_numb[71] = 
      {
          0,   -1,    1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
         -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1
      };

   // Terminal action function pointers ...
      int (*lrstar_parser_tables::tact_func[2])(void *parser, int &t) =
      {
         lrstar_term_actions::error,
         lrstar_term_actions::lookup
      };

//
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Zeus_ParserTables_instantiate.h"
