/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    32.LongestValidParentheses.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/01/02 21:42:51
*   @brief:

Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses
substring


Example 1:
    Input: s = "(()"
    Output: 2
    Explanation: The longest valid parentheses substring is "()".

Example 2:
    Input: s = ")()())"
    Output: 4
    Explanation: The longest valid parentheses substring is "()()".

Example 3:
    Input: s = ""
    Output: 0


Constraints:
    0 <= s.length <= 3 * 10^4
    s[i] is '(', or ')'.

*****************************************************************/

class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        stack<int> bracket_stack;
        bracket_stack.push(-1);

        for (auto i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                bracket_stack.push(i); // 存储的是合法序列的 index
            } else if (s[i] == ')') {
                bracket_stack.pop();
                if (bracket_stack.empty()) {
                    bracket_stack.push(i);  // 用于下一次计算合法子串长度的起始位置
                }
                result = max(result, i - bracket_stack.top());
            }
        }
        return result;
    }
};
