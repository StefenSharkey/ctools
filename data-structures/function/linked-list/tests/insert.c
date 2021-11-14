#include "common.h"

int main() {
    struct StringList *list = string_list_linked_init();

    /* Appending */
    string_list_linked_append(list, "foo");
    assert(list->length == 1);
    assert(strcmp(list->head->value, "foo") == 0);
    assert(strcmp(list->tail->value, "foo") == 0);

    string_list_linked_append(list, "bar");
    assert(list->length == 2);
    assert(list->head->next == list->tail);
    assert(strcmp(list->head->next->value, "bar") == 0);
    assert(strcmp(list->tail->value, "bar") == 0);

    /* Insertion */
    string_list_linked_insert(list, list->head, "spam");
    assert(list->length == 3);
    assert(strcmp(list->head->value, "spam") == 0);
    assert(strcmp(list->head->next->value, "foo") == 0);
    assert(strcmp(list->head->next->next->value, "bar") == 0);
    assert(strcmp(list->tail->value, "bar") == 0);

    string_list_linked_insert(list, list->tail, "tuna");
    assert(list->length == 4);
    assert(strcmp(list->head->value, "spam") == 0);
    assert(strcmp(list->head->next->value, "foo") == 0);
    assert(strcmp(list->head->next->next->value, "tuna") == 0);
    assert(strcmp(list->head->next->next->next->value, "bar") == 0);
    assert(strcmp(list->tail->value, "bar") == 0);

    string_list_linked_free(list);
}
