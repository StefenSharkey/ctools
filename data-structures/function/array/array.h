/*
 * A function-based, ANSI C compliant dynamic array implementation
*/

#ifndef CT_ARRAY_H
#define CT_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

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

#endif
