/* Copyright 2023 Logic Magicians Software
 * BSD License.
 */
#if !defined(_LRSTAR_PARSER_TABLES_H_)
#define _LRSTAR_PARSER_TABLES_H_

#include "lrstar.h"

template<typename T_term_symb,
         typename T_head_symb,
         typename T_tact_name,
         typename T_node_name,
         typename T_text_str,

         typename T_head_numb,
         typename T_f_tail,
         typename T_tail,

         typename T_arga,
         typename T_argx,
         typename T_argy,

         typename T_Bm,
         typename T_Br,
         typename T_Bc,
         typename T_Bf,

         typename T_Tm,
         typename T_Tr,
         typename T_Tc,

         typename T_Nm,
         typename T_Nr,
         typename T_Nc,

         typename T_Rm,
         typename T_Rr,
         typename T_Rc,

         typename T_PL,

         typename T_nd_fterm,
         typename T_nd_term,
         typename T_nd_faction,
         typename T_nd_action,

         typename T_tact_numb,
         typename T_node_numb,
         typename T_nact_numb,
         typename T_reverse>
struct templ_lrstar_parser_tables {
public:
    static const int n_terms;
    static const int n_heads;
    static const int n_prods;
    static const int n_states;
    static const int accept_state;
    static const int n_termactns;
    static const int n_nodenames;
    static const int n_nodeactns;
    static const int eof_symb;
    static const int err_used;

public:
    static const int n_term_symb; // Terminal symbols of the grammar.
    static const int n_head_symb; // Nonterminal symbols of the grammar.
    static const int n_tact_name; // Terminal action names in grammar.
    static const int n_node_name; // Node names found in grammar.
    static const int n_text_str; // Text strings found in grammar.

    static const int n_head_numb; // Head symbol number for production.
    static const int n_f_tail; // First tail in a production.
    static const int n_tail; // Tail symbol number.

    static const int n_arga; // Arguments for terminal actions.
    static const int n_argx; // Arguments for terminal actions.
    static const int n_argy; // Arguments for terminal actions.

    static const int n_Bm; // Boolean matrix.
    static const int n_Br; // Boolean matrix row.
    static const int n_Bc; // Boolean matrix column.
    static const int n_Bf; // Boolean matrix filter/mask.

    static const int n_Tm; // Terminal transition matrix.
    static const int n_Tr; // Terminal transition matrix row.
    static const int n_Tc; // Terminal transition matrix column.

    static const int n_Nm; // Nonterminal transition matrix.
    static const int n_Nr; // Nonterminal transition matrix row.
    static const int n_Nc; // Nonterminal transition matrix column.

    static const int n_Rm; // Reduction matrix.
    static const int n_Rr; // Reduction matrix row.
    static const int n_Rc; // Reduction matrix column.

    static const int n_PL; // Production length minus one.

    static const int n_nd_fterm;
    static const int n_nd_term;
    static const int n_nd_faction;
    static const int n_nd_action;

    static const int n_tact_numb; // Terminal action numbers.
    static const int n_node_numb;
    static const int n_nact_numb;
    static const int n_reverse;

public:
    static const T_term_symb  *term_symb; // Terminal symbols of the grammar.
    static const T_head_symb  *head_symb; // Nonterminal symbols of the grammar.
    static const T_tact_name  *tact_name; // Terminal action names in grammar.
    static const T_node_name  *node_name; // Node names found in grammar.
    static const T_text_str   *text_str; // Text strings found in grammar.

    static const T_head_numb  *head_numb; // Head symbol number for production.
    static const T_f_tail     *f_tail; // First tail in a production.
    static const T_tail       *tail; // Tail symbol number.

    static const T_arga       *arga; // Arguments for terminal actions.
    static const T_argx       *argx; // Arguments for terminal actions.
    static const T_argy       *argy; // Arguments for terminal actions.

    static const T_Bm         *Bm; // Boolean matrix.
    static const T_Br         *Br; // Boolean matrix row.
    static const T_Bc         *Bc; // Boolean matrix column.
    static const T_Bf         *Bf; // Boolean matrix filter/mask.

    static const T_Tm         *Tm; // Terminal transition matrix.
    static const T_Tr         *Tr; // Terminal transition matrix row.
    static const T_Tc         *Tc; // Terminal transition matrix column.

    static const T_Nm         *Nm; // Nonterminal transition matrix.
    static const T_Nr         *Nr; // Nonterminal transition matrix row.
    static const T_Nc         *Nc; // Nonterminal transition matrix column.

    static const T_Rm         *Rm; // Reduction matrix.
    static const T_Rr         *Rr; // Reduction matrix row.
    static const T_Rc         *Rc; // Reduction matrix column.

    static const T_PL         *PL; // Production length minus one.

    static const T_nd_fterm   *nd_fterm;
    static const T_nd_term    *nd_term;
    static const T_nd_faction *nd_faction;
    static const T_nd_action  *nd_action;

    static const T_tact_numb  *tact_numb; // Terminal action numbers.
    static const T_node_numb  *node_numb;
    static const T_nact_numb  *nact_numb;
    static const T_reverse    *reverse;

    static init_func_t        *init_func;   /* Pointer to init_func  table. */
    static tact_func_t        *tact_func;   /* Pointer to tact_func table.  */
    static nact_func_t        *nact_func;   /* Pointer to nact_func table.  */
};
#endif
