/*
 * An array of JSON nodes.
*/

#include "array.h"
#include "../parse.h"
#include "node-array.h"

ct_array_define_append(JSONNodeArray, struct JSONNode, json_node)

ct_array_define_init(JSONNodeArray, struct JSONNode, json_node)
