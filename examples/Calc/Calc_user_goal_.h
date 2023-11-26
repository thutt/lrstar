void
Calc_goal_(UNUSED_PARAM(Calc_parser_t *parser), UNUSED_PARAM(Node *v))
{
    if (parser->traversal == FIRST_PASS) {
        switch (parser->direction) {
        case TOP_DOWN:
            printf("\t\tSTART\n");
            break;

        case BOTTOM_UP:
            printf("\t\tEOF\n");
            break;
        }
    }
}
