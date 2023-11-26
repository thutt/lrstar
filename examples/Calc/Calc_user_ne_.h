void
Calc_ne_(Calc_parser_t *parser, Node *v)
{
    if (parser->traversal == FIRST_PASS) {
        switch (parser->direction) {
        case TOP_DOWN:
            break;

        case BOTTOM_UP:
            printf("\t\tNE\n");
            break;
        }
    }
}
