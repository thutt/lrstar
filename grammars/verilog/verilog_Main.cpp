#include "lrstar_basic_defs.h"
#include "verilog_LexerTables_typedef.h"
#include "verilog_Parser.h"

void verilog_init_actions(lrstar_parser *parser); /* User-supplied */
void verilog_term_actions(lrstar_parser *parser); /* User-supplied */
static init_func_t verilog_init_funcs_[2] = {
   verilog_init_actions,
   verilog_term_actions
};

int verilog_error(lrstar_parser *parser, int &t);
int verilog_lookup(lrstar_parser *parser, int &t);
// Terminal action function pointers ...
static tact_func_t verilog_tact_funcs_[2] = {
   verilog_error,
   verilog_lookup,
};


lrstar_parser generated_parser(/* grammar      */   "verilog",
                               /* user data    */   NULL,
                               /* actions      */   true,
                               /* debug_parser */   false,
                               /* debug_trace  */   false,
                               /* expecting    */   true,
                               /* insensitive  */   false,
                               /* lookaheads   */   1,
                               /* make_ast     */   false,
                               /* nd_parsing   */   false,
                               /* nd_threads   */   0,
                               /* node_actions */   false,
                               /* reversable   */   false,
                               /* semantics    */   false,
                               /* stksize      */   100,
                               /* term_actions */   true,
                               /* init_func    */   &verilog_init_funcs_[0],
                               /* tact_func    */   &verilog_tact_funcs_[0],
                               /* nact_func    */   NULL);

#include "lrstar_main.cpp"
