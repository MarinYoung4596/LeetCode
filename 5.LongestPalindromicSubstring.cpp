/*
Given a string S, find the longest palindromic substring in S.

Example 1:
    Input: s = "babad"
    Output: "bab"
    Explanation: "aba" is also a valid answer.

Example 2:
    Input: s = "cbbd"
    Output: "bb"

Constraints:
    1 <= s.length <= 1000
    s consist of only digits and English letters.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        const auto len = s.size();
        if (len <= 1) {
            return s;
        }
        string res;
        auto max = 0, sublen = 0;
        for (auto i = 0; i < len; ++i) {
            size_t j = 0;
            // odd
            for (; i - j > 0
                    && i + j < len
                    && s[i - j] == s[i + j];
                    ++j);
            j = (s[i - j] == s[i + j]) ? j : --j;
            sublen = 2 * j + 1;
            if (sublen >= max) {
                res = s.substr(i - j, sublen);
                max = sublen;
            }
            // event
            for (j = 0; i - j > 0
                    && i + j + 1 < len
                    && s[i - j] == s[i + j + 1];
                    ++j);
            j = (s[i - j] == s[i + j + 1]) ? j : --j;
            sublen = 2 * j + 2;
            if (sublen >= max) {
                res = s.substr(i - j, sublen);
                max = sublen;
            }
        }
        return res;
    }
};

// second solution
class Solution2 {
public:
    std::string getPalindrom(const std::string &str, int left, int right) {
        if (left < 0 || right >= str.size() || left > right) {
            return std::string();
        }
        while (left >= 0 && right < str.size() && str[left] == str[right]) {
            --left;
            ++right;
        }
        return str.substr(left + 1, right - left - 1);
    }

    std::string LongestPalindrom(const std::string &str) {
        std::string result;
        for (auto i = 0; i < str.size(); ++i) {
            auto odds_result = getPalindrom(str, i, i);
            auto even_result = getPalindrom(str, i, i + 1);

            if (result.size() < odds_result.size()) {
                result = odds_result;
            }
            if (result.size() < even_result.size()) {
                result = even_result;
            }
        }
        return result;
    }
};

// third solution: dp
class Solution3 {
public:
    string longestPalindrome(string s) {
        const auto n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        auto max_len = 0;
        string result = "";
        for (int i = n - 1; i >= 0; --i) {
            for (auto j = i; j < n; ++j) {
                if (s[i] == s[j]) {
                    if (j - i < 2) {
                        dp[i][j] = j - i + 1;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1] > 0 ? dp[i + 1][j - 1] + 2 : 0;
                    }
                }
                if (dp[i][j] > max_len) {
                    max_len = dp[i][j];
                    result = s.substr(i, j - i + 1);
                }
            }
        }
        return result;
    }
};

int main(int argc, char **argv) {
    string s = "cbbd";
    Solution3 obj;
    std::cout << obj.longestPalindrome(s) << std::endl; //jjddjj

    return 0;
}
