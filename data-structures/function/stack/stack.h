/*
 * A function based, ANSI C compliant stack implementation.
*/

#ifndef CT_STACK_H
#define CT_STACK_H

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

#endif
