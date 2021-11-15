#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "../src/ctstring.h"

int main() {
    char buffer_a[10];
    struct CtString* string_a = ctstring_init(32);
    
    ctstring_concat_nt(string_a, "foobar");
    assert(ctstring_to_nt(string_a, buffer_a, 10) == 6);
    assert(strcmp(buffer_a, "foobar") == 0);
    ctstring_set(string_a, 0);
    string_a->length = 0;

    /* The string is larger than the buffer. the character should be overwritten
     * with a NUL byte. */
    ctstring_concat_nt(string_a, "012345678910");
    assert(ctstring_to_nt(string_a, buffer_a, 10) ==  10);
    assert(strcmp(buffer_a, "0123456789") == 0);
    ctstring_set(string_a, 0);
    string_a->length = 0;

    /* Giving a larger buffer than actually exists should not segfault
     * when the string in question is smaller than the buffer's actual size*/
    ctstring_concat_nt(string_a, "0123456789");
    assert(ctstring_to_nt(string_a, buffer_a, 13) == 10);
    assert(strcmp(buffer_a, "0123456789") == 0);
    ctstring_set(string_a, 0);
    string_a->length = 0;

    ctstring_free(string_a);

    return 0;
}
