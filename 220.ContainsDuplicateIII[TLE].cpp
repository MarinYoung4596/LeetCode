/*
220. Contains Duplicate III

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
*/
// First Solution: O(N^2), Time Limit Exceeded
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // abs(i-j) <= k
        // abs(nums[i]-nums[j]) <= t
        
        const int n = nums.size();
        for (auto i = 0; i < n; ++i) {
            for (auto j = i + 1; j < n && j < (i + k + 1); ++j) {
                long long difference = abs(nums[i] - nums[j]);
                if (difference <= t) {
                    return true;
                }
            }
        }
        return false;
    }
};
