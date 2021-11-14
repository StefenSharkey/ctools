#ifndef CT_LINKED_COMMON_H
#define CT_LINKED_COMMON_H

#include <assert.h>

#include "../linked-list.h"

static void free_string(const char* string) {
    return;
}

ct_linked_define_node(StringNode, char*);
ct_linked_define_list(StringList, StringNode);
static ct_linked_define_init(StringList, string_list)
static ct_linked_define_free(StringList, StringNode, string_list, free_string)

#endif
