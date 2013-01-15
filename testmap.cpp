#include "kvset.hpp"
#include "testmap.hpp"

/** @file
 * @brief provide C interface to testmap
 * @note this has to be compiled using a C++ compiler, but functions are to be used in C
 */

extern "C" {
KVSet* new_cppset_default() {
	return make_kv_set<testmap>();
}

} /* extern "C" */
