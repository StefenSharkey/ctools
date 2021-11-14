#include "common.h"

int main() {
    struct StringList *list = string_list_linked_init();

    assert(list->head == NULL);    
    assert(list->tail == NULL);    
    assert(list->length == 0);    

    string_list_linked_free(list);
}
