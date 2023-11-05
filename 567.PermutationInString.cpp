/*****************************************************************
*   Copyright (C) 2022 All rights reserved.
*
*   @file:    567.PermutationInString.cpp
*   @author:  marinyoung@163.com
*   @date:    2022/12/31 19:24:08
*   @brief:

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.


Example 1:
    Input: s1 = "ab", s2 = "eidbaooo"
    Output: true
    Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
    Input: s1 = "ab", s2 = "eidboaoo"
    Output: false


Constraints:
    1 <= s1.length, s2.length <= 10^4
    s1 and s2 consist of lowercase English letters.

*****************************************************************/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        unordered_map<char, int> s1_map;
        str_to_map(s1, s1_map);

        for (auto i = 0; i <= s2.size() - s1.size(); ++i) {
            auto tmp_str = s2.substr(i, s1.size());
            unordered_map<char, int> tmp_map;
            str_to_map(tmp_str, tmp_map);
            if (is_map_equal(s1_map, tmp_map)) {
                return true;
            }
        }
        return false;
    }

private:
    void str_to_map(const string &str, unordered_map<char, int> &cmap) {
        for (auto ch : str) {
            if (cmap.find(ch) != cmap.end()) {
                cmap[ch] += 1;
            } else {
                cmap[ch] = 1;
            }
        }
    }

    bool is_map_equal(const unordered_map<char, int> &target,
                      const unordered_map<char, int> &ours) {
        for (auto& [word, cnt] : target) {
            auto it = ours.find(word);
            if (it == ours.end() || it->second != cnt) {
                return false;
            }
        }
        return true;
    }
};
