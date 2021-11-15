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

#endif
