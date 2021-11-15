#ifndef CT_JSON_H
#define CT_JSON_H

struct FILE;

enum JSONType {
    CT_JSON_INT,
    CT_JSON_KEY,
    CT_JSON_LIST,
    CT_JSON_STRING
};

struct JSONNode {
    enum JSONType type;
    union data {
        int integer;
        struct CtString *string;
        struct JSONNodeArray *array;
        struct JSONKey *key;
    } data;
};

struct JSONKey {
    char *key;
    struct JSONNode *value;
    struct JSONKey *next;
};

/*
 * Parse a string between the current character and the next
 * quote from a file STREAM.
 *
 * @param stream: the stream to parse
 * @return: a new string
*/
struct CtString *ct_json_parse_string(FILE *stream);

/*
 * Initialize a new JSON node.
 *
 * @return: a new JSON node.
*/
struct JSONNode *ct_json_node_init();

/*
 * Display a formatted error message to the stderr.
 *
 * @param format: the format to print
*/
void ct_json_error(const char *format, ...);

#endif
