void
Calc_target_(UNUSED_PARAM(Calc_parser_t *parser), UNUSED_PARAM(Node *v))
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
