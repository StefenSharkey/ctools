/*
 * A function-based, ANSI C compliant queue implementation.
*/

#ifndef CT_QUEUE_H
#define CT_QUEUE_H

#define ct_queue_define_node(node_name, node_type) \
    struct node_name {                             \
        node_type value;                           \
        struct node_name *next;                    \
    }

#define ct_queue_define_queue(queue_name, node_name) \
    struct queue_name {                              \
        unsigned int length;                         \
        node_name *front;                            \
        node_name *back;                             \
    }


#endif
