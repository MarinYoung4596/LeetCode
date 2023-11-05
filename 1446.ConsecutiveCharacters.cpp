/*****************************************************************
*   Copyright (C) 2022 All rights reserved.
*
*   @file:    1446.ConsecutiveCharacters.cpp
*   @author:  marinyoung@163.com
*   @date:    2022/12/10 17:41:25
*   @brief:

The power of the string is the maximum length of a non-empty substring that contains only one unique character.
Given a string s, return the power of s.


Example 1:
    Input: s = "leetcode"
    Output: 2
    Explanation: The substring "ee" is of length 2 with the character 'e' only.

Example 2:
    Input: s = "abbcccddddeeeeedcba"
    Output: 5
    Explanation: The substring "eeeee" is of length 5 with the character 'e' only.

Constraints:
    1 <= s.length <= 500
    s consists of only lowercase English letters.

*****************************************************************/


class Solution {
public:
    int maxPower(string s) {
        auto max_len = 0;
        auto pre = 0;
        auto cur = 0;
        while (pre < s.size()) {
            while (cur < s.size() && s[cur] == s[pre]) {
                ++cur;
            }
            max_len = std::max(max_len, cur - pre);
            pre = cur;
        }
        return max_len;
    }
};