/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    2129.CapitalizeTheTitle.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/09/26 00:12:44
*   @brief:

You are given a string title consisting of one or more words separated by a single space, where each word consists of English letters. Capitalize the string by changing the capitalization of each word such that:

    If the length of the word is 1 or 2 letters, change all letters to lowercase.
    Otherwise, change the first letter to uppercase and the remaining letters to lowercase.

Return the capitalized title.



Example 1:
    Input: title = "capiTalIze tHe titLe"
    Output: "Capitalize The Title"
    Explanation:
        Since all the words have a length of at least 3, the first letter of each word is uppercase, and the remaining letters are lowercase.

Example 2:
    Input: title = "First leTTeR of EACH Word"
    Output: "First Letter of Each Word"
    Explanation:
        The word "of" has length 2, so it is all lowercase.
        The remaining words have a length of at least 3, so the first letter of each remaining word is uppercase, and the remaining letters are lowercase.

Example 3:
    Input: title = "i lOve leetcode"
    Output: "i Love Leetcode"
    Explanation:
        The word "i" has length 1, so it is lowercase.
        The remaining words have a length of at least 3, so the first letter of each remaining word is uppercase, and the remaining letters are lowercase.


Constraints:
    1 <= title.length <= 100
    title consists of words separated by a single space without any leading or trailing spaces.
    Each word consists of uppercase and lowercase English letters and is non-empty.

*****************************************************************/


class Solution {
public:
    string capitalizeTitle(string title) {
        string result = "";

        auto left = 0;
        auto right = 0;
        while (right < title.size()) {
            while (right < title.size() && title[right] != ' ') {
                ++right;
            }
            auto word = title.substr(left, right - left);
            result += capitalize_word(word);
            result += " ";

            ++right;
            left = right;
        }
        if (left < title.size()) {
            auto word = title.substr(left, right - left);
            result += capitalize_word(word);
        }
        if (result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }

private:
    string capitalize_word(const string &word) {
        auto res = word;
        for (auto i = 0; i < res.size(); ++i) {
            res[i] = tolower(res[i]);
        }
        if (res.size() > 2) {
            res[0] = toupper(res[0]);
        }
        return res;
    }
};