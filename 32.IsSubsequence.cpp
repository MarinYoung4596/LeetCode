/*
392. Is Subsequence

Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"

Return true.

Example 2:
s = "axc", t = "ahbgdc"

Return false.

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

*/


/* First Solution: Search */

class Solution {
public:
// s = "abc", t = "ahbgdc"
    bool isSubsequence(string &s, string &t) {
        const auto sn = s.size();
        const auto tn = t.size();
        
        int begin = 0;
        for (auto i = 0; i < sn && begin != string::npos; ++i)
        {
            if (i == 0 || s[i-1] != s[i])
                begin = t.find_first_of(s[i], begin);
            else
                begin = t.find_first_of(s[i], begin + 1); // for the case like:
            /*
            s = "leeeeetcode" // 5 'e' between 'l' and 't'
			t = "yyylyyyyeyyyeyyyyeyyytyyycyyyoyyydyyyeyyy" // only 3 'e' between 'l' and 't'
            */
        }
        if (begin == string::npos) return false;
        return true;
    }
};