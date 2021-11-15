/*
 * A function based, ANSI C compliant stack implementation.
*/

#ifndef CT_STACK_H
#define CT_STACK_H

#include <stdlib.h>

#define ct_stack_is_empty(stack) \
    ((stack)->length == 0)

#define ct_stack_length(stack) \
    ((stack)->length)

#define ct_stack_define_node(node_name, node_type) \
    struct node_name {                             \
        node_type value;                           \
        struct node_name *next;                    \
    }                                              \

#define ct_stack_define_stack(stack_name, node_name) \
    struct stack_name {                              \
        unsigned int length;                         \
        struct node_name *top;                       \
    }

#define ct_stack_define_init(stack_name, node_name, identifier)           \
    struct stack_name *identifier##_stack_init() {                        \
        return (struct stack_name*) calloc(1, sizeof(struct stack_name)); \
    }

#define ct_stack_define_free(stack_name, node_name, identifier, free_value) \
    void identifier##_stack_free(struct stack_name *stack) {                \
        struct node_name *node = stack->top;                                \
                                                                            \
        while(node != NULL) {                                               \
            struct node_name *next = node->next;                            \
                                                                            \
            free_value(node->value);                                        \
            free(node);                                                     \
            node = next;                                                    \
        }                                                                   \
    }

#endif
