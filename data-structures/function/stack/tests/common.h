#ifndef CT_STACK_COMMON_H
#define CT_STACK_COMMON_H

#include <assert.h>
#include <string.h>

#include "../stack.h"

ct_stack_define_node(StringNode, char*);
ct_stack_define_stack(StringStack, StringNode);



#endif
