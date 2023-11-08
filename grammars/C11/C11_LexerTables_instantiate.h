// Generated by DFA 24.0.016)
// DO NOT EDIT.

#if !defined(__C11__LexerTables_INSTANTIATE)
#define __C11__LexerTables_INSTANTIATE

// Include this file only once in a project.  It instantiates a lexer.
template<typename T_term_numb, typename T_Tm, typename T_Tr, typename T_Tc>
const int templ_lrstar_lexer<T_term_numb, T_Tm, T_Tr, T_Tc>::n_term_numb = 288;

template<typename T_term_numb, typename T_Tm, typename T_Tr, typename T_Tc>
const int templ_lrstar_lexer<T_term_numb, T_Tm, T_Tr, T_Tc>::n_Tm = 14927;

template<typename T_term_numb, typename T_Tm, typename T_Tr, typename T_Tc>
const int templ_lrstar_lexer<T_term_numb, T_Tm, T_Tr, T_Tc>::n_Tr = 288;

template<typename T_term_numb, typename T_Tm, typename T_Tr, typename T_Tc>
const int templ_lrstar_lexer<T_term_numb, T_Tm, T_Tr, T_Tc>::n_Tc = 256;

template<typename T_term_numb, typename T_Tm, typename T_Tr, typename T_Tc>
const T_term_numb *templ_lrstar_lexer<T_term_numb, T_Tm, T_Tr, T_Tc>::l_term_numb = &term_numb_[0];

template<typename T_term_numb, typename T_Tm, typename T_Tr, typename T_Tc>
const T_Tm *templ_lrstar_lexer<T_term_numb, T_Tm, T_Tr, T_Tc>::l_Tm = &Tm_[0];

template<typename T_term_numb, typename T_Tm, typename T_Tr, typename T_Tc>
const T_Tr *templ_lrstar_lexer<T_term_numb, T_Tm, T_Tr, T_Tc>::l_Tr = &Tr_[0];

template<typename T_term_numb, typename T_Tm, typename T_Tr, typename T_Tc>
const T_Tc *templ_lrstar_lexer<T_term_numb, T_Tm, T_Tr, T_Tc>::l_Tc = &Tc_[0];

template<typename T_term_numb, typename T_Tm, typename T_Tr, typename T_Tc>
Token templ_lrstar_lexer<T_term_numb, T_Tm, T_Tr, T_Tc>::token;

template<typename T_term_numb, typename T_Tm, typename T_Tr, typename T_Tc>
Token templ_lrstar_lexer<T_term_numb, T_Tm, T_Tr, T_Tc>::lookahead;

template<typename T_term_numb, typename T_Tm, typename T_Tr, typename T_Tc>
int templ_lrstar_lexer<T_term_numb, T_Tm, T_Tr, T_Tc>::tab;

template<typename T_term_numb, typename T_Tm, typename T_Tr, typename T_Tc>
int templ_lrstar_lexer<T_term_numb, T_Tm, T_Tr, T_Tc>::linenumb;

template<typename T_term_numb, typename T_Tm, typename T_Tr, typename T_Tc>
int templ_lrstar_lexer<T_term_numb, T_Tm, T_Tr, T_Tc>::linenumb_printed;

template<typename T_term_numb, typename T_Tm, typename T_Tr, typename T_Tc>
int templ_lrstar_lexer<T_term_numb, T_Tm, T_Tr, T_Tc>::lookahead_linenumb;

template class templ_lrstar_lexer<char, ushort, ushort, uchar>;

#endif
