/*
 * A function-based, ANSI C compliant hashtable implementation.
*/

#ifndef CT_HASHTABLE_H
#define CT_HASHTABLE_H

#include <stdlib.h>

/* Overload-able default size */
#ifndef CT_HASHTABLE_PHYSICAL_SIZE
#define CT_HASHTABLE_PHYSICAL_SIZE 10
#endif

/* Overload-able load threshold */
#ifndef CT_HASHTABLE_LOAD_THRESHOLD
#define CT_HASHTABLE_LOAD_THRESHOLD 0.8f
#endif

/* Overload-able equation for changing the size */
#ifndef CT_HASHTABLE_GROWTH_FACTOR
#define CT_HASHTABLE_GROWTH_FACTOR(current_size) \
    current_size * 0.3f
#endif

#define ct_hashtable_define_bucket(bucket_name, key_type, value_type) \
    struct bucket_name {                                              \
        int state;                                                    \
        key_type key;                                                 \
        value_type value;                                             \
    }

#define ct_hashtable_define_hashtable(hashtable_name, bucket_name) \
    struct hashtable_name {                                        \
        unsigned int logical_size;                                 \
        unsigned int physical_size;                                \
        struct bucket_name *buckets;                               \
    }

#define ct_hashtable_define_init(hashtable_name, bucket_name, identifier)                                              \
    struct hashtable_name *identifier##_hashtable_init() {                                                             \
        struct hashtable_name *new_hashtable = (struct hashtable_name*) calloc(1, sizeof(struct hashtable_name));      \
                                                                                                                       \
        new_hashtable->physical_size = CT_HASHTABLE_PHYSICAL_SIZE;                                                     \
        new_hashtable->buckets = (struct bucket_name*) calloc(CT_HASHTABLE_PHYSICAL_SIZE, sizeof(struct bucket_name)); \
                                                                                                                       \
        return new_hashtable;                                                                                          \
    }

#define ct_hashtable_define_free(hashtable_name, identifier, free_key, free_value) \
    void identifier##_hashtable_free(struct hashtable_name *hashtable) {           \
        size_t index = 0;                                                           \
                                                                                    \
        for(index = 0; index < hashtable->physical_size; index++) {                 \
            if(hashtable->buckets[index].state != 2) {                              \
                continue;                                                           \
            }                                                                       \
                                                                                    \
            free_key(hashtable->buckets[index].key);                                \
            free_value(hashtable->buckets[index].value);                            \
        }                                                                           \
                                                                                    \
        free(hashtable->buckets);                                                   \
        free(hashtable);                                                            \
    }

#endif
