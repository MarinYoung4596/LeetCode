/*****************************************************************
*   Copyright (C) 2022 All rights reserved.
*
*   @file:    704.BinarySearch.cpp
*   @author:  marinyoung@163.com
*   @date:    2022/11/26 21:03:13
*   @brief:

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
    Input: nums = [-1,0,3,5,9,12], target = 9
    Output: 4
    Explanation: 9 exists in nums and its index is 4

Example 2:
    Input: nums = [-1,0,3,5,9,12], target = 2
    Output: -1
    Explanation: 2 does not exist in nums so return -1

Constraints:
    1 <= nums.length <= 10^4
    -10^4 < nums[i], target < 10^4
    All the integers in nums are unique.
    nums is sorted in ascending order.

*****************************************************************/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int begin = 0;
        int end = nums.size() - 1;
        while (begin < end) {  // 不能等于，否则无法退出循环
            int mid = begin + (end - begin) / 2;  // 重要，否则会溢出
            // printf("begin=%d end=%d mid=%d\n", begin, end, mid);
            if (nums[mid] < target) {
                begin = mid + 1;  // 重要，否则会陷入死循环
            } else if (nums[mid] > target) {
                end = mid;
            } else {
                return mid;
            }
        }
        return nums[begin] == target ? begin : -1;
    }
};
