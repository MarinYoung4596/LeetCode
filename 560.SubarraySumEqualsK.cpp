/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.


Example 1:
    Input:nums = [1,1,1], k = 2
    Output: 2

Example 2:
    Input: nums = [1,2,3], k = 3
    Output: 2


Constraints:
    1 <= nums.length <= 2 * 10^4
    -1000 <= nums[i] <= 1000
    -10^7 <= k <= 10^7

Hints:
    1) Will Brute force work here? Try to optimize it.
    2) Can we optimize it by using some extra space?
    3) What about storing sum frequencies in a hash table? Will it be useful?
    4) sum(i,j)=sum(0,j)-sum(0,i), where sum(i,j) represents the sum of all the elements from index i to j-1. Can we use this property to optimize it.
*/


// First Solution: Time Limit Exceeded
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()) {
            return 0;
        }
        auto result = 0;
        vector<int> sumi(nums);
        for (auto i = 1; i < nums.size(); ++i) {
            sumi[i] += sumi[i - 1];
        }
        // sum(i,j)=sum(0,j)-sum(0,i),
        // where sum(i,j) represents the sum of all the elements from index i to j-1
        for (auto i = 0; i < sumi.size(); ++i) {
            if (sumi[i] == k) {
                ++result;
            }
            for (auto j = 0; j < i;  ++j) {
                auto sub_sum = sumi[i] - sumi[j];
                if (sub_sum == k) {
                    ++result;
                }
            }
        }
        return result;
    }
};

// second Solution: 前缀和数组解决, Time Limit Exceeded
class Solution2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix_sum(nums.size() + 1, 0);

        for (auto i = 0; i < nums.size(); ++i) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }

        int result = 0;
        for (auto i = 0; i < nums.size(); ++i) {
            for (auto j = i; j < nums.size(); ++j) {
                if (prefix_sum[j + 1] - prefix_sum[i] == k) {
                    ++result;
                }
            }
        }
        return result;
    }
};

// Third Solution: 通过 hash_table 记录前缀和。如果当前前缀和 - k 已经存在，说明二者的差刚好是 k
class Solution3 {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_freq_map;  // prefix_sum : freq
        prefix_freq_map[0] = 1;

        int result = 0;
        int prefix_sum = 0;
        for (auto x : nums) {
            prefix_sum += x;
            auto key = prefix_sum - k;  // 如果key在map中，说明这俩的差刚好是 k
            if (prefix_freq_map.count(key) > 0) {
                result += prefix_freq_map[key];
            }
            prefix_freq_map[prefix_sum]++;
        }
        return result;
    }
};