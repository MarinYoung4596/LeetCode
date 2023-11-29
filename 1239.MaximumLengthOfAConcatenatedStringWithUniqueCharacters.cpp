/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    1239.MaximumLengthOfAConcatenatedStringWithUniqueCharacters.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/29 23:17:01
*   @brief:

You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.



Example 1:
    Input: arr = ["un","iq","ue"]
    Output: 4
    Explanation: All the valid concatenations are:
        - ""
        - "un"
        - "iq"
        - "ue"
        - "uniq" ("un" + "iq")
        - "ique" ("iq" + "ue")
    Maximum length is 4.

Example 2:
    Input: arr = ["cha","r","act","ers"]
    Output: 6
    Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").

Example 3:
    Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
    Output: 26
    Explanation: The only string in arr has all 26 characters.


Constraints:
    1 <= arr.length <= 16
    1 <= arr[i].length <= 26
    arr[i] contains only lowercase English letters.


Hints:
    You can try all combinations and keep mask of characters you have.
    You can use DP.

*****************************************************************/

// First Solution: backtrack
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bool> ch_map(26, false);
        return backtrack(arr, 0, ch_map, 0);
    }

private:
    int backtrack(vector<string> &arr, int index, vector<bool> &ch_map, int cur_len) {
        if (index >= arr.size()) {
            return cur_len;
        }
        if (!check_valid(arr[index], ch_map)) { // 不满足条件
            return backtrack(arr, index + 1, ch_map, cur_len);
        }
        set_ch_map(arr[index], ch_map, true);
        auto ret1 = backtrack(arr, index + 1, ch_map, cur_len + arr[index].size()); // 用当前 index 的字符串
        set_ch_map(arr[index], ch_map, false);
        auto ret2 = backtrack(arr, index + 1, ch_map, cur_len); // 不用
        return max(ret1, ret2);
    }

    bool check_valid(const string &item, const vector<bool> &ch_map) {
        vector<bool> cur_ch_map(26, false);
        for (auto ch : item) {
            if (ch_map[ch - 'a'] || cur_ch_map[ch - 'a']) {
                return false;
            }
            cur_ch_map[ch - 'a'] = true;
        }
        return true;
    }

    void set_ch_map(const string &item, vector<bool> &ch_map, bool val) {
        for (auto ch : item) {
            ch_map[ch - 'a'] = val;
        }
    }
};