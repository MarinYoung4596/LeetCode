/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    315.CountOfSmallerNumbersAfterSelf.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/17 00:42:14
*   @brief:

Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].


Example 1:
    Input: nums = [5,2,6,1]
    Output: [2,1,1,0]
    Explanation:
        To the right of 5 there are 2 smaller elements (2 and 1).
        To the right of 2 there is only 1 smaller element (1).
        To the right of 6 there is 1 smaller element (1).
        To the right of 1 there is 0 smaller element.

Example 2:
    Input: nums = [-1]
    Output: [0]

Example 3:
    Input: nums = [-1,-1]
    Output: [0,0]


Constraints:
    1 <= nums.length <= 10^5
    -10^4 <= nums[i] <= 10^4

*****************************************************************/

#include "util.h"

#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;

/*
    First Solution: merge sort
*/

class Item {
public:
    Item(int v = 0, int p = 0) : val(v), pos(p) {}

public:
    int val;
    int pos;
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        vector<Item> vec; // val, pos
        for (auto i = 0; i < nums.size(); ++i) {
            vec.push_back(Item(nums[i], i));
        }
        merge_sort(vec, 0, vec.size() - 1, result);
        return result;
    }

private:
    void merge_sort(vector<Item> &vec, int left, int right, vector<int> &count) {
        if (right <= left) {
            return;
        }
        auto mid = left + (right - left) / 2;

        merge_sort(vec, left, mid, count);
        merge_sort(vec, mid + 1, right, count);
        merge(vec, left, mid, right, count);
    }

    void merge(vector<Item> &vec, int left, int mid, int right, vector<int> &count) {
        vector<Item> tmp(right - left + 1, Item());
        auto i = left;
        auto j = mid + 1;
        auto k = 0;
        while (i <= mid && j <= right) {
            if (vec[i].val <= vec[j].val) {  // Q1: 为啥这里需要有『=』才行
                count[vec[i].pos] += (j - mid - 1);
                tmp[k++] = vec[i++];
            } else {
                tmp[k++] = vec[j++]; // vec[j] 比 vec[i] 大，因此不算“右侧比vec[i]小的数”
            }
        }
        while (i <= mid) {
            count[vec[i].pos] += (j - mid - 1);  // 左半部分没遍历完。此时右半部分已经遍历完，意味着所有右半部分都比 vec[i] 要小（否则一定可以遍历完）
            tmp[k++] = vec[i++];
        }
        while (j <= right) {
            tmp[k++] = vec[j++];
        }
        for (auto x = 0; x < k; ++x) {
            vec[left + x] = tmp[x];
        }
    }
};

int main() {
    Solution obj;
    vector<int> test1 = {5, 2, 6, 1};  // expect output: [2, 1, 1, 0]
    auto res1 = obj.countSmaller(test1);
    print_vector(res1);

    vector<int> test2 = {-1, -1};     // expect output: [0, 0]
    auto res2 = obj.countSmaller(test2);
    print_vector(res2);

    vector<int> test3 = {7, 5, 6, 5, 2, 6, 5, 1};     // expect output: [7,2,4,2,1,2,1,0]
    auto res3 = obj.countSmaller(test3);
    print_vector(res3);

    return 0;
}
