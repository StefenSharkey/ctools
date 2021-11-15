#include "common.h"

int main() {
    struct StringArray *array = string_array_init();

    string_array_append(array, "foo");
    string_array_append(array, "bar");
    string_array_append(array, "baz");
    string_array_append(array, "tuna");

    /* Pop */
    assert(strcmp(string_array_pop(array, 0), "foo") == 0);
    assert(array->logical_size == 3);

    assert(strcmp(string_array_pop(array, 2), "baz") == 0);
    assert(array->logical_size == 2);

    string_array_free(array);
}
