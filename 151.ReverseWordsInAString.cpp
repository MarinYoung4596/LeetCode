/*
Given an input string, reverse the string word by word.

For example,
    Given s = "the sky is blue",
    return "blue is sky the".

Update (2015-02-12):
    For C programmers: Try to solve it in-place in O(1) space.


click to show clarification.

Clarification:
    What constitutes a word?
    A sequence of non-space characters constitutes a word.
    Could the input string contain leading or trailing spaces?
    Yes. However, your reversed string should not contain leading or trailing spaces.
    How about multiple spaces between two words?
    Reduce them to a single space in the reversed string.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// First Solution:
// Time Complexity: O(N), Space Complexity: O(N)
class Solution {
public:
    void reverseWords(string &s) {
        string res;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') continue;
            string tmp = "";
            while (s[i] != ' ' && i < s.size()) {
                tmp += s[i++];
            }

            tmp += ' ';
            res = tmp + res;
        }
        s.clear();
        s = res.substr(0, res.length() - 1);
    }
};

// Second Solution:
// Time Complexity: O(N), Space Complexity: O(1)
// https://leetcode.com/discuss/14794/help-improve-my-o-1-space-complexity-solution?show=14794#q14794
class Solution2 {
private:
    void reverseStr(string &s, string::iterator begin, string::iterator end) {
        while (begin < end) {
            char tmp = *begin;
            *begin = *end;
            *end = tmp;
            ++begin;
            --end;
        }
    }

public:
    void reverseWords(string &s) {
        if (s.empty()) {
            return;
        }
        reverseStr(s, s.begin(), s.end() - 1);    // reverse all

        vector<string::iterator> removedSpace;
        // reverse every single word
        for (auto i = s.begin(), j = s.begin(); i != s.end(); ++i) {
            if (*i == ' ') {
                if (i == s.begin() || i == s.end() - 1 || *(i - 1) == ' ') {
                    removedSpace.push_back(i);
                }
                else {
                    reverseStr(s, j, i - 1);
                }
                j = i + 1;
            }
            if (i == s.end() - 1 && *i != ' ') {
                reverseStr(s, j, i);
            }
        }
        for (int i = 0; i < removedSpace.size(); ++i) {
            s.erase(removedSpace[i] - i);
        }
        if (!s.empty() && *(s.end() - 1) == ' ') {
            s.erase(s.end() - 1);
        }
    }
};
