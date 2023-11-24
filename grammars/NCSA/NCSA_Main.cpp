#include "lrstar_basic_defs.h"
#include "NCSA_LexerTables_typedef.h"
#include "NCSA_Parser.h"

void NCSA_init_actions(lrstar_parser *parser); /* User-supplied */
void NCSA_term_actions(lrstar_parser *parser); /* User-supplied */
static init_func_t NCSA_init_funcs_[2] = {
   NCSA_init_actions,
   NCSA_term_actions
};

int NCSA_error(lrstar_parser *parser, int &t);
int NCSA_lookup(lrstar_parser *parser, int &t);
// Terminal action function pointers ...
static tact_func_t NCSA_tact_funcs_[2] = {
   NCSA_error,
   NCSA_lookup,
};

// Node action function pointers ...
static nact_func_t NCSA_nact_funcs_[11] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
};


lrstar_parser generated_parser(/* grammar      */   "NCSA",
                               /* user data    */   NULL,
                               /* actions      */   true,
                               /* debug_parser */   false,
                               /* debug_trace  */   false,
                               /* expecting    */   true,
                               /* insensitive  */   false,
                               /* lookaheads   */   1,
                               /* make_ast     */   true,
                               /* nd_parsing   */   false,
                               /* nd_threads   */   0,
                               /* node_actions */   true,
                               /* reversable   */   false,
                               /* semantics    */   true,
                               /* stksize      */   100,
                               /* term_actions */   true,
                               /* init_func    */   &NCSA_init_funcs_[0],
                               /* tact_func    */   &NCSA_tact_funcs_[0],
                               /* nact_func    */   &NCSA_nact_funcs_[0]);

#include "lrstar_main.cpp"
