#include "common.h"

int main() {
    size_t index = 0;
    struct StringIntTable* hashtable = string_int_hashtable_init();

    /* 'foo' 'eop' and 'doq' are collisions */
    string_int_hashtable_assign(hashtable, "foo", 1);
    assert(strcmp(hashtable->buckets[4].key, "foo") == 0);
    assert(hashtable->buckets[4].value == 1);
    assert(hashtable->logical_size == 1);

    string_int_hashtable_assign(hashtable, "eop", 1);
    assert(strcmp(hashtable->buckets[5].key, "eop") == 0);
    assert(hashtable->buckets[5].value == 1);
    assert(hashtable->logical_size == 2);

    string_int_hashtable_assign(hashtable, "doq", 1);
    assert(strcmp(hashtable->buckets[6].key, "doq") == 0);
    assert(hashtable->buckets[6].value == 1);
    assert(hashtable->logical_size == 3);

    string_int_hashtable_free(hashtable);
}
