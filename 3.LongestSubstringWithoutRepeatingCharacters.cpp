/*

3. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

Examples:
    Given "abcabcbb", the answer is "abc", which the length is 3.
    Given "bbbbb", the answer is "b", with the length of 1.
    Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

#include <string>
#include <vector>
#include <iostream>
#include <cstdio>


class Solution {
public:
//  Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
    int lengthOfLongestSubstring(std::string s) {
        if (s.size() < 2) {
            return s.size();
        }
        int res = 0;
        for (auto i = 0; i < s.size(); ++i) {
            int tmp = findLongestSubstr(s, i);
            res = std::max(res, tmp);
        }
        return res;
    }

private:
    int findLongestSubstr(const std::string &s, int begin) {
        std::vector<bool> set(256, false);
        for (auto i = begin; i < s.size(); ++i) {
            if (set[s[i]]) {
                return i - begin;
            } else {
                set[s[i]] = true;
            }
        }
        return s.size() - begin;
    }
};


// Second Solution: greddy search
class Solution2 {
public:
    int lengthOfLongestSubstring(std::string str) {
        if (str.empty()) {
            return 0;
        }
        std::vector<int> cmap(256, -1); // 记录每个字符上次出现的位置
        int left = 0;
        int right = 0;
        int result = 0;
        while (right < str.size()) {
            if (cmap[str[right]] >= left) {
                result = std::max(result, right - left);
                left = cmap[str[right]] + 1; // 取str[right]重复字符的下一个位置
            }
            cmap[str[right]] = right; // 更新当前字符的位置索引
            ++right;
        }
        return std::max(result, right - left);
    }
};


// third solution: slidding window
class Solution3 {
public:
    int lengthOfLongestSubstring(std::string str) {
        if (str.size() < 2) {
            return str.size();
        }
        int result = 0;
        std::vector<int> cmap(256, 0);
        int left = 0;
        int right = 0;
        while (right < str.size()) {
            if (cmap[str[right]] > 0) {
                --cmap[str[left]];
                ++left;
            } else {
                ++cmap[str[right]];

                auto len = right - left + 1;
                result = std::max(result, len);
                ++right;
            }
        }
        return std::max(result, right - left);
    }
};


int main() {
    Solution3 obj;
    std::cout << obj.lengthOfLongestSubstring("abcabcbb") << std::endl;
    std::cout << obj.lengthOfLongestSubstring("bbbbb") << std::endl;
    std::cout << obj.lengthOfLongestSubstring("pwwkew") << std::endl;
    std::cout << obj.lengthOfLongestSubstring("dvdf") << std::endl;

    return 0;
}
