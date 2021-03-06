#ifndef CT_LINKED_COMMON_H
#define CT_LINKED_COMMON_H

#include <assert.h>
#include <string.h>

#include "../linked-list.h"

static void free_string(const char* string) {
    return;
}

static int compare_string(const char* a, const char* b) {
    return strcmp(a, b) == 0;
}

ct_linked_define_node(StringNode, char*);
ct_linked_define_list(StringList, StringNode);
static ct_linked_define_init(StringList, string_list)
static ct_linked_define_free(StringList, StringNode, string_list, free_string)
static ct_linked_define_insert(StringList, StringNode, char*, string_list)
static ct_linked_define_append(StringList, StringNode, char*, string_list)
static ct_linked_define_remove(StringList, StringNode, string_list, free_string)
static ct_linked_define_find(StringList, StringNode, char*, string_list, compare_string)

#endif
