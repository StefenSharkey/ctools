#include "common.h"

int main() {
    struct StringList *list = string_list_linked_init();

    string_list_linked_append(list, "foo");
    string_list_linked_append(list, "bar");
    string_list_linked_append(list, "baz");
    string_list_linked_append(list, "tuna");
    string_list_linked_append(list, "spam");

    assert(string_list_linked_find(list, "foo") == list->head);
    assert(string_list_linked_find(list, "bar") == list->head->next);
    assert(string_list_linked_find(list, "baz") == list->head->next->next);
    assert(string_list_linked_find(list, "tuna") == list->head->next->next->next);
    assert(string_list_linked_find(list, "spam") == list->head->next->next->next->next);
    assert(string_list_linked_find(list, "spam") == list->tail);
    assert(string_list_linked_find(list, "thud") == NULL);

    string_list_linked_free(list);
}
