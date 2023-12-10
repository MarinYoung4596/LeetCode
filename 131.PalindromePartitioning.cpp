/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    131.PalindromePartitioning.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/09/10 14:56:29
*   @brief:

Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

Example 1:
    Input: s = "aab"
    Output: [["a","a","b"],["aa","b"]]

Example 2:
    Input: s = "a"
    Output: [["a"]]

Constraints:
    1 <= s.length <= 16
    s contains only lowercase English letters.
*****************************************************************/

#include "util.h"
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> subres;
        vector<vector<string>> result;
        backtrack(s, 0, subres, result);
        return result;
    }

private:
    void backtrack(const string &s, int index,
                   vector<string> &subres,
                   vector<vector<string>> &result) {
        if (index == s.size()) {
            result.push_back(subres);
            return;
        }
        for (auto i = index; i < s.size(); ++i) {
            if (!valid_palindrome(s, index, i)) {
                continue;  // s[index : i] 非回文
            }
            auto part = s.substr(index, i - index + 1);
            subres.push_back(part);
            backtrack(s, i + 1, subres, result);
            subres.pop_back();
        }
    }

    bool valid_palindrome(const string& s, int begin, int end) {
        if (begin > end) {
            return false;
        }
        while (begin < end) {
            if (s[begin] != s[end]) {
                return false;
            }
            ++begin;
            --end;
        }
        return true;
    }
};

int main() {
    vector<string> test_cases = {
        "aab",
        "a",
        // "abcd",
        // "aaaaa",
        "aabb"
    };
    Solution obj;
    for (auto &item : test_cases) {
        auto res = obj.partition(item);
        std::cout << "input: " << item << "\n";
        print_matrix<string>(res);
        print_gap();
    }
}