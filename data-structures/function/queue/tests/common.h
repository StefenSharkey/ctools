#ifndef CT_QUEUE_COMMON_H
#define CT_QUEUE_COMMON_H

#include <string.h>

#include "../queue.h"

static void free_string(const char *string) {
    return;
}

ct_queue_define_node(StringNode, char*);
ct_queue_define_queue(StringQueue, StringNode);
static ct_queue_define_init(StringQueue, StringNode, string)

#endif
