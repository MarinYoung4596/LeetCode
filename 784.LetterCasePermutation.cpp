/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    784.LetterCasePermutation.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/09/09 18:36:35
*   @brief:

Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. Return the output in any order.

Example 1:
    Input: s = "a1b2"
    Output: ["a1b2","a1B2","A1b2","A1B2"]

Example 2:
    Input: s = "3z4"
    Output: ["3z4","3Z4"]

Constraints:
    1 <= s.length <= 12
    s consists of lowercase English letters, uppercase English letters, and digits.
*****************************************************************/


// First Solution: dfs
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        dfs(s, 0, result);
        return result;
    }

private:
    void dfs(string &s, int index, vector<string> &result) {
        if (index == s.size()) {
            result.push_back(s);
            return;
        }
        dfs(s, index + 1, result);
        if (isalpha(s[index])) {
            s[index] = convert_char_case(s[index]);
            dfs(s, index + 1, result);
        }
    }

    char convert_char_case(char x) {
        x ^= ' ';
        return x;
    }
};


// Second Solution: backtrack
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        string subres = "";
        backtrack(s, 0, subres, result);

        return result;
    }

private:
    void backtrack(const string &s, int index, string subres, vector<string> &result) {
        if (index == s.size()) {
            result.push_back(subres);
            return;
        }

        subres.push_back(s[index]);  // 原始字符
        backtrack(s, index + 1, subres, result);
        subres.pop_back();

        if (!isdigit(s[index])) {
            subres.push_back(convert_char_case(s[index])); // 转换大小写后的字符
            backtrack(s, index + 1, subres, result);
            subres.pop_back();
        }
    }

    char convert_char_case(char x) {
        x ^= ' ';
        return x;
    }
};
