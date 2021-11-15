#include <stdio.h>
#include <assert.h>

#include "../src/ctstring.h"

void print_ctstring(struct CtString* string) {
    int index;

    for(index = 0; index < string->length; index++) {
        printf("%c", string->string[index]);
    }

    printf("%c", '\n');
}

int main() {
    size_t index = 0;
    int status;
    struct CtString* string = ctstring_init(32);
    struct CtString split_state;

    ctstring_concat_nt(string, "foo bar baz tuna spam");

    status = ctstring_split(string, &split_state, &index, ' ');
    assert(split_state.length == 3);
    assert(split_state.string[0] == 'f');
    assert(split_state.string[1] == 'o');
    assert(split_state.string[2] == 'o');
    assert(status == 0);

    status = ctstring_split(string, &split_state, &index, ' ');
    assert(split_state.length == 3);
    assert(split_state.string[0] == 'b');
    assert(split_state.string[1] == 'a');
    assert(split_state.string[2] == 'r');
    assert(status == 0);

    status = ctstring_split(string, &split_state, &index, ' ');
    assert(split_state.length == 3);
    assert(split_state.string[0] == 'b');
    assert(split_state.string[1] == 'a');
    assert(split_state.string[2] == 'z');
    assert(status == 0);

    status = ctstring_split(string, &split_state, &index, ' ');
    assert(split_state.length == 4);
    assert(split_state.string[0] == 't');
    assert(split_state.string[1] == 'u');
    assert(split_state.string[2] == 'n');
    assert(split_state.string[3] == 'a');
    assert(status == 0);

    status = ctstring_split(string, &split_state, &index, ' ');
    assert(split_state.length == 4);
    assert(split_state.string[0] == 's');
    assert(split_state.string[1] == 'p');
    assert(split_state.string[2] == 'a');
    assert(split_state.string[3] == 'm');

    status = ctstring_split(string, &split_state, &index, ' ');
    assert(status == 1);

    ctstring_free(string);
}
