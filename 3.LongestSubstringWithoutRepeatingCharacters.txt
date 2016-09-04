/*

3. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
//  Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
    int lengthOfLongestSubstring(string &s) {
        if (s.size() < 2) return s.size();
        
        int res = 0;
        for (auto i = 0; i < s.size(); ++i)
        {
            int tmp = findLongestSubstr(s, i);
            res = max(res, tmp);
        }
        return res;
    }
    
private:
    int findLongestSubstr(string &s, int begin)
    {
        bool _set[256]; // 用数组，而不是unordered_set 可以显著提高速度，尤其是在s较大时
        memset(_set, false, sizeof(_set));
        for (auto i = begin; i < s.size(); ++i)
        {
            if (_set[static_cast<size_t>(s[i])])
                return i - begin;
            else
                _set[static_cast<size_t>(s[i])] = true;
        }
        return s.size()-begin;
    }
};