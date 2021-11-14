#include "common.h"

int main() {
    struct StringList *list = string_list_linked_init();

    string_list_linked_append(list, "foo");
    assert(strcmp(list->head->value, "foo") == 0);
    assert(strcmp(list->tail->value, "foo") == 0);

    string_list_linked_free(list);
}
