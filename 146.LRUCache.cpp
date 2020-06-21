/*
146. LRU Cache

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set. 

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item. 

*/


class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity) {}
    
    ~LRUCache() {}
    
    int get(int key) {
        auto it = address.find(key);
        if (it == address.end()) {
            return -1;
        }
        
        // put the current element at the head of list
        pair<int, int> p(key, address[key]->second);
        cache.erase(address[key]);
        cache.push_front(p);
        address[key] = cache.begin();
        
        return address[key]->second; // address[key]: iterator, get it's value (*iter).second == iter->second
    }
    
    void set(int key, int value) {
        if (address.find(key) == address.end()) { // doesn't exist
            if (cache.size() == cap) { // cache full
                auto key_back = cache.back().first;
                address.erase(key_back); // erase from the address
                cache.pop_back(); // remove tail
            }
        } else { // found : erase this node from list
            cache.erase(address[key]);
        }
        // insert at the front
        cache.push_front(std::pair<int,int>(key, value));
        address[key] = cache.begin(); // insert key and it's address in the map
    }

private:
    // maximum capacity
    int cap; 
    // the closer distance to the head, the more frequent the element uses
    std::list<pair<int, int>> cache;// key : value
    // save the key's position in the list
    std::unordered_map<int, std::list<std::pair<int,int>>::iterator> address;
};


int main() {
	LRUCache cache(4);
	cache.set(4, 1);
	cache.set(6, 8);
	cache.set(0, 9);
	cache.set(2, 4);
	cache.set(9, 6);

	std::cout << cache.get(2) << std::endl;
	cache.set(5, 2);
	std::cout << cache.get(5) << std::endl;

	cache.set(6, 7);
	std::cout << cache.get(6) << std::endl;

	cache.set(2, 1);
	cache.set(1, 1);
	cache.set(2, 3);
	cache.set(4, 1);

	std::cout << cache.get(1) << std::endl;
	std::cout << cache.get(2) << std::endl;
	
	return 0;
}
