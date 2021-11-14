#include "common.h"

int main() {
    struct StringList *list = string_list_linked_init();

    string_list_linked_append(list, "foo");
    string_list_linked_append(list, "bar");
    string_list_linked_append(list, "baz");
    string_list_linked_append(list, "tuna");
    string_list_linked_append(list, "spam");

    /* Make sure things can be deleted from the head */
    string_list_linked_remove(list, list->head);
    assert(strcmp(list->head->value, "bar") == 0);
    assert(list->length == 4);

    /* Make sure that things can be deleted in the middle */
    string_list_linked_remove(list, list->head->next);
    assert(strcmp(list->head->value, "bar") == 0);
    assert(strcmp(list->head->next->value, "tuna") == 0);
    assert(list->length == 3);

    /* Make sure that the tail will be shifted back one node */
    string_list_linked_remove(list, list->tail);
    assert(strcmp(list->head->value, "bar") == 0);
    assert(strcmp(list->head->next->value, "tuna") == 0);
    assert(list->tail == list->head->next);
    assert(list->length == 2);

    string_list_linked_remove(list, list->tail);
    assert(strcmp(list->head->value, "bar") == 0);
    assert(list->tail == list->head);
    assert(list->length == 1);

    string_list_linked_remove(list, list->tail);
    assert(list->head == NULL);
    assert(list->tail == NULL);
    assert(list->length == 0);

    string_list_linked_free(list);
}
