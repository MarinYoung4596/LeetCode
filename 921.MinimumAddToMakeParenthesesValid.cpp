/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    921.MinimumAddToMakeParenthesesValid.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/01/02 21:48:51
*   @brief:

A parentheses string is valid if and only if:
    It is the empty string,
    It can be written as AB (A concatenated with B), where A and B are valid strings, or
    It can be written as (A), where A is a valid string.

    You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
    For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
    Return the minimum number of moves required to make s valid.


Example 1:
    Input: s = "())"
    Output: 1

Example 2:
    Input: s = "((("
    Output: 3


Constraints:
    1 <= s.length <= 1000
    s[i] is either '(' or ')'.

*****************************************************************/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int result = 0;
        int left_num = 0;
        for (auto ch : s) {
            if (ch == '(') {
                ++left_num;
            } else if (ch == ')') {
                --left_num;
                if (left_num == -1) {  // 不合法,相当于从头开始计数
                    left_num = 0;
                    ++result;
                }
            }
        }
        return left_num + result;
    }
};
