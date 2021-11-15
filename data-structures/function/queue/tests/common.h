#ifndef CT_QUEUE_COMMON_H
#define CT_QUEUE_COMMON_H

#include <string.h>
#include <assert.h>

#include "../queue.h"

static void free_string(const char *string) {
    return;
}

ct_queue_define_node(StringNode, char*);
ct_queue_define_queue(StringQueue, StringNode);
static ct_queue_define_init(StringQueue, StringNode, string)
static ct_queue_define_free(StringQueue, StringNode, string, free_string)
static ct_queue_define_enqueue(StringQueue, StringNode, char*, string)
static ct_queue_define_dequeue(StringQueue, StringNode, char*, string)

#endif
