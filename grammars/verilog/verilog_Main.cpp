#include "lrstar_basic_defs.h"
#include "verilog_LexerTables_typedef.h"
#include "verilog_Parser.h"


const char verilog_grammar_name[] = "verilog";


void verilog_init_actions(UNUSED_PARAM(verilog_parser_t *parser)); /* User-supplied */
void verilog_term_actions(UNUSED_PARAM(verilog_parser_t *parser)); /* User-supplied */
static verilog_parser_t::init_func_t verilog_init_funcs_[2] = {
   verilog_init_actions,
   verilog_term_actions
};

int verilog_error(UNUSED_PARAM(verilog_parser_t *parser), UNUSED_PARAM(int &t));
int verilog_lookup(UNUSED_PARAM(verilog_parser_t *parser), UNUSED_PARAM(int &t));
// Terminal action function pointers ...
static verilog_parser_t::tact_func_t verilog_tact_funcs_[2] = {
   verilog_error,
   verilog_lookup,
};

verilog_parser_t *
verilog_new_parser(const char *input_path,
                   char       *input_text,
                   unsigned    max_symbols)
{
   return new verilog_parser_t(/* input path   */   input_path,
                               /* input text   */   input_text,
                               /* max symbols  */   max_symbols,
                               /* init_func    */   &verilog_init_funcs_[0],
                               /* tact_func    */   &verilog_tact_funcs_[0],
                               /* nact_func    */   0);
}

