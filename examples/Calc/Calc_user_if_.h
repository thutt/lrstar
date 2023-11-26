void
Calc_if_(Calc_parser_t *parser, Node *v)
{
    if (parser->traversal == FIRST_PASS) {
        switch (parser->direction) {
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
