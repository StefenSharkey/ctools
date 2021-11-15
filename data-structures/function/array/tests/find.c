#include "common.h"

int main() {
    struct StringArray *array = string_array_init();

    string_array_append(array, "foo");
    string_array_append(array, "bar");
    string_array_append(array, "baz");
    string_array_append(array, "tuna");
    string_array_append(array, "spam");

    assert(string_array_find(array, "foo") == 0);
    assert(string_array_find(array, "bar") == 1);
    assert(string_array_find(array, "baz") == 2);
    assert(string_array_find(array, "tuna") == 3);
    assert(string_array_find(array, "spam") == 4);
    assert(string_array_find(array, "thud") == -1);

    string_array_free(array);
}
