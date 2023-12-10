/*
Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

Example 1:
    Input: s = "aaabb", k = 3
    Output: 3
    Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.

Example 2:
    Input: s = "ababbc", k = 2
    Output: 5
    Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.

*/

class Solution {
public:
    int longestSubstring(string s, int k) {
        int result = 0;
        dfs(s, k, 0, s.size(), result);
        return result;
    }

private:
    void dfs(const string &str, int k, int left, int right, int &result) {
        if (right - left < k) {
            return;
        }
        vector<int> ch_map(256, 0);
        for (auto i = left; i < right; ++i) {
            ++ch_map[str[i]];
        }

        int begin = left;
        for (auto i = left; i < right - k; ++i) {
            if (ch_map[str[i]] < k) { // 当前不满足要求，抛弃当前ch
                dfs(str, k, begin, i, result);
                ++begin;
            }
        }
        if (begin != left) { // 不满足条件
            dfs(str, k, begin, right, result);
        } else { // 说明满足条件
            result = max(result, right - left);
        }
    }
};