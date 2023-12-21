void
Calc_goal_(UNUSED_PARAM(unsigned traversal_number),
           UNUSED_PARAM(parse_direction_t direction),
           UNUSED_PARAM(Calc_parser_t *parser),
           UNUSED_PARAM(Node *v))
{
    if (traversal_number == 1) {
        switch (direction) {
        case TOP_DOWN:
            printf("\t\tSTART\n");
            break;

        case BOTTOM_UP:
            printf("\t\tEOF\n");
            break;
        }
    }
}
