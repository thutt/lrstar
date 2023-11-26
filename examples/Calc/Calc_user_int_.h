void
Calc_int_(Calc_parser_t *parser, Node *v)
{
    Node *n = v;

    if (parser->traversal == FIRST_PASS) {
        switch (parser->direction) {
        case TOP_DOWN:
            break;

        case BOTTOM_UP:
            printf("\t\tLOAD %s\n", parser->symbol_name(n->sti));
            break;
        }
    }
}
