#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "../src/ctstring.h"

int main() {
    struct CtString* string_a;
    struct CtString* string_b = ctstring_init(32);

    ctstring_concat_nt(string_b, "foobar");

    /* Base comparison test */
    string_a = ctstring_nt_to_ctstring("foobar");
    assert(ctstring_compare(string_a, string_b) == 1);
    assert(string_a->length == 6);
    ctstring_free(string_a);

    /* What happens with empty strings? */
    string_a = ctstring_nt_to_ctstring("");
    assert(ctstring_compare(string_a, string_b) == 0);
    assert(string_a->length == 0);
    ctstring_free(string_a);

    ctstring_free(string_b);

    return 0;
}
