/*

139. Word Break

Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

*/

// First Solution: TLE
class Solution {
public:
//  if s can be segmented into a space-separated sequence of one or more dictionary words.
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (wordDict.find(s) != wordDict.end()) return true;
        
        const auto n = s.size();
        for (auto i = 1; i < n; ++i)
        {
            if (wordDict.find(s.substr(0, i)) != wordDict.end())
            {
                if( wordBreak(s.substr(i, n-i), wordDict) )
                    return true;
                // else continue loop
            }
        }
        return false;
    }
};