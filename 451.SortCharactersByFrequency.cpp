/*
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.


Example 1:
    Input: s = "tree"
    Output: "eert"
    Explanation:
        'e' appears twice while 'r' and 't' both appear once.
        So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:
    Input: s = "cccaaa"
    Output: "aaaccc"
    Explanation:
        Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
        Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:
    Input: s = "Aabb"
    Output: "bbAa"
    Explanation:
        "bbaA" is also a valid answer, but "Aabb" is incorrect.
        Note that 'A' and 'a' are treated as two different characters.


Constraints:
    1 <= s.length <= 5 * 10^5
    s consists of uppercase and lowercase English letters and digits.

*/

class Solution {
public:
    string frequencySort(string s) {
        vector<std::pair<int, int>> cfreq_map(256, std::make_pair(0, 0));
        for (auto ch : s) {
            cfreq_map[static_cast<int>(ch)].second++;
        }
        for (auto i = 0; i < cfreq_map.size(); ++i) {
            cfreq_map[i].first = i;
        }
        std::sort(cfreq_map.begin(), cfreq_map.end(),
                [&](const auto &lhs, const auto &rhs) {
                    return lhs.second > rhs.second;
                });
        string res = "";
        for (const auto &item: cfreq_map) {
            if (item.second < 1) {
                break;
            }
            string tmp(item.second, static_cast<char>(item.first));
            res += tmp;
        }
        return res;
    }
};