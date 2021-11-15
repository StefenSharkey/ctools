#ifndef CT_ARRAY_COMMON_H
#define CT_ARRAY_COMMON_H

#include "../array.h"

static void free_string(const char *string) {
    return;
}

ct_array_define_array(StringArray, char*);
static ct_array_define_init(StringArray, char*, string)
static ct_array_define_free(StringArray, string, free_string)

#endif
