#ifndef CT_LINKED_COMMON_H
#define CT_LINKED_COMMON_H

#include "../linked-list.h"

ct_linked_define_node(StringNode, char*);
ct_linked_define_list(StringList, StringNode);
static ct_linked_define_init(StringList, string_list)

#endif
