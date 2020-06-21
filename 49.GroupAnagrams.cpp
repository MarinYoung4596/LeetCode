/*
Given an array of strings, group anagrams together.

Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:
    All inputs will be in lowercase.
    The order of your output does not matter.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> cache;
        for (auto s : strs) {
            auto key = s;
            std::sort(key.begin(), key.end());
            if (cache.find(key) != cache.end()) {
                cache[key].push_back(s);
            } else {
                cache[key] = std::vector({s});
            }
        }
        std::vector<std::vector<std::string>> result;
        for (auto it = cache.begin(); it != cache.end(); ++it) {
            result.push_back(it->second);
        }
        return result;
    }
};