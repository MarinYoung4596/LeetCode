/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    460.LFUCache.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/02/01 12:38:33
*   @brief:

Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:
    LFUCache(int capacity) Initializes the object with the capacity of the data structure.
    int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
    void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.

To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.


Example:
    Input
        ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
        [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
    Output
        [null, null, null, 1, null, -1, 3, null, -1, 3, 4]

    Explanation
        // cnt(x) = the use counter for key x
        // cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
        LFUCache lfu = new LFUCache(2);
        lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
        lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
        lfu.get(1);      // return 1
                         // cache=[1,2], cnt(2)=1, cnt(1)=2
        lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                         // cache=[3,1], cnt(3)=1, cnt(1)=2
        lfu.get(2);      // return -1 (not found)
        lfu.get(3);      // return 3
                         // cache=[3,1], cnt(3)=2, cnt(1)=2
        lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                         // cache=[4,3], cnt(4)=1, cnt(3)=2
        lfu.get(1);      // return -1 (not found)
        lfu.get(3);      // return 3
                         // cache=[3,4], cnt(4)=1, cnt(3)=3
        lfu.get(4);      // return 4
                         // cache=[4,3], cnt(4)=2, cnt(3)=3


Constraints:
    0 <= capacity <= 10^4
    0 <= key <= 10^5
    0 <= value <= 10^9
    At most 2 * 10^5 calls will be made to get and put.

*****************************************************************/

#include "util.h"
#include <list>

class Node {
public:
    Node() {}
    Node(int v, int f) : value(v), freq(f) {}
public:
    int value;
    int freq;
    std::list<int>::iterator addr;
};

class LFUCache {
public:
    LFUCache(int capacity) : cap(capacity) {
        min_freq = 0;
    }

    int get(int key) {
        auto iter = key_node_map.find(key);
        if (iter == key_node_map.end()) {
            return -1;
        }
        auto& node = iter->second;
        del_from_freq_map(node.freq, node);
        node.freq += 1;
        add_to_freq_map(node.freq, key);
        node.addr = freq_keys_map[node.freq].begin();  // 头部是最新添加的元素
        if (freq_keys_map[min_freq].empty()) {  // 更新 min_freq
            ++min_freq;
        }
        return node.value;
    }

    void put(int key, int value) {
        if (cap < 1) {
            return;
        }
        auto iter = key_node_map.find(key);
        if (iter == key_node_map.end()) {  // key不存在
            if (key_node_map.size() == cap) {
                auto& keys_list = freq_keys_map[min_freq];  // 从最低频的候选里删除
                auto del_key = keys_list.back();  // 最低频的可能有多个,删除最旧的那个(back 位置即是最旧的)
                keys_list.pop_back();   // 从 freq_keys_map 里移除
                key_node_map.erase(del_key);  // 从 key_node_map 里移除
            }
            Node node(value, 1);
            min_freq = 1;
            add_to_freq_map(min_freq, key);
            node.addr = freq_keys_map[1].begin();
            key_node_map[key] = node;
        } else {  // key存在，更新
            auto& node = iter->second;
            del_from_freq_map(node.freq, node);
            node.freq += 1;
            add_to_freq_map(node.freq, key);
            node.addr = freq_keys_map[node.freq].begin();
            node.value = value;
            if (freq_keys_map[min_freq].empty()) {  // 更新 min_freq
                ++min_freq;
            }
        }
    }

private:
    void add_to_freq_map(int freq, int key) {
        auto iter = freq_keys_map.find(freq);
        if (iter == freq_keys_map.end()) {
            auto keys_list = std::list<int>({key});
            freq_keys_map[freq] = keys_list;
        } else {
            auto& keys_list = iter->second;
            keys_list.push_front(key); // 添加到头部，最新的元素
        }
    }

    void del_from_freq_map(int freq, const Node &node) {
        auto iter = freq_keys_map.find(freq);
        if (iter == freq_keys_map.end()) {
            return;
        }
        auto& keys_list = iter->second;
        keys_list.erase(node.addr);
    }

private:
    std::unordered_map<int, Node> key_node_map;
    std::unordered_map<int, std::list<int>> freq_keys_map; // 同一freq 对应的 key 列表

    int cap = 0;
    int min_freq = INT_MAX;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int main() {
    LFUCache lfu(2);
    lfu.put(1, 1);
    lfu.put(2, 2);
    std::cout << lfu.get(1) << '\n';

    lfu.put(3, 3);
    std::cout << lfu.get(2) << '\n';
    std::cout << lfu.get(3) << '\n';

    lfu.put(4, 4);
    std::cout << lfu.get(1) << '\n';
    std::cout << lfu.get(3) << '\n';
    std::cout << lfu.get(4) << '\n';

    return 0;
}
