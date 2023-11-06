
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "lrstar_basic_defs.h"
#include "Calc_Actions.h"
#include "lrstar_main.h"

///////////////////////////////////////////////////////////////////////////////

#ifdef ACTIONS

void    lrstar_parser_actions::init_actions ()
{
    /* Initialization code goes here */
}

void    lrstar_parser_actions::term_actions ()
{
    /* Termination code goes here */
}

#endif

///////////////////////////////////////////////////////////////////////////////

#ifdef TERM_ACTIONS

int   lrstar_term_actions::error (int& t)
{
    if (token.end == token.start) // Illegal character?
    {
        token.end++;
    }
    return 0;
}

int   lrstar_term_actions::lookup (int& t)                             // Lookup in symbol table.
{
    int sti;
#ifdef ND_PARSING
    if (lookahead.start > 0)                                        // In lookahead mode?
    {
        sti = add_symbol (t, lookahead.start, lookahead.end);
    }
    else                                                                                            // Regular mode of parsing.
#endif
    {
        sti = add_symbol (t, token.start, token.end);
    }
#ifdef SEMANTICS
    t = symbol[sti].term;                                           //      Redefine terminal number?
#endif
    return sti;                                                                             // Return symbol-table index.
}

#endif

///////////////////////////////////////////////////////////////////////////////

#ifdef NODE_ACTIONS

int     lrstar_node_actions::goal_ (void* v)
{
    Node* n = (Node*)v;
    if (traversal == FIRST_PASS)
        switch (direction)
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

int     lrstar_node_actions::program_ (void* v)
{
    Node* n = (Node*)v;
    if (traversal == FIRST_PASS)
        switch (direction)
        {
        case TOP_DOWN:
            fprintf (output, "\t\tPROGRAM %s\n", symbol_name (n->sti));
            break;
        case BOTTOM_UP:
            fprintf (output, "\t\tEND PROGRAM %s\n", symbol_name (n->sti));
            break;
        }
    return 1; // OK
}

int     lrstar_node_actions::ident_ (void* v)
{
    Node* n = (Node*)v;
    if (traversal == FIRST_PASS)
        switch (direction)
        {
        case TOP_DOWN:
            break;
        case BOTTOM_UP:
            fprintf (output, "\t\tLOAD %s\n", symbol_name (n->sti));
            break;
        }
    return 1; // OK
}

int     lrstar_node_actions::int_ (void* v)
{
    Node* n = (Node*)v;
    if (traversal == FIRST_PASS)
        switch (direction)
        {
        case TOP_DOWN:
            break;
        case BOTTOM_UP:
            fprintf (output, "\t\tLOAD %s\n", symbol_name (n->sti));
            break;
        }
    return 1; // OK
}

int     lrstar_node_actions::add_ (void* v)
{
    Node* n = (Node*)v;
    if (traversal == FIRST_PASS)
        switch (direction)
        {
        case TOP_DOWN:
            break;
        case BOTTOM_UP:
            fprintf (output, "\t\tADD\n");
            break;
        }
    return 1; // OK
}

int     lrstar_node_actions::sub_ (void* v)
{
    Node* n = (Node*)v;
    if (traversal == FIRST_PASS)
        switch (direction)
        {
        case TOP_DOWN:
            break;
        case BOTTOM_UP:
            fprintf (output, "\t\tSUB\n");
            break;
        }
    return 1; // OK
}

int     lrstar_node_actions::mul_ (void* v)
{
    Node* n = (Node*)v;
    if (traversal == FIRST_PASS)
        switch (direction)
        {
        case TOP_DOWN:
            break;
        case BOTTOM_UP:
            fprintf (output, "\t\tMUL\n");
            break;
        }
    return 1; // OK
}

int     lrstar_node_actions::div_ (void* v)
{
    Node* n = (Node*)v;
    if (traversal == FIRST_PASS)
        switch (direction)
        {
        case TOP_DOWN:
            break;
        case BOTTOM_UP:
            fprintf (output, "\t\tDIV\n");
            break;
        }
    return 1; // OK
}

int     lrstar_node_actions::pwr_ (void* v)
{
    Node* n = (Node*)v;
    if (traversal == FIRST_PASS)
        switch (direction)
        {
        case TOP_DOWN:
            break;
        case BOTTOM_UP:
            fprintf (output, "\t\tPWR\n");
            break;
        }
    return 1; // OK
}

int     lrstar_node_actions::if_ (void* v)
{
    Node* n = (Node*)v;
    if (traversal == FIRST_PASS)
        switch (direction)
        {
        case TOP_DOWN:
            fprintf (output, "if%d:\n", stack[stacki].counter);
            break;
        case BOTTOM_UP:
            fprintf (output, "endif%d:\n", stack[stacki].counter);
            break;
        }
    return 1; // OK
}

int     lrstar_node_actions::then_ (void* v)
{
    Node* n = (Node*)v;
    if (traversal == FIRST_PASS)
        switch (direction)
        {
        case TOP_DOWN:
            fprintf (output, "\t\tBR NZ endif%d\n", stack[stacki-1].counter);
            fprintf (output, "then%d:\n",           stack[stacki-1].counter);
            break;
        case BOTTOM_UP:
            break;
        }
    return 1; // OK
}

int     lrstar_node_actions::then2_ (void* v)
{
    Node* n = (Node*)v;
    if (traversal == FIRST_PASS)
        switch (direction)
        {
        case TOP_DOWN:
            fprintf (output, "\t\tBR NZ else%d\n", stack[stacki-1].counter);
            fprintf (output, "then%d:\n",          stack[stacki-1].counter);
            break;
        case BOTTOM_UP:
            break;
        }
    return 1; // OK
}

int     lrstar_node_actions::else2_ (void* v)
{
    Node* n = (Node*)v;
    if (traversal == FIRST_PASS)
        switch (direction)
        {
        case TOP_DOWN:
            fprintf (output, "\t\tBR endif%d\n", stack[stacki-1].counter);
            fprintf (output, "else%d:\n",        stack[stacki-1].counter);
            break;
        case BOTTOM_UP:
            break;
        }
    return 1; // OK
}

int     lrstar_node_actions::eq_ (void* v)
{
    Node* n = (Node*)v;
    if (traversal == FIRST_PASS)
        switch (direction)
        {
        case TOP_DOWN:
            break;
        case BOTTOM_UP:
            fprintf (output, "\t\tEQ\n");
            break;
        }
    return 1; // OK
}

int     lrstar_node_actions::ne_ (void* v)
{
    Node* n = (Node*)v;
    if (traversal == FIRST_PASS)
        switch (direction)
        {
        case TOP_DOWN:
            break;
        case BOTTOM_UP:
            fprintf (output, "\t\tNE\n");
            break;
        }
    return 1; // OK
}

int     lrstar_node_actions::store_ (void* v)
{
    Node* n = (Node*)v;
    if (traversal == FIRST_PASS)
        switch (direction)
        {
        case TOP_DOWN:
            break;
        case BOTTOM_UP:
            fprintf (output, "\t\tSTORE\n");
            break;
        }
    return 1; // OK
}

int     lrstar_node_actions::target_ (void* v)
{
    Node* n = (Node*)v;
    if (traversal == FIRST_PASS)
        switch (direction)
        {
        case TOP_DOWN:
            break;
        case BOTTOM_UP:
            fprintf (output, "\t\tLADR %s\n", symbol_name (n->sti));
            break;
        }
    return 1; // OK
}

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

/* Local Variables:      */
/* mode: c               */
/* c-basic-offset: 3     */
/* tab-width: 3          */
/* indent-tabs-mode: nil */
/* End:                  */
