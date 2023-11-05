/*

387. First Unique Character in a String

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

    s = "leetcode"
    return 0.

    s = "loveleetcode",
    return 2.

Note: You may assume the string contain only lowercase letters.

*/

class Solution {
public:
    int firstUniqChar(string &s) {
        int map[26];
        memset(map, 0, 26*sizeof(int));

        for (auto i = 0; i < s.size(); ++i)
            ++map[static_cast<int>(s[i]-'a')];
        for (auto i = 0; i < s.size(); ++i)
        {
            if (map[static_cast<int>(s[i]-'a')] == 1)
                return i;
        }
        return -1;
    }
};