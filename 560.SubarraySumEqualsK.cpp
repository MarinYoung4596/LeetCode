/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.


Example 1:
Input:nums = [1,1,1], k = 2
Output: 2


Constraints:
    The length of the array is in range [1, 20,000].
    The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].


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
        std::vector<int> sumi(nums);
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