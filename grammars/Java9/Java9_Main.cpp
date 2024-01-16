#include "lrstar_basic_defs.h"
#include "Java9_LexerTables_typedef.h"
#include "Java9_Parser.h"

namespace Java9 {

const char grammar_name[] = "Java9";


void init_actions(UNUSED_PARAM(parser_t *parser)); /* User-supplied */
void term_actions(UNUSED_PARAM(parser_t *parser)); /* User-supplied */
static parser_t::init_func_t init_funcs_[2] = {
   init_actions,
   term_actions
};

int error(UNUSED_PARAM(parser_t *parser), UNUSED_PARAM(int &t));
int lookup(UNUSED_PARAM(parser_t *parser), UNUSED_PARAM(int &t));
// Terminal action function pointers.
static parser_t::tact_func_t tact_funcs_[2] = {
   error,
   lookup,
};

// Node action function pointers.
static parser_t::nact_func_t nact_funcs_[1] = {
   0,
};

parser_t *
new_parser(const char *input_path,
           char       *input_text,
           unsigned    max_symbols)
{
   return new parser_t(/* input path   */   input_path,
                       /* input text   */   input_text,
                       /* max symbols  */   max_symbols,
                       /* init_func    */   &init_funcs_[0],
                       /* tact_func    */   &tact_funcs_[0],
                       /* nact_func    */   &nact_funcs_[0]);
}


};   /* namespace Java9 */
