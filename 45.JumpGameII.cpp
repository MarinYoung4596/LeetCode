/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.

Example:
Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.


Note:
You can assume that you can always reach the last index.

*/


// First Solution: Time Limit Exceeded
class Solution {
public:
    int jump(vector<int>& nums) {
        std::vector<int> cache(nums.size(), INT_MAX);
        return dp(nums, cache, 0);
    }

private:
    // 从位置p跳到末尾，最少需要的步数
    int dp(const std::vector<int> &nums,
           std::vector<int> cache,
           int p) {
        if (p >= nums.size() - 1) {
            return 0;
        }
        if (cache[p] != INT_MAX) { // 缓存的子问题的解
            return cache[p];
        }
        // 递归，相当于从后往前找；
        for (auto step = 1; step <= nums[p]; ++step) {
            auto subres = dp(nums, cache, p + step);
            cache[p] = min(cache[p], subres + 1); // 选取最小的
        }
        return cache[p];
    }
};


// Second Solution : Greedy search
class Solution2 {
public:
    int jump(vector<int>& nums) {
        int end = 0;
        int farthest = 0;
        int result = 0;
        for (auto i = 0; i < nums.size() - 1; ++i) { // 注意，不用走到n
            farthest = std::max(farthest, i + nums[i]);
            if (end == i) { //
                end = farthest;
                ++result;
            }
        }
        return result;
    }
};