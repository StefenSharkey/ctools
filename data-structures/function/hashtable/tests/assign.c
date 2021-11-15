#include "common.h"

int main() {
    size_t index = 0;
    struct StringIntTable* hashtable = string_int_hashtable_init();

    string_int_hashtable_assign(hashtable, "foo", 1);

    for(index = 0; index < hashtable->physical_size; index++) {
        if(hashtable->buckets[index].state != CT_HASHTABLE_FILLED) {
            continue;
        }

        printf("%s, %i\n", hashtable->buckets[index].key, hashtable->buckets[index].value);
    }

    string_int_hashtable_free(hashtable);
}
