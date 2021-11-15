#ifndef CT_JSON_NODE_ARRAY_H
#define CT_JSON_NODE_ARRAY_H

struct JSONNode;

struct JSONNodeArray {
    unsigned int logical_size;
    unsigned int physical_size;
    struct JSONNode* contents;
};

#endif
