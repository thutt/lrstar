#include "lrstar_basic_defs.h"
#include "lrstar_parser_tables.h"
#include "Pascal_LexerTables_typedef.h"
#include "Pascal_ParserTables_typedef.h"
#include "Pascal_Parser.h"
#include "Pascal_Actions.h"

template<>
const int Pascal_parser_tables_t::n_term_symb = 113;

template<>
const int Pascal_parser_tables_t::n_head_symb = 194;

template<>
const int Pascal_parser_tables_t::n_tact_name = 2;

template<>
const int Pascal_parser_tables_t::n_node_name = 185;

template<>
const int Pascal_parser_tables_t::n_head_numb = 379;

template<>
const int Pascal_parser_tables_t::n_f_tail = 380;

template<>
const int Pascal_parser_tables_t::n_tail = 695;

template<>
const int Pascal_parser_tables_t::n_arga = 113;

template<>
const int Pascal_parser_tables_t::n_argx = 379;

template<>
const int Pascal_parser_tables_t::n_argy = 379;

template<>
const int Pascal_parser_tables_t::n_Bm = 530;

template<>
const int Pascal_parser_tables_t::n_Br = 344;

template<>
const int Pascal_parser_tables_t::n_Bc = 113;

template<>
const int Pascal_parser_tables_t::n_Bf = 113;

template<>
const int Pascal_parser_tables_t::n_Tm = 703;

template<>
const int Pascal_parser_tables_t::n_Tr = 344;

template<>
const int Pascal_parser_tables_t::n_Tc = 113;

template<>
const int Pascal_parser_tables_t::n_Nm = 3240;

template<>
const int Pascal_parser_tables_t::n_Nr = 344;

template<>
const int Pascal_parser_tables_t::n_Nc = 379;

template<>
const int Pascal_parser_tables_t::n_Rm = 12;

template<>
const int Pascal_parser_tables_t::n_Rr = 344;

template<>
const int Pascal_parser_tables_t::n_Rc = 113;

template<>
const int Pascal_parser_tables_t::n_PL = 379;

template<>
const int Pascal_parser_tables_t::n_nd_fterm = 0;

template<>
const int Pascal_parser_tables_t::n_nd_term = 0;

template<>
const int Pascal_parser_tables_t::n_nd_faction = 0;

template<>
const int Pascal_parser_tables_t::n_nd_action = 0;

template<>
const int Pascal_parser_tables_t::n_tact_numb = 113;

template<>
const int Pascal_parser_tables_t::n_node_numb = 379;

template<>
const int Pascal_parser_tables_t::n_nact_numb = 379;

template<>
const int Pascal_parser_tables_t::n_reverse = 0;

template<>
const int Pascal_parser_tables_t::n_terms = 113; // Number of terminals.

template<>
const int Pascal_parser_tables_t::n_heads = 194; // Number of nonterminals.

template<>
const int Pascal_parser_tables_t::n_prods = 379; // Number of productions.

template<>
const int Pascal_parser_tables_t::n_states = 344; // Number of states.

template<>
const int Pascal_parser_tables_t::accept_state = 343; // Accept state.

template<>
const int Pascal_parser_tables_t::n_termactns = 2; // Number of terminal actions.

template<>
const int Pascal_parser_tables_t::n_nodenames = 185; // Number of node names.

template<>
const int Pascal_parser_tables_t::n_nodeactns = 185; // Number of node actions.

template<>
const int Pascal_parser_tables_t::eof_symb = 1; // <eof> symbol number.

template<>
const int Pascal_parser_tables_t::err_used = 0; // <error> used in grammar?


// Terminal symbols of the grammar.
static const char *term_symb_[113] = {
   "<error>",
   "<eof>",
   "<identifier>",
   "<number>",
   "<string>",
   "\'OR\'",
   "\'XOR\'",
   "\'AND\'",
   "\'=\'",
   "\'<>\'",
   "\'<\'",
   "\'>\'",
   "\'<=\'",
   "\'>=\'",
   "\'SHL\'",
   "\'SHR\'",
   "\'+\'",
   "\'-\'",
   "\'*\'",
   "\'/\'",
   "\'MOD\'",
   "\'DIV\'",
   "\'IN\'",
   "\';\'",
   "\'.\'",
   "\'PROGRAM\'",
   "\'(\'",
   "\',\'",
   "\')\'",
   "\'USES\'",
   "\'UNIT\'",
   "\'INTERFACE\'",
   "\'IMPLEMENTATION\'",
   "\'LABEL\'",
   "{label_identifier}",
   "\'CONST\'",
   "{constant_identifier}",
   "\'TYPE\'",
   "\':\'",
   "{field_identifier}",
   "\'[\'",
   "\'..\'",
   "\']\'",
   "{type_identifier}",
   "\'REAL\'",
   "\'SINGLE\'",
   "\'DOUBLE\'",
   "\'EXTENDED\'",
   "\'COMP\'",
   "\'SHORTINT\'",
   "\'INTEGER\'",
   "\'BYTE\'",
   "\'LONGINT\'",
   "\'WORD\'",
   "\'BOOLEAN\'",
   "\'CHAR\'",
   "\'STRING\'",
   "\'PACKED\'",
   "\'ARRAY\'",
   "\'OF\'",
   "\'RECORD\'",
   "\'END\'",
   "\'CASE\'",
   "\'SET\'",
   "\'FILE\'",
   "\'^\'",
   "\'VAR\'",
   "\'ABSOLUTE\'",
   "\'@\'",
   "\'NOT\'",
   "\'ORD\'",
   "\'ODD\'",
   "\'LO\'",
   "\'LENGTH\'",
   "\'HI\'",
   "\'CHR\'",
   "\'ABS\'",
   "\'PRED\'",
   "\'PTR\'",
   "\'ROUND\'",
   "\'SIZEOF\'",
   "\'SUCC\'",
   "\'SWAP\'",
   "\'TRUNC\'",
   "\'NIL\'",
   "\'BEGIN\'",
   "\':=\'",
   "\'GOTO\'",
   "\'IF\'",
   "\'THEN\'",
   "\'ELSE\'",
   "\'REPEAT\'",
   "\'UNTIL\'",
   "\'WHILE\'",
   "\'DO\'",
   "\'FOR\'",
   "\'WITH\'",
   "\'FUNCTION\'",
   "{func_identifier}",
   "\'PROCEDURE\'",
   "{proc_identifier}",
   "\'FORWARD\'",
   "\'EXTERNAL\'",
   "\'INTERUPT\'",
   "\'INLINE\'",
   "\'OBJECT\'",
   "\'VIRTUAL\'",
   "\'CONSTRUCTOR\'",
   "\'DESTRUCTOR\'",
   "{variable_identifier}",
   "{ordinal_type_id}",
   "\'TO\'",
   "\'DOWNTO\'",
};

template<>
const char * const *Pascal_parser_tables_t::term_symb = &term_symb_[0];

// Nonterminal symbols of the grammar.
static const char *head_symb_[194] = {
   "Goal",
   "Unit",
   "Program",
   "ProgramHeading",
   "UseClause",
   "UnitHeading",
   "InterfacePart",
   "InterfaceDecl",
   "ProcAndFuncHeadingPart",
   "ImplementationPart",
   "Block",
   "DeclSection",
   "LabelDeclPart",
   "LabelIdent",
   "ConDefPart",
   "UntypedConDef",
   "ConIdent",
   "TypeDefPart",
   "TypeAssignment",
   "TypeConDef",
   "TypedConstant",
   "ArrayConstant",
   "RecordConstant",
   "SetConstant",
   "Type",
   "SimpleType",
   "RealType",
   "OrdinalType",
   "OrdIdentifier",
   "SubrangeType",
   "EnumeratedType",
   "StringType",
   "StrucType",
   "ArrayType",
   "RecType",
   "FieldList",
   "FixedPart",
   "VariantPart",
   "Variant",
   "TagFieldType",
   "SetType",
   "FileType",
   "PointerType",
   "ProcedureType",
   "VarDeclPart",
   "VarDeclList",
   "VarReference",
   "Qualifier",
   "VarTypeCast",
   "Expression",
   "SimpleExpression",
   "Term",
   "Factor",
   "CExpression",
   "CTerm",
   "CFactor",
   "PreDefinedFunction",
   "UnsignedConstant",
   "FunctionCall",
   "SetConstructor",
   "MemberGrp",
   "ValueTypeCast",
   "StmtPart",
   "Statement",
   "SimpleStatement",
   "AssgStmt",
   "ProcStmt",
   "GotoStmt",
   "StructStmt",
   "CondStmt",
   "IfStmt",
   "CaseStmt",
   "CasePart",
   "ElsePart",
   "ReptStmt",
   "RepeatStmt",
   "WhileStmt",
   "ForStmt",
   "WithStmt",
   "ProcAndFuncDeclPart",
   "ProcDecl",
   "FuncDecl",
   "FuncHeading",
   "FuncIdent",
   "ProcHeading",
   "ProcIdent",
   "FuncBody",
   "FormalParSection",
   "ProcBody",
   "InlineDirective",
   "InlineElement",
   "ObjectType",
   "Heritage",
   "MethodList",
   "MethodHeading",
   "ConstrucHeading",
   "ConsIdent",
   "DestrucHeading",
   "DesIdent",
   "OfieldList",
   "InitPart",
   "Constant",
   "ObjectId",
   "QualifiedIdentifier",
   "Identifier",
   "LIdentifier",
   "TIdentifier",
   "VIdentifier",
   "PIdentifier",
   "FIdentifier",
   "FiIdentifier",
   "ORDIdentifier",
   "Integer",
   "Number",
   "String",
   "Sign",
   "UporDown",
   "RelOp",
   "(Program | Unit)",
   "(Program | Unit)*",
   "(ProgramHeading ';')?",
   "UseClause?",
   "Identifier/','+",
   "('(' Identifier/','+ ')')?",
   "(Identifier/','+ ';')",
   "(Identifier/','+ ';')*",
   "InterfaceDecl*",
   "InlineDirective?",
   "DeclSection*",
   "DeclSection?",
   "LabelIdent/','+",
   "(UntypedConDef | TypeConDef)",
   "(UntypedConDef | TypeConDef)+",
   "(ConIdent '=' Constant ';')",
   "(ConIdent '=' Constant ';')+",
   "TypeAssignment+",
   "TypedConstant/','+",
   "({field_identifier} ':' TypedConstant)",
   "({field_identifier} ':' TypedConstant)/';'+",
   "('..' Constant)",
   "('..' Constant)/','*",
   "(Constant ('..' Constant)/','*)?",
   "(OrdinalType | RealType)",
   "(SubrangeType | EnumeratedType | OrdIdentifier)",
   "('[' Integer ']')?",
   "PACKED?",
   "(ArrayType | SetType | FileType | RecType)",
   "OrdinalType/','+",
   "FieldList?",
   "';'?",
   "(';'? VariantPart)?",
   "(Identifier/','+ ':' Type)",
   "(Identifier/','+ ':' Type)/';'+",
   "(Identifier ':')?",
   "Variant/';'+",
   "Constant/','+",
   "(ProcHeading | FuncHeading)",
   "VarDeclList+",
   "Qualifier*",
   "Expression/','+",
   "(VarReference | PIdentifier)",
   "('(' Expression/','+ ')')?",
   "MemberGrp/','*",
   "('..' Expression)?",
   "Statement/';'+",
   "(LIdentifier ':')?",
   "(SimpleStatement | StructStmt)?",
   "(ProcStmt | AssgStmt | GotoStmt)",
   "(VarReference | FIdentifier)",
   "(IfStmt | CaseStmt)",
   "(ELSE Statement)?",
   "CasePart/';'+",
   "ElsePart?",
   "(RepeatStmt | WhileStmt | ForStmt)",
   "ProcDecl+",
   "FuncDecl+",
   "FormalParSection/';'+",
   "('(' FormalParSection/';'+ ')')?",
   "(SimpleType | STRING)",
   "VAR?",
   "(':' SimpleType | STRING | FILE)?",
   "(INTERUPT ';')?",
   "InlineElement/'/'+",
   "RelOp?",
   "(Sign Number)",
   "(Sign Number)*",
   "(Number | Identifier (Sign Number)*)",
   "Heritage?",
   "MethodList?",
   "(';' VIRTUAL)?",
   "(MethodHeading (';' VIRTUAL)?)",
   "(MethodHeading (';' VIRTUAL)?)/';'+",
   "(Identifier/','+ ':' Type)/';'*",
   "(Identifier '.')?",
};

template<>
const char * const *Pascal_parser_tables_t::head_symb = &head_symb_[0];

// Terninal action names found in the grammar ...
static const char *tact_name_[2] = {
   "error",
   "lookup",
};

template<>
const char * const *Pascal_parser_tables_t::tact_name = &tact_name_[0];

// Node names found in the grammar.
static const char * node_name_[185] = {
   "Comp_Unit,"   "Unit_Tree,"   "Prog_Tree,"   "Prog_ID,"   "Use_List,"   "Unit_Head,"   "Iface_Part,"   "Con_Def,"   "Type_Def,"   "Var_Decl,"   "Proc_Func_Heading,"   "Proc_Head,"   "Func_Head,"   "Unit_Impl,"   "Block,"   "Lable_Part,"   "ConDef_Part,"   "TypeDef_Part,"   "VarDecl_Part,"   "ProcFunc_Part,"   "ConDef_Decl,"   "Type_Const,"   "Type_Array,"   "Type_Record,"   "Array_Const,"   "Rec_Const,"   "Set_Const,"   "Simple_Type,"   "Struc_Type,"   "Pointer_Type,"   "String_Type,"   "Proced_Type,"   "Type_Ident,"   "Object_Type,"   "Simp_Ty,"   "Real_Ty,"   "Sing_Ty,"   "Doub_Ty,"   "Exten_Ty,"   "Comp_Ty,"   "Ord_Ty,"   "SHORTINT,"   "INTEGER,"   "BYTE,"   "LONG,"   "WORD,"   "BOOL,"   "CHAR,"   "Subrng_Ty,"   "Enum_Ty,"   "Str_Ty,"   "StrucTy,"   "Array_Ty,"   "Rec_Ty,"   "Field_Lst,"   "Variant_Pt,"   "Varnt,"   "TagFld,"   "Set_Ty,"   "File_Ty,"   "Ptr_Ty,"   "Proc_Type,"   "Var_Id,"   "Type_Cst,"   "Ptr_Deref,"   "Idx,"   "Fid,"   "Ptr,"   "Typcst,"   "SimpExp,"   "LTGTOP,"   "LTEOP,"   "GTEOP,"   "EQOP,"   "NEQOP,"   "INOP,"   "TOP,"   "Addop,"   "OROP,"   "XOROP,"   "Factor,"   "MulOp,"   "DIVOp,"   "DIVOP,"   "ModOp,"   "AndOp,"   "SHLOP,"   "SHROP,"   "Ref,"   "AtRef,"   "UsCnst,"   "Expr,"   "Negat,"   "Unary,"   "FuncCall,"   "SetCnst,"   "ValCst,"   "Predif,"   "OrdFunc,"   "OddFunc,"   "LoFunc,"   "LenFunc,"   "HiFunc,"   "ChrFunc,"   "AbsFunc,"   "PredFunc,"   "PtrFunc,"   "RndFunc,"   "SizeFunc,"   "SuccFunc,"   "SwapFunc,"   "TruncFunc,"   "CNum,"   "CString,"   "CId,"   "CNil,"   "FCall,"   "Set,"   "SetList,"   "ValTpCst,"   "Stmt_Pt,"   "Stmt,"   "Simp_Stmt,"   "Asg_Stmt,"   "Prc_Stmt,"   "Goto_Stmt,"   "CmpdS,"   "Cond,"   "Rept,"   "With,"   "Cond_Stmt,"   "If_Stmt,"   "Case_Stmt,"   "Case_Part,"   "Else_Pt,"   "RptSmt,"   "Repeat_Stmt,"   "While_Stmt,"   "For_Stmt,"   "WithStmt,"   "Proc_Decl,"   "Func_Decl,"   "Proc_Def,"   "Func_Def,"   "Func_Code,"   "Func_For,"   "Func_Ext,"   "Func_Asm,"   "Parm_El,"   "Proc_Code,"   "Proc_For,"   "Proc_Ext,"   "Proc_Asm,"   "Inline_Dir,"   "Inline_Element,"   "OBJ_Ty,"   "Heritg,"   "Method_list,"   "Proc_Meth,"   "Func_Meth,"   "Cnst_Meth,"   "Dest_Meth,"   "O_Field,"   "No_Init,"   "Init_Stmts,"   "Con,"   "Obj_Id,"   "Qual_Id,"   "Id,"   "LID,"   "TID,"   "VID,"   "PID,"   "FID,"   "FiId,"   "ORDId,"   "Int,"   "Numb,"   "Str,"   "SiP,"   "SiM,"   "Up,"   "Down,"   "LTH,"   "GTH,"
};

template<>
const char * const *Pascal_parser_tables_t::node_name = &node_name_[0];

// Head symbol numbers for the productions.
static const uint8 head_numb_[379] = {
       0,     1,     2,     3,     4,     5,     6,     7,     7,     7, 
       7,     8,     8,     9,    10,    11,    11,    11,    11,    11, 
      12,    12,    13,    14,    15,    16,    17,    18,    19,    20, 
      20,    20,    21,    22,    23,    24,    24,    24,    24,    24, 
      24,    24,    25,    26,    26,    26,    26,    26,    27,    28, 
      28,    28,    28,    28,    28,    28,    29,    30,    31,    32, 
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42, 
      43,    44,    45,    45,    45,    46,    46,    46,    47,    47, 
      47,    48,    49,    49,    49,    49,    49,    49,    49,    50, 
      50,    50,    50,    51,    51,    51,    51,    51,    51,    51, 
      51,    52,    52,    52,    52,    52,    52,    52,    52,    52, 
      53,    53,    53,    53,    54,    54,    54,    54,    54,    54, 
      54,    54,    55,    55,    55,    55,    55,    55,    56,    56, 
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56, 
      56,    56,    57,    57,    57,    57,    58,    59,    60,    61, 
      62,    63,    64,    65,    66,    67,    68,    68,    68,    68, 
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78, 
      79,    79,    80,    81,    82,    83,    84,    85,    86,    86, 
      86,    86,    87,    88,    88,    88,    88,    89,    90,    91, 
      92,    93,    94,    94,    94,    94,    95,    96,    97,    98, 
      99,   100,   100,   101,   102,   103,   104,   105,   106,   107, 
     108,   109,   110,   111,   112,   113,   114,   115,   115,   116, 
     116,   117,   117,   118,   118,   119,   119,   120,   120,   121, 
     121,   122,   122,   123,   123,   124,   125,   125,   126,   126, 
     127,   127,   128,   128,   129,   129,   130,   130,   131,   131, 
     132,   132,   133,   134,   134,   135,   135,   136,   136,   137, 
     138,   138,   139,   140,   140,   140,   141,   141,   142,   142, 
     143,   143,   143,   144,   144,   145,   145,   146,   146,   146, 
     146,   147,   147,   148,   148,   149,   149,   150,   150,   151, 
     152,   152,   153,   153,   154,   154,   155,   155,   156,   156, 
     157,   157,   158,   158,   159,   159,   160,   160,   161,   161, 
     162,   162,   162,   163,   163,   164,   164,   165,   165,   166, 
     166,   166,   167,   167,   167,   168,   168,   169,   169,   170, 
     170,   171,   171,   172,   172,   173,   173,   173,   174,   174, 
     175,   175,   176,   176,   177,   177,   178,   178,   179,   179, 
     180,   180,   180,   180,   181,   181,   182,   182,   183,   183, 
     184,   185,   185,   186,   186,   187,   187,   188,   188,   189, 
     189,   190,   191,   191,   192,   192,   192,   193,   193, 
};

template<>
const uint8 *Pascal_parser_tables_t::head_numb = &head_numb_[0];

// First tail symbol index into the tail list ...
static const uint16 f_tail_[380] = {
       0,     2,     8,    12,    15,    17,    19,    22,    23,    24, 
      25,    26,    29,    32,    35,    37,    38,    39,    40,    41, 
      42,    44,    47,    48,    50,    51,    52,    54,    58,    63, 
      64,    65,    66,    69,    72,    75,    76,    77,    78,    79, 
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89, 
      90,    91,    92,    93,    94,    95,    96,    99,   102,   104, 
     106,   112,   115,   118,   119,   124,   129,   130,   133,   136, 
     138,   139,   141,   145,   151,   159,   161,   163,   166,   169, 
     171,   172,   176,   177,   180,   183,   186,   189,   192,   195, 
     196,   199,   202,   205,   206,   209,   212,   215,   218,   221, 
     224,   227,   228,   230,   231,   234,   236,   238,   239,   240, 
     241,   242,   245,   248,   251,   252,   255,   258,   261,   264, 
     267,   270,   273,   274,   277,   279,   281,   282,   283,   287, 
     291,   295,   299,   303,   307,   311,   315,   319,   323,   327, 
     331,   335,   339,   340,   341,   342,   343,   345,   348,   350, 
     354,   357,   359,   360,   363,   365,   367,   368,   369,   370, 
     371,   372,   377,   384,   388,   390,   391,   395,   399,   407, 
     411,   412,   413,   417,   421,   426,   427,   430,   431,   432, 
     433,   434,   435,   438,   440,   442,   444,   445,   449,   451, 
     457,   460,   461,   462,   463,   464,   465,   468,   469,   472, 
     473,   474,   475,   476,   477,   479,   481,   482,   483,   484, 
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494, 
     495,   496,   497,   498,   499,   500,   500,   502,   502,   504, 
     504,   505,   506,   509,   509,   512,   514,   514,   516,   516, 
     518,   518,   519,   519,   521,   521,   522,   523,   526,   527, 
     528,   529,   531,   535,   536,   538,   539,   541,   542,   545, 
     548,   549,   552,   554,   554,   555,   558,   558,   560,   561, 
     562,   563,   564,   565,   565,   568,   568,   569,   570,   571, 
     572,   573,   574,   577,   577,   578,   578,   579,   579,   581, 
     584,   585,   588,   588,   590,   591,   594,   595,   598,   599, 
     600,   601,   603,   603,   605,   606,   609,   610,   611,   611, 
     614,   614,   615,   618,   618,   620,   621,   624,   624,   626, 
     626,   627,   628,   629,   630,   631,   632,   633,   634,   635, 
     635,   637,   638,   641,   641,   642,   643,   644,   645,   646, 
     648,   649,   651,   652,   655,   655,   658,   659,   660,   660, 
     661,   661,   663,   664,   665,   665,   667,   668,   671,   671, 
     672,   674,   674,   676,   677,   679,   679,   680,   680,   681, 
     681,   683,   685,   686,   689,   689,   690,   693,   693,   695, 
};

template<>
const uint16 *Pascal_parser_tables_t::f_tail = &f_tail_[0];

// Tail symbol numbers ...
static const int16 tail_[695] = {
    -119,     1,    -5,    23,    -6,    -9,  -100,    24,  -120,  -121, 
     -10,    24,    25,  -104,  -123,    29,  -125,    30,  -104,    31, 
    -121,  -126,   -14,   -17,   -44,    -8,   -84,    23,  -127,   -82, 
      23,  -127,    32,  -121,  -128,  -129,   -62,   -12,   -14,   -17, 
     -44,   -79,    33,    23,    33,  -130,    23,     2,    35,  -132, 
    -134,     2,    37,  -135,  -104,     8,   -24,    23,   -16,    38, 
     -24,     8,   -20,  -101,   -21,   -22,    26,  -136,    28,    26, 
    -138,    28,    40,  -141,    42,   -25,   -32,   -42,   -31,   -43, 
      43,   -91,  -142,    44,    45,    46,    47,    48,  -143,    49, 
      50,    51,    52,    53,    54,    55,  -101,    41,  -101,    26, 
    -122,    28,    56,  -144,  -145,  -146,    58,    40,  -147,    42, 
      59,   -24,    60,  -148,    61,   -36,  -150,  -149,  -152,    62, 
    -153,   -39,    59,  -154,  -155,    38,    26,  -148,    28,  -111, 
      63,    59,   -27,    64,    59,   -24,    65,  -106,  -156,    66, 
    -157,     2,    38,   -24,    23,     2,    38,   -24,    67,  -107, 
      23,     2,    38,   -24,    67,  -112,    38,  -112,    23,  -107, 
    -158,   -48,  -158,   -58,    65,  -158,    40,  -159,    42,    24, 
    -110,    65,  -104,    26,   -46,    28,   -50,   -49,  -117,   -49, 
     -49,    12,   -49,   -49,    13,   -49,   -49,     8,   -49,   -49, 
       9,   -49,   -49,    22,   -49,   -51,   -50,  -115,   -50,   -50, 
       5,   -50,   -50,     6,   -50,   -52,   -51,    18,   -51,   -51, 
      19,   -51,   -51,    21,   -51,   -51,    20,   -51,   -51,     7, 
     -51,   -51,    14,   -51,   -51,    15,   -51,  -160,    68,  -160, 
     -57,    26,   -49,    28,    69,   -52,  -115,   -52,   -58,   -59, 
     -61,   -54,   -53,  -115,   -53,   -53,     5,   -53,   -53,     6, 
     -53,   -55,   -54,    18,   -54,   -54,    19,   -54,   -54,    21, 
     -54,   -54,    20,   -54,   -54,     7,   -54,   -54,    14,   -54, 
     -54,    15,   -54,   -57,    26,   -53,    28,    69,   -55,  -115, 
     -55,   -23,   -56,    70,    26,   -53,    28,    71,    26,   -53, 
      28,    72,    26,  -113,    28,    73,    26,     4,    28,    74, 
      26,  -113,    28,    75,    26,   -53,    28,    76,    26,   -53, 
      28,    77,    26,   -53,    28,    78,    26,   -53,    28,    79, 
      26,   -53,    28,    80,    26,   -53,    28,    81,    26,   -53, 
      28,    82,    26,   -53,    28,    83,    26,   -53,    28,  -113, 
    -114,    36,    84,  -109,  -161,    40,  -162,    42,   -49,  -163, 
    -106,    26,   -49,    28,    85,  -164,    61,  -165,  -166,  -167, 
    -168,    86,   -49,  -108,  -161,    87,  -104,   -62,   -69,   -74, 
     -78,  -169,    88,   -49,    89,   -63,  -170,    62,   -49,    59, 
    -171,  -172,  -149,    61,  -101,  -140,    38,   -63,    90,   -63, 
    -173,    91,  -164,    92,   -49,    93,   -49,    94,   -63,    95, 
    -107,    86,   -49,  -116,   -49,    94,   -63,    96,  -122,    94, 
     -63,  -174,  -175,   -84,    23,   -88,    23,   -82,    23,   -86, 
      23,    97,   -83,  -177,    38,  -178,     2,    99,   -85,  -177, 
       2,   -10,   101,   102,   -89,  -179,  -122,  -180,  -181,   -10, 
    -181,   101,  -181,   102,   -89,   104,    26,  -182,    28,  -183, 
    -186,   105,  -187,   -99,  -149,  -188,    61,    26,  -102,    28, 
    -191,   -84,   -82,   -95,   -97,   107,   -96,  -177,     2,   108, 
     -98,  -177,     2,  -192,    61,   -62,   -53,  -193,  -103,  -193, 
    -104,     2,    34,    43,   109,   100,    98,    39,   110,     3, 
       3,     4,    16,    17,   111,   112,    10,    11,    -2,    -1, 
    -119,  -118,    -3,    23,    -4,  -104,  -122,    27,  -104,    26, 
    -122,    28,  -122,    23,  -125,  -124,  -126,    -7,   -89,  -128, 
     -11,   -11,   -13,  -130,    27,   -13,   -15,   -19,  -131,  -132, 
    -131,   -16,     8,  -101,    23,  -133,  -134,  -133,   -18,  -135, 
     -18,   -20,  -136,    27,   -20,    39,    38,   -20,  -137,  -138, 
      23,  -137,    41,  -101,  -139,  -140,    27,  -139,  -101,  -140, 
     -27,   -26,   -29,   -30,   -28,    40,  -112,    42,    57,   -33, 
     -40,   -41,   -34,   -27,  -147,    27,   -27,   -35,    23,  -149, 
     -37,  -122,    38,   -24,  -151,  -152,    23,  -151,  -104,    38, 
     -38,  -154,    23,   -38,  -101,  -155,    27,  -101,   -84,   -82, 
     -45,  -157,   -45,  -158,   -47,   -49,  -159,    27,   -49,   -46, 
    -108,    26,  -159,    28,   -60,  -162,    27,   -60,    41,   -49, 
     -63,  -164,    23,   -63,  -105,    38,   -64,   -68,   -66,   -65, 
     -67,   -46,  -109,   -70,   -71,    90,   -63,   -72,  -171,    23, 
     -72,   -73,   -75,   -76,   -77,   -80,  -174,   -80,   -81,  -175, 
     -81,   -87,  -176,    23,   -87,    26,  -176,    28,   -25,    56, 
      66,    38,   -25,    56,    64,   103,    23,   -90,  -182,    19, 
     -90,  -117,  -115,  -113,  -185,  -184,  -113,  -104,  -185,   -92, 
     -93,    23,   106,   -94,  -189,  -190,  -191,    23,  -190,  -151, 
    -192,    23,  -151,  -104,    24, 
};

template<>
const int16 *Pascal_parser_tables_t::tail = &tail_[0];

// Arguments for token actions ...
static const int8 arga_[113] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1, 
};

template<>
const int8 *Pascal_parser_tables_t::arga = &arga_[0];

// First arguments for productions ...
static const int8 argx_[379] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,     0,    -1,    -1,     0,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,     0,    -1,     0,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,     0, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
};

template<>
const int8 *Pascal_parser_tables_t::argx = &argx_[0];

// Second arguments for productions ...
static const int8 argy_[379] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    34,    -1,    -1,    36,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    98,    -1,   100,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,   100, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
};

template<>
const int8 *Pascal_parser_tables_t::argy = &argy_[0];

// Boolean matrix ...
static const uint8 Bm_[530] = {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2, 
       0,     0,     0,     0,     0,     0,     0,    64,     0,     0, 
       0,     0,     0,     0,     4,     0,     0,     0,     0,     0, 
       0,     0,     0,    10,     0,    32,     0,     5,     0,     0, 
     128,     0,     0,     0,     0,     0,     0,     8,     0,     0, 
       0,     0,     0,     0,     0,     4,     0,     0,     0,     0, 
       0,     0,     0,     1,     0,     4,     0,     2,     0,     0, 
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0, 
       0,     0,    96,     0,     0,     0,    10,     0,    32,     0, 
      85,     0,     0,    18,     0,     0,     0,     0,     0,     0, 
       1,     0,    32,     0,     0,     0,     0,    32,     0,     0, 
       0,     0,     0,     2,     2,     0,     0,    48,     0,     0, 
       0,     0,     0,     0,     2,     0,     0,     2,     0,     0, 
       0,     4,     0,     0,     0,     0,     4,    10,    10,     2, 
       0,     0,     0,    10,     0,    32,     0,    21,     0,    24, 
      32,     8,   144,   124,    16,     1,     5,     0,    24,    32, 
       8,   144,     0,     0,     1,     0,     0,     0,     0,     0, 
      32,     0,     0,     0,     8,     0,    32,     0,     5,     0, 
       0,     0,     0,     0,    16,     0,     0,     0,    28,    32, 
       8,   144,     4,   128,     0,    10,     2,    96,    32,     0, 
       0,     0,     0,     0,     0,   128,   208,     0,     0,     0, 
       0,     0,     0,   128,     8,     0,     0,     0,    28,    32, 
       8,   144,     0,     0,     1,     0,     0,     0,   128,     0, 
       0,     0,     0,     0,     2,     0,     0,    64,     0,     0, 
       0,    34,     0,     0,     0,     0,     0,     0,    24,    32, 
       8,   144,    56,     0,     1,     0,     0,     4,   128,     0, 
      16,     0,     0,     0,     4,     0,     0,     0,     0,     0, 
       0,     2,     2,     0,    15,     1,     0,     0,     0,    16, 
       0,     0,     4,     0,     0,     0,     0,     0,     0,    10, 
       2,     0,    15,     1,     0,     0,     1,     0,     0,     0, 
       2,     0,     0,     0,    64,     0,     0,    15,     1,     0, 
       0,     0,   128,     0,     0,    16,     0,     0,     0,   128, 
       0,   128,    32,     0,     0,     0,     0,     0,     0,    12, 
       0,     0,     0,     0,     0,     0,     0,    96,    32,    32, 
       0,     0,     0,     0,     0,     0,     8,     0,     0,     0, 
       0,     0,     0,     0,    16,     0,     0,     0,     0,     0, 
       0,     0,     0,     8,     0,     0,     0,     0,     0,     0, 
       0,     2,     0,     0,    16,    32,    32,     8,     0,     0, 
       0,    15,     1,     0,     0,     0,     0,     0,    32,     0, 
       0,     0,     0,     0,     0,    15,    33,     0,     0,     0, 
       0,     0,    16,     0,     2,     0,     0,     0,     0,    15, 
       1,     0,     1,     0,     0,     0,     0,    24,    32,     8, 
     208,     0,     0,     1,     0,    64,    32,     0,     0,     0, 
       0,     0,     0,    32,     0,     0,     0,     0,     0,     0, 
     208,     0,     0,     0,     0,     0,     0,   192,     0,     0, 
       0,     0,     0,     0,     0,    24,    32,     8,   144,    16, 
       0,     1,     0,     0,    16,    32,     0,     0,     0,     0, 
       0,    24,    32,     8,   144,    24,     0,     1,     0,     0, 
      12,     1,     0,     0,     0,     0,     0,     0,     2,     0, 
       0,     0,    32,     0,     0,    15,     1,     0,     0,     0, 
       0,     0,     8,     0,     0,     0,     0,     0,     0,     0, 
       5,     1,     0,     0,     0,     0,     0,     0,     0,     0, 
       4,     0,     0,     0,     0,     0,     0,     0,   128,     0, 
};

template<>
const uint8 *Pascal_parser_tables_t::Bm = &Bm_[0];

// Boolean matrix row (for state)...
static const uint16 Br_[344] = {
       0,     9,    15,     7,     7,    24,    24,    30,     0,    38, 
      45,    22,     3,    48,     7,    56,     7,    65,    24,    24, 
      24,    24,    24,    24,    71,    15,    24,    21,    75,    83, 
      91,    24,    24,    99,    24,    73,    24,   104,    45,    45, 
      91,   108,    15,     0,   115,   122,   131,   104,     7,   140, 
       7,    45,     7,    24,    73,   149,   158,   149,   149,   165, 
     104,    24,    22,     0,   171,    21,    45,    18,     0,     0, 
      45,   179,    45,    24,   188,   188,    21,   188,     1,    24, 
      23,    73,    70,   197,   205,   158,   209,   218,   158,   158, 
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45, 
      45,    45,    45,    45,    20,   225,    45,     7,   158,     7, 
     232,   239,    24,   248,    30,     7,     7,   188,   188,   255, 
     255,   264,     0,   273,   197,   205,   179,    45,   188,    45, 
     282,   188,   188,   188,   291,   298,   306,    18,   313,   320, 
     329,   158,   158,   158,   158,   158,   158,   158,   158,   158, 
     158,   158,   158,   225,    69,    69,    24,   115,   337,     5, 
      70,   158,   158,   346,   354,   346,   158,   158,   158,   158, 
     158,   158,   158,   158,   158,   346,    24,    24,   363,   165, 
     372,    10,    10,   115,   380,   380,   188,    14,   386,   255, 
     188,   188,   188,   188,   188,   188,    21,   188,   188,   188, 
     188,   188,   188,   188,   188,   188,   188,   188,   394,   400, 
     408,   158,   188,    21,   188,    21,    23,     0,   417,     0, 
     425,   432,     0,     0,     0,     0,   439,   446,   446,   455, 
     455,   149,     4,     7,     7,   462,   352,   158,   337,   337, 
     386,   386,   386,   337,   337,   337,   337,   337,   337,   337, 
     337,   337,     5,     7,     7,   386,    24,    22,     7,   104, 
     471,   188,   400,     0,    72,    72,   479,   479,     0,   427, 
       0,   425,   432,     0,     0,     0,     0,   439,   446,   446, 
     394,   188,   188,   486,    70,   380,   494,   432,   115,   337, 
     239,   104,   400,     7,    19,    24,   149,    70,   503,    24, 
      24,   346,   380,    21,   380,     7,    21,   158,   462,   188, 
     346,   158,    14,   158,    69,   455,    24,     4,     7,     7, 
      24,    24,     7,     4,    21,   306,   149,   512,   104,   503, 
     521,    45,    45,    21,    69,   158,     7,   462,   158,    45, 
     158,    24,   386,     0, 
      };

template<>
const uint16 *Pascal_parser_tables_t::Br = &Br_[0];

// Boolean matrix column (displacement) ...
static const uint8 Bc_[113] = {
       0,     0,     0,     0,     0,     0,     0,     0,     1,     1, 
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1, 
       1,     1,     2,     2,     2,     0,     2,     2,     2,     2, 
       0,     2,     3,     3,     3,     3,     3,     3,     3,     3, 
       3,     4,     4,     4,     4,     4,     4,     4,     4,     4, 
       4,     4,     4,     4,     4,     4,     4,     4,     4,     5, 
       4,     5,     5,     4,     5,     5,     5,     5,     5,     3, 
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6, 
       6,     6,     6,     6,     3,     6,     6,     6,     6,     6, 
       6,     6,     6,     6,     6,     6,     6,     7,     7,     7, 
       7,     7,     7,     7,     7,     4,     7,     8,     8,     8, 
       8,     8,     8, 
      };

template<>
const uint8 *Pascal_parser_tables_t::Bc = &Bc_[0];

// Boolean matrix filter/mask value ...
static const uint8 Bf_[113] = {
       1,     2,     4,     8,    16,    32,    64,   128,     1,     2, 
       4,     4,     8,     8,    16,    16,    32,    32,    64,   128, 
      64,    64,     1,     2,     4,     2,     8,    16,    32,    64, 
       2,   128,     1,     2,     4,     8,    16,     8,    32,    64, 
     128,     1,     2,     4,     8,     8,     8,     8,     8,    16, 
      16,    16,    16,    16,    16,    16,    32,    64,   128,     1, 
     128,     2,     4,   128,     8,    16,    32,    64,   128,    16, 
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1, 
       1,     1,     1,     1,    16,     2,     4,     8,     8,    16, 
      32,     8,    64,     8,   128,     8,     8,     1,     2,     4, 
       8,    16,    16,    32,    64,    64,   128,     1,     1,     2, 
       4,     8,     8, 
};

template<>
const uint8 *Pascal_parser_tables_t::Bf = &Bf_[0];

// Terminal transition matrix ...
static const int16 Tm_[703] = {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,  -252,   341,   163,   179,  -132,   166,   329,  -345, 
     174,   312,  -190,   207,  -173,   -33,   162,   340,  -131,  -355, 
     339,   161,   297,  -130,     0,   324,  -217,  -218,     0,   -27, 
       0,   164,     0,  -133,  -217,  -218,     0,   181,     0,   167, 
       0,  -135,  -217,  -218,     0,   182,  -199,   168,     0,  -136, 
       0,  -217,  -218,     0,  -286,     0,   169,   144,  -137,  -217, 
    -218,     0,   295,     0,   170,   144,  -138,  -217,  -218,     0, 
     299,   145,   171,   144,  -139,     0,     0,     0,     0,   145, 
       0,     0,   144,     0,     0,     0,     0,   145,  -217,  -218, 
     144,   -73,     0,   172,     0,  -140,   145,     0,   144,     0, 
    -217,  -218,     0,   -72,   145,   165,     0,  -134,  -217,  -218, 
       0,   307,   145,   173,     0,  -141,     0,  -217,  -218,   144, 
    -235,     0,   121,    61,  -128,     0,   296,     0,     0,     0, 
     178,   144,     0,   145,     0,     0,     0,     0,     0,   144, 
       0,     0,     0,     0,     0,   145,     0,  -197,   144,     0, 
       0,   306,     0,   145,     0,   193,   194,  -221,  -222,   191, 
     192,     0,   145,   195,   330,     0,   177,     0,  -149,   193, 
     194,  -221,  -222,   191,   192,     0,   141,   195,   -21,     0, 
     117,    53,  -104,     0,   301,    28,   187,    80,   281,  -187, 
       0,  -318,   186,     0,     0,     0,     0,     0,   216,     0, 
       0,     0,     0,     0,     0,  -175,     0,  -215,  -216,   326, 
    -189,   -80,    37,     0,     0,  -217,  -218,     0,    65,  -349, 
     131,   261,  -309,  -144,   313,   133,     0,  -208,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -147, 
    -215,  -216,     0,  -150,     0,  -206,   130,   132,  -217,  -218, 
       0,   338,     0,   218,     0,   -65,  -144,     0,    89,     0, 
     212,     0,     0,     0,     0,     0,     0,  -210,  -145,     0, 
       0,     0,   -78,     0,     0,     0,  -209,     0,     0,  -211, 
      88,    90,    91,    92,    93,    94,    95,    96,    97,    98, 
     291,    99,   100,     0,   101,     0,   102,   103,  -215,  -216, 
       0,  -145,     0,     0,     0,     0,  -217,  -218,     0,  -172, 
       0,   108,   315,  -129,  -144,  -293,    89,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,  -206,   144,    88,    90, 
      91,    92,    93,    94,    95,    96,    97,    98,     0,    99, 
     100,   145,   101,     0,   102,   103,  -214,     0,    57,  -145, 
       0,     0,     0,   314,  -217,  -218,     0,     9,    -1,    59, 
      61,   -57,   204,    58,   229,   237,     0,   205,   206,   200, 
     201,   203,   202,     0,     0,     0,     0,     0,    17,     0, 
      18,   231,   -61,     0,   -25,   198,    19,     0,     0,   316, 
       0,    20,     0,   214,     0,     0,   291,     0,     0,   199, 
       0,     0,     0,     0,    22,    21,     0,  -184,  -185,     0, 
       0,  -274,     0,     0,     0,  -209,  -215,  -216,   193,   194, 
    -221,  -222,   191,   192,  -217,  -218,   195,   -20,     0,   108, 
      61,   -81,  -144,   260,    89,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -352, 
       0,   335,     0,     0,   -22,     0,    88,    90,    91,    92, 
      93,    94,    95,    96,    97,    98,     0,    99,   100,     0, 
     101,   333,   102,   103,     0,  -215,  -216,  -145,     0,     0, 
       0,     0,     0,  -217,  -218,     0,   -74,  -353,    87,   311, 
     -32,  -144,     0,    89,     0,     0,   -43,   -44,   -45,   -46, 
     -47,   -49,   -50,   -51,   -52,   -53,   -54,   -55,  -347,     0, 
       0,     0,     0,     0,     0,    88,    90,    91,    92,    93, 
      94,    95,    96,    97,    98,     0,    99,   100,     0,   101, 
       0,   102,   103,     0,     0,     0,  -145,  -215,  -216,   193, 
     194,  -221,  -222,   191,   192,  -217,  -218,   195,    29,  -378, 
      87,   297,  -123,  -144,   113,    89,   282,   -40,   -43,   -44, 
     -45,   -46,   -47,   -49,   -50,   -51,   -52,   -53,   -54,   -55, 
     105,  -276,   211,  -162,   104,  -177,   144,    88,    90,    91, 
      92,    93,    94,    95,    96,    97,    98,   196,    99,   100, 
     145,   101,   213,   102,   103,    22,    21,     0,  -145,     0, 
       0,     0,   106,     0,     0,     0,     0,     0,  -219,  -220, 
    -215,   241,    56,   343,  -221,  -222,   191,   192,  -217,  -218, 
     195,  -228,    -2,    26,    61,  -234,   150,    55,   175,   142, 
    -208,   151,   152,   146,   147,   149,   148,     5,     8,     6, 
      25,    42,    17,  -207,    18,   230,  -201,   122,  -206,   144, 
      19,   153,   156,    75,   154,    20,    27,   118,    73,    74, 
    -212,   303,    76,   145,    77,   215,    78,    79,    22,    21, 
    -210,  -179,  -180,    50,    51,   -34,  -370,   320,   321,  -209, 
    -213,   155,  -211, 
};

template<>
const int16 *Pascal_parser_tables_t::Tm = &Tm_[0];

// Terminal transition matrix row ...
static const uint16 Tr_[344] = {
     630,   630,   630,   630,   366,   630,   630,   630,   630,   630, 
     630,   630,   630,   630,   184,   630,   557,   436,   366,   630, 
     184,   557,   177,   630,   630,   630,   630,   630,   630,   630, 
     177,   366,   366,   630,   630,   366,   184,   366,   366,   366, 
     119,   630,   630,   630,   630,   217,   630,   184,   308,   366, 
      18,   184,    13,   436,   630,   557,   436,   557,   557,   184, 
     557,   630,   366,   630,   630,   630,   177,   630,   630,   630, 
     119,   630,   177,   630,   217,   217,   630,   217,   630,   630, 
     630,   184,   630,   630,   630,   436,   630,   308,   436,   436, 
      18,    13,     1,    28,   102,     4,    36,    44,    53,    61, 
      69,    90,   110,     7,   630,   630,   163,     1,   436,    28, 
     102,     4,   630,   495,   630,    36,    44,   217,   217,   184, 
     184,   630,   630,   557,   366,   366,   630,   177,   217,    10, 
     630,   217,   217,   217,   557,   217,   557,   366,   630,   184, 
     630,   250,   436,   436,   436,   436,   436,   436,   436,   436, 
     436,   436,   436,   366,   630,   366,   630,   366,   557,   630, 
     366,   436,   436,   630,   630,   630,   436,   436,   436,   436, 
     436,   436,   436,   436,   436,   366,   630,   630,   366,   184, 
     436,   630,   630,   217,   557,   557,   217,   630,   436,   184, 
     217,   217,   217,   217,   217,   217,   630,   217,   217,   217, 
     217,   217,   217,   217,   217,   217,   217,   217,   177,   184, 
     557,   436,   217,   630,   217,   630,   630,   630,   250,   630, 
     630,   630,   630,   630,   630,   630,   630,   630,   630,   557, 
     557,   557,   366,    53,    61,   119,   557,   436,   119,   308, 
      18,    13,     1,    28,   102,    36,    44,    53,    61,    69, 
      90,   110,   366,    53,    69,     7,   630,   557,    90,   177, 
     557,   217,   217,   630,   630,   630,   630,   630,   630,   630, 
     630,   366,   630,   630,   630,   630,   630,   366,   366,   366, 
     163,   217,   217,   110,   366,   557,   557,   630,   495,   557, 
      10,   217,   308,    53,   366,   630,   557,   366,   630,   630, 
     630,   366,   557,   630,   557,    53,   630,   436,    18,   217, 
     630,   250,   366,   250,   184,   557,   630,   184,     7,   163, 
     119,    18,   495,   557,   630,   436,   557,   630,   308,   630, 
     630,   366,   366,   630,   436,   436,   250,    13,   436,     0, 
     436,   630,   250,   630, 
};

template<>
const uint16 *Pascal_parser_tables_t::Tr = &Tr_[0];

// Terminal transition matrix column ...
static const uint8 Tc_[113] = {
       3,     3,    38,     0,     1,    39,    53,    16,     2,     3, 
       4,     5,     6,     7,    21,    22,     8,     9,    23,    24, 
      25,    26,    10,    11,    12,    27,    13,    14,    15,    28, 
      29,    30,    31,    32,    33,    34,    16,    40,    17,    50, 
      18,    19,    65,    20,    21,    22,    23,    24,    25,    26, 
      27,    28,    29,    30,    31,    32,    33,    34,    41,    35, 
      42,    36,    43,    44,    71,    37,    45,    38,    39,    40, 
      41,    42,    43,    44,    45,    46,    47,    48,    49,    51, 
      52,    54,    56,    57,    61,    46,    47,    48,    49,    50, 
      51,    52,    53,    54,    55,    56,    57,    58,    72,    59, 
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69, 
      70,    71,    72, 
};

template<>
const uint8 *Pascal_parser_tables_t::Tc = &Tc_[0];

// Nonterminal transition matrix ...
static const int16 Nm_[3240] = {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,  -231,   217,     0,     0,     0,     0,     0,  -360, 
     242,  -363,   197,   310,  -142,  -143,    85,  -126,     0,   180, 
       0,  -205,  -142,  -143,    85,  -126,     0,     0,   228,  -142, 
    -143,    85,  -126,   238,     0,     0,    84,  -142,  -143,    85, 
    -126,     0,     0,   225,  -142,  -143,    85,  -126,   239,     0, 
       0,    84,     0,     0,     0,   243,     0,     0,    84,     0, 
    -114,     0,     0,  -127,  -122,     0,     0,     0,  -114,     0, 
       0,  -127,  -122,     0,     0,  -114,     0,     0,  -127,  -122, 
       0,     0,  -362,  -114,  -188,     0,  -127,  -122,     0,     0, 
    -114,     0,     0,  -127,  -122,  -142,  -143,    85,  -126,     0, 
    -142,  -143,    85,  -126,     0,     0,   244,     0,     0,    84, 
       0,   245,     0,     0,    84,  -142,  -143,    85,  -126,     0, 
    -142,  -143,    85,  -126,     0,     0,   246,     0,     0,    84, 
       0,   247,     0,     0,    84,     0,     0,  -142,  -143,    85, 
    -126,  -114,     0,     0,  -127,  -122,  -114,     0,   248,  -127, 
    -122,    84,     0,     0,     0,     0,     0,  -142,  -143,    85, 
    -126,  -114,     0,     0,  -127,  -122,  -114,     0,   249,  -127, 
    -122,    84,     0,     0,  -142,  -143,    85,  -126,     0,  -142, 
    -143,    85,  -126,  -114,     0,   250,  -127,  -122,    84,   328, 
     251,     0,     0,    84,     0,     0,     0,  -142,  -143,    85, 
    -126,     0,     0,  -114,     0,  -262,  -127,  -122,     0,     0, 
       0,   226,     0,     0,     0,     0,  -142,  -143,    85,  -126, 
    -114,     0,     0,  -127,  -122,  -114,     0,    83,  -127,  -122, 
      84,     0,     0,     0,     0,     0,     0,   327,  -297,     0, 
       0,     0,     0,  -114,     0,     0,  -127,  -122,     0,  -142, 
    -143,    85,  -126,     0,     0,     0,     0,     0,     0,  -231, 
      83,     0,  -114,    84,     0,  -127,  -122,  -142,  -143,    85, 
    -126,     0,     0,  -204,   257,     0,   157,     0,   158,     0, 
    -231,    84,  -142,  -143,    85,  -126,     0,     0,  -142,  -143, 
      85,  -126,     0,     0,     0,  -114,   222,   235,  -127,  -122, 
       0,  -231,   223,     0,     0,     0,     0,     0,   284,  -142, 
    -143,    85,  -126,  -114,     0,     0,  -127,  -122,   235,  -142, 
    -143,    85,  -126,   224,     0,     0,  -291,     0,  -114,     0, 
      83,  -127,  -122,    84,  -114,     0,     0,  -127,  -122,   255, 
       0,   257,     0,     0,     0,     0,     0,  -376,     0,  -142, 
    -143,    85,  -126,     0,     0,  -114,     0,     0,  -127,  -122, 
     221,   284,   300,    84,     0,  -114,  -296,     0,  -127,  -122, 
       0,     0,  -142,  -143,    85,  -126,     0,  -142,  -143,    85, 
    -126,     0,     0,    83,     0,     0,    84,  -258,    83,   -29, 
    -332,    84,     0,     0,     0,  -114,     0,     0,  -127,  -122, 
    -142,  -143,    85,  -126,     0,     0,     0,     0,     0,     0, 
       0,    83,     0,     0,    84,  -295,     0,     0,  -114,   337, 
       0,  -127,  -122,  -114,     0,     0,  -127,  -122,     0,   256, 
     283,     0,     0,     0,     0,     0,     0,     0,  -259,     0, 
     -29,     0,     0,  -331,     0,     0,  -114,     0,     0,  -127, 
    -122,  -142,  -143,    85,  -126,  -296,     0,     0,     0,     0, 
       0,     0,    83,     0,     0,    84,  -142,  -143,    85,  -126, 
       0,     0,     0,   -30,     0,     0,     0,    83,     0,   -31, 
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,  -114,     0,     0, 
    -127,  -122,     0,     0,  -294,   253,     0,   336,   337,     0, 
    -231,     0,  -114,     0,     0,  -127,  -122,     0,  -142,  -143, 
      85,  -126,     0,     0,   -30,     0,  -231,   235,     0,   220, 
     -31,     0,    84,     0,  -142,  -143,    85,  -126,     0,     0, 
       0,     0,     0,   235,     0,     0,     0,     0,   227,     0, 
       0,     0,     0,     0,     0,     0,  -375,  -284,     0,  -270, 
       0,     0,     0,     0,  -114,    82,     0,  -127,  -122,   342, 
       0,     0,  -290,   234,   233,     0,  -142,  -143,    85,  -126, 
    -114,     0,  -270,  -127,  -122,     0,     0,    83,    82,     0, 
      84,     0,     0,     0,     0,     0,     0,   254,     0,  -142, 
    -143,    85,  -126,     0,   -67,     0,   -48,     0,     0,     0, 
      83,     0,     0,    84,     0,     0,     0,     0,     0,     0, 
       0,     0,  -114,     0,     0,  -127,  -122,  -282,  -306,   -48, 
      69,  -106,    70,     0,    68,  -307,   127,     0,     0,     0, 
    -142,  -143,   128,     0,     0,  -114,     0,  -272,  -127,  -122, 
       0,     0,     0,     0,  -271,     0,     0,     0,     0,     0, 
       0,     0,  -108,   126,     0,     0,     0,     0,  -109,     0, 
    -272,     0,  -306,     0,    69,  -105,    70,  -271,    68,  -307, 
     127,     0,     0,     0,  -142,  -143,   128,  -101,     0,     0, 
    -103,     0,     0,     0,  -231,     0,     0,     0,     0,     0, 
     129,     0,  -142,  -143,    85,  -126,  -108,   126,     0,     0, 
       0,   235,  -109,   219,     0,  -306,    84,    69,   -93,    70, 
       0,    68,  -307,   127,     0,  -284,     0,  -142,  -143,   128, 
     273,  -101,     0,     0,  -103,     0,     0,   232,     0,     0, 
    -290,   234,   233,  -257,   129,   -29,     0,     0,  -114,  -108, 
     126,  -127,  -122,     0,     0,  -109,  -142,  -143,    85,  -126, 
       0,     0,     0,     0,     0,  -270,     0,   289,     0,     0, 
      84,    82,     0,     0,  -101,     0,     0,  -103,     0,   288, 
    -260,   290,  -142,  -143,    85,  -126,     0,   129,     0,     0, 
       0,     0,     0,    83,     0,     0,    84,     0,     0,     0, 
       0,     0,  -114,     0,     0,  -127,  -122,     0,     0,     0, 
    -281,  -306,   -48,    69,   -93,    70,   292,    68,  -307,   127, 
       0,     0,     0,  -142,  -143,   128,   274,     0,  -114,   -30, 
       0,  -127,  -122,     0,     0,   -31,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,  -108,   126,     0,     0,     0, 
       0,  -109,     0,  -272,     0,     0,     0,     0,     0,     0, 
    -271,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
    -101,     0,  -306,  -103,    69,   -93,    70,     0,    68,  -307, 
     127,     0,     0,   129,  -142,  -143,   128,   275,  -306,     0, 
      69,   -93,    70,     0,    68,  -307,   127,     0,     0,     0, 
    -142,  -143,   128,   276,     0,     0,  -108,   126,     0,     0, 
       0,     0,  -109,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,  -108,   126,     0,     0,     0,     0,  -109,     0, 
       0,  -101,     0,     0,  -103,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,   129,     0,     0,  -101,     0,  -306, 
    -103,    69,   -93,    70,     0,    68,  -307,   127,     0,     0, 
     129,  -142,  -143,   128,   277,  -306,     0,    69,   -93,    70, 
       0,    68,  -307,   127,     0,     0,     0,  -142,  -143,   128, 
     278,     0,     0,  -108,   126,     0,     0,     0,     0,  -109, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -108, 
     126,     0,     0,     0,     0,  -109,     0,     0,  -101,     0, 
       0,  -103,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,   129,     0,     0,  -101,     0,  -306,  -103,    69,   -93, 
      70,     0,    68,  -307,   127,     0,     0,   129,  -142,  -143, 
     128,   279,  -306,   -56,    69,     0,    70,     0,    68,  -307, 
     127,     0,     0,     0,  -142,  -143,    85,  -126,     0,     0, 
    -108,   126,     0,     0,     0,    83,  -109,     0,    84,     0, 
       0,     0,     0,     0,     0,     0,     0,    71,     0,     0, 
       0,     0,     0,     0,     0,  -101,     0,     0,  -103,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,   129,     0, 
    -114,  -102,     0,  -127,  -122,  -306,     0,    69,   -93,    70, 
       0,    68,  -307,   127,     0,     0,     0,  -142,  -143,   128, 
     125,  -306,     0,    69,   -93,    70,     0,    68,  -307,   127, 
       0,     0,     0,  -142,  -143,   128,   125,     0,     0,  -108, 
     126,     0,     0,     0,     0,  -109,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,  -108,   126,     0,     0,     0, 
       0,  -109,     0,     0,  -101,     0,     0,  -103,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,   129,     0,     0, 
    -101,     0,     0,  -103,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,   129,     0,  -306,   270,    69,   -93,    70, 
       0,    68,  -307,   127,     0,  -270,     0,  -142,  -143,   128, 
     125,    82,   271,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,  -142,  -143,    85,  -126,     0,     0,     0,  -108, 
     126,     0,     0,    83,     0,  -109,    84,     0,     0,     0, 
       0,     0,     0,     0,  -351,     0,     0,  -269,     0,     0, 
    -268,   -42,   -48,     0,  -101,     0,     0,  -103,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,   129,  -114,     0, 
       0,  -127,  -122,     0,     0,  -306,     0,    69,   -93,    70, 
       0,    68,  -307,   127,     0,     0,   272,  -142,  -143,   128, 
     125,     0,     0,  -272,     0,     0,     0,     0,     0,     0, 
    -271,     0,     0,     0,     0,     0,     0,     0,     0,  -108, 
     126,     0,     0,     0,  -306,  -109,    69,   -93,    70,     0, 
      68,  -307,   127,     0,     0,     0,  -142,  -143,   128,   125, 
       0,     0,     0,     0,  -101,     0,     0,  -103,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,   129,  -108,   126, 
       0,     0,     0,     0,  -109,     0,   -28,   188,   -29,    69, 
     136,    70,     0,    68,     0,   127,   124,     0,     0,  -142, 
    -143,    85,  -126,  -101,     0,     0,  -103,     0,     0,     0, 
      83,     0,     0,    84,     0,     0,   129,     0,     0,     0, 
       0,     0,    71,     0,  -306,     0,    69,   -93,    70,   185, 
      68,  -307,   127,     0,     0,   124,  -142,  -143,   128,   125, 
       0,     0,     0,     0,     0,  -114,     0,     0,  -127,  -122, 
       0,     0,     0,     0,     0,     0,     0,     0,  -108,   126, 
       0,     0,     0,     0,  -109,     0,     0,  -306,     0,    69, 
     -93,    70,   -30,    68,  -307,   127,     0,     0,   -31,  -142, 
    -143,   128,   125,  -101,     0,  -306,  -103,    69,   -93,    70, 
       0,    68,  -307,   127,     0,     0,   129,  -142,  -143,   128, 
     125,  -108,   126,     0,     0,     0,     0,  -109,     0,   208, 
       0,     0,     0,     0,     0,   124,     0,     0,     0,  -108, 
     126,     0,     0,     0,     0,  -109,  -101,     0,  -306,  -103, 
      69,   -93,    70,     0,    68,  -307,   127,     0,     0,   129, 
    -142,  -143,   128,   125,  -101,     0,     0,  -103,     0,     0, 
       0,     0,   263,     0,     0,     0,     0,   129,   124,     0, 
       0,     0,  -108,   126,     0,     0,     0,     0,  -109,     0, 
     264,  -306,     0,    69,   -93,    70,   124,    68,  -307,   127, 
       0,     0,     0,  -142,  -143,   128,   125,  -101,     0,  -306, 
    -103,    69,   -93,    70,     0,    68,  -307,   127,     0,     0, 
     129,  -142,  -143,   128,   125,  -108,   126,     0,     0,     0, 
       0,  -109,     0,   265,     0,     0,     0,     0,     0,   124, 
       0,     0,     0,  -108,   126,     0,     0,     0,     0,  -109, 
    -101,     0,  -306,  -103,    69,   -93,    70,     0,    68,  -307, 
     127,     0,     0,   129,  -142,  -143,   128,   125,  -101,     0, 
       0,  -103,     0,     0,     0,     0,   266,     0,     0,     0, 
       0,   129,   124,     0,     0,     0,  -108,   126,     0,     0, 
       0,     0,  -109,     0,   267,  -306,     0,    69,   -93,    70, 
     124,    68,  -307,   127,     0,     0,     0,  -142,  -143,   128, 
     125,  -101,     0,  -306,  -103,    69,   -93,    70,     0,    68, 
    -307,   127,     0,     0,   129,  -142,  -143,   128,   125,  -108, 
     126,     0,     0,     0,     0,  -109,     0,   268,     0,     0, 
       0,     0,     0,   124,     0,     0,     0,  -108,   126,     0, 
       0,     0,     0,  -109,  -101,     0,  -306,  -103,    69,   -93, 
      70,     0,    68,  -307,   127,     0,     0,   129,  -142,  -143, 
     128,   125,  -101,     0,     0,  -103,     0,     0,     0,     0, 
     280,     0,     0,     0,     0,   129,   124,     0,     0,     0, 
    -108,   126,     0,     0,     0,     0,  -109,     0,   285,  -306, 
       0,    69,   -93,    70,   124,    68,  -307,   127,     0,     0, 
       0,  -142,  -143,   128,   125,  -101,     0,  -306,  -103,    69, 
     -93,    70,     0,    68,  -307,   127,     0,     0,   129,  -142, 
    -143,   128,   125,  -108,   126,     0,     0,     0,     0,  -109, 
       0,   286,     0,     0,     0,     0,     0,   124,     0,     0, 
       0,  -108,   126,     0,     0,     0,     0,  -109,  -101,     0, 
    -306,  -103,    69,   -93,    70,     0,    68,  -307,   127,     0, 
       0,   129,  -142,  -143,   128,   125,  -101,     0,     0,  -103, 
       0,     0,     0,     0,   302,     0,     0,     0,     0,   129, 
     124,     0,     0,     0,  -108,   126,     0,     0,     0,     0, 
    -109,     0,   304,  -306,     0,    69,   -93,    70,   124,    68, 
    -307,   127,     0,     0,     0,  -142,  -143,   128,   125,  -101, 
       0,     0,  -103,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,   129,     0,     0,     0,     0,  -108,   126,     0, 
       0,     0,     0,  -109,     0,   325,     0,     0,     0,     0, 
       0,   124,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,   183,  -101,     0,  -306,  -103,    69,   -93,    70,     0, 
      68,  -307,   127,     0,     0,   129,  -142,  -143,   128,   125, 
       0,     0,     0,     0,     0,     0,     0,     0,   184,     0, 
       0,     0,     0,     0,   124,     0,     0,     0,  -108,   126, 
       0,     0,     0,  -306,  -109,    69,   -93,    70,     0,    68, 
    -307,   127,     0,     0,     0,  -142,  -143,   128,   125,     0, 
       0,     0,   262,  -101,     0,     0,  -103,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,   129,  -108,   126,     0, 
    -312,     0,     0,  -109,     0,     0,     0,     0,     0,   184, 
    -270,     0,     0,     0,     0,   124,    82,     0,     0,  -231, 
       0,     0,  -101,     0,     0,  -103,     0,  -142,  -143,    85, 
    -126,     0,     0,     0,     0,   129,   138,     0,    83,     0, 
       0,    84,     0,     0,     0,     0,     0,     0,   210,  -346, 
       0,     0,  -269,     0,   124,  -268,   -42,   -48,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,  -114,     0,     0,  -127,  -122,     0,     0, 
       0,  -306,     0,    69,   -93,    70,     0,    68,  -307,   127, 
       0,     0,  -174,  -142,  -143,   128,   125,     0,  -272,     0, 
       0,     0,     0,     0,     0,  -271,     0,     0,     0,     0, 
       0,     0,     0,     0,   115,  -108,   126,    -7,  -311,     0, 
       0,  -109,   160,     0,  -239,  -232,    47,     0,     0,     0, 
       0,     0,     0,  -142,  -143,    85,  -126,     0,     0,     0, 
    -101,     0,   209,  -103,    83,     0,     0,    84,     0,     0, 
       0,     0,     0,   129,     0,   -10,     0,     0,     0,     0, 
       0,   159,     0,     0,     0,     0,   210,  -164,     0,     0, 
       0,     0,   124,    -8,     0,    14,  -338,   -15,   -16,  -114, 
      -9,     0,  -127,  -122,     0,    46,  -155,    47,     0,  -340, 
       0,     0,     0,     0,  -142,  -143,    85,  -126,     0,     0, 
       0,     0,     0,     0,     0,   158,     0,     0,    84,     0, 
       0,  -192,     0,   116,   319,  -194,  -195,     0,  -306,     0, 
      69,   -93,    70,     0,    68,  -307,   127,     0,  -163,     0, 
    -142,  -143,   128,   125,   -17,     0,     0,     0,     0,     0, 
    -114,   -18,     0,  -127,  -122,     0,    46,     0,     0,     0, 
       0,     0,  -108,   126,     0,    13,    15,     0,  -109,     0, 
       0,     0,     0,     0,     0,  -243,     0,     0,     0,     0, 
       0,   -19,     0,     0,    16,     0,     0,  -101,     0,     0, 
    -103,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
     129,     0,  -298,   -41,  -270,   -38,   -36,   -37,   -39,     0, 
      82,     0,   -68,   134,     0,     0,     0,  -373,     0,   124, 
    -193,  -142,  -143,    85,  -126,     0,     0,     0,     0,     0, 
       0,     0,    83,     0,     0,    84,     0,     0,     0,     0, 
       0,     0,     0,   -35,     0,     0,  -269,     0,     0,  -268, 
     -42,   -48,     0,    86,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,   -70,     0,     0,  -114,     0,     0, 
    -127,  -122,     0,     0,  -298,   -41,  -270,   -38,   -36,   -37, 
     -39,     0,    82,     0,  -289,     0,     0,     0,     0,     0, 
       0,     0,  -272,  -142,  -143,    85,  -126,     0,     0,  -271, 
       0,  -299,     0,     0,    83,     0,     0,    84,     0,     0, 
       0,     0,     0,     0,     0,   -35,     0,     0,  -269,     0, 
       0,  -268,   -42,   -48,     0,    86,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,   -70,     0,     0,  -114, 
       0,     0,  -127,  -122,     0,     0,  -298,   -41,  -270,   -38, 
     -36,   -37,   -39,     0,    82,     0,   -60,     0,     0,     0, 
       0,     0,     0,     0,  -272,  -142,  -143,    85,  -126,     0, 
       0,  -271,     0,  -299,     0,     0,    83,     0,     0,    84, 
       0,     0,     0,     0,     0,     0,     0,   -35,     0,     0, 
    -269,     0,     0,  -268,   -42,   -48,     0,    86,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,   -70,     0, 
       0,  -114,     0,     0,  -127,  -122,     0,     0,    14,  -338, 
     -15,   -16,     0,     0,     0,     0,     0,     0,     0,  -231, 
      47,     0,  -340,     0,     0,     0,  -272,  -142,  -143,    85, 
    -126,     0,     0,  -271,     0,  -299,    40,     0,  -237,     0, 
       0,   -12,     0,    12,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,  -183,     0,     0,     0,     0, 
       0,   269,     0,   323,     0,     0,     0,   -17,     0,     0, 
    -241,     0,     0,  -124,   -18,     0,  -127,  -122,     0,    46, 
       0,     0,     0,     0,     0,     0,     0,     0,    13,    15, 
       0,  -198,     0,     0,     0,     0,     0,     0,  -245,     0, 
       0,     0,     0,     0,   -19,     0,  -192,    16,  -368,   319, 
    -194,  -195,     0,  -306,     0,    69,   -93,    70,    47,    68, 
    -307,   127,     0,     0,     0,  -142,  -143,   128,   125,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,  -108,   126,     0, 
       0,     0,     0,  -109,     0,     0,     0,     0,     0,  -168, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,  -101,     0,     0,  -103,     0,    46,     0,     0, 
       0,     0,     0,     0,     0,   129,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,   123,     0, 
     317,     0,  -372,   318,   124,  -193,  -298,   -41,  -270,   -38, 
     -36,   -37,   -39,     0,    82,     0,    81,  -231,    47,     0, 
       0,     0,     0,     0,     0,  -142,  -143,    85,  -126,     0, 
       0,     0,     0,     0,    44,     0,    83,     0,     0,    84, 
       0,     0,     0,     0,     0,     0,     0,   -35,     0,     0, 
    -269,     0,     0,  -268,   -42,   -48,     0,    86,     0,  -167, 
       0,     0,     0,     0,     0,     0,     0,     0,   -70,     0, 
       0,  -114,     0,     0,  -127,  -122,     0,    46,  -298,   -41, 
    -270,   -38,   -36,   -37,   -39,     0,    82,     0,   109,    35, 
      47,     0,     0,     0,     0,     0,  -272,  -142,  -143,    85, 
    -126,     0,     0,  -271,     0,  -299,     0,     0,    83,     0, 
       0,    84,     0,     0,     0,     0,     0,     0,     0,   -35, 
       0,     0,  -269,     0,     0,  -268,   -42,   -48,     0,    86, 
       0,  -169,     0,     0,     0,  -256,     0,     0,     0,     0, 
     -70,     0,     0,  -114,     0,     0,  -127,  -122,     0,    46, 
       0,    14,  -339,     0,     0,  -248,  -249,  -230,    62,     0, 
       0,     0,    -5,    47,   258,  -341,     0,     0,  -272,   259, 
     240,     0,   143,   309,   190,  -271,     0,  -299,    43,  -202, 
       0,     0,     0,     0,   -11,     0,     0,     0,  -251,     0, 
    -253,    32,     0,    33,     0,     0,  -264,   308,     0,     0, 
    -343,     0,     0,     0,  -316,     0,   298,     0,     0,     0, 
       0,     0,     0,  -241,     0,   120,     0,     0,  -146,     0, 
    -148,     0,    46,     0,     0,     0,     0,     0,  -301,     0, 
       0,     0,     0,     0,    60,     0,   112,     0,     0,     0, 
      14,  -338,   -15,   -16,     0,     0,  -230,     0,  -247,     0, 
      16,    35,    47,     0,  -340,     0,     0,     0,   322,  -142, 
    -143,    85,  -126,  -359,     0,     0,     0,    63,     0,     0, 
       0,     0,     0,     0,     0,    12,     0,     0,     0,  -254, 
       0,    34,    54,     0,     0,  -265,     0,  -178,     0,     0, 
       0,     0,     0,  -315,     0,   -62,     0,  -255,     0,   -17, 
       0,     0,  -181,     0,   189,  -125,   -18,     0,  -127,  -122, 
     135,    46,  -357,     0,     0,     0,     0,     0,     0,     0, 
      13,    15,     0,  -196,     0,     0,     0,     0,     0,   140, 
    -245,     0,     0,     0,     0,     0,   -19,    52,     0,    16, 
    -298,   -41,  -270,   -38,   -36,   -37,   -39,  -325,    82,    69, 
     110,    70,    47,    68,    66,    72,     0,     0,     0,  -142, 
    -143,    85,  -126,     0,     0,     0,     0,     0,  -156,     0, 
      83,     0,     0,    84,     0,     0,     0,     0,     0,     0, 
       0,   -35,    71,     0,  -269,     0,     0,  -268,   -42,   -48, 
       0,    86,     0,  -330,  -323,     0,     0,  -322,  -324,  -320, 
    -321,  -157,   -70,     0,     0,  -114,  -327,     0,  -127,  -122, 
       0,    46,  -151,  -152,    67,  -160,     0,  -328,     0,  -165, 
       0,     0,     0,     0,  -158,     0,     0,     0,     0,     0, 
    -272,     0,  -335,     0,  -337,     0,  -159,  -271,  -336,  -299, 
      14,  -338,   -15,   -16,  -248,  -249,  -230,  -277,   107,  -280, 
    -224,    10,    47,   137,  -340,    39,   -79,   -66,   252,  -142, 
    -143,    85,  -126,  -359,  -226,     1,     2,     7,   -14,    -3, 
      83,    23,    64,    84,   114,    12,    30,  -250,    31,  -253, 
      32,  -223,    33,  -261,    41,  -264,   236,    11,    38,  -342, 
     -58,    48,   -59,  -315,  -288,   294,   293,     3,   334,   -17, 
    -278,  -279,  -186,    36,   119,  -114,   -18,  -154,  -127,  -122, 
      45,    46,  -356,  -366,   331,   332,  -161,  -300,   305,   -69, 
      13,    15,   111,  -176,  -303,   112,  -182,    49,   139,   140, 
    -245,   287,     4,   176,  -334,  -371,   -19,  -246,    24,    16, 
};

template<>
const int16 *Pascal_parser_tables_t::Nm = &Nm_[0];

// Nonterminal transition matrix row ...
static const uint16 Nr_[344] = {
 3140,  3140,  3140,  3140,  3140,  3140,  2851,  3140,  3140,  3140, 
 3140,  3140,  3140,  2851,  3140,  2851,  3140,  3140,  3140,  2940, 
 3140,  3140,  3140,  2508,  3140,  2851,  2706,  3140,  3140,  2940, 
 3140,  2851,  2940,  3140,  2778,  3140,  2851,  3140,  3140,  2851, 
 3140,  2851,  2940,  3140,  3140,  3140,  3040,  3140,  3140,  2508, 
 3140,  3140,  3140,  2851,  3140,  2706,  3140,  2778,  3040,  3140, 
 3140,  2114,  3140,  3140,  2114,  2851,  3140,  3140,  3140,  2851, 
 3140,  3140,  2851,  2175,  2606,  2211,  2940,  1278,  3140,  2008, 
 3140,  3140,  3140,  2851,  3140,  2940,  3140,   258,  2508,  2114, 
 3140,  3140,  3140,  3140,  3140,  3140,  3140,  3140,  3140,  3140, 
 3140,  3140,  3140,  3140,  3140,  3140,  3140,  3140,  2175,  3140, 
 3140,  3140,     1,  2008,  2175,  3140,  3140,  1856,  1317,  3140, 
 3140,  1360,  2940,  2851,     1,  3140,  3140,  2851,   631,  3140, 
 1045,  1397,   675,  2074,  2851,  3140,  2851,  3140,  3140,  3140, 
    2,  1360,  1045,   693,   509,   340,   273,   279,   300,    20, 
  188,   525,     5,  3140,  3140,  3140,   693,  3140,  2851,  3140, 
 3140,    13,    28,  2851,  3140,     1,    35,    86,    91,   106, 
  111,   128,   148,   165,   170,  3140,   509,   340,  2851,  2851, 
 3140,  2851,  2508,  3140,  2851,  2851,  1917,  3140,  3140,  3140, 
 1440,  1458,  1501,  1544,  1562,  1605,  2508,  1108,  1124,  1198, 
  718,   814,   875,   891,   952,   968,  1029,  1648,  2851,  3140, 
 2851,   363,  1666,  2706,  1709,  2778,  2940,  3140,   747,  2851, 
 2851,  2851,  3140,  3140,  3140,  3140,  3140,  3140,  3140,   773, 
  567,  2292,  3140,  3140,  3140,  3140,  3140,   207,  2851,  2851, 
 3140,  3140,  3140,  2851,  2851,  2851,  2851,  2851,  2851,  2851, 
 2851,  2851,  3140,  2851,  3140,  3140,   273,  3140,  3140,  3140, 
 1213,  1752,  3140,  2851,  2851,  2851,  2851,  2851,  2851,  3140, 
    1,     1,     1,  3140,  3140,  3140,  3140,  3140,  3140,  3140, 
 2851,  1956,  1770,  3140,  2851,  2851,  2851,     2,  3140,  2851, 
 3140,  3140,  3140,  2940,  3140,   279,  2364,  2940,  2606,   300, 
   20,  2940,  2851,  3040,  2851,  2508,  2114,   310,  3140,  1813, 
    0,   391,  3140,   442,  3140,   590,   188,  3140,  3140,  3140, 
 3140,  3140,  3140,  3140,  2175,  2851,  2436,  3140,  3140,  2211, 
 3140,  2940,  2508,  2606,  3140,   457,  3140,  3140,   368,  3140, 
  240,   525,  3140,  3140, 
};

template<>
const uint16 *Pascal_parser_tables_t::Nr = &Nr_[0];

// Nonterminal transition matrix column ...
static const uint8 Nc_[379] = {
   10,    10,    41,    57,     6,    92,    98,    10,    10,    10, 
   10,    41,    41,    44,    47,    90,    90,    90,    90,    90, 
    2,     2,    97,     3,     4,    42,    59,    57,     5,     6, 
    6,     6,    92,    98,    22,    10,    10,    10,    10,    10, 
   10,    10,    41,    44,    44,    44,    44,    44,    47,    90, 
   90,    90,    90,    90,    90,    90,     2,    97,     3,     4, 
    7,     9,    42,    59,    54,    57,    58,    60,    61,     5, 
    6,    66,    77,    77,    77,     7,     7,     7,    84,    84, 
   84,     9,    92,    92,    92,    92,    92,    92,    92,    98, 
   98,    98,    98,    22,    22,    22,    22,    22,    22,    22, 
   22,    10,    10,    10,    10,    10,    10,    10,    10,    10, 
   30,    30,    30,    30,    33,    33,    33,    33,    33,    33, 
   33,    33,    65,    65,    65,    65,    65,    65,    68,    68, 
   68,    68,    68,    68,    68,    68,    68,    68,    68,    68, 
   68,    68,    69,    69,    69,    69,    42,    41,    44,    47, 
   28,    53,    59,    54,    57,    58,    60,    60,    60,    60, 
   61,    66,    77,    90,    94,    84,    92,    98,    94,    96, 
   96,    96,     1,    14,    99,    15,     0,    48,    97,    97, 
   97,    97,    49,    51,    51,    51,    51,    62,    72,     1, 
   73,     2,     3,     3,     3,     3,     4,    74,     5,    75, 
    6,     7,     7,     8,     9,    10,    11,    12,    79,    13, 
   14,    15,    16,    17,    18,    19,    20,    21,    21,    22, 
   22,    23,    23,    24,    24,    25,    25,    26,    26,    27, 
   27,    28,    28,    29,    29,    30,    31,    31,    32,    32, 
   33,    33,    34,    34,    35,    35,    36,    36,    37,    37, 
   38,    38,    39,    40,    40,    41,    41,    42,    42,    43, 
   44,    44,    45,    46,    46,    46,    47,    47,    48,    48, 
   49,    49,    49,    50,    50,    51,    51,    52,    52,    52, 
   52,    53,    53,    54,    54,    55,    55,    56,    56,    57, 
   58,    58,    59,    59,    60,    60,    61,    61,    62,    62, 
   63,    63,    64,    64,    65,    65,    66,    66,    67,    67, 
   68,    68,    68,    69,    69,    70,    70,    71,    71,    72, 
   72,    72,    73,    73,    73,    74,    74,    75,    75,    76, 
   76,    77,    77,    78,    78,    79,    79,    79,    80,    80, 
   81,    81,    82,    82,    83,    83,    84,    84,    85,    85, 
   86,    86,    86,    86,    87,    87,    88,    88,    89,    89, 
   90,    91,    91,    92,    92,    93,    93,    94,    94,    95, 
   95,    96,    97,    97,    98,    98,    98,    99,    99, 
};

template<>
const uint8 *Pascal_parser_tables_t::Nc = &Nc_[0];

// Reduction matrix ...
static const uint16 Rm_[12] = {
       0,     0,     0,     0,     0,   308,   326,     0,   287,   285, 
       0,     0, 
};

template<>
const uint16 *Pascal_parser_tables_t::Rm = &Rm_[0];

// Reduction matrix row ...
static const int16 Rr_[344] = {
     225,   227,   229,     0,     0,     0,     0,   244,   236,     0, 
     233,     0,     0,   170,     0,   171,     0,     0,     0,     0, 
       0,     0,     0,     4,     0,   229,     0,   317,   354,   244, 
       0,    23,    24,     0,    26,     0,    71,     0,   344,   344, 
       0,     0,   229,   238,     0,     0,   319,     0,     0,   244, 
       0,     0,     0,     0,     0,   275,     0,   275,   275,   348, 
       0,     0,     0,   242,     6,   317,   308,     0,   302,   302, 
       0,     0,    -2,     0,     0,     0,   317,     0,     0,     0, 
     358,     0,     0,   203,   110,     0,     0,     0,     0,   266, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,   273,   365,     0,     0,     0, 
       0,     0,     0,     0,    13,     0,     0,     0,     0,    75, 
      76,     0,   302,     0,    82,    89,   107,   308,     0,     0, 
       0,     0,     0,   310,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,   283,     0,     0,     0, 
     263,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,   374,     0,     0,   348, 
     350,   240,   240,     0,   304,   153,     0,     0,     0,    77, 
       0,     0,     0,     0,     0,     0,   317,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
     313,     0,     0,   317,     0,   317,   358,   361,     0,   111, 
     112,   113,   115,   116,   117,   118,   119,   120,   121,     0, 
       0,   275,     0,    -7,    63,     0,   267,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,   285,   200,     0,     0,     0,     0,     0, 
       0,     0,     0,    83,    84,    85,    86,    87,    88,   329, 
      90,    91,    92,    94,    95,    96,    97,    98,    99,   100, 
       0,     0,     0,   333,   263,   166,     0,   364,     0,   203, 
       0,     0,     0,   285,     0,     0,   275,     0,   367,     0, 
       0,     0,   305,   317,   314,   285,   317,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,   292,     0,   191,   369, 
       0,     0,     0,     0,   317,     0,   275,     0,     0,     0, 
       0,   344,   344,   317,     0,     0,    64,     0,     0,     0, 
       0,   283,     0,     0, 
};

template<>
const int16 *Pascal_parser_tables_t::Rr = &Rr_[0];

// Reduction matrix column ...
static const uint8 Rc_[113] = {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     1,     2,     0,     0,     3,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     4,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0, 
};

template<>
const uint8 *Pascal_parser_tables_t::Rc = &Rc_[0];

// Production lengths (minus one) ...
static const int8 PL_[379] = {
       1,     5,     3,     2,     1,     1,     2,     0,     0,     0, 
       0,     2,     2,     2,     1,     0,     0,     0,     0,     0, 
       1,     2,     0,     1,     0,     0,     1,     3,     4,     0, 
       0,     0,     2,     2,     2,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     2,     2,     1,     1, 
       5,     2,     2,     0,     4,     4,     0,     2,     2,     1, 
       0,     1,     3,     5,     7,     1,     1,     2,     2,     1, 
       0,     3,     0,     2,     2,     2,     2,     2,     2,     0, 
       2,     2,     2,     0,     2,     2,     2,     2,     2,     2, 
       2,     0,     1,     0,     2,     1,     1,     0,     0,     0, 
       0,     2,     2,     2,     0,     2,     2,     2,     2,     2, 
       2,     2,     0,     2,     1,     1,     0,     0,     3,     3, 
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3, 
       3,     3,     0,     0,     0,     0,     1,     2,     1,     3, 
       2,     1,     0,     2,     1,     1,     0,     0,     0,     0, 
       0,     4,     6,     3,     1,     0,     3,     3,     7,     3, 
       0,     0,     3,     3,     4,     0,     2,     0,     0,     0, 
       0,     0,     2,     1,     1,     1,     0,     3,     1,     5, 
       2,     0,     0,     0,     0,     0,     2,     0,     2,     0, 
       0,     0,     0,     0,     1,     1,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
       0,     0,     0,     0,     0,    -1,     1,    -1,     1,    -1, 
       0,     0,     2,    -1,     2,     1,    -1,     1,    -1,     1, 
      -1,     0,    -1,     1,    -1,     0,     0,     2,     0,     0, 
       0,     1,     3,     0,     1,     0,     1,     0,     2,     2, 
       0,     2,     1,    -1,     0,     2,    -1,     1,     0,     0, 
       0,     0,     0,    -1,     2,    -1,     0,     0,     0,     0, 
       0,     0,     2,    -1,     0,    -1,     0,    -1,     1,     2, 
       0,     2,    -1,     1,     0,     2,     0,     2,     0,     0, 
       0,     1,    -1,     1,     0,     2,     0,     0,    -1,     2, 
      -1,     0,     2,    -1,     1,     0,     2,    -1,     1,    -1, 
       0,     0,     0,     0,     0,     0,     0,     0,     0,    -1, 
       1,     0,     2,    -1,     0,     0,     0,     0,     0,     1, 
       0,     1,     0,     2,    -1,     2,     0,     0,    -1,     0, 
      -1,     1,     0,     0,    -1,     1,     0,     2,    -1,     0, 
       1,    -1,     1,     0,     1,    -1,     0,    -1,     0,    -1, 
       1,     1,     0,     2,    -1,     0,     2,    -1,     1, 
};

template<>
const int8 *Pascal_parser_tables_t::PL = &PL_[0];

template<>
const uint32 *Pascal_parser_tables_t::nd_fterm = 0;

template<>
const uint32 *Pascal_parser_tables_t::nd_term = 0;

template<>
const uint32 *Pascal_parser_tables_t::nd_faction = 0;

template<>
const uint32 *Pascal_parser_tables_t::nd_action = 0;

// Terminal action number ...
static const int8 tact_numb_[113] = {
       0,    -1,     1,     1,     1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1, 
};

template<>
const int8 *Pascal_parser_tables_t::tact_numb = &tact_numb_[0];

// Node number for each production ...
static const int16 node_numb_[379] = {
       0,     1,     2,     3,     4,     5,     6,     7,     8,     9, 
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19, 
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    21, 
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31, 
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41, 
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51, 
      52,    53,    54,    -1,    55,    56,    57,    58,    59,    60, 
      61,     9,    -1,    -1,    -1,    62,    63,    64,    65,    66, 
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76, 
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86, 
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96, 
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85, 
      86,    87,    90,    91,    92,    93,    95,    97,    98,    99, 
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109, 
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119, 
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129, 
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139, 
     140,   141,   142,   143,    -1,    -1,    -1,    -1,   144,   145, 
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155, 
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1, 
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171, 
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181, 
     182,   183,   184,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
};

template<>
const int16 *Pascal_parser_tables_t::node_numb = &node_numb_[0];

// Node action numbers ...
static const int8 nact_numb_[379] = {
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1, 
};

template<>
const int8 *Pascal_parser_tables_t::nact_numb = &nact_numb_[0];

template<>
const uint32 *Pascal_parser_tables_t::reverse = 0;

