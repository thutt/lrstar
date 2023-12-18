void
Calc_then_(UNUSED_PARAM(ast_pass_t pass),
           UNUSED_PARAM(parse_direction_t direction),
           UNUSED_PARAM(Calc_parser_t *parser),
           UNUSED_PARAM(Node *v))
{
    if (pass == FIRST_PASS) {
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
