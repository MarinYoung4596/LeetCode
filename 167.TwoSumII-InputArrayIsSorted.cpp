/*

Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;

        const auto n = numbers.size();
        if (n < 2) {
            return result;
        }

        int begin = 0, end = n - 1;
        while (begin < end) {
            int tmp = numbers[begin] + numbers[end];
            if (tmp > target) {
                --end;
            } else if (tmp < target) {
                ++begin;
            } else {
                return {begin + 1, end + 1};
            }
        }
        return result;
    }
};
