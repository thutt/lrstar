void
Calc_else2_(Calc_parser_t *parser, Node *v)
{
    if (parser->traversal == FIRST_PASS) {
        switch (parser->direction) {
        case TOP_DOWN:
            printf("\t\tBR endif%d\n"
                   "else%d:\n",
                   parser->stack[parser->stacki - 1].counter,
                   parser->stack[parser->stacki - 1].counter);
            break;

        case BOTTOM_UP:
            break;
        }
    }
}
