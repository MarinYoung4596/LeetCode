/*
Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).

Example 1:
    Input: [1,3,5,4,7]
    Output: 3
    Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3.
    Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4.


Example 2:
    Input: [2,2,2,2,2]
    Output: 1
    Explanation: The longest continuous increasing subsequence is [2], its length is 1.


Note: Length of the array will not exceed 10,000.
*/


// Runtime: 1496 ms, faster than 6.95% of C++ online submissions for Longest Continuous Increasing Subsequence.
// Memory Usage: 11 MB, less than 70.42% of C++ online submissions for Longest Continuous Increasing Subsequence.
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int result = 0;
        for (auto i = 0; i < nums.size(); ++i) {
            int subres = 1;
            for (auto j = 1; j <= i; ++j) {
                if (nums[j - 1] < nums[j]) {
                    ++subres;
                } else {
                    result = std::max(result, subres);
                    subres = 1;
                }
            }
            result = std::max(result, subres);
        }
        return result;
    }
};
