/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    442.FindAllDuplicatesInAnArray.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/15 22:56:03
*   @brief:
*
*****************************************************************/

// 原地 hash，相似题目：448
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for (auto i = 0; i < nums.size(); ++i) {
            auto idx = abs(nums[i]) - 1;
            if (nums[idx] > 0) {
                nums[idx] *= (-1);
            } else {
                result.push_back(idx + 1);
            }
        }
        return result;
    }
};