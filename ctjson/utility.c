/*
 * Base utilities for the JSON parser.
*/

#include <stdlib.h>
#include <stdio.h>

#include "parse.h"

struct JSONNode *ct_json_node_init() {
    return (struct JSONNode*) calloc(1, sizeof(struct JSONNode));
}

void ct_json_error(const char *format, ...) {
    va_list specifiers = {0};

    va_start(specifiers, format);
    vfprintf(stderr, format, specifiers);
    va_end(specifiers);
}
