#include "common.h"

int main() {
    struct StringArray *array = string_array_init();

    /* Insertion */
    assert(string_array_insert(array, "foo", 0) == array);
    assert(strcmp(array->contents[0], "foo") == 0);
    assert(array->logical_size == 1);
    assert(array->physical_size == 5);

    assert(string_array_insert(array, "bar", 0) == array);
    assert(strcmp(array->contents[0], "bar") == 0);
    assert(strcmp(array->contents[1], "foo") == 0);
    assert(array->logical_size == 2);
    assert(array->physical_size == 5);

    assert(string_array_insert(array, "spam", 2) == array);
    assert(strcmp(array->contents[0], "bar") == 0);
    assert(strcmp(array->contents[1], "foo") == 0);
    assert(strcmp(array->contents[2], "spam") == 0);
    assert(array->logical_size == 3);
    assert(array->physical_size == 5);

    /* Appending */

    string_array_free(array);
}
