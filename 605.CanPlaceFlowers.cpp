/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    605.CanPlaceFlowers.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/22 15:02:24
*   @brief:

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.


Example 1:
    Input: flowerbed = [1,0,0,0,1], n = 1
    Output: true

Example 2:
    Input: flowerbed = [1,0,0,0,1], n = 2
    Output: false


Constraints:
    1 <= flowerbed.length <= 2 * 10^4
    flowerbed[i] is 0 or 1.
    There are no two adjacent flowers in flowerbed.
    0 <= n <= flowerbed.length

*****************************************************************/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int idx = 0;
        while (idx < flowerbed.size() && n > 0) {
            if (flowerbed[idx] == 1) {
                idx += 2;
                continue;
            }

            if (idx == 0) {
                if ((idx + 1 < flowerbed.size() && flowerbed[idx + 1] == 0) || idx + 1 == flowerbed.size()) {
                    --n;
                    idx += 2;
                } else {
                    ++idx;
                }
            } else if (idx == flowerbed.size() - 1) {
                if (idx - 1 >= 0 && flowerbed[idx - 1] == 0) {
                    --n;
                    idx += 2;
                } else {
                    ++idx;
                }
            } else {
                if (flowerbed[idx - 1] == 0 && flowerbed[idx + 1] == 0) {
                    --n;
                    idx += 2;
                } else {
                    ++idx;
                }
            }
        }
        return !n;
    }
};