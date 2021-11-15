/*
 * A recursive-descent parser for JSON.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "parse.h"
#include "data-structures/ctstring.h"
#include "data-structures/node-array.h"

struct JSONNode *ct_json_parse_value(FILE *stream) {
    struct JSONNode *node = ct_json_node_init();

    return node;
}

struct JSONNode *ct_json_parse_dictionary(FILE *stream) {
    char character = -1;
    struct JSONNode *node = ct_json_node_init();

    /* Keep parsing keys and values until a closing brace is found */
    while((character = (char) fgetc(stream)) != '}') {
        if(character != '"') {
            continue;
        }

        /* Parse a key */
        ct_json_parse_string(stream);
        character = (char) fgetc(stream);

        /* Keys must have a : after */
        if(character != ':') {
            ct_json_error("ERROR: missing : after key");
        }

        

    }

    return node;
}

struct JSONNode *ct_json_parse(FILE *stream) {
    char character = (char) fgetc(stream);

    if(character != '{') {
        return NULL;
    }

    return ct_json_parse_dictionary(stream);
}

int main(int argc, char *argv[]) {
    ct_json_parse(stdin);
}
