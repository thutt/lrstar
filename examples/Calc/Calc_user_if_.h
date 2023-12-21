void
Calc_if_(UNUSED_PARAM(unsigned traversal_number),
         UNUSED_PARAM(parse_direction_t direction),
         UNUSED_PARAM(Calc_parser_t *parser),
         UNUSED_PARAM(Node *v))
{
    if (traversal_number == 1) {
        switch (direction) {
        case TOP_DOWN:
            printf("if%d:\n",
                    parser->stack[parser->stacki].counter);
            break;

        case BOTTOM_UP:
            printf("endif%d:\n",
                    parser->stack[parser->stacki].counter);
            break;
        }
    }
}
