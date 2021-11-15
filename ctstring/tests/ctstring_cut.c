#include <stdio.h>
#include <assert.h>

#include "../src/ctstring.h"

int main() {
    struct CtString* string = ctstring_init(32);

    ctstring_concat_nt(string, "foobar");

    assert(ctstring_cut(string, 0, 6) == string);
    assert(string->length == 0);

    ctstring_concat_nt(string, "foobar");
    assert(ctstring_cut(string, 0, 4) == string);
    assert(string->length == 2);
    assert(string->string[0] == 'a');
    assert(string->string[1] == 'r');

    ctstring_set(string, 0);
    string->length = 0;
    ctstring_concat_nt(string, "foobar");
    assert(ctstring_cut(string, 2, 4) == string);
    assert(string->length == 4);
    assert(string->string[0] == 'f');
    assert(string->string[1] == 'o');
    assert(string->string[2] == 'a');
    assert(string->string[3] == 'r');

    ctstring_set(string, 0);
    string->length = 0;
    ctstring_concat_nt(string, "foobar");
    assert(ctstring_cut(string, 3, 4) == string);
    assert(string->length == 5);
    assert(string->string[0] == 'f');
    assert(string->string[1] == 'o');
    assert(string->string[2] == 'o');
    assert(string->string[3] == 'a');
    assert(string->string[4] == 'r');

    ctstring_set(string, 0);
    string->length = 0;
    assert(ctstring_concat_nt(string, "foobar") == string);
    ctstring_cut(string, 1, 5);
    assert(string->length == 2);
    assert(string->string[0] == 'f');
    assert(string->string[1] == 'r');

    ctstring_free(string);

    return 0;
}
