/* This file is created by lrstar.
 *
 *
 *  NOTE: lrstar will never rewrite or delete this file.
 *        It can be safely edited to add user-supplied code.
 */

void
JSON_member(UNUSED_PARAM(unsigned traversal_number),
            UNUSED_PARAM(parse_direction_t direction),
            UNUSED_PARAM(JSON_parser_t *parser),
            UNUSED_PARAM(Node *v))
{
    if (traversal_number == 2 && direction == BOTTOM_UP) {
        json_data   *key   = reinterpret_cast<json_data *>(v->child->user_data);
        json_data   *value = reinterpret_cast<json_data *>(v->child->next->user_data);
        json_member *d     = new json_member(key, value);

        assert(key != 0);
        assert(value != 0);
        v->set_node_data(d);
    }
}
