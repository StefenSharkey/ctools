/*
 * A function-based, ANSI C compliant queue implementation.
*/

#ifndef CT_QUEUE_H
#define CT_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define ct_queue_define_node(node_name, node_type) \
    struct node_name {                             \
        node_type value;                           \
        struct node_name *next;                    \
    }

#define ct_queue_define_queue(queue_name, node_name) \
    struct queue_name {                              \
        unsigned int length;                         \
        struct node_name *front;                     \
        struct node_name *back;                      \
    }

#define ct_queue_define_init(queue_name, node_name, identifier)           \
    struct queue_name *identifier##_queue_init() {                        \
        return (struct queue_name*) calloc(1, sizeof(struct queue_name)); \
    }

#endif