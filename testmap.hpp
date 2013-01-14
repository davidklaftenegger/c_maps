#ifndef TESTMAP_HPP
#define TESTMAP_HPP

/**@file
 * @brief a testing data structure for ETS, implemented in C++
 * 
 * Note this is just a proof of concept
 */

#include<set>

template<typename KeyType = long*, class StdFuns = standard_functions<KeyType>>
class testmap {
	std::set<KeyType> m;
	public:
		testmap() : m() {}
		KeyType put(KeyType key)     {
			auto p = m.insert(key);
			if(!p.second) {
				auto r = *p.first;
				m.erase(p.first);
				m.insert(key);
				return r;
			}
			return nullptr;
		}
		bool put_new(KeyType key)    { bool r = m.count(key); if(!r) m.insert(key); return !r; }
		KeyType remove(KeyType key)  { auto it = m.find(key); auto r=*it; m.erase(it); return r; }
		KeyType lookup(KeyType key)  {
			auto it = m.find(key);
			if(it == m.end()) {
				return nullptr;
			}
			else {
				return *it;
			}
		}
		bool member(KeyType key)     { return m.count(key); }
		KeyType first()              { return *m.begin(); }
		KeyType last()               { return *m.rbegin(); }
		KeyType next(KeyType key)    {
			auto it = m.lower_bound(key);
			if(it != m.end()) {
				it = std::next(it);
				if(it != m.end()) {
					return *it;
				}
			}
			return nullptr;
		}
		KeyType previous(KeyType key){
			auto it = m.lower_bound(key);
			if(it != m.end()) {
				it = std::prev(it);
				if(it != m.end()) {
					return *it;
				}
			}
			return nullptr;
		}
};


#endif // TESTMAP_HPP
