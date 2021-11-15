/*
 * Functions that parse terminal tokens, like strings, integers, etc.
*/

#include <stdio.h>

#include "parse.h"
#include "data-structures/ctstring.h"

struct CtString *ct_json_parse_string(FILE *stream) {
    char character = (char) fgetc(stream);
    struct CtString *new_string = ctstring_init(32);

    while(character != EOF && character != '"') {
        ctstring_concat_ch(new_string, character);
        character = (char) fgetc(stream);
    }

    return new_string;
}
