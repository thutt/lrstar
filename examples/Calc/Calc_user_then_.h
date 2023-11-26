void
Calc_then_(Calc_parser_t *parser, Node *v)
{
    Node *n = v;

    if (parser->traversal == FIRST_PASS) {
        switch (parser->direction) {
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
