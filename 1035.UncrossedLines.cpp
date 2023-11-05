/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    1035.UncrossedLines.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/29 22:25:34
*   @brief:

You are given two integer arrays nums1 and nums2. We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.

We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:

    nums1[i] == nums2[j], and
    the line we draw does not intersect any other connecting (non-horizontal) line.

Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).

Return the maximum number of connecting lines we can draw in this way.


Example 1:
    (pic)
    Input: nums1 = [1,4,2], nums2 = [1,2,4]
    Output: 2
        Explanation: We can draw 2 uncrossed lines as in the diagram.
        We cannot draw 3 uncrossed lines, because the line from nums1[1] = 4 to nums2[2] = 4 will intersect the line from nums1[2]=2 to nums2[1]=2.

Example 2:
    Input: nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
    Output: 3

Example 3:
    Input: nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
    Output: 2


Constraints:
    1 <= nums1.length, nums2.length <= 500
    1 <= nums1[i], nums2[j] <= 2000

*****************************************************************/


class Solution {
public:
    // 最长公公子数组
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        const auto n1 = nums1.size();
        const auto n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (auto i = 1; i <= n1; ++i) {
            for (auto j = 1; j <= n2; ++j) {
                if (nums1[i - 1] != nums2[j - 1]) {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                } else {
                    auto pre = std::max(dp[i - 1][j], dp[i][j - 1]);
                    dp[i][j] = std::max(pre, dp[i - 1][j - 1] + 1);
                }
            }
        }
        return dp[n1][n2];
    }
};