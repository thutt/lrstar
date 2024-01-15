/* This file is created by lrstar.
 *
 *
 *  NOTE: lrstar will never rewrite or delete this file.
 *        It can be safely edited to add user-supplied code.
 */
namespace JSON {
    void
    real_(UNUSED_PARAM(unsigned traversal_number),
          UNUSED_PARAM(parse_direction_t direction),
          UNUSED_PARAM(parser_t *parser),
          UNUSED_PARAM(Node *v))
    {
        if (traversal_number == 1 && direction == TOP_DOWN) {
            json_data *d = new json_data(v->get_token());
            v->set_node_data(d);
        }
    }
};
