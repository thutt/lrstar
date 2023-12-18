void
Calc_program_(UNUSED_PARAM(ast_pass_t pass),
              UNUSED_PARAM(parse_direction_t direction),
              UNUSED_PARAM(Calc_parser_t *parser),
              UNUSED_PARAM(Node *v))
{
    Node *n = v;

    if (pass == FIRST_PASS) {
        switch (direction) {
        case TOP_DOWN:
            printf("\t\tPROGRAM %s\n",
                    parser->symbol_name(n->sti));
            break;

        case BOTTOM_UP:
            printf("\t\tEND PROGRAM %s\n",
                    parser->symbol_name(n->sti));
            break;
        }
    }
}
