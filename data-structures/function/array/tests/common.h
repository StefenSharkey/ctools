#ifndef CT_ARRAY_COMMON_H
#define CT_ARRAY_COMMON_H

#include "../array.h"

ct_array_define_array(StringArray, char*);
static ct_array_define_init(StringArray, char*, string);

#endif
