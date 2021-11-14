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

#define ct_linked_define_free(list_name, node_name, identifier, free_value) \
    void identifier##_linked_free(struct list_name *list) { \
        struct node_name *node = list->head;                \
                                                            \
        while(node != NULL) {                               \
            struct node_name *temp = node;                  \
                                                            \
            free_value(node->value);                        \
            node = node->next;                              \
            free(temp);                                     \
        }                                                   \
                                                            \
        free(list);                                         \
    }

#endif
