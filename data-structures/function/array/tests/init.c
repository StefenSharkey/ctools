#include "common.h"

int main() {
    struct StringArray *array = string_array_init();

    assert(array->physical_size == 5);
    assert(array->logical_size == 0);
    assert(array->contents != NULL);

    string_array_free(array);
}
