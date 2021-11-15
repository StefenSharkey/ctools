#include <stdio.h>
#include <assert.h>

#include "../src/ctstring.h"

int main() {
    struct CtString* string_a = ctstring_init(32);
    struct CtString* string_b = ctstring_init(32);
    struct CtString* string_c = ctstring_init(32);
    struct CtString* string_d = ctstring_init(32);

    ctstring_concat_nt(string_a, "foobar");
    ctstring_concat_nt(string_b, "bar");
    ctstring_concat_nt(string_c, "foobarbaz");
    ctstring_concat_nt(string_d, "tuna");

    assert(ctstring_find(string_a, string_b) == 3);
    assert(ctstring_find(string_b, string_a) == -1); /* Too big */
    assert(ctstring_find(string_a, string_c) == -1); /* Too big */
    assert(ctstring_find(string_a, string_d) == -1); /* Not in the string */

    ctstring_free(string_a);
    ctstring_free(string_b);
    ctstring_free(string_c);
    ctstring_free(string_d);
}
