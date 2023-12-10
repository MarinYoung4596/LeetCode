/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    1493.LongestSubarrayOf1AfterDeletingOneElement.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/11 23:44:54
*   @brief:

Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.


Example 1:
    Input: nums = [1,1,0,1]
    Output: 3
    Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

Example 2:
    Input: nums = [0,1,1,1,0,1,1,0,1]
    Output: 5
    Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

Example 3:
    Input: nums = [1,1,1]
    Output: 2
    Explanation: You must delete one element.


Constraints:
    1 <= nums.length <= 10^5
    nums[i] is either 0 or 1.

*****************************************************************/

#include "util.h"
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        auto left = 0;
        auto right = 0;
        auto zero_cnt = 0;
        auto range_sum = 0;
        auto result = 0;
        while (right < nums.size()) {
            if (!nums[right]) {
                ++zero_cnt;
            }
            range_sum += nums[right];
            if (zero_cnt == 0) {
                result = max(result, range_sum - 1);
            } else if (zero_cnt == 1) {
                result = max(result, range_sum);
            } else {
                while (zero_cnt > 1) {
                    if (!nums[left]) {
                        --zero_cnt;
                    }
                    range_sum -= nums[left];
                    ++left;
                    result = max(result, range_sum);
                }
            }
            ++right;
        }
        return result;
    }
};

int main() {
    Solution obj;
    vector<int> vec= {0,1,1,1,0,0,1,1,0};
    cout << obj.longestSubarray(vec) << endl;
    return 0;
}