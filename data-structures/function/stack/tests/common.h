#ifndef CT_STACK_COMMON_H
#define CT_STACK_COMMON_H

#include <assert.h>
#include <string.h>

#include "../stack.h"

static void free_string(const char *string) {
    return;
}

ct_stack_define_node(StringNode, char*);
ct_stack_define_stack(StringStack, StringNode);
static ct_stack_define_init(StringStack, StringNode, string)
static ct_stack_define_free(StringStack, StringNode, string, free_string)

#endif
