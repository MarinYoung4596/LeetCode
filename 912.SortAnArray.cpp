/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    912.SortAnArray.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/02/11 13:05:13
*   @brief:

Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.


Example 1:
    Input: nums = [5,2,3,1]
    Output: [1,2,3,5]
    Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

Example 2:
    Input: nums = [5,1,1,2,0,0]
    Output: [0,0,1,1,2,5]
    Explanation: Note that the values of nums are not necessairly unique.

Constraints:
    1 <= nums.length <= 5 * 10^4
    -5 * 10^4 <= nums[i] <= 5 * 10^4

*****************************************************************/

// First Solution: Quick Sort: TLE
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void quick_sort(vector<int> &v, int begin, int end) {
        if (begin >= end) {
            return;
        }
        auto k = partition(v, begin, end);
        quick_sort(v, begin, k - 1);
        quick_sort(v, k + 1, end);
    }

    int partition(vector<int>& nums, int begin, int end) {
        auto pivot = nums[begin];

        while (begin < end) {
            while (end > begin && nums[end] >= pivot) {
                --end;
            }
            std::swap(nums[begin], nums[end]);
            while (begin < end && nums[begin] <= pivot) {
                ++begin;
            }
            std::swap(nums[begin], nums[end]);
        }
        return begin;
    }
};


// Second Solution: merge_sort
class Solution2 {
public:
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void merge_sort(vector<int> &nums, int left, int right) {
        if (right <= left) {
            return;
        }
        auto mid = left + (right - left) / 2;
        merge_sort(nums, left, mid);
        merge_sort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    void merge(vector<int> &nums, int left, int mid, int right) {
        vector<int> temp(right - left + 1, 0);
        auto i = left;
        auto j = mid + 1;
        auto k = 0;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        while (j <= right) {
            temp[k++] = nums[j++];
        }
        for (i = 0; i < k; ++i) {
            nums[left + i] = temp[i];
        }
    }
};