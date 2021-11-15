/*
 * Parsers for non-terminal data structures like lists and dictionaries.
*/

struct JSONNode *ct_json_parse_value(FILE *stream) {
    char character = (char) fgetc(stream);
    struct JSONNode *node = ct_json_node_init();

    /* Determine what kind of terminal to parse based off the first character */
    switch(character) {
        case '{': ct_json_parse_dictionary(stream);
    }
    

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
            ct_json_error("ERROR: missing : after key\n");
        }

        ct_json_ignore_whitespace(stream);
        last_key->value = ct_json_parse_value(stream);

        /* Add a new key into the chain */
        last_key->next = ct_json_key_init();
        last_key = last_key->next;
    }

    return head;
}
