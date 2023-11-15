/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.


Example 1:
    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]

Example 2:
    Input: nums = [1], k = 1
    Output: [1]


Constraints:
    1 <= nums.length <= 10^5
    -10^4 <= nums[i] <= 10^4
    k is in the range [1, the number of unique elements in the array].
    It is guaranteed that the answer is unique.


Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

/* First Solution: using vector (linear array), 842ms in total*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> mapping;
        auto iter_map = mapping.begin();
        for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
            iter_map = find_if(mapping.begin(), mapping.end(), [&](const pair<int, int> &x) {
                return x.first == *iter;
            });
            if (iter_map != mapping.end()) {
                ++iter_map->second;
            } else {
                mapping.push_back({*iter, 1});
            }
        }
        std::sort(mapping.begin(), mapping.end(),
            [&](const pair<int, int> &x, const pair<int, int> &y) {
            return x.second > y.second;
        });

        vector<int> res;
        auto i = 0;
        for (auto iter = mapping.begin(); iter != mapping.end() && i < k; ++i, ++iter) {
            res.push_back(iter->first);
        }
        return res;
    }
};

/*Second Solution: using map (rb-tree) & unordered_map (hash-table)*/
class Solution2 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um; // <key, freq>
        for (auto &x : nums) {
            um[x]++;
        }
        multimap<int,int, greater<int>> mm; // <freq, key>
        for (auto it = um.begin(); it != um.end(); ++it) {
            mm.insert({it->second, it->first});
        }
        vector<int> res; // <key>
        for (auto it = mm.begin(); k != 0 && it != mm.end(); --k, ++it) {
            res.push_back(it->second);
        }
        return res;
    }
};

/*Third Solution: using priority queue (max heap) ===> O(n log k )*/


/*Forth Solution: using partition */