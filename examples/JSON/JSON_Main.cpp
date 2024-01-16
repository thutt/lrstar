#include "lrstar_basic_defs.h"
#include "JSON_LexerTables_typedef.h"
#include "JSON_Parser.h"

namespace JSON {

const char grammar_name[] = "JSON";


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

void goal_(UNUSED_PARAM(unsigned traversal_number),
                UNUSED_PARAM(parse_direction_t direction),
                UNUSED_PARAM(parser_t *parser),
                UNUSED_PARAM(Node *node));
void string_(UNUSED_PARAM(unsigned traversal_number),
                  UNUSED_PARAM(parse_direction_t direction),
                  UNUSED_PARAM(parser_t *parser),
                  UNUSED_PARAM(Node *node));
void integer_(UNUSED_PARAM(unsigned traversal_number),
                   UNUSED_PARAM(parse_direction_t direction),
                   UNUSED_PARAM(parser_t *parser),
                   UNUSED_PARAM(Node *node));
void real_(UNUSED_PARAM(unsigned traversal_number),
                UNUSED_PARAM(parse_direction_t direction),
                UNUSED_PARAM(parser_t *parser),
                UNUSED_PARAM(Node *node));
void null_(UNUSED_PARAM(unsigned traversal_number),
                UNUSED_PARAM(parse_direction_t direction),
                UNUSED_PARAM(parser_t *parser),
                UNUSED_PARAM(Node *node));
void false_(UNUSED_PARAM(unsigned traversal_number),
                 UNUSED_PARAM(parse_direction_t direction),
                 UNUSED_PARAM(parser_t *parser),
                 UNUSED_PARAM(Node *node));
void true_(UNUSED_PARAM(unsigned traversal_number),
                UNUSED_PARAM(parse_direction_t direction),
                UNUSED_PARAM(parser_t *parser),
                UNUSED_PARAM(Node *node));
void array_(UNUSED_PARAM(unsigned traversal_number),
                 UNUSED_PARAM(parse_direction_t direction),
                 UNUSED_PARAM(parser_t *parser),
                 UNUSED_PARAM(Node *node));
void object_(UNUSED_PARAM(unsigned traversal_number),
                  UNUSED_PARAM(parse_direction_t direction),
                  UNUSED_PARAM(parser_t *parser),
                  UNUSED_PARAM(Node *node));
void member_(UNUSED_PARAM(unsigned traversal_number),
                  UNUSED_PARAM(parse_direction_t direction),
                  UNUSED_PARAM(parser_t *parser),
                  UNUSED_PARAM(Node *node));
// Node action function pointers.
static parser_t::nact_func_t nact_funcs_[10] = {
   goal_,
   string_,
   integer_,
   real_,
   null_,
   false_,
   true_,
   array_,
   object_,
   member_,
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


};   /* namespace JSON */
