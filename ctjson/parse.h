#ifndef CT_JSON_H
#define CT_JSON_H

struct FILE;

enum JSONType {
    CT_JSON_INT,
    CT_JSON_KEY,
    CT_JSON_ARRAY,
    CT_JSON_STRING
};

struct JSONNode {
    enum JSONType type;
    union {
        int integer;
        struct CtString *string;
        struct JSONNodeArray *array;
        struct JSONKey *key;
    } data;
};

struct JSONKey {
    struct CtString *key;
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
 * Parses forward in a file STREAM until a non-whitespace character
 * is met.
 *
 * @param stream: the file to parse
 * @return: the first non-whitespace character
*/
char ct_json_ignore_whitespace(FILE *stream);

/*
 * Initialize a new JSON node.
 *
 * @return: a new JSON node
*/
struct JSONNode *ct_json_node_init();

/*
 * Initialize a new JSON key.
 *
 * @return: a new JSON key
*/
struct JSONKey *ct_json_key_init();

/*
 * Display a formatted error message to the stderr.
 *
 * @param format: the format to print
*/
void ct_json_error(const char *format, ...);

/*
 * Retrieve the string representation of a JSON type.
 *
 * @param node: the node to get the type of
 * @return: the type of the node
*/
char *ct_json_str_type(struct JSONNode *node);

/*
 * Parse a generic 'value' from the file STREAM, and return a node
 * representing that value.
 *
 * @param stream: the stream to parse from
 * @return: a node representing the key
*/
struct JSONNode *ct_json_parse_value(FILE *stream);

/*
 * Parse a string key from the file STREAM, and return a key object
 * that contains the first key in a chain of keys, each having an
 * assigned value.
 *
 * @param stream: the stream to parse from
 * @return: the key representing a key value pair
*/
struct JSONKey *ct_json_parse_dictionary(FILE *stream);

/*
 * Parses a list from the file STREAM and return a list of nodes
 * which contain each element of the list.
 *
 * @param stream: the stream to parse from
 * @return: a new list
*/
struct JSONNodeArray *ct_json_parse_array(FILE *stream);












#endif
