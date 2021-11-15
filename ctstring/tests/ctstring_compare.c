#include <stdio.h>
#include <assert.h>

#include "../src/ctstring.h"

int main() {
    struct CtString* string_a = ctstring_init(32);
    struct CtString* string_b = ctstring_init(32);
    struct CtString* string_c = ctstring_init(32);
    struct CtString* string_d = ctstring_init(32);

    ctstring_concat_nt(string_a, "foobar");
    ctstring_concat_nt(string_b, "barfoo");
    ctstring_concat_nt(string_c, "foobar");
    ctstring_concat_nt(string_d, "foobarbaz");

    /* Compare ctStrings to ctStrings */
    assert(ctstring_compare(string_a, string_b) == 0);
    assert(ctstring_compare(string_a, string_c) == 1);
    assert(ctstring_compare(string_c, string_d) == 0);

    /* Compare ctStrings to NUL-terminated string */
    assert(ctstring_compare_nt(string_a, "foobar") == 1);
    assert(ctstring_compare_nt(string_b, "barfoo") == 1);
    assert(ctstring_compare_nt(string_c, "fbarfoo") == 0);
    assert(ctstring_compare_nt(string_d, "foobarbazs") == 0);
    assert(ctstring_compare_nt(string_a, "") == 0);

    ctstring_free(string_a);
    ctstring_free(string_b);
    ctstring_free(string_c);
    ctstring_free(string_d);
}
