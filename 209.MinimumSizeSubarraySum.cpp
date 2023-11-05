/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 
    Input: s = 7, nums = [2,3,1,2,4,3]
    Output: 2
    Explanation: the subarray [4,3] has the minimal length under the problem constraint.

Follow up:
    If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
*/


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int left = 0;
        int right = 0;

        auto result = 0;
        auto sub_sum = 0;
        while (right < nums.size()) {
            sub_sum += nums[right];
            ++right;

            while (sub_sum >= s) {
                result = result > 0 ? std::min(result, right - left) : right - left;
                sub_sum -= nums[left];
                ++left;
            }
        }
        return result;
    }
};