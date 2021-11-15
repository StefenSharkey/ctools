/*
 * A recursive-descent parser for JSON.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "parse.h"
#include "data-structures/ctstring.h"
#include "data-structures/node-array.h"

struct JSONKey *ct_json_parse(FILE *stream) {
    char character = (char) fgetc(stream);

    if(character != '{') {
        return NULL;
    }

    return ct_json_parse_dictionary(stream);
}

int main(int argc, char *argv[]) {
    struct JSONKey *root = ct_json_parse(stdin);

    ctstring_print(root->key);
    ctstring_print(root->next->key);
    ctstring_print(root->next->next->key);
}
