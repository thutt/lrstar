/* This file is created by lrstar.
 *
 *
 *  NOTE: lrstar will never rewrite or delete this file.
 *        It can be safely edited to add user-supplied code.
 */

namespace JSON {
    void
    array_(UNUSED_PARAM(unsigned traversal_number),
           UNUSED_PARAM(parse_direction_t direction),
           UNUSED_PARAM(parser_t *parser),
           UNUSED_PARAM(Node *v))
    {
        if (traversal_number == 2 && direction == BOTTOM_UP) {
            Node        *np;
            json_array  *array    = new json_array();
            json_base  **head = &array->elements;

            v->set_node_data(array);

            np   = v->child;
            while (np != 0) {
                assert(np->user_data != NULL);
                *head = reinterpret_cast<json_base *>(np->user_data);
                head  = &(*head)->next;
                np    = np->next;
            }
        }
    }
};
