/* This file is created by lrstar.
 *
 * This file can be used to add any code that must be
 * available to all the user-defined functions.  For example,
 * if string comparisons are needed, '#include <string.h>'.
 *
 *
 *  NOTE: lrstar will never rewrite or delete this file.
 *        It can be safely edited to add user-supplied code.
 */
#if !defined(__JSON_USER_HEADER__)

struct json_base : NodeData {
    json_base *next;

    json_base() : next(0) { }
    virtual void print(unsigned indent) { printf("base node %d", indent); }
    unsigned expand(unsigned indent)
    {
        if (static_cast<int>(indent) < 0) {
            return 0;
        } else {
            return indent * 2;
        }
    }
};


struct json_array : json_base {
    json_base *elements;

    json_array() : elements(0) { }

    virtual void
    print(unsigned indent)
    {
        json_base *e = elements;
        printf("[");
        while (e != NULL) {
            printf("\n%*s", expand(indent + 1), "");
            e->print(indent + 1);
            e = e->next;
            if (e != 0) {
                printf(", ");
            }
        }
        printf("\n%*s]", expand(indent), "");
    }
};


struct json_object : json_base { // Dictionary
    json_base *members;

    json_object() : members(0) { }

    virtual void
    print(unsigned indent)
    {
        json_base *m = members;
        printf("{");
        while (m != NULL) {
            printf("\n%*s", expand(indent + 1), "");
            m->print(indent + 1);
            m = m->next;
            if (m != 0) {
                printf(",");
            }
        }
        printf("\n%*s}", expand(indent), "");
    }
};


struct json_member : json_base {
    json_base *key;
    json_base *value;

    json_member(json_base *key_, json_base *value_) : json_base(), key(key_), value(value_)
    {
    }

    virtual void
    print(unsigned indent)
    {
        key->print(indent);
        printf(" : ");
        value->print(indent);
    }

};


struct json_boolean : json_base {
    bool value;

    json_boolean(bool value_) : json_base(), value(value_) { }

    virtual void
    print(unsigned indent)
    {
        printf("%*s%s", expand(indent), "", value ? "true" : "false");
    }
};


struct json_null : json_base {
    // No need for data.

    virtual void
    print(unsigned indent)
    {
        printf("%*snull", expand(indent), "");
    }
};


struct json_data : json_base {
    char *data;                 // ASCIIZ token

    json_data(char *data_) : json_base(), data(data_) { }

    virtual void
    print(UNUSED_PARAM(unsigned indent))
    {
        printf("%s", data);
    }
};
#endif
