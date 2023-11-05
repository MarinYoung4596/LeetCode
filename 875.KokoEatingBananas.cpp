/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    875.KokoEatingBananas.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/28 19:38:25
*   @brief:

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.


Example 1:
    Input: piles = [3,6,7,11], h = 8
    Output: 4

Example 2:
    Input: piles = [30,11,23,4,20], h = 5
    Output: 30

Example 3:
    Input: piles = [30,11,23,4,20], h = 6
    Output: 23


Constraints:
    1 <= piles.length <= 10^4
    piles.length <= h <= 10^9
    1 <= piles[i] <= 10^9

*****************************************************************/


class Solution {
public:
    // 相当于求左边界的二分查找
    int minEatingSpeed(vector<int>& piles, int h) {
        std::sort(piles.begin(), piles.end());
        uint64_t base = 0;
        uint64_t banana_cnt = std::accumulate(piles.begin(), piles.end(), base);
        int min_speed = banana_cnt / h;
        int left = std::max(1, min_speed);        // 最小速度，否则必然吃不完
        int right = piles[piles.size() - 1];      // 最大速度
        while (left < right) {
            auto mid = left + (right - left) / 2;
            auto cur_h = count_hours(piles, mid);
            if (cur_h < h) {  // 用时小于标准时间，说明速度快了
                right = mid;
            } else if (cur_h > h) { // 同理，说明速度慢了
                left = mid + 1;
            } else {
                right = mid;  // 相等时，更新右边界
            }
        }
        return left;
    }

private:
    int count_hours(const vector<int> &piles, int speed) {
        int hours = 0;
        for (auto banana_cnt : piles) {
            if (banana_cnt <= speed) {
                ++hours;
            } else {
                hours += static_cast<int>(banana_cnt / speed);
                hours += banana_cnt % speed > 0 ? 1 : 0;
            }
        }
        return hours;
    }
};
