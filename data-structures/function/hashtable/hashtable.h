/*
 * A function-based, ANSI C compliant hashtable implementation.
*/

#ifndef CT_HASHTABLE_H
#define CT_HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>

/* Overload-able default size */
#ifndef CT_HASHTABLE_PHYSICAL_SIZE
#define CT_HASHTABLE_PHYSICAL_SIZE 10
#endif

/* Overload-able load threshold */
#ifndef CT_HASHTABLE_LOAD_THRESHOLD
#define CT_HASHTABLE_LOAD_THRESHOLD 0.8
#endif

/* Overload-able equation for changing the size */
#ifndef CT_HASHTABLE_GROWTH_FACTOR
#define CT_HASHTABLE_GROWTH_FACTOR(current_size) \
    current_size * 2
#endif

#define ct_hashtable_define_bucket(bucket_name, key_type, value_type) \
    struct bucket_name {                                              \
        int state;                                                    \
        key_type key;                                                 \
        value_type value;                                             \
    }

#define CT_HASHTABLE_UNFILLED   0
#define CT_HASHTABLE_FILLED     1
#define CT_HASHTABLE_TOMBSTONE  2

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
            if(hashtable->buckets[index].state != CT_HASHTABLE_FILLED) {            \
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

#define ct_hashtable_define_assign(hashtable_name, bucket_name, key_type, value_type, identifier, hash, free_value, compare) \
    void identifier##_hashtable_assign(struct hashtable_name *hashtable, key_type key, value_type value) {                   \
        long key_hash = 0;                                                                                                   \
                                                                                                                             \
        if(((double) hashtable->logical_size) / ((double) hashtable->physical_size) >= CT_HASHTABLE_LOAD_THRESHOLD) {        \
            size_t index = 0;                                                                                                \
            unsigned int next_size = CT_HASHTABLE_GROWTH_FACTOR(hashtable->physical_size);                                   \
            struct bucket_name *new_buckets = (struct bucket_name*) calloc(next_size, sizeof(struct bucket_name));           \
                                                                                                                             \
            /* Add each old bucket into the new bucket array */                                                              \
            for(index = 0; index < hashtable->physical_size; index++) {                                                      \
                long temporary_hash = 0;                                                                                     \
                                                                                                                             \
                if(hashtable->buckets[index].state != CT_HASHTABLE_FILLED) {                                                 \
                    continue;                                                                                                \
                }                                                                                                            \
                                                                                                                             \
                temporary_hash = hash(hashtable->buckets[index].key) % next_size;                                            \
                                                                                                                             \
                /* Search the new buckets array for a new spot */                                                            \
                while(1) {                                                                                                   \
                    struct bucket_name new_bucket = new_buckets[temporary_hash];                                             \
                                                                                                                             \
                    if(new_bucket.state == CT_HASHTABLE_UNFILLED) {                                                          \
                        break;                                                                                               \
                    }                                                                                                        \
                                                                                                                             \
                    if(compare(new_bucket.key, hashtable->buckets[index].key) == 1) {                                        \
                        break;                                                                                               \
                    }                                                                                                        \
                                                                                                                             \
                    temporary_hash = ((temporary_hash + 1) % next_size);                                                     \
                }                                                                                                            \
                                                                                                                             \
                new_buckets[temporary_hash].key = hashtable->buckets[index].key;                                             \
                new_buckets[temporary_hash].value = hashtable->buckets[index].value;                                         \
                new_buckets[temporary_hash].state = CT_HASHTABLE_FILLED;                                                     \
            }                                                                                                                \
                                                                                                                             \
            free(hashtable->buckets);                                                                                        \
            hashtable->physical_size = next_size;                                                                            \
            hashtable->buckets = new_buckets;                                                                                \
        }                                                                                                                    \
                                                                                                                             \
        key_hash = (long) hash(key) % hashtable->physical_size;                                                              \
                                                                                                                             \
        /* Search the buckets array for a spot to put the new key value pair in */                                           \
        while(1) {                                                                                                           \
            struct bucket_name bucket = hashtable->buckets[key_hash];                                                        \
                                                                                                                             \
            if(bucket.state == CT_HASHTABLE_UNFILLED) {                                                                      \
                break;                                                                                                       \
            }                                                                                                                \
                                                                                                                             \
            if(compare(bucket.key, key) == 1) {                                                                              \
                break;                                                                                                       \
            }                                                                                                                \
                                                                                                                             \
            key_hash = ((key_hash + 1) % hashtable->physical_size);                                                          \
        }                                                                                                                    \
                                                                                                                             \
        if(hashtable->buckets[key_hash].state == CT_HASHTABLE_FILLED) {                                                      \
            free_value(hashtable->buckets[key_hash].value);                                                                  \
        } else {                                                                                                             \
            hashtable->logical_size++;                                                                                       \
        }                                                                                                                    \
                                                                                                                             \
        hashtable->buckets[key_hash].key = key;                                                                              \
        hashtable->buckets[key_hash].value = value;                                                                          \
        hashtable->buckets[key_hash].state = CT_HASHTABLE_FILLED;                                                            \
    }

#define ct_hashtable_define_lookup(hashtable_name, key_type, value_type, identifier, hash, compare)      \
    value_type identifier##_hashtable_lookup(struct hashtable_name *hashtable, key_type key) {           \
        long key_hash = hash(key) % hashtable->physical_size;                                            \
                                                                                                         \
        while(1) {                                                                                       \
            if(hashtable->buckets[key_hash].state == CT_HASHTABLE_UNFILLED) {                            \
                fprintf(stderr, "%s", #identifier "_hashtable_lookup: attempt to lookup invalid key\n"); \
                exit(EXIT_FAILURE);                                                                      \
            }                                                                                            \
                                                                                                         \
            if(compare(hashtable->buckets[key_hash].key, key) == 1) {                                    \
                break;                                                                                   \
            }                                                                                            \
                                                                                                         \
            key_hash = ((key_hash + 1) % hashtable->physical_size);                                      \
        }                                                                                                \
                                                                                                         \
        return hashtable->buckets[key_hash].value;                                                       \
    }

#define ct_hashtable_define_contains(hashtable_name, key_type, identifier, hash, compare)                \
    int identifier##_hashtable_contains(struct hashtable_name *hashtable, key_type key) {                \
        long key_hash = hash(key) % hashtable->physical_size;                                            \
                                                                                                         \
        while(1) {                                                                                       \
            if(hashtable->buckets[key_hash].state == CT_HASHTABLE_UNFILLED) {                            \
                return 0;                                                                                \
            }                                                                                            \
                                                                                                         \
            if(compare(hashtable->buckets[key_hash].key, key) == 1) {                                    \
                break;                                                                                   \
            }                                                                                            \
                                                                                                         \
            key_hash = ((key_hash + 1) % hashtable->physical_size);                                      \
        }                                                                                                \
                                                                                                         \
        return 1;                                                                                        \
    }

#endif
