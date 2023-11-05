/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    380.InsertDeleteGetRandomO1.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/08/29 00:31:10
*   @brief:

Implement the RandomizedSet class:

    RandomizedSet() Initializes the RandomizedSet object.
    bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
    bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
    int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.

You must implement the functions of the class such that each function works in average O(1) time complexity.


Example 1:
    Input
        ["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
        [[], [1], [2], [2], [], [1], [2], []]
    Output
        [null, true, false, true, 2, true, false, 2]

Explanation
    RandomizedSet randomizedSet = new RandomizedSet();
    randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
    randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
    randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
    randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
    randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
    randomizedSet.insert(2); // 2 was already in the set, so return false.
    randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.


Constraints:
    -2^31 <= val <= 2^31 - 1
    At most 2 * 10^5 calls will be made to insert, remove, and getRandom.
    There will be at least one element in the data structure when getRandom is called.

*****************************************************************/

class RandomizedSet {
public:
    RandomizedSet() {

    }

    bool insert(int val) {
        if (value_to_index.count(val) > 0) {  // 已存在
            return false;
        }
        nums.push_back(val);  // 直接插入在尾部
        value_to_index[val] =  nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (value_to_index.find(val) == value_to_index.end()) { // 不存在
            return false;
        }

        // 把要删除的元素和尾部元素交换位置，同时更新尾部元素在map中的下标
        auto index = value_to_index[val];
        auto tail_value = nums.back();
        std::swap(nums[index], nums[nums.size() - 1]);

        value_to_index[tail_value] = index;

        nums.pop_back();
        value_to_index.erase(val);

        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }

private:
    vector<int> nums;
    unordered_map<int, int> value_to_index; // 存储每个 value 在 nums 中的下标
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */