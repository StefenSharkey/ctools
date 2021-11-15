#ifndef CT_HASHTABLE_COMMON_H
#define CT_HASHTABLE_COMMON_H

#include "../hashtable.h"

ct_hashtable_define_bucket(StringIntBucket, char*, int);
ct_hashtable_define_hashtable(StringIntTable, StringIntBucket);

#endif
