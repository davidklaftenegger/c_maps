#ifndef __TEST_KVSET_H__
#define __TEST_KVSET_H__

#ifdef __cplusplus
/* allow this header to be used verbatim in C++ code */
extern "C" {
#endif

#include "kvset.h"

void test_general_kvset_properties(KVSet * (*create_kvset_fun)());

void test_ordered_kvset_properties(KVSet * (*create_kvset_fun)());

void test_unordered_kvset_properties(KVSet * (*create_kvset_fun)());

#ifdef __cplusplus
/* see top, C++ compatibility */
}
#endif

#endif
