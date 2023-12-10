/*
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.

Example 1:
    ![pic](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)
    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
    Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
        In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
    Input: height = [4,2,0,3,2,5]
    Output: 9


Constraints:
    n == height.length
    1 <= n <= 2 * 10^4
    0 <= height[i] <= 10^5
*/

/**
 * @brief 双指针，
 * 边界情况：两边最低
 * water[i] = min(
               max(height[0..i]),  # 左边最高的柱子
               max(height[i..end]) # 右边最高的柱子
            ) - height[i]
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int left = 0;
        int right = height.size() - 1;
        int max_left = 0;
        int max_right = 0;
        while (left <= right) {
            if (height[left] <= height[right]) {  // left 往后走
                if (height[left] >= max_left) {
                    max_left = height[left];  // 更新左边最大值
                } else {
                    water += (max_left - height[left]);  // 否则剪掉当前值 （处于两个最大值中间）
                }
                ++left;
            } else {
                if (height[right] >= max_right) {
                    max_right = height[right];
                } else {
                    water += (max_right - height[right]);
                }
                --right;
            }
        }
        return water;
    }
};
