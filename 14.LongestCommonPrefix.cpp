/*
14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.
*/

#include <string>
#include <vector>

// First Solution: Time Complexity: O(N * m)
// compare each character of each str in the vector.
class Solution {
    string longestCommonPrefix(vector<string>& strs) {
        if (strsm.empty()) {
            return string();
        }

        for (int index = 0; index < strs[0].size(); index++) {
            for (size_t i = 1; i < strs.size(); i++) {
                if (strs[i][index] != strs[0][index]) {
                    return strs[0].substr(0, index);
                }
            }
        }
        return strs[0];
    }
};


// Second Solution: Time Complexity: O(NlogN)
class Solution2 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        const auto N = strs.size();
        if (!N) {
            return std::string();
        }
        std::sort(strs.begin(), strs.end());
        auto i = 0;
        while (i < strs[0].size()
               && i < strs[N - 1].size()
               && strs[0][i] == strs[N - 1][i]) {
            ++i;
        }
        return strs[0].substr(0, i);
    }
};

// Third Solution
class Solution3 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 先取最小长度
        auto min_len = strs[0].size();
        for (const auto &str: strs) {
            min_len = std::min(min_len, str.size());
        }
        // 然后遍历
        auto idx = 0;
        for (; idx < min_len; ++idx) {
            auto flag = false;
            for (auto j = 1; j < strs.size(); ++j) {
                if (strs[0][idx] != strs[j][idx]) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        return strs[0].substr(0, idx);
    }
}