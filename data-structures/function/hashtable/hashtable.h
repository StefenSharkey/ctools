/*
 * A function-based, ANSI C compliant hashtable implementation.
*/

#ifndef CT_HASHTABLE_H
#define CT_HASHTABLE_H

#ifndef CT_HASHTABLE_PHYSICAL_SIZE
#define CT_HASHTABLE_PHYSICAL_SIZE 10
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

#endif
