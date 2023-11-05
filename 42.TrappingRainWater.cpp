/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
    Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/

class Solution {
public:
// 边界情况： 两边最低
/* water[i] = min(
               max(height[0..i]),  # 左边最高的柱子
               max(height[i..end]) # 右边最高的柱子
            ) - height[i]
*/
    int trap(vector<int>& height) {
        int water = 0;
        int left = 0;
        int right = height.size() - 1;
        int max_left = 0;
        int max_right = 0;
        while (left <= right) {
            if (height[left] <= height[right]) {  //left 往后走
                if (height[left] >= max_left) {
                    max_left = height[left];  //更新左边最大值
                } else {
                    water += (max_left - height[left]);  //否则剪掉当前值 （处于两个最大值中间）
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
