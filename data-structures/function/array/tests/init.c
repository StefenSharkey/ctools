#include "common.h"

int main() {
    struct StringArray *array = string_array_init();

    string_array_free(array);
}
