/*
 * A function-based, ANSI C compliant dynamic array implementation
*/

#ifndef CT_ARRAY_H
#define CT_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Overload-able default size */
#ifndef CT_ARRAY_PHYSICAL_SIZE
#define CT_ARRAY_PHYSICAL_SIZE 5
#endif

/* Overload-able equation for changing the size */
#ifndef CT_ARRAY_GROWTH_FACTOR
#define CT_ARRAY_GROWTH_FACTOR(current_size) \
    ((current_size) * 2)
#endif

#define ct_array_define_array(array_name, array_type) \
    struct array_name {                               \
        unsigned int logical_size;                    \
        unsigned int physical_size;                   \
        array_type *contents;                         \
    }

#define ct_array_define_init(array_name, array_type, identifier)                                  \
    struct array_name *identifier##_array_init() {                                                \
        struct array_name *new_array = (struct array_name*) calloc(1, sizeof(struct array_name)); \
                                                                                                  \
        new_array->contents = (array_type*) calloc(CT_ARRAY_PHYSICAL_SIZE, sizeof(array_type));   \
        new_array->physical_size = CT_ARRAY_PHYSICAL_SIZE;                                        \
                                                                                                  \
        return new_array;                                                                         \
    }

#define ct_array_define_free(array_name, identifier, free_value) \
    void identifier##_array_free(struct array_name *array) {     \
        unsigned int index = 0;                                  \
                                                                 \
        for(index = 0; index < array->logical_size; index++) {   \
            free_value(array->contents[index]);                  \
        }                                                        \
                                                                 \
        free(array);                                             \
    }

#define ct_array_define_insert(array_name, array_type, identifier)                                                                                      \
    struct array_name *identifier##_array_insert(struct array_name* array, array_type value, unsigned int index) {                                      \
        if(index < 0 || index > array->logical_size) {                                                                                                  \
            fprintf(stderr, #identifier "_array_insert: attempt to insert outside the bounds of array (array: %p, index: %i)\n", (void*) array, index); \
            exit(EXIT_FAILURE);                                                                                                                         \
        }                                                                                                                                               \
                                                                                                                                                        \
        if(array->logical_size == array->physical_size) {                                                                                               \
            array->physical_size = CT_ARRAY_GROWTH_FACTOR(array->physical_size);                                                                        \
            array->contents = (array_type*) realloc(array->contents, sizeof(array_type) * array->physical_size);                                        \
        }                                                                                                                                               \
                                                                                                                                                        \
        memmove(array->contents + (index + 1), array->contents + index, sizeof(array_type) * (array->logical_size - index));                            \
        array->contents[index] = value;                                                                                                                 \
        array->logical_size++;                                                                                                                          \
                                                                                                                                                        \
        return array;                                                                                                                                   \
    }

#endif
