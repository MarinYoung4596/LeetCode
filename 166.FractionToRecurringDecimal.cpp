/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    166.FractionToRecurringDecimal.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/19 17:25:56
*   @brief:

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than 10^4 for all the given inputs.


Example 1:
    Input: numerator = 1, denominator = 2
    Output: "0.5"

Example 2:
    Input: numerator = 2, denominator = 1
    Output: "2"

Example 3:
    Input: numerator = 4, denominator = 333
    Output: "0.(012)"


Constraints:
    -2^31 <= numerator, denominator <= 2^31 - 1
    denominator != 0

*****************************************************************/


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // 确定符号
        string sign = "";
        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) {
            sign = "-";
        }
        // 转换成正数
        numerator = abs(numerator);
        denominator = abs(denominator);

        long integer = numerator / denominator;  // 整数部分
        long long_num = numerator - integer * denominator;  // 余数; 转换成long 格式，防止后续补0时溢出
        if (long_num == 0) { // 整除
            return sign + to_string(integer);
        }
        string decimal = "";  // 小数部分
        auto index = 0;
        auto repeat_index = -1;
        unordered_map<long, int> num_index_map;
        while (long_num != 0) {
            long_num *= 10; // 新的被除数
            if (num_index_map.count(long_num) > 0) {  // 被除数已经存在过
                repeat_index = num_index_map[long_num];
                break;
            }
            num_index_map[long_num] = index;
            auto cur_dec = long_num / denominator; // 商
            decimal += to_string(cur_dec);
            long_num -= cur_dec * denominator; // 余数
            ++index;
        }
        if (repeat_index != -1) {  // 存在循环小数，找到循环部分
            auto recurr_dec = decimal.substr(repeat_index, decimal.size() - repeat_index + 1);
            decimal = decimal.substr(0, repeat_index);
            decimal += "(" + recurr_dec + ")";
        }
        return sign + to_string(integer) + "." + decimal;
    }
};