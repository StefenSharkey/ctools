#include "common.h"

int main() {
    struct StringIntTable* hashtable = string_int_hashtable_init();

    string_int_hashtable_assign(hashtable, "foo", 1);
    string_int_hashtable_assign(hashtable, "bar", 2);
    string_int_hashtable_assign(hashtable, "tuna", 3);
    string_int_hashtable_assign(hashtable, "eop", 1);
    string_int_hashtable_assign(hashtable, "doq", 1);

    /* Delete some keys */
    string_int_hashtable_delete(hashtable, "eop");
    assert(hashtable->logical_size == 4);

    string_int_hashtable_delete(hashtable, "doq");
    assert(hashtable->logical_size == 3);

    /* Do lookups still work? */
    assert(string_int_hashtable_lookup(hashtable, "foo") == 1);
    assert(string_int_hashtable_lookup(hashtable, "bar") == 2);
    assert(string_int_hashtable_lookup(hashtable, "tuna") == 3);

    assert(string_int_hashtable_contains(hashtable, "foo") == 1);
    assert(string_int_hashtable_contains(hashtable, "bar") == 1);
    assert(string_int_hashtable_contains(hashtable, "tuna") == 1);
    assert(string_int_hashtable_contains(hashtable, "eop") == 0);
    assert(string_int_hashtable_contains(hashtable, "doq") == 0);

    string_int_hashtable_free(hashtable);
}
