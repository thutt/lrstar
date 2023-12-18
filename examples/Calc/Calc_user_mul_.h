void
Calc_mul_(UNUSED_PARAM(ast_pass_t pass),
          UNUSED_PARAM(parse_direction_t direction),
          UNUSED_PARAM(Calc_parser_t *parser),
          UNUSED_PARAM(Node *v))
{
    if (pass == FIRST_PASS) {
        switch (direction) {
        case TOP_DOWN:
            break;

        case BOTTOM_UP:
            printf("\t\tMUL\n");
            break;
        }
    }
}
