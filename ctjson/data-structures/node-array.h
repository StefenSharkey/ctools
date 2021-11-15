#ifndef CT_JSON_NODE_ARRAY_H
#define CT_JSON_NODE_ARRAY_H

struct JSONNode;

/*
 * An array of JSON nodes.
*/
struct JSONNodeArray {
    unsigned int logical_size;
    unsigned int physical_size;
    struct JSONNode** contents;
};

/*
 * Append a node to an array of JSON nodes.
 *
 * @param array: the array to append to
 * @param value: the node to append
*/
struct JSONNodeArray *json_node_array_append(struct JSONNodeArray *array, struct JSONNode* value);

/*
 * Initialize a new node array.
 *
 * @return: a new array of nodes
*/
struct JSONNodeArray *json_node_array_init();

#endif
