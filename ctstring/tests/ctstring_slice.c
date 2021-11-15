#include <stdio.h>
#include <assert.h>

#include "../src/ctstring.h"

int main() {
    struct CtString slice;
    struct CtString* string = ctstring_init(32);

    ctstring_concat_nt(string, "foo bar baz tuna spam");

    slice = ctstring_slice(string, 0, 3);
    assert(slice.length == 3);
    assert(slice.string[0] == 'f');
    assert(slice.string[1] == 'o');
    assert(slice.string[2] == 'o');

    slice = ctstring_slice(string, 4, 7);
    assert(slice.length == 3);
    assert(slice.string[0] == 'b');
    assert(slice.string[1] == 'a');
    assert(slice.string[2] == 'r');

    slice = ctstring_slice(string, 8, 11);
    assert(slice.length == 3);
    assert(slice.string[0] == 'b');
    assert(slice.string[1] == 'a');
    assert(slice.string[2] == 'z');

    slice = ctstring_slice(string, 12, 16);
    assert(slice.length == 4);
    assert(slice.string[0] == 't');
    assert(slice.string[1] == 'u');
    assert(slice.string[2] == 'n');
    assert(slice.string[3] == 'a');

    slice = ctstring_slice(string, 17, 21);
    assert(slice.length == 4);
    assert(slice.string[0] == 's');
    assert(slice.string[1] == 'p');
    assert(slice.string[2] == 'a');
    assert(slice.string[3] == 'm');

    ctstring_free(string);
}
