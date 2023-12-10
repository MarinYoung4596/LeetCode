/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:
    Input: S = "ADOBECODEBANC", T = "ABC"
    Output: "BANC"


Note:
    If there is no such window in S that covers all characters in T, return the empty string "".
    If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/

// 滑动窗口
class Solution {
public:
    string minWindow(string s, string t) {
        const auto CHAR_SIZE = 256;
        vector<int> tmap(CHAR_SIZE, 0);
        for (auto ch : t) {
            ++tmap[ch];
        }

        int left = 0;
        int right = 0;

        string result;
        vector<int> wmap(CHAR_SIZE, 0);
        while (right < s.size()) {
            auto cur = s[right];
            ++wmap[cur];  // 右侧开始移动
            ++right;

            if (is_valid(tmap, wmap)) {  // 符合条件
                while (wmap[s[left]] == 0 || wmap[s[left]] > tmap[s[left]]) {
                    --wmap[s[left]];  // 左侧窗口开始收缩
                    ++left;
                }
                // 暂存 subres
                auto subres = s.substr(left, right - left);
                if (result.empty() || subres.size() < result.size()) {
                    result = subres;  // 保存最小值
                }
                // 左侧窗口收缩 (窗口滑动)
                auto front = s[left];
                --wmap[front];
                ++left;
            }
        }
        return result;
    }

private:
    bool is_valid(const vector<int> &tmap,
                  const vector<int> &wmap) {
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
