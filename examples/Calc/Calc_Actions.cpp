
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "Calc_LexerTables_typedef.h"
#include "Calc_Actions.h"
#include "lrstar_main.h"


void    Calc_init_actions(Calc_parser_t *parser)
{
    /* Initialization code goes here */
}

void    Calc_term_actions(Calc_parser_t *parser)
{
    /* Termination code goes here */
}


int Calc_error(Calc_parser_t *parser, int &t)
{
    if (parser->lt.token.end == parser->lt.token.start) // Illegal character?
    {
        parser->lt.token.end++;
    }
    return 0;
}

int Calc_lookup(Calc_parser_t *parser, int &t) // Lookup in symbol table.
{
    int sti;
    if (parser->opt_nd_parsing &&
        parser->lt.lookahead.start != 0) // In lookahead mode?
    {
        sti = parser->add_symbol(t, parser->lt.lookahead.start, parser->lt.lookahead.end);
    } else {                        // Regular mode of parsing.
        sti = parser->add_symbol(t, parser->lt.token.start, parser->lt.token.end);
    }
    if (parser->opt_semantics) {
       t = parser->symbol[sti].term; // Redefine terminal number?
    }
    return sti;                 // Return symbol-table index.
}


int Calc_goal_ (Calc_parser_t *parser, Node *v)
{
    Node* n = (Node*)v;
    if (parser->traversal == FIRST_PASS)
        switch (parser->direction)
        {
        case TOP_DOWN:
            fprintf (output, "\t\tSTART\n");
            break;
        case BOTTOM_UP:
            fprintf (output, "\t\tEOF\n");
            break;
        }
    return 1; // OK
}

int Calc_program_ (Calc_parser_t *parser, Node *v)
{
    Node* n = (Node*)v;
    if (parser->traversal == FIRST_PASS)
        switch (parser->direction)
        {
        case TOP_DOWN:
            fprintf (output, "\t\tPROGRAM %s\n", parser->symbol_name (n->sti));
            break;
        case BOTTOM_UP:
            fprintf (output, "\t\tEND PROGRAM %s\n", parser->symbol_name (n->sti));
            break;
        }
    return 1; // OK
}

int Calc_ident_ (Calc_parser_t *parser, Node *v)
{
    Node* n = (Node*)v;
    if (parser->traversal == FIRST_PASS)
        switch (parser->direction)
        {
        case TOP_DOWN:
            break;
        case BOTTOM_UP:
            fprintf (output, "\t\tLOAD %s\n", parser->symbol_name (n->sti));
            break;
        }
    return 1; // OK
}

int Calc_int_ (Calc_parser_t *parser, Node *v)
{
    Node* n = (Node*)v;
    if (parser->traversal == FIRST_PASS)
        switch (parser->direction)
        {
        case TOP_DOWN:
            break;
        case BOTTOM_UP:
            fprintf (output, "\t\tLOAD %s\n", parser->symbol_name (n->sti));
            break;
        }
    return 1; // OK
}

int Calc_add_ (Calc_parser_t *parser, Node *v)
{
    Node* n = (Node*)v;
    if (parser->traversal == FIRST_PASS)
        switch (parser->direction)
        {
        case TOP_DOWN:
            break;
        case BOTTOM_UP:
            fprintf (output, "\t\tADD\n");
            break;
        }
    return 1; // OK
}

int Calc_sub_ (Calc_parser_t *parser, Node *v)
{
    Node* n = (Node*)v;
    if (parser->traversal == FIRST_PASS)
        switch (parser->direction)
        {
        case TOP_DOWN:
            break;
        case BOTTOM_UP:
            fprintf (output, "\t\tSUB\n");
            break;
        }
    return 1; // OK
}

int Calc_mul_ (Calc_parser_t *parser, Node *v)
{
    Node* n = (Node*)v;
    if (parser->traversal == FIRST_PASS)
        switch (parser->direction)
        {
        case TOP_DOWN:
            break;
        case BOTTOM_UP:
            fprintf (output, "\t\tMUL\n");
            break;
        }
    return 1; // OK
}

int Calc_div_ (Calc_parser_t *parser, Node *v)
{
    Node* n = (Node*)v;
    if (parser->traversal == FIRST_PASS)
        switch (parser->direction)
        {
        case TOP_DOWN:
            break;
        case BOTTOM_UP:
            fprintf (output, "\t\tDIV\n");
            break;
        }
    return 1; // OK
}

int Calc_pwr_ (Calc_parser_t *parser, Node *v)
{
    Node* n = (Node*)v;
    if (parser->traversal == FIRST_PASS)
        switch (parser->direction)
        {
        case TOP_DOWN:
            break;
        case BOTTOM_UP:
            fprintf (output, "\t\tPWR\n");
            break;
        }
    return 1; // OK
}

int Calc_if_ (Calc_parser_t *parser, Node *v)
{
    Node* n = (Node*)v;
    if (parser->traversal == FIRST_PASS)
        switch (parser->direction)
        {
        case TOP_DOWN:
            fprintf (output, "if%d:\n", parser->stack[parser->stacki].counter);
            break;
        case BOTTOM_UP:
            fprintf (output, "endif%d:\n", parser->stack[parser->stacki].counter);
            break;
        }
    return 1; // OK
}

int Calc_then_ (Calc_parser_t *parser, Node *v)
{
    Node* n = (Node*)v;
    if (parser->traversal == FIRST_PASS)
        switch (parser->direction)
        {
        case TOP_DOWN:
            fprintf (output, "\t\tBR NZ endif%d\n", parser->stack[parser->stacki-1].counter);
            fprintf (output, "then%d:\n",           parser->stack[parser->stacki-1].counter);
            break;
        case BOTTOM_UP:
            break;
        }
    return 1; // OK
}

int Calc_then2_ (Calc_parser_t *parser, Node *v)
{
    Node* n = (Node*)v;
    if (parser->traversal == FIRST_PASS)
        switch (parser->direction)
        {
        case TOP_DOWN:
            fprintf (output, "\t\tBR NZ else%d\n", parser->stack[parser->stacki-1].counter);
            fprintf (output, "then%d:\n",          parser->stack[parser->stacki-1].counter);
            break;
        case BOTTOM_UP:
            break;
        }
    return 1; // OK
}

int Calc_else2_ (Calc_parser_t *parser, Node *v)
{
    Node* n = (Node*)v;
    if (parser->traversal == FIRST_PASS)
        switch (parser->direction)
        {
        case TOP_DOWN:
            fprintf (output, "\t\tBR endif%d\n", parser->stack[parser->stacki-1].counter);
            fprintf (output, "else%d:\n",        parser->stack[parser->stacki-1].counter);
            break;
        case BOTTOM_UP:
            break;
        }
    return 1; // OK
}

int Calc_eq_ (Calc_parser_t *parser, Node *v)
{
    Node* n = (Node*)v;
    if (parser->traversal == FIRST_PASS)
        switch (parser->direction)
        {
        case TOP_DOWN:
            break;
        case BOTTOM_UP:
            fprintf (output, "\t\tEQ\n");
            break;
        }
    return 1; // OK
}

int Calc_ne_ (Calc_parser_t *parser, Node *v)
{
    Node* n = (Node*)v;
    if (parser->traversal == FIRST_PASS)
        switch (parser->direction)
        {
        case TOP_DOWN:
            break;
        case BOTTOM_UP:
            fprintf (output, "\t\tNE\n");
            break;
        }
    return 1; // OK
}

int Calc_store_ (Calc_parser_t *parser, Node *v)
{
    Node* n = (Node*)v;
    if (parser->traversal == FIRST_PASS)
        switch (parser->direction)
        {
        case TOP_DOWN:
            break;
        case BOTTOM_UP:
            fprintf (output, "\t\tSTORE\n");
            break;
        }
    return 1; // OK
}

int Calc_target_ (Calc_parser_t *parser, Node *v)
{
    Node* n = (Node*)v;
    if (parser->traversal == FIRST_PASS)
        switch (parser->direction)
        {
        case TOP_DOWN:
            break;
        case BOTTOM_UP:
            fprintf (output, "\t\tLADR %s\n", parser->symbol_name (n->sti));
            break;
        }
    return 1; // OK
}

/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
