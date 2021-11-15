#include <stdio.h>
#include <assert.h>

#include "../src/ctstring.h"

int main() {
    struct CtString* string_a = ctstring_init(32);

    ctstring_concat_nt(string_a, "foobar");
    ctstring_lower(string_a);
    assert(ctstring_compare_nt(string_a, "foobar") == 1);
    ctstring_set(string_a, 0);
    string_a->length = 0;

    ctstring_concat_nt(string_a, "fOObar");
    assert(ctstring_lower(string_a) == string_a);
    assert(ctstring_compare_nt(string_a, "foobar") == 1);
    ctstring_set(string_a, 0);
    string_a->length = 0;

    ctstring_concat_nt(string_a, "FooBAR");
    assert(ctstring_lower(string_a) == string_a);
    assert(ctstring_compare_nt(string_a, "foobar") == 1);
    ctstring_set(string_a, 0);
    string_a->length = 0;

    ctstring_concat_nt(string_a, "FOOBAR");
    assert(ctstring_lower(string_a) == string_a);
    assert(ctstring_compare_nt(string_a, "foobar") == 1);
    ctstring_set(string_a, 0);
    string_a->length = 0;

    ctstring_concat_nt(string_a, "!FOO!BAR!");
    assert(ctstring_lower(string_a) == string_a);
    assert(ctstring_compare_nt(string_a, "!foo!bar!") == 1);
    ctstring_set(string_a, 0);
    string_a->length = 0;

    ctstring_concat_nt(string_a, "");
    assert(ctstring_lower(string_a) == string_a);
    assert(ctstring_compare_nt(string_a, "") == 1);
    ctstring_set(string_a, 0);
    string_a->length = 0;

    ctstring_free(string_a);

    return 0;
}
