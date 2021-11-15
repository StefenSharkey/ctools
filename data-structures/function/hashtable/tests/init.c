#include "common.h"

int main() {
    struct StringIntTable* hashtable = string_int_hashtable_init();

    assert(hashtable->buckets != NULL);
    assert(hashtable->logical_size == 0);
    assert(hashtable->physical_size == 10);

    string_int_hashtable_free(hashtable);
}
