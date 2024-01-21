/* Copyright 2023, 2024 Logic Magicians Software
 * BSD License.
 */
#if !defined(_LRSTAR_PARSER_TABLES_H_)
#define _LRSTAR_PARSER_TABLES_H_

template<typename T_term_symb,
         typename T_head_symb,
         typename T_tact_name,
         typename T_node_name,

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
struct lrstar_parser_tables_data {
    const T_term_symb  *term_symb; // Terminal symbols of the grammar.
    const T_head_symb  *head_symb; // Nonterminal symbols of the grammar.
    const T_tact_name  *tact_name; // Terminal action names in grammar.
    const T_node_name  *node_name; // Node names found in grammar.

    const T_head_numb  *head_numb; // Head symbol number for production.
    const T_f_tail     *f_tail; // First tail in a production.
    const T_tail       *tail; // Tail symbol number.

    const T_arga       *arga; // Arguments for terminal actions.
    const T_argx       *argx; // Arguments for terminal actions.
    const T_argy       *argy; // Arguments for terminal actions.

    const T_Bm         *Bm; // Boolean matrix.
    const T_Br         *Br; // Boolean matrix row.
    const T_Bc         *Bc; // Boolean matrix column.
    const T_Bf         *Bf; // Boolean matrix filter/mask.

    const T_Tm         *Tm; // Terminal transition matrix.
    const T_Tr         *Tr; // Terminal transition matrix row.
    const T_Tc         *Tc; // Terminal transition matrix column.

    const T_Nm         *Nm; // Nonterminal transition matrix.
    const T_Nr         *Nr; // Nonterminal transition matrix row.
    const T_Nc         *Nc; // Nonterminal transition matrix column.

    const T_Rm         *Rm; // Reduction matrix.
    const T_Rr         *Rr; // Reduction matrix row.
    const T_Rc         *Rc; // Reduction matrix column.

    const T_PL         *PL; // Production length minus one.

    const T_nd_fterm   *nd_fterm;
    const T_nd_term    *nd_term;
    const T_nd_faction *nd_faction;
    const T_nd_action  *nd_action;

    const T_tact_numb  *tact_numb; // Terminal action numbers.
    const T_node_numb  *node_numb;
    const T_nact_numb  *nact_numb;
    const T_reverse    *reverse;

};


template<typename T_term_symb,
         typename T_head_symb,
         typename T_tact_name,
         typename T_node_name,

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
struct lrstar_parser_tables {
public:
    const int  n_terms;
    const int  n_heads;
    const int  n_prods;
    const int  n_states;
    const int  accept_state;
    const int  n_termactns;
    const int  n_nodenames;
    const int  n_nodeactns;
    const int  eof_symb;
    const bool err_used;

public:
    const lrstar_parser_tables_data<T_term_symb,
        T_head_symb,
        T_tact_name,
        T_node_name,
        T_head_numb,
        T_f_tail,
        T_tail,
        T_arga,
        T_argx,
        T_argy,
        T_Bm,
        T_Br,
        T_Bc,
        T_Bf,
        T_Tm,
        T_Tr,
        T_Tc,
        T_Nm,
        T_Nr,
        T_Nc,
        T_Rm,
        T_Rr,
        T_Rc,
        T_PL,
        T_nd_fterm,
        T_nd_term,
        T_nd_faction,
        T_nd_action,
        T_tact_numb,
        T_node_numb,
        T_nact_numb,
        T_reverse> tbls;

    lrstar_parser_tables(int                 n_terms_,
                         int                 n_heads_,
                         int                 n_prods_,
                         int                 n_states_,
                         int                 accept_state_,
                         int                 n_termactns_,
                         int                 n_nodenames_,
                         int                 n_nodeactns_,
                         int                 eof_symb_,
                         bool                err_used_,
                         lrstar_parser_tables_data<T_term_symb,
                         T_head_symb,
                         T_tact_name,
                         T_node_name,
                         T_head_numb,
                         T_f_tail,
                         T_tail,
                         T_arga,
                         T_argx,
                         T_argy,
                         T_Bm,
                         T_Br,
                         T_Bc,
                         T_Bf,
                         T_Tm,
                         T_Tr,
                         T_Tc,
                         T_Nm,
                         T_Nr,
                         T_Nc,
                         T_Rm,
                         T_Rr,
                         T_Rc,
                         T_PL,
                         T_nd_fterm,
                         T_nd_term,
                         T_nd_faction,
                         T_nd_action,
                         T_tact_numb,
                         T_node_numb,
                         T_nact_numb,
                         T_reverse> tbls_) :
        n_terms(n_terms_),
        n_heads(n_heads_),
        n_prods(n_prods_),
        n_states(n_states_),
        accept_state(accept_state_),
        n_termactns(n_termactns_),
        n_nodenames(n_nodenames_),
        n_nodeactns(n_nodeactns_),
        eof_symb(eof_symb_),
        err_used(err_used_),
        tbls(tbls_)
        {
        }
};
#endif
/* Local Variables:      */
/* mode: c++             */
/* c-basic-offset: 4     */
/* tab-width: 4          */
/* indent-tabs-mode: nil */
/* End:                  */
