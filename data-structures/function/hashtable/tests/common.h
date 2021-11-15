#ifndef CT_HASHTABLE_COMMON_H
#define CT_HASHTABLE_COMMON_H

#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "../hashtable.h"

static void free_string(const char *string) {
    return;
}

static void free_int(int x) {
    return;
}

static long hash_string(const char *string) {
    long hash = 5031;

    while(*string != '\0') {
        hash += *string;    
        string++;
    }

    return hash;
}

static int compare_string(const char *a, const char *b) {
    return strcmp(a, b);
}

ct_hashtable_define_bucket(StringIntBucket, char*, int);
ct_hashtable_define_hashtable(StringIntTable, StringIntBucket);
static ct_hashtable_define_init(StringIntTable, StringIntBucket, string_int)
static ct_hashtable_define_free(StringIntTable, string_int, free_string, free_int)
static ct_hashtable_define_assign(StringIntTable, StringIntBucket, char*, int, string_int, hash_string, free_int, compare_string)

#endif
