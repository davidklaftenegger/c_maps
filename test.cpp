#include "kvset.hpp"
#include "testmap.hpp"
#include "test_kvset.h"

#include<iostream>

int main() {
	auto kvs = make_kv_set<testmap>();
	long a = 42;
//	long* i = &a;
//	std::cout << a << '\n';
//	kvs->funs.put(kvs, a);
//	std::cout << "fine" << '\n';
//	long* j = kvs->funs.lookup(kvs, a);
//	std::cout << j << '\n';
	destroy_kv_set(kvs);

	std::cout << "\n\n\n\033[32m ### STARTING TESTMAP TESTS! -- \033[m\n\n\n";

	test_general_kvset_properties(make_kv_set<testmap>);

	test_ordered_kvset_properties(make_kv_set<testmap>);

	std::cout << "\n\n\n\033[32m ### TESTMAP TESTS COMPLETED! -- \033[m\n\n\n";


	return 0;
}
