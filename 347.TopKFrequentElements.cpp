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
    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<pair<int, int>> mapping;
        auto iter_map = mapping.begin();
        for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
            iter_map = find_if(mapping.begin(), mapping.end(),
                               [&](const pair<int, int> &x) {
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
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> um; // <key, freq>
        for (auto &x : nums) {
            um[x]++;
        }
        multimap<int, int, greater<int>> mm; // <freq, key>
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

/**
 * Third Solution: using priority queue (max heap)
 * 时间：O(n log k)，beats 86.61% c++ users
 * 空间：beats 40.56% c++ users
 */
class Solution3 {
public:
    using int_pair = pair<int, int>;

    static bool freq_greater_func(const int_pair &lhs, const int_pair &rhs) {
        return lhs.second > rhs.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_freq_map;
        for (auto x : nums) {
            num_freq_map[x]++;
        }
        priority_queue<int_pair, vector<int_pair>, decltype(&freq_greater_func)> my_heap(freq_greater_func);
        for (auto& [num, freq] : num_freq_map) {
            if (my_heap.size() < k) {
                my_heap.push(make_pair(num, freq));
            } else {
                if (freq > my_heap.top().second) {
                    my_heap.pop();
                    my_heap.push(make_pair(num, freq));
                }
            }
        }
        vector<int> result;
        while (!my_heap.empty()) {
            result.push_back(my_heap.top().first);
            my_heap.pop();
        }
        return result;
    }
};

/**
 * Forth Solution: using partition
 * 时间：beats 50.78% c++ users
 * 空间：beats 27.24% c++ users
 */
class Solution4 {
public:
    using int_pair = pair<int, int>;

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_freq_map;
        for (auto x : nums) {
            num_freq_map[x]++;
        }
        vector<int_pair> vec;
        for (auto &kv : num_freq_map) {
            vec.push_back(kv);
        }
        int begin = 0;
        int end = vec.size() - 1;
        auto idx = partition(vec, begin, end);
        while (idx != k - 1) {
            if (idx < k - 1) {
                begin = idx + 1;
            } else if (idx > k - 1) {
                end = idx - 1;
            }
            idx = partition(vec, begin, end);
        }
        vector<int> result;
        for (auto i = 0; i < k; ++i) {
            result.push_back(vec[i].first);
        }
        return result;
    }

private:
    int partition(vector<int_pair> &v, int begin, int end) {
        auto pivot = v[begin];
        while (begin < end) {
            while (begin < end && pivot.second >= v[end].second) {
                --end;
            }
            swap(v[begin], v[end]);
            while (begin < end && v[begin].second >= pivot.second) {
                ++begin;
            }
            swap(v[begin], v[end]);
        }
        return begin;
    }
};