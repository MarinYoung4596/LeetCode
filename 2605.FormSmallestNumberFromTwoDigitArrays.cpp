/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    998.MaximumBinaryTreeII.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/03/25 23:31:40
*   @brief:

Given two arrays of unique digits nums1 and nums2, return the smallest number that contains at least one digit from each array.


Example 1:
    Input: nums1 = [4,1,3], nums2 = [5,7]
    Output: 15
    Explanation: The number 15 contains the digit 1 from nums1 and the digit 5 from nums2. It can be proven that 15 is the smallest number we can have.

Example 2:
    Input: nums1 = [3,5,2,6], nums2 = [3,1,7]
    Output: 3
    Explanation: The number 3 contains the digit 3 which exists in both arrays.


Constraints:
    1 <= nums1.length, nums2.length <= 9
    1 <= nums1[i], nums2[i] <= 9
    All digits in each array are unique.
*****************************************************************/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minNumber(vector<int> &nums1, vector<int> &nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        vector<int> inter(std::min(nums1.size(), nums2.size()), 0);
        auto it = std::set_intersection(nums1.begin(), nums1.end(),
                                        nums2.begin(), nums2.end(),
                                        inter.begin());
        inter.resize(it - inter.begin());
        if (!inter.empty()) {
            std::sort(inter.begin(), inter.end());
            return inter[0];
        }
        auto min_value = std::min(nums1[0], nums2[0]);
        auto max_value = std::max(nums1[0], nums2[0]);
        return min_value * 10 + max_value;
    }
};

int main() {
    vector<int> nums1 = {3,5,2,6};
    vector<int> nums2 = {3,1,7};
    Solution obj;
    auto out = obj.minNumber(nums1, nums2);
    std::cout << out << std::endl;

    return 0;
}