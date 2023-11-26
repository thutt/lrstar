void
Calc_goal_(Calc_parser_t *parser, Node *v)
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
