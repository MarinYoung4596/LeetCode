/*
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
    Input: "aba"
    Output: True

Example 2:
    Input: "abca"
    Output: True
    Explanation: You could delete the character 'c'.

Note:
    The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/

class Solution {
public:
    bool validPalindrome(string s) {
        return dfs(s, 0, s.size() - 1, false);
    }

private:
    bool dfs(const string &s, int begin, int end, bool del_flag) {
        if (begin >= end) {
            return true;
        }
        if (s[begin] == s[end]) {
            return dfs(s, begin + 1, end - 1, del_flag);
        } else if (del_flag) {
            return false;
        } else {
            auto stat1 = dfs(s, begin + 1, end, true);
            auto stat2 = dfs(s, begin, end - 1, true);
            return stat1 || stat2;
        }
    }
};