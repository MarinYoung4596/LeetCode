/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    916.WordSubsets.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/10/18 23:09:17
*   @brief:

You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".

A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.


Example 1:
    Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
    Output: ["facebook","google","leetcode"]

Example 2:
    Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
    Output: ["apple","google","leetcode"]


Constraints:
    1 <= words1.length, words2.length <= 10^4
    1 <= words1[i].length, words2[i].length <= 10
    words1[i] and words2[i] consist only of lowercase English letters.
    All the strings of words1 are unique.

*****************************************************************/

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // words2 中所有字符串，合并成一个 map
        vector<int> w2_merge_map(char_size, 0);
        for (const auto &w2 : words2) {
            auto w2_map = str2map(w2);
            for (auto i = 0; i < char_size; ++i) {
                w2_merge_map[i] = max(w2_merge_map[i], w2_map[i]);
            }
        }
        vector<string> result;
        for (const auto &w1 : words1) {
            auto w1_map = str2map(w1);
            auto valid = is_valid(w1_map, w2_merge_map);
            if (valid) {
                result.push_back(w1);
            }
        }
        return result;
    }

private:
    vector<int> str2map(const string &str) {
        vector<int> ch_freq_map(char_size, 0);
        for (const auto ch : str) {
            ch_freq_map[ch - 'a']++;
        }
        return std::move(ch_freq_map);
    }

    bool is_valid(const vector<int> &w1_map, const vector<int> &w2_map) {
        for (auto i = 0; i < char_size; ++i) {
            if (w1_map[i] < w2_map[i]) {
                return false;
            }
        }
        return true;
    }

private:
    const int char_size = 26;
};