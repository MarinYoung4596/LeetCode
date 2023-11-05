/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:
    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.


Example 1:
    Input: s = "leetcode", wordDict = ["leet", "code"]
    Output: true
    Explanation: Return true because "leetcode" can be segmented as "leet code".


Example 2:
    Input: s = "applepenapple", wordDict = ["apple", "pen"]
    Output: true
    Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
                Note that you are allowed to reuse a dictionary word.


Example 3:
    Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
    Output: false

*/

// First Solution: recursive, TLE
class Solution {
public:
//  if s can be segmented into a space-separated sequence of one or more dictionary words.
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (wordDict.find(s) != wordDict.end()) {
            return true;
        }

        const auto n = s.size();
        for (auto i = 1; i < n; ++i) {
            if (wordDict.find(s.substr(0, i)) != wordDict.end()) {
                if(wordBreak(s.substr(i, n - i), wordDict)) {
                    return true;
                }
                // else continue loop
            }
        }
        return false;
    }
};


// Second Solution: 带备忘录加速的dfs
// Runtime: 8 ms, faster than 87.79% of C++ online submissions for Word Break.
// Memory Usage: 9.3 MB, less than 73.68% of C++ online submissions for Word Break.
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::unordered_set<std::string> word_dict;
        std::unordered_set<std::size_t> word_len_dict;
        for (const auto &item : wordDict) {
            word_dict.insert(item);
            word_len_dict.insert(item.size());
        }
        std::unordered_map<std::string, bool> cache;
        return dfs(s, word_dict, word_len_dict, cache);
    }

private:
    bool dfs(const std::string &str,
            const std::unordered_set<std::string> &word_dict,
            const std::unordered_set<std::size_t> &word_len_dict,
            std::unordered_map<std::string, bool> &cache) {
        if (str.empty()) {
            return true;
        }
        if (cache.count(str) > 0) {
            return cache[str];
        }
        if (word_dict.count(str) > 0) {
            return true;
        }
        for (const auto len : word_len_dict) {
            if (str.size() < len || word_dict.count(str.substr(0, len)) == 0) {
                continue;
            }
            auto stat = dfs(str.substr(len), word_dict, word_len_dict, cache);
            if (stat) {
                cache[str] = true;
                return true;
            }
        }
        cache[str] = false;
        return false;
    }
};