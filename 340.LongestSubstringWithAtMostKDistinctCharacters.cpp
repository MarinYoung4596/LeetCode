/*
Given a string, find the length of the longest substring T that contains at most k distinct characters.

Example 1:
    Input: s = "eceba", k = 2
    Output: 3
    Explanation: T is "ece" which its length is 3.

Example 2:
    Input: s = "aa", k = 1
    Output: 2
    Explanation: T is "aa" which its length is 2.
*/

#include <unordered_set>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(const string &str, int k) {
        int max_len = 0;
        if (k == 0) {
            return max_len;
        }
        int left = 0;
        int right = 0;
        unordered_set<char> us;
        while (right < str.length()) {
            if (us.count(str[right]) > 0 || us.size() < k) {  // 1）字符已存在，放心扩展窗口；2）字符不存在 但是字符个数 < k
                max_len = std::max(max_len, right - left + 1);
                if (us.count(str[right]) < 1) {
                    us.insert(str[right]);
                }
                ++right;
                while (right < str.length() && str[right] == str[right - 1]) {
                    max_len = std::max(max_len, right - left + 1);
                    ++right;
                }
            } else { // 否则，字符个数超限，窗口收缩
                us.erase(str[left++]);
                while (left < right && str[left] == str[left - 1]) {
                    ++left;
                }
            }
        }
        return max_len;
    }
};

int main() {
    vector<pair<string, int>> test_cases = {
        {"eceba", 2},
        {"aa", 1},
        {"abcde", 2},
        {"aaaaaabc", 1},
        {"abcd", 0},
        {"abcdeeeeeeef", 3}
    };
    Solution obj;
    for (const auto &item : test_cases) {
        cout << obj.lengthOfLongestSubstringKDistinct(item.first, item.second) << '\n';
    }
    return 0;
}