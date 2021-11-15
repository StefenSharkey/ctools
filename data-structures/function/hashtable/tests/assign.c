#include "common.h"

int main() {
    size_t index = 0;
    struct StringIntTable* hashtable = string_int_hashtable_init();

    /* 'foo' 'eop' and 'doq' are collisions */
    string_int_hashtable_assign(hashtable, "foo", 1);
    assert(strcmp(hashtable->buckets[4].key, "foo") == 0);
    assert(hashtable->buckets[4].value == 1);
    assert(hashtable->logical_size == 1);
    assert(hashtable->physical_size == 10);

    string_int_hashtable_assign(hashtable, "eop", 1);
    assert(strcmp(hashtable->buckets[5].key, "eop") == 0);
    assert(hashtable->buckets[5].value == 1);
    assert(hashtable->logical_size == 2);
    assert(hashtable->physical_size == 10);

    string_int_hashtable_assign(hashtable, "doq", 1);
    assert(strcmp(hashtable->buckets[6].key, "doq") == 0);
    assert(hashtable->buckets[6].value == 1);
    assert(hashtable->logical_size == 3);
    assert(hashtable->physical_size == 10);

    /* Should not qualify as a new key */
    string_int_hashtable_assign(hashtable, "doq", 1);
    assert(strcmp(hashtable->buckets[6].key, "doq") == 0);
    assert(hashtable->buckets[6].value == 1);
    assert(hashtable->logical_size == 3);
    assert(hashtable->physical_size == 10);

    /* This should not collide */
    string_int_hashtable_assign(hashtable, "tuna", 1);
    assert(strcmp(hashtable->buckets[0].key, "tuna") == 0);
    assert(hashtable->buckets[0].value == 1);
    assert(hashtable->logical_size == 4);
    assert(hashtable->physical_size == 10);

    string_int_hashtable_assign(hashtable, "spam", 1);
    assert(strcmp(hashtable->buckets[3].key, "spam") == 0);
    assert(hashtable->buckets[3].value == 1);
    assert(hashtable->logical_size == 5);
    assert(hashtable->physical_size == 10);

    string_int_hashtable_assign(hashtable, "thud", 1);
    assert(strcmp(hashtable->buckets[7].key, "thud") == 0);
    assert(hashtable->buckets[7].value == 1);
    assert(hashtable->logical_size == 6);
    assert(hashtable->physical_size == 10);

    string_int_hashtable_assign(hashtable, "quz", 1);
    assert(strcmp(hashtable->buckets[2].key, "quz") == 0);
    assert(hashtable->buckets[2].value == 1);
    assert(hashtable->logical_size == 7);
    assert(hashtable->physical_size == 10);

    string_int_hashtable_assign(hashtable, "foobar", 1);
    assert(strcmp(hashtable->buckets[8].key, "foobar") == 0);
    assert(hashtable->buckets[8].value == 1);
    assert(hashtable->logical_size == 8);
    assert(hashtable->physical_size == 10);

    /* This should trigger a resize */
    string_int_hashtable_assign(hashtable, "food", 1);
    assert(strcmp(hashtable->buckets[7].key, "food") == 0);
    assert(hashtable->buckets[7].value == 1);
    assert(hashtable->logical_size == 9);
    assert(hashtable->physical_size == 20);

    printf("%f\n", 9.0 / 10.0);

    for(index = 0; index < hashtable->physical_size; index++) {
        if(hashtable->buckets[index].state != CT_HASHTABLE_FILLED) {
            continue;
        }

        printf("%li\n", index);
        printf("%s, %i\n", hashtable->buckets[index].key, hashtable->buckets[index].value);
    }

    string_int_hashtable_free(hashtable);
}
