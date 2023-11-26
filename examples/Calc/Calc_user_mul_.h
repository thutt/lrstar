void
Calc_mul_(UNUSED_PARAM(Calc_parser_t *parser), UNUSED_PARAM(Node *v))
{
    if (parser->traversal == FIRST_PASS) {
        switch (parser->direction) {
        case TOP_DOWN:
            break;

        case BOTTOM_UP:
            printf("\t\tMUL\n");
            break;
        }
    }
}
