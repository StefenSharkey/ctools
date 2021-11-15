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

struct JSONKey *ct_json_parse_dictionary(FILE *stream) {
    char character = -1;
    struct JSONKey *last_key = ct_json_key_init();
    struct JSONKey *head = last_key;

    /* Keep parsing keys and values until a closing brace is found */
    while((character = (char) fgetc(stream)) != '}') {
        if(character != '"') {
            continue;
        }

        /* Parse a key */
        last_key->key = ct_json_parse_string(stream);
        character = (char) fgetc(stream);

        ct_json_ignore_whitespace(stream);

        /* Keys must have a : after */
        if(character != ':') {
            ct_json_error("ERROR: missing : after key");
        }

        ct_json_ignore_whitespace(stream);
        last_key->value = ct_json_parse_value(stream);

        /* Add a new key into the chain */
    }

    return head;
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
