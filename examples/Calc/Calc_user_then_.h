void
Calc_then_(UNUSED_PARAM(unsigned traversal_number),
           UNUSED_PARAM(parse_direction_t direction),
           UNUSED_PARAM(Calc_parser_t *parser),
           UNUSED_PARAM(Node *v))
{
    if (traversal_number == 1) {
        switch (direction) {
        case TOP_DOWN:
            printf("\t\tBR NZ endif%d\n"
                   "then%d:\n",
                   parser->stack[parser->stacki - 1].counter,
                   parser->stack[parser->stacki - 1].counter);
            break;

        case BOTTOM_UP:
            break;
        }
    }
}
