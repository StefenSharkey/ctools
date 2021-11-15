#ifndef CT_HASHTABLE_COMMON_H
#define CT_HASHTABLE_COMMON_H

#include <assert.h>

#include "../hashtable.h"

static void free_string(const char* string) {
    return;
}

static void free_int(int x) {
    return;
}

ct_hashtable_define_bucket(StringIntBucket, char*, int);
ct_hashtable_define_hashtable(StringIntTable, StringIntBucket);
static ct_hashtable_define_init(StringIntTable, StringIntBucket, string_int)
static ct_hashtable_define_free(StringIntTable, string_int, free_string, free_int)

#endif
