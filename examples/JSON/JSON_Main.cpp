#include "lrstar_basic_defs.h"
#include "JSON_LexerTables_typedef.h"
#include "JSON_Parser.h"


const char JSON_grammar_name[] = "JSON";


void JSON_init_actions(UNUSED_PARAM(JSON_parser_t *parser)); /* User-supplied */
void JSON_term_actions(UNUSED_PARAM(JSON_parser_t *parser)); /* User-supplied */
static JSON_parser_t::init_func_t JSON_init_funcs_[2] = {
   JSON_init_actions,
   JSON_term_actions
};

int JSON_error(UNUSED_PARAM(JSON_parser_t *parser), UNUSED_PARAM(int &t));
int JSON_lookup(UNUSED_PARAM(JSON_parser_t *parser), UNUSED_PARAM(int &t));
// Terminal action function pointers ...
static JSON_parser_t::tact_func_t JSON_tact_funcs_[2] = {
   JSON_error,
   JSON_lookup,
};

void JSON_goal(UNUSED_PARAM(unsigned traversal_number),
               UNUSED_PARAM(parse_direction_t direction),
               UNUSED_PARAM(JSON_parser_t *parser),
               UNUSED_PARAM(Node *node));
void JSON_string(UNUSED_PARAM(unsigned traversal_number),
                 UNUSED_PARAM(parse_direction_t direction),
                 UNUSED_PARAM(JSON_parser_t *parser),
                 UNUSED_PARAM(Node *node));
void JSON_integer(UNUSED_PARAM(unsigned traversal_number),
                  UNUSED_PARAM(parse_direction_t direction),
                  UNUSED_PARAM(JSON_parser_t *parser),
                  UNUSED_PARAM(Node *node));
void JSON_real(UNUSED_PARAM(unsigned traversal_number),
               UNUSED_PARAM(parse_direction_t direction),
               UNUSED_PARAM(JSON_parser_t *parser),
               UNUSED_PARAM(Node *node));
void JSON_null(UNUSED_PARAM(unsigned traversal_number),
               UNUSED_PARAM(parse_direction_t direction),
               UNUSED_PARAM(JSON_parser_t *parser),
               UNUSED_PARAM(Node *node));
void JSON_false(UNUSED_PARAM(unsigned traversal_number),
                UNUSED_PARAM(parse_direction_t direction),
                UNUSED_PARAM(JSON_parser_t *parser),
                UNUSED_PARAM(Node *node));
void JSON_true(UNUSED_PARAM(unsigned traversal_number),
               UNUSED_PARAM(parse_direction_t direction),
               UNUSED_PARAM(JSON_parser_t *parser),
               UNUSED_PARAM(Node *node));
void JSON_array(UNUSED_PARAM(unsigned traversal_number),
                UNUSED_PARAM(parse_direction_t direction),
                UNUSED_PARAM(JSON_parser_t *parser),
                UNUSED_PARAM(Node *node));
void JSON_object(UNUSED_PARAM(unsigned traversal_number),
                 UNUSED_PARAM(parse_direction_t direction),
                 UNUSED_PARAM(JSON_parser_t *parser),
                 UNUSED_PARAM(Node *node));
void JSON_member(UNUSED_PARAM(unsigned traversal_number),
                 UNUSED_PARAM(parse_direction_t direction),
                 UNUSED_PARAM(JSON_parser_t *parser),
                 UNUSED_PARAM(Node *node));
// Node action function pointers ...
static JSON_parser_t::nact_func_t JSON_nact_funcs_[10] = {
   JSON_goal,
   JSON_string,
   JSON_integer,
   JSON_real,
   JSON_null,
   JSON_false,
   JSON_true,
   JSON_array,
   JSON_object,
   JSON_member,
};

JSON_parser_t *
JSON_new_parser(const char *input_path,
                char       *input_text,
                unsigned    max_symbols)
{
   return new JSON_parser_t(/* input path   */   input_path,
                            /* input text   */   input_text,
                            /* max symbols  */   max_symbols,
                            /* init_func    */   &JSON_init_funcs_[0],
                            /* tact_func    */   &JSON_tact_funcs_[0],
                            /* nact_func    */   &JSON_nact_funcs_[0]);
}

