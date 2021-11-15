/*
 * Base utilities for the JSON parser.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "parse.h"

struct JSONNode *ct_json_node_init() {
    return (struct JSONNode*) calloc(1, sizeof(struct JSONNode));
}

struct JSONKey *ct_json_key_init() {
    return (struct JSONKey*) calloc(1, sizeof(struct JSONKey));
}

void ct_json_error(const char *format, ...) {
    va_list specifiers = {0};

    va_start(specifiers, format);
    vfprintf(stderr, format, specifiers);
    va_end(specifiers);
}
