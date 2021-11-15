/*
 * A function based, ANSI C compliant stack implementation.
*/

#ifndef CT_STACK_H
#define CT_STACK_H

#include <stdio.h>
#include <stdlib.h>

#define ct_stack_is_empty(stack) \
    ((stack)->length == 0)

#define ct_stack_length(stack) \
    ((stack)->length)

#define ct_stack_peek(stack) \
    ((stack)->top)

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

#define ct_stack_define_push(stack_name, node_name, value_type, identifier)                   \
    struct stack_name *identifier##_stack_push(struct stack_name *stack, value_type value) {  \
        struct node_name *new_node = (struct node_name*) calloc(1, sizeof(struct node_name)); \
                                                                                              \
        stack->length++;                                                                      \
        new_node->value = value;                                                              \
                                                                                              \
        if(stack->top == NULL) {                                                              \
            stack->top = new_node;                                                            \
        } else {                                                                              \
            new_node->next = stack->top;                                                      \
            stack->top = new_node;                                                            \
        }                                                                                     \
                                                                                              \
        return stack;                                                                         \
    }

#define ct_stack_define_pop(stack_name, node_name, value_type, identifier)                                           \
    value_type identifier##_stack_pop(struct stack_name *stack) {                                                    \
        value_type temp = {0};                                                                                       \
        struct node_name *next = NULL;                                                                               \
                                                                                                                     \
        if(stack->top == NULL) {                                                                                     \
            fprintf(stderr, #identifier "_stack_pop: attempt to pop from empty stack (stack: %p)\n", (void*) stack); \
            exit(EXIT_FAILURE);                                                                                      \
        }                                                                                                            \
                                                                                                                     \
        temp = stack->top->value;                                                                                    \
        next = stack->top->next;                                                                                     \
        free(stack->top);                                                                                            \
        stack->top = next;                                                                                           \
        stack->length--;                                                                                             \
                                                                                                                     \
        if(stack->length == 0) {                                                                                     \
            stack->top = NULL;                                                                                       \
        }                                                                                                            \
                                                                                                                     \
        return temp;                                                                                                 \
    }

#endif
