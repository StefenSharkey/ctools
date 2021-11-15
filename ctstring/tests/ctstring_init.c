#include <assert.h>

#include "../src/ctstring.h"

int main() {
    struct CtString* string = ctstring_init(32);

    assert(string->string != NULL);
    assert(string->length == 0);
    assert(string->capacity == 32);

    ctstring_free(string);
}
