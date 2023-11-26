/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    424.LongestRepeatingCharacterReplacement.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/23 23:23:50
*   @brief:

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.


Example 1:
    Input: s = "ABAB", k = 2
    Output: 4
    Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:
    Input: s = "AABABBA", k = 1
    Output: 4
    Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
        The substring "BBBB" has the longest repeating letters, which is 4.
        There may exists other ways to achieve this answer too.


Constraints:
    1 <= s.length <= 10^5
    s consists of only uppercase English letters.
    0 <= k <= s.length

*****************************************************************/


class Solution {
public:
    int characterReplacement(string s, int k) {
        int result = 0;
        int left = 0;
        int right = 0;
        int max_ch_freq = 0;   // 单个字符的最大长度
        unordered_map<char, int> ch_freq_map;  // 只允许有两个字符，并且最小的那个，频次 < k
        while (right < s.size()) {
            ch_freq_map[s[right]]++;
            max_ch_freq = max(max_ch_freq, ch_freq_map[s[right]]);
            right++;

            while (right - left - max_ch_freq > k) {
                ch_freq_map[s[left]]--;
                ++left;
            }
            result = max(result, right - left);
        }
        return result;
    }
};