/*
 * A function-based, ANSI C compliant linked list implementation.
*/

#ifndef CT_LINKED_H
#define CT_LINKED_H

#include <stdlib.h>

#define ct_linked_define_node(node_name, node_type) \
    struct node_name {                              \
        node_type value;                            \
        struct node_name *next;                     \
    }

#define ct_linked_define_list(list_name, node_name) \
    struct list_name {                              \
        unsigned int length;                        \
        struct node_name *head;                     \
        struct node_name *tail;                     \
    }

#define ct_linked_define_init(list_name, identifier)                    \
    struct list_name *identifier##_linked_init() {                      \
        return (struct list_name*) calloc(1, sizeof(struct list_name)); \
    }

#endif
