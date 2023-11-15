/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    1624.LargestSubstringBetweenTwoEqualCharacters.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/15 00:02:13
*   @brief:

Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.

A substring is a contiguous sequence of characters within a string.


Example 1:
    Input: s = "aa"
    Output: 0
    Explanation: The optimal substring here is an empty substring between the two 'a's.

Example 2:
    Input: s = "abca"
    Output: 2
    Explanation: The optimal substring here is "bc".

Example 3:
    Input: s = "cbzxy"
    Output: -1
    Explanation: There are no characters that appear twice in s.


Constraints:
    1 <= s.length <= 300
    s contains only lowercase English letters.

*****************************************************************/


class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> pos_map(26, -1);
        int result = -1;
        for (auto i = 0; i < s.size(); ++i) {
            auto ch = s[i] - 'a';
            if (pos_map[ch] != -1) {
                result = max(result, i - pos_map[ch] - 1);
            } else {
                pos_map[ch] = i;
            }
        }
        return result;
    }
};