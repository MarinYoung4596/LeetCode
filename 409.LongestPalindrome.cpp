/*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
This is case sensitive, for example "Aa" is not considered a palindrome here.

Note: Assume the length of given string will not exceed 1,010.

Example:
    Input: "abccccdd"
    Output: 7
    Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
*/


class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> smap;
        for (auto x : s) {
            if (smap.count(x) > 0) {
                ++smap[x];
            } else {
                smap[x] = 1;
            }
        }
        int result = 0;
        bool flag = false;
        for (auto it = smap.begin(); it != smap.end(); ++it) {
            if ((it->second) % 2) { // 奇数如果>1，选择偶数个即可
                result += (it->second - 1);
                flag = true;
            } else { // 偶数都可以用
                result += it->second;
            }
        }
        return result + flag; // 其中一个奇数全选
    }
};