#include <stdio.h>
#include <assert.h>

#include "../src/ctstring.h"

int main() {
    struct CtString* string_a = ctstring_init(32);

    ctstring_concat_nt(string_a, "foobar");
    assert(ctstring_upper(string_a) == string_a);
    assert(ctstring_compare_nt(string_a, "FOOBAR") == 1);
    ctstring_set(string_a, 0);
    string_a->length = 0;

    ctstring_concat_nt(string_a, "FOOBar");
    assert(ctstring_upper(string_a) == string_a);
    assert(ctstring_compare_nt(string_a, "FOOBAR") == 1);
    ctstring_set(string_a, 0);
    string_a->length = 0;

    ctstring_concat_nt(string_a, "!FOO!Bar!");
    assert(ctstring_upper(string_a) == string_a);
    assert(ctstring_compare_nt(string_a, "!FOO!BAR!") == 1);
    ctstring_set(string_a, 0);
    string_a->length = 0;


    ctstring_free(string_a);

    return 0;
}
