/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.


Example 1:
    Input: nums = [1,2,3,1], k = 3
    Output: true

Example 2:
    Input: nums = [1,0,1,1], k = 1
    Output: true

Example 3:
    Input: nums = [1,2,3,1,2,3], k = 2
    Output: false


Constraints:
    1 <= nums.length <= 10^5
    -10^9 <= nums[i] <= 10^9
    0 <= k <= 10^5
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.empty()) {
            return false;
        }

        map<int, vector<int>::iterator> um;
        for (auto i = nums.begin(); i != nums.end(); ++i) {
            if (um.find(*i) == um.end()) {
                um.insert({ *i, i });
            } else {
                if (i - um[*i] <= k) {
                    return true;
                }
                um[*i] = i;  // update position
            }
        }
        return false;
    }
};