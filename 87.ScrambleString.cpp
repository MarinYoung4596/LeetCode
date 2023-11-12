/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    87.ScrambleString.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/12 13:48:49
*   @brief:

We can scramble a string s to get a string t using the following algorithm:

    1. If the length of the string is 1, stop.
    2. If the length of the string is > 1, do the following:
        * Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
        * Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
        * Apply step 1 recursively on each of the two substrings x and y.

Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.


Example 1:
    Input: s1 = "great", s2 = "rgeat"
    Output: true
    Explanation: One possible scenario applied on s1 is:
        "great" --> "gr/eat" // divide at random index.
        "gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
        "gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at random index each of them.
        "g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
        "r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
        "r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
        The algorithm stops now, and the result string is "rgeat" which is s2.
        As one possible scenario led s1 to be scrambled to s2, we return true.

Example 2:
    Input: s1 = "abcde", s2 = "caebd"
    Output: false

Example 3:
    Input: s1 = "a", s2 = "a"
    Output: true


Constraints:
    s1.length == s2.length
    1 <= s1.length <= 30
    s1 and s2 consist of lowercase English letters.

*****************************************************************/


class Solution {
public:
    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> cache;  // 注意，这里必须要用记忆化的回溯，否则会超时
        return backtrack(s1, s2, cache);
    }

private:
    bool backtrack(const string &s1, const string &s2,
                   unordered_map<string, bool> &cache) {
        auto key = construct_key(s1, s2);
        if (cache.count(key)) {
            return cache[key];
        }
        if (s1 == s2) {
            return true;
        }
        if (!valid_anagrams(s1, s2)) {
            return false;
        }
        for (auto i = 1; i < s1.size(); ++i) {
            // s2 不交换
            auto s1_left = s1.substr(0, i);
            auto s1_right = s1.substr(i, s1.size() - i);

            auto s2_left = s2.substr(0, i);
            auto s2_right = s2.substr(i, s2.size() - i);

            auto left_valid = backtrack(s1_left, s2_left, cache);
            auto right_valid = backtrack(s1_right, s2_right, cache);

            cache[construct_key(s1_left, s2_left)] = left_valid;
            cache[construct_key(s1_right, s2_right)] = right_valid;
            if (left_valid && right_valid) {
                cache[key] = true;
                return true;
            }
            // s2 交换
            s2_left = s2.substr(s2.size() - i, i);  // 从s2 右侧截取跟 s1 左侧长度一致的子串
            s2_right = s2.substr(0, s2.size() - i);

            left_valid = backtrack(s1_left, s2_left, cache);
            right_valid = backtrack(s1_right, s2_right, cache);

            cache[construct_key(s1_left, s2_left)] = left_valid;
            cache[construct_key(s1_right, s2_right)] = right_valid;
            if (left_valid && right_valid) {
                cache[key] = true;
                return true;
            }
        }
        cache[key] = false;
        return false;
    }

    string construct_key(const string &s1, const string &s2) {
        return s1 + '@' + s2;
    }

    bool valid_anagrams(const string &s1, const string &s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        vector<int> cmap(26, 0);
        for (auto i = 0; i < s1.size(); ++i) {
            cmap[s1[i] - 'a']++;
            cmap[s2[i] - 'a']--;
        }
        for (auto x : cmap) {
            if (x != 0) {
                return false;
            }
        }
        return true;
    }
};