void
Calc_target_(Calc_parser_t *parser, Node *v)
{
    Node *n = v;

    if (parser->traversal == FIRST_PASS) {
        switch (parser->direction) {
        case TOP_DOWN:
            break;

        case BOTTOM_UP:
            printf("\t\tLADR %s\n", parser->symbol_name(n->sti));
            break;
        }
    }
}
