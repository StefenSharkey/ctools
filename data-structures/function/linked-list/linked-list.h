/*
 * A function-based, ANSI C compliant linked list implementation.
*/

#ifndef CT_LINKED_H
#define CT_LINKED_H

#include <stdio.h>
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

#define ct_linked_define_append(list_name, node_name, node_type, identifier)                  \
    struct node_name *identifier##_linked_append(struct list_name *list, node_type value) {   \
        struct node_name *new_node = (struct node_name*) calloc(1, sizeof(struct node_name)); \
        new_node->value = value;                                                              \
                                                                                              \
        if(list->head == NULL) {                                                              \
            list->head = new_node;                                                            \
            list->tail = new_node;                                                            \
        } else {                                                                              \
            list->tail->next = new_node;                                                      \
            list->tail = list->tail->next;                                                    \
        }                                                                                     \
                                                                                              \
        return new_node;                                                                      \
    }


#define ct_linked_define_insert(list_name, node_name, node_type, identifier)                                                                                                             \
    struct node_name *identifier##_linked_insert(struct list_name *list, struct node_name *node, node_type value) {                                                                      \
        struct node_name *new_node = NULL;                                                                                                                                               \
        struct node_name *previous = list->head;                                                                                                                                         \
                                                                                                                                                                                         \
        while(previous != NULL && previous->next != node && previous != list->head) {                                                                                                    \
            previous = previous->next;                                                                                                                                                   \
        }                                                                                                                                                                                \
                                                                                                                                                                                         \
        if(previous == NULL) {                                                                                                                                                           \
            fprintf(stderr, #identifier "_linked_insert: Attempt to insert value into node that is not in the provided linked list (list: %p, node: %p)\n", (void*) list, (void*) node); \
            exit(1);                                                                                                                                                                     \
        }                                                                                                                                                                                \
                                                                                                                                                                                         \
        new_node = (struct node_name*) calloc(1, sizeof(struct node_name));                                                                                                              \
        new_node->value = value;                                                                                                                                                         \
        new_node->next = node;                                                                                                                                                           \
        previous->next = new_node;                                                                                                                                                       \
                                                                                                                                                                                         \
        if(previous == list->head) {                                                                                                                                                     \
            list->head = new_node;                                                                                                                                                       \
        }                                                                                                                                                                                \
                                                                                                                                                                                         \
        return new_node;                                                                                                                                                                 \
    }

#endif
