#ifndef CT_JSON_H
#define CT_JSON_H

enum JSONType {
    CT_JSON_INT,
    CT_JSON_KEY,
    CT_JSON_LIST,
    CT_JSON_STRING
};

struct JSONNode {
    enum JSONType type;
    union data {
        
    };
};

struct JSONKey {
    char* key;
    struct JSONNode *value;
    struct JSONKey *next;
};

#endif
