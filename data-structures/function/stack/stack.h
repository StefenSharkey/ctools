/*
 * A function based, ANSI C compliant stack implementation.
*/

#ifndef CT_STACK_H
#define CT_STACK_H

#include <stdlib.h>

#define ct_stack_define_node(node_name, node_type) \
    struct node_name {                             \
        node_type value;                           \
        node_name *next;                           \
    }                                              \

#define ct_stack_define_stack(stack_name, node_name) \
    struct stack_name {                              \
        unsigned int length;                         \
        node_name *top;                              \
    }

#define ct_stack_define_init(stack_name, node_name, identifier)           \
    struct stack_name *identifier##_stack_init() {                        \
        return (struct stack_name*) calloc(1, sizeof(struct stack_name)); \
    }

#endif
