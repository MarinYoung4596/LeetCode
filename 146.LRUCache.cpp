/*
146. LRU Cache

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

*/

#include <list>
#include "util.h"

class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity) {}

    ~LRUCache() {}

    int get(int key) {
        if (address.find(key) == address.end()) {
            return -1;
        }
        make_recently(key);  // 取完后，让她在头部
        return address[key]->second;
    }

    void put(int key, int value) {
        if (address.find(key) != address.end()) {  // 找到，先删除旧的，
            del_key(key);
        } else if (cap == cache.size()) {
            del_least_recently();  // cache已满, 删除最久未使用的
        }
        add_recently(key, value);  // 再插入新的
    }

private:
    void make_recently(int key) {  // 从原来的位置删除，然后插入到头部
        auto addr = address[key];
        auto value = addr->second;
        cache.erase(addr);
        auto node = make_pair(key, value);
        cache.push_front(node);
    }

    void add_recently(int key, int value) { // 直接插入到头部
        auto node = make_pair(key, value);
        cache.push_front(node);
        address[key] = cache.begin();
    }

    void del_key(int key) {
        auto iter = address.find(key);
        if (iter != address.end()) {
            auto addr = iter->second;
            cache.erase(addr);  // 从链表中删除
            address.erase(key);  // 从map 中删除
        }
    }

    void del_least_recently() {  // 删除最久未使用的:即链表头部
        auto head_node = cache.back();
        address.erase(head_node.first);
        cache.pop_back();
    }

private:
    // maximum capacity
    int cap;
    // the closer distance to the head, the more frequent the element uses (头部元素用的更频繁)
    list<pair<int, int>> cache;  // key : value
    // save the key's position in the list (存储每个 key 在链表中的位置)
    unordered_map<int, list<pair<int,int>>::iterator> address;
};


int main() {
    // test case 1
    LRUCache cache(4);
    cache.put(4, 1);
    cache.put(6, 8);
    cache.put(0, 9);
    cache.put(2, 4);
    cache.put(9, 6);

    cout << cache.get(2) << endl;  // 4
    cache.put(5, 2);
    cout << cache.get(5) << endl;  // 2

    cache.put(6, 7);
    cout << cache.get(6) << endl;  // 7

    cache.put(2, 1);
    cache.put(1, 1);
    cache.put(2, 3);
    cache.put(4, 1);

    cout << cache.get(1) << endl;  // 1
    cout << cache.get(2) << endl;  // 3

    // test case 2

    LRUCache cache2(2);
    cache2.put(1, 1);
    cache2.put(2, 2);
    cout << cache2.get(1) << endl; // 1

    cache2.put(3, 3);
    cout << cache2.get(2) << endl; // -1

    cache2.put(4, 4);
    cout << cache2.get(1) << endl; // -1
    cout << cache2.get(3) << endl; // 3
    cout << cache2.get(4) << endl; // 4

    return 0;
}
