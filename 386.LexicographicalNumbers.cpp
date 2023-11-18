/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    386.LexicographicalNumbers.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/17 23:20:34
*   @brief:

Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space.


Example 1:
    Input: n = 13
    Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]

Example 2:
    Input: n = 2
    Output: [1,2]


Constraints:
    1 <= n <= 5 * 10^4

*****************************************************************/


/**
 * @brief First Solution: dfs, recursive based method
 * Time: O(N) beats 42.37 c++ users
 * Space: O(N)
 */
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (auto i = 1; i < 10; ++i) {
            dfs(n, i, result);
        }
        return result;
    }

private:
    void dfs(int n, int cur, vector<int> &result) {
        if (cur > n) {
            return;
        }
        result.push_back(cur);

        for (auto i = 0; i < 10; ++i) {
            auto val = cur * 10 + i;
            dfs(n, val, result);
        }
    }
};

/**
 * @brief Second Solution : iteration based method
 * time: O(N), beats 96.36% c++ users
 * space: O(1)
 */
class Solution2 {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int number = 1;
        for (auto i = 0; i < n; ++i) {
            result.push_back(number);
            if (number * 10 <= n) {
                number *= 10;
            } else {
                while (number % 10 == 9 || number + 1 > n) {
                    number /= 10;
                }
                ++number; // 进位
            }
        }
        return result;
    }
};