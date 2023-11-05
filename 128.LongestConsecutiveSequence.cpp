/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:
    Input: [100, 4, 200, 1, 3, 2]
    Output: 4
    Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

*/

// First Solution:
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int, bool> cache;
        for (const auto &x : nums) {
            cache[x] = false;
        }

        int result = 0;
        for (auto i = 0; i < nums.size(); ++i) {
            if (cache[nums[i]]) {
                continue; // 说明之前已经遍历过了，没必要再去遍历
            }
            int subres = 1;
            for (auto j = nums[i] + 1; cache.count(j) > 0; ++j, ++subres) {
                cache[j] = true;
            }
            for (auto j = nums[i] - 1; cache.count(j) > 0; --j, ++subres) {
                cache[j] = true;
            }
            result = std::max(result, subres);
        }
        return result;
    }
};

// second solution: Union Find ?