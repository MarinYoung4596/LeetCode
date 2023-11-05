/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.


Example 1:
    Input: nums = [1,2,3,1]
    Output: true

Example 2:
    Input: nums = [1,2,3,4]
    Output: false

Example 3:
    Input: nums = [1,1,1,3,3,4,3,2,4,2]
    Output: true


Constraints:
    1 <= nums.length <= 10^5
    -10^9 <= nums[i] <= 10^9
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for (auto i = nums.begin(); i != nums.end(); ++i) {
            if (us.find(*i) == us.end()) {
                us.insert(*i);
            } else {
                return true;
            }
        }
        return false;
    }
};