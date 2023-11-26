void
Calc_add_(Calc_parser_t *parser, Node *v)
{
    Node *n = v;

    if (parser->traversal == FIRST_PASS) {
        switch (parser->direction) {
        case TOP_DOWN:
            break;

        case BOTTOM_UP:
            printf("\t\tADD\n");
            break;
        }
    }
}
