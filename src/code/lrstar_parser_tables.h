/* Copyright 2023 Logic Magicians Software
 * BSD License.
 */
#if !defined(_LRSTAR_PARSER_TABLES_H_)
#define _LRSTAR_PARSER_TABLES_H_

template<typename T_term_numb, typename T_Tm, typename T_Tr, typename T_Tc>
class templ_lrstar_parser_tables {
public:
    static const char **term_symb; // Terminal symbols of the grammar.
    static const char **head_symb; // Nonterminal symbols of the grammar.
    static const char **tact_name; // Terminal action names found in the grammar.
    static const uchar  *head_numb; // Head symbol number for a production.
    static const ushort *f_tail   [   227]; // First tail in a production.
    static const char   *tail     [   397]; // Tail symbol number.
    static const char   *arga     [    71]; // Arguments for terminal actions.

private:
    static const uchar  Bm[   158]       ; // Boolean matrix.
    static const uchar  Br[   205]       ; // Boolean matrix row.
    static const uchar  Bc[    71]       ; // Boolean matrix column.
    static const uchar  Bf[    71]       ; // Boolean matrix filter/mask.
    static const short  Tm[   229]       ; // Terminal transition matrix.
    static const uchar  Tr[   205]       ; // Terminal transition matrix row.
    static const uchar  Tc[    71]       ; // Terminal transition matrix column.
    static const short  Nm[  1169]       ; // Nonterminal transition matrix.
    static const ushort Nr[   205]       ; // Nonterminal transition matrix row.
    static const uchar  Nc[   226]       ; // Nonterminal transition matrix column.
    static const uchar  Rm[   239]       ; // Reduction matrix.
    static const short  Rr[   205]       ; // Reduction matrix row.
    static const uchar  Rc[    71]       ; // Reduction matrix column.
    static const char   PL[   226]       ; // Production length minus one.

    static const char   tact_numb[    71]; // Terminal action numbers.

    static void   (*init_func[    2]) ()       ; // Init action function pointers.
    static int    (*tact_func[    2]) (int& t) ; // Terminal action function pointers.
};

#endif
