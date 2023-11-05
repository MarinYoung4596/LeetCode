/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
    '.' Matches any single character.
    '*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).


Note:
    s could be empty and contains only lowercase letters a-z.
    p could be empty and contains only lowercase letters a-z, and characters like . or *.


Example 1:
    Input:
        s = "aa"
        p = "a"
    Output: false
    Explanation: "a" does not match the entire string "aa".

Example 2:
    Input:
        s = "aa"
        p = "a*"
    Output: true
    Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
    Input:
        s = "ab"
        p = ".*"
    Output: true
    Explanation: ".*" means "zero or more (*) of any character (.)".

Example 4:
    Input:
        s = "aab"
        p = "c*a*b"
    Output: true
    Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".

Example 5:
    Input:
        s = "mississippi"
        p = "mis*is*p*."
    Output: false
*/


/*
s="aa";     p="a"       false
s="aa";     p="a*"      true
s="ab";     p=".*"      true
s="aab";    p="c*a*b"   true
s="mississippi";    p="mis*is*p*."      false
s="";       p="xxx"     false
s="";       p="."       false
s="";       p=".*"      true
s="xxxx";   p=""        false
s="";       p=""        true
s="xxxx";   p="a*x*"    true
s="mississippi";    p="mis*is*ip*."     true
*/

#include <string>
#include <vector>
#include <iostream>
#include <cstdio>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        return dfs(s.c_str(), p.c_str());
    }

private:
    bool dfs(const char* s, const char* p) {
        if (*p == '\0') {
            return *s == '\0';
        }
        if (*(p + 1) == '*') {
            while (*p == *s || (*p == '.' && *s != '\0')) {
                if (dfs(s, p + 2)) {
                    return true;
                }
                s++;
            }
            return isMatch(s, p + 2);
        } else {
            if (*p == *s || (*p == '.' && *s != '\0')) {
                return dfs(s + 1, p + 1);
            } else {
                return false;
            }
        }
    }
};


class Solution2 {
public:
    bool isMatch(std::string s, std::string p) {
        return dfs(s, p);
    }

private:
    bool dfs(const std::string &s, const std::string &p) {
        //printf("s[%s] p[%s]\n", s.c_str(), p.c_str());
        if (p.empty()) {
            return s.empty();
        }
        auto first_match = !s.empty() && (p[0] == s[0] || p[0] == '.');
        if (p.size() >= 2 && p[1] == '*') {
            return dfs(s, p.substr(2, p.size() - 2))
                || (first_match && dfs(s.substr(1, s.size() - 1), p));
        } else {
            return first_match && dfs(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1));
        }
    }
};

int main() {
    std::vector<std::pair<std::string, std::string>> vec = {
        {"aa", "a"},
        {"aa", "a*"},
        {"ab", ".*"},
        {"aab", "c*a*b"},
        {"mississippi", "mis*is*p*."},
        {"", "xxx"},
        {"", "."},
        {"", ".*"},
        {"xxxx", ""},
        {"", ""},
        {"xxxxx", "a*x*"},
        {"mississippi", "mis*is*ip*."},
        {"ab", ".*c"},
        {"aaa", "a*a"}
    };
    std::vector<bool> result = {
        false, true, true, true, false, false, false,
        true, false, true, true, true, false, true
    };
    Solution2 obj;
    for (auto i = 0; i < vec.size(); ++i) {
        std::cout << obj.isMatch(vec[i].first, vec[i].second) << '\t' << result[i] << '\n';
    }

    return 0;
}
