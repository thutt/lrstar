/* This file is created by lrstar.
 *
 *
 *  NOTE: lrstar will never rewrite or delete this file.
 *        It can be safely edited to add user-supplied code.
 */
namespace JSON {
    void
    goal_(UNUSED_PARAM(unsigned traversal_number),
          UNUSED_PARAM(parse_direction_t direction),
          UNUSED_PARAM(parser_t *parser),
          UNUSED_PARAM(Node *v))
    {
        Node *p;
        if (traversal_number == 3 && direction == TOP_DOWN) {
            p = v->child;
            while (p != NULL) {
                reinterpret_cast<json_base *>(p->user_data)->print(0);
                p = p->next;
            }
        }
    }
};
