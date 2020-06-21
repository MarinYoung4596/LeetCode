/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:
Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"


Note:
If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        const auto CHAR_SIZE = 256;
        std::vector<int> tmap(CHAR_SIZE, 0);
        for (auto ch : t) {
            ++tmap[ch];
        }

        int left = 0;
        int right = 0;

        std::string result;
        std::vector<int> wmap(CHAR_SIZE, 0);
        while (right < s.size()) {
            auto cur = s[right];
            ++wmap[cur];
            ++right;

            if (is_valid(tmap, wmap)) {
                while (wmap[s[left]] == 0 || wmap[s[left]] > tmap[s[left]]) {
                    --wmap[s[left]];
                    ++left;
                }
                auto subres = s.substr(left, right - left);
                if (result.empty() || subres.size() < result.size()) {
                    result = subres;
                }
                auto front = s[left];
                --wmap[front];
                ++left;
            }
        }
        return result;
    }

private:
    bool is_valid(const std::vector<int> &tmap,
                  const std::vector<int> &wmap) {
        assert(tmap.size() == wmap.size());
        // tmap 是 wmap的子集
        for (auto i = 0; i < tmap.size(); ++i) {
            if (tmap[i] > wmap[i]) {
                return false;
            }
        }
        return true;
    }
};