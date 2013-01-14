#include "kvset.hpp"
#include "testmap.hpp"

/** @file
 * @brief provide C interface to testmap
 * @note this has to be compiled using a C++ compiler, but functions are to be used in C
 */

extern "C" {
int compare(Eterm*, Eterm*);

KVSet* new_cppset() {
	typedef Eterm* K;
	typedef standard_functions<K, void*, compare, malloc_function, free_function> F;
	typedef testmap<K,F> M;
	return make_kv_set<M>();
}

KVSet* new_cppset_default() {
	return make_kv_set<testmap>();
}

} /* extern "C" */
