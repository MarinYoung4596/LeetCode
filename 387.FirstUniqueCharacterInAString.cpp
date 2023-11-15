/*
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.


Example 1:
    Input: s = "leetcode"
    Output: 0

Example 2:
    Input: s = "loveleetcode"
    Output: 2

Example 3:
    Input: s = "aabb"
    Output: -1


Constraints:
    1 <= s.length <= 10^5
    s consists of only lowercase English letters.
*/

class Solution {
public:
    int firstUniqChar(string &s) {
        vector<int> ch_map(26, 0);

        for (auto x : s) {
            ++ch_map[x - 'a'];
        }
        for (auto i = 0; i < s.size(); ++i) {
            if (ch_map[static_cast<int>(s[i] - 'a')] == 1) {
                return i;
            }
        }
        return -1;
    }
};