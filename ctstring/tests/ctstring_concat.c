/*
 * Tests concatenation of two ctStrings
*/

#include <stdio.h>
#include <assert.h>

#include "../src/ctstring.h"

int main() {
    struct CtString* string_a = ctstring_init(20);
    struct CtString* string_b = ctstring_init(20);
    struct CtString* string_c = ctstring_init(32);

    assert(string_a->length == 0);
    assert(string_a->capacity == 20);
    assert(string_a->string != NULL);

    assert(string_b->length == 0);
    assert(string_b->capacity == 20);
    assert(string_a->string != NULL);

    assert(ctstring_concat_nt(string_b, "foobar") == string_b);
    assert(string_b->string[0] == 'f');
    assert(string_b->string[1] == 'o');
    assert(string_b->string[2] == 'o');
    assert(string_b->string[3] == 'b');
    assert(string_b->string[4] == 'a');
    assert(string_b->string[5] == 'r');
    assert(string_b->length == 6);
    assert(string_b->capacity == 20);

    assert(ctstring_concat(string_a, string_b) == string_a);
    assert(string_a->string[0] == 'f');
    assert(string_a->string[1] == 'o');
    assert(string_a->string[2] == 'o');
    assert(string_a->string[3] == 'b');
    assert(string_a->string[4] == 'a');
    assert(string_a->string[5] == 'r');
    assert(string_a->length == 6);
    assert(string_a->capacity == 20);

    assert(ctstring_concat(string_a, string_b) == string_a);
    assert(string_a->string[0] == 'f');
    assert(string_a->string[1] == 'o');
    assert(string_a->string[2] == 'o');
    assert(string_a->string[3] == 'b');
    assert(string_a->string[4] == 'a');
    assert(string_a->string[5] == 'r');
    assert(string_a->string[6] == 'f');
    assert(string_a->string[7] == 'o');
    assert(string_a->string[8] == 'o');
    assert(string_a->string[9] == 'b');
    assert(string_a->string[10] == 'a');
    assert(string_a->string[11] == 'r');
    assert(string_a->length == 12);
    assert(string_a->capacity == 20);

    assert(ctstring_concat(string_a, string_b) == string_a);
    assert(string_a->string[0] == 'f');
    assert(string_a->string[1] == 'o');
    assert(string_a->string[2] == 'o');
    assert(string_a->string[3] == 'b');
    assert(string_a->string[4] == 'a');
    assert(string_a->string[5] == 'r');
    assert(string_a->string[6] == 'f');
    assert(string_a->string[7] == 'o');
    assert(string_a->string[8] == 'o');
    assert(string_a->string[9] == 'b');
    assert(string_a->string[10] == 'a');
    assert(string_a->string[11] == 'r');
    assert(string_a->string[12] == 'f');
    assert(string_a->string[13] == 'o');
    assert(string_a->string[14] == 'o');
    assert(string_a->string[15] == 'b');
    assert(string_a->string[16] == 'a');
    assert(string_a->string[17] == 'r');
    assert(string_a->length == 18);
    assert(string_a->capacity == 20);

    assert(ctstring_concat(string_a, string_b) == string_a);
    assert(string_a->string[0] == 'f');
    assert(string_a->string[1] == 'o');
    assert(string_a->string[2] == 'o');
    assert(string_a->string[3] == 'b');
    assert(string_a->string[4] == 'a');
    assert(string_a->string[5] == 'r');
    assert(string_a->string[6] == 'f');
    assert(string_a->string[7] == 'o');
    assert(string_a->string[8] == 'o');
    assert(string_a->string[9] == 'b');
    assert(string_a->string[10] == 'a');
    assert(string_a->string[11] == 'r');
    assert(string_a->string[12] == 'f');
    assert(string_a->string[13] == 'o');
    assert(string_a->string[14] == 'o');
    assert(string_a->string[15] == 'b');
    assert(string_a->string[16] == 'a');
    assert(string_a->string[17] == 'r');
    assert(string_a->string[18] == 'f');
    assert(string_a->string[19] == 'o');
    assert(string_a->string[20] == 'o');
    assert(string_a->string[21] == 'b');
    assert(string_a->string[22] == 'a');
    assert(string_a->string[23] == 'r');
    assert(string_a->length == 24);
    assert(string_a->capacity == 33);

    assert(ctstring_concat_nt(string_a, "") == string_a);
    assert(string_a->length == 24);
    assert(string_a->capacity == 33);

    ctstring_concat_nt(string_c, "foobar");
    assert(string_c->length == 6);
    assert(string_c->capacity == 32);

    assert(ctstring_repeat(string_c, 3) == string_c);
    assert(string_c->length == 18);
    assert(string_c->capacity == 32);

    assert(ctstring_repeat(string_c, 3) == string_c);
    assert(string_c->length == 54);
    assert(string_c->capacity == 117);

    ctstring_free(string_a);
    ctstring_free(string_b);
    ctstring_free(string_c);
}
