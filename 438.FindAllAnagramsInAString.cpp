/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
The order of output does not matter.

Example 1:
Input:
    s: "cbaebabacd" p: "abc"
Output:
    [0, 6]
Explanation:
    The substring with start index = 0 is "cba", which is an anagram of "abc".
    The substring with start index = 6 is "bac", which is an anagram of "abc".


Example 2:
Input:
    s: "abab" p: "ab"
Output:
    [0, 1, 2]
Explanation:
    The substring with start index = 0 is "ab", which is an anagram of "ab".
    The substring with start index = 1 is "ba", which is an anagram of "ab".
    The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        const auto CHAR_SIZE = 256;

        std::vector<int> pmap(CHAR_SIZE, 0);
        for (auto x : p) {
            ++pmap[x];
        }

        std::vector<int> result;

        int left = 0;
        int right = 0;
        std::vector<int> wmap(CHAR_SIZE, 0);
        while (right < s.size()) {
            ++wmap[s[right]];
            ++right; // 右指针扩张

            if (is_valid(pmap, wmap)) {
                result.push_back(left);
            }
            if ((right - left + 1) > p.size()) { // 滑动窗口长度超过p, 左指针收缩
                --wmap[s[left]];
                ++left;
            }
        }
        return result;
    }


private:
    bool is_valid(const std::vector<int> &tmap,
                  const std::vector<int> &wmap) {
        if (tmap.size() != wmap.size()) {
            return false;
        }
        for (auto i = 0; i < tmap.size(); ++i) {
            if (tmap[i] != wmap[i]) {
                return false;
            }
        }
        return true;
    }
};
