/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:
    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.


Example 1:
    Input:
    s = "catsanddog"
    wordDict = ["cat", "cats", "and", "sand", "dog"]
    Output:
    [
        "cats and dog",
        "cat sand dog"
    ]

Example 2:
    Input:
        s = "pineapplepenapple"
        wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
    Output:
    [
        "pine apple pen apple",
        "pineapple pen apple",
        "pine applepen apple"
    ]
    Explanation: Note that you are allowed to reuse a dictionary word.


Example 3:
    Input:
        s = "catsandog"
        wordDict = ["cats", "dog", "sand", "and", "cat"]
    Output: []


Constraints:
    1 <= s.length <= 20
    1 <= wordDict.length <= 1000
    1 <= wordDict[i].length <= 10
    s and wordDict[i] consist of only lowercase English letters.
    All the strings of wordDict are unique.
    Input is generated in a way that the length of the answer doesn't exceed 10^5.

*/


// First Solution: backtrack;
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_dict;
        unordered_set<std::size_t> word_len_dict;
        for (const auto &item : wordDict) {
            word_dict.insert(item);
            word_len_dict.insert(item.size());
        }
        vector<string> result;
        vector<string> candidate;
        backtrack(s, word_dict, word_len_dict, candidate, result);
        return result;
    }

private:
    bool backtrack(const string &str,
            const unordered_set<string> &word_dict,
            const unordered_set<std::size_t> &word_len_dict,
            vector<string> &candidate,
            vector<string> &result) {
        if (str.empty()) {
            result.push_back(vec_to_str(candidate));
            return true;
        }
        for (const auto len : word_len_dict) {
            if (str.size() < len) {
                continue;
            }
            auto tmp_str = str.substr(0, len);
            if (word_dict.count(tmp_str) < 1) {
                continue;
            }
            candidate.push_back(tmp_str);
            backtrack(str.substr(len), word_dict, word_len_dict, candidate, result);
            candidate.pop_back();
        }
        return false;
    }

    string vec_to_str(const vector<string> &vec) {
        string result;
        for (const auto &item : vec) {
            result += item;
            result += " ";
        }
        result.pop_back();
        return result;
    }
};

// second solution: backtrack
class Solution2 {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> candidate;
        vector<string> result;
        backtrack(s, 0, wordDict, candidate, result);
        return result;
    }

private:
    void backtrack(string s, int index,
                    const vector<string> &word_dict,
                    vector<string> &candidate,
                    vector<string> &result) {
        if (index == s.length()) {
            result.push_back(vec_to_str(candidate));
            return;
        }
        if (index > s.length()) {
            return;
        }
        for (const auto &word : word_dict) {
            auto cur_len = word.length();
            if (index + cur_len > s.length()) {   // 已经超长
                continue;
            }
            auto cur_str = s.substr(index, cur_len);
            if (cur_str != word) {  // 无法匹配
                continue;
            }
            candidate.push_back(cur_str);
            backtrack(s, index + cur_len, word_dict, candidate, result);
            candidate.pop_back();
        }
    }

    string vec_to_str(const vector<string> &vec) {
        string result;
        for (const auto &item : vec) {
            result += item;
            result += " ";
        }
        result.pop_back();
        return result;
    }
};