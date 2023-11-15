/*
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.


Example 1:
    Input: nums = [4,3,2,7,8,2,3,1]
    Output: [5,6]

Example 2:
    Input: nums = [1,1]
    Output: [2]


Constraints:
    n == nums.length
    1 <= n <= 10^5
    1 <= nums[i] <= n


Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.


Hint:
    This is a really easy problem if you decide to use additional memory. For those trying to write an initial solution using additional memory, think counters!
    However, the trick really is to not use any additional space than what is already available to use. Sometimes, multiple passes over the input array help find the solution. However, there's an interesting piece of information in this problem that makes it easy to re-use the input array itself for the solution.
    The problem specifies that the numbers in the array will be in the range [1, n] where n is the number of elements in the array. Can we use this information and modify the array in-place somehow to find what we need?

*/


// 原地哈希，相似题目：442
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (auto i = 0; i < nums.size(); ++i) {
            auto index = abs(nums[i]) - 1;
            if (nums[index] > 0) {
                nums[index] *= -1;
            }
        }
        std::vector<int> result;
        for (auto i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                continue;
            }
            result.push_back(i + 1);  // 没有置为负数的，说明该下标的元素值肯定缺失
        }
        return result;
    }
};