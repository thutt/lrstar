#if !defined(__LRSTAR_H__)
#define __LRSTAR_H__

class Node;
class lrstar_parser;
typedef void (*init_func_t)(lrstar_parser *parser);
typedef int  (*tact_func_t)(lrstar_parser *parser, int &t);
typedef int  (*nact_func_t)(lrstar_parser *parser, Node *t);

#endif
