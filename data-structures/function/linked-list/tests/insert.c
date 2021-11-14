#include "common.h"

int main() {
    struct StringList *list = string_list_linked_init();



    string_list_linked_free(list);
}
