/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    400.NthDigit
*   @author:  marinyoung@163.com
*   @date:    2023/10/26 21:29:51
*   @brief:

Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].

Example 1:
    Input: n = 3
    Output: 3

Example 2:
    Input: n = 11
    Output: 0
    Explanation: The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.

Constraints:
    1 <= n <= 2^31 - 1
*****************************************************************/

class Solution {
public:
    /*
    1位：9
    2位：99-10+1 = 90
    3位：999-100+1 = 900
    ...
    */
    int findNthDigit(int n) {
        uint64_t cnt = 9;  // 代表数字的个数
        uint64_t digit = 1; // 代表是几位数（也即数字转成 str 之后的长度）
        while (n > cnt * digit) {
            n -= cnt * digit;
            cnt *= 10;
            ++digit;
        }
        uint64_t base = pow(10, digit - 1); // digit 位数的最小值 100……000
        uint64_t number = base + (n - 1) / digit;  // n-th个数字 所在的数（因为每个数字都有digit位，所以要除以 digit）

        auto idx = (n - 1) % digit;  // 在 number中的 index
        return std::to_string(number)[idx] - '0';
    }
};