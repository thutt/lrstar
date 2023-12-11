#include "lrstar_basic_defs.h"
#include "LRK_LexerTables_typedef.h"
#include "LRK_Parser.h"


const char LRK_grammar_name[] = "LRK";


void LRK_init_actions(UNUSED_PARAM(LRK_parser_t *parser)); /* User-supplied */
void LRK_term_actions(UNUSED_PARAM(LRK_parser_t *parser)); /* User-supplied */
static LRK_parser_t::init_func_t LRK_init_funcs_[2] = {
   LRK_init_actions,
   LRK_term_actions
};

int LRK_error(UNUSED_PARAM(LRK_parser_t *parser), UNUSED_PARAM(int &t));
int LRK_lookup(UNUSED_PARAM(LRK_parser_t *parser), UNUSED_PARAM(int &t));
// Terminal action function pointers ...
static LRK_parser_t::tact_func_t LRK_tact_funcs_[2] = {
   LRK_error,
   LRK_lookup,
};

// Node action function pointers ...
static LRK_parser_t::nact_func_t LRK_nact_funcs_[8] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
};

LRK_parser_t *
LRK_new_parser(const char *input_path,
               char       *input_text,
               unsigned    max_symbols)
{
   return new LRK_parser_t(/* input path   */   input_path,
                           /* input text   */   input_text,
                           /* max symbols  */   max_symbols,
                           /* init_func    */   &LRK_init_funcs_[0],
                           /* tact_func    */   &LRK_tact_funcs_[0],
                           /* nact_func    */   &LRK_nact_funcs_[0]);
}

