/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    17.LetterCombinationsOfAPhoneNumber.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/09/09 19:25:27
*   @brief:

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


Example 1:
    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
    Input: digits = ""
    Output: []

Example 3:
    Input: digits = "2"
    Output: ["a","b","c"]

Constraints:
    0 <= digits.length <= 4
    digits[i] is a digit in the range ['2', '9'].

*****************************************************************/


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        string subres;
        backtrack(digits, 0, subres, result);
        return result;
    }

private:
    vector<char> num_to_alpha(int x) {
        switch (x) {
            case 2: return {'a', 'b', 'c'}; break;
            case 3: return {'d', 'e', 'f'}; break;
            case 4: return {'g', 'h', 'i'}; break;
            case 5: return {'j', 'k', 'l'}; break;
            case 6: return {'m', 'n', 'o'}; break;
            case 7: return {'p', 'q', 'r', 's'}; break;
            case 8: return {'t', 'u', 'v'}; break;
            case 9: return {'w', 'x', 'y', 'z'}; break;
            default: return {};
        }
    }

    void backtrack(string digits, int index, string &subres, vector<string> &result) {
        if (index == digits.size()) {
            result.push_back(subres);
            return;
        }

        auto cur = digits[index] - '0';
        auto char_list = num_to_alpha(cur);

        for (auto ch : char_list) {
            subres.push_back(ch);
            backtrack(digits, index + 1, subres, result);
            subres.pop_back();
        }
    }
};