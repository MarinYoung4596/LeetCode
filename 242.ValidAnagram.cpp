/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
    s = "anagram", t = "nagaram", return true.
    s = "rat", t = "car", return false.

Note:
    You may assume the string contains only lowercase alphabets.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        map<char, size_t> map_s;
        for (size_t i = 0; i != s.size(); ++i) {
            if (s[i] == t[i]) {
                continue;
            }
            if (map_s.find(s[i]) != map_s.end()) {
                ++map_s[s[i]];
            } else {
                map_s.insert(pair<char, size_t>(s[i], 1));
            }

            if (map_s.find(t[i]) != map_s.end()) {
                --map_s[t[i]];
            }
        }

        for (auto it = map_s.begin(); it != map_s.end(); ++it) {
            if (it->second != 0) {
                return false;
            }
        }
        return true;
    }
};

class Solution2 {
public:
    bool isAnagram(const string &s1, const string &s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        vector<int> cmap(26, 0);
        for (auto i = 0; i < s1.size(); ++i) {
            cmap[s1[i] - 'a']++;
            cmap[s2[i] - 'a']--;
        }
        for (auto x : cmap) {
            if (x != 0) {
                return false;
            }
        }
        return true;
    }
};

class Solution3 {
public:
    bool isAnagram(const string &s1, const string &s2) {
        auto s1_sorted = sort(s1.begin(), s1.end());
        auto s2_sorted = sort(s1.begin(), s2.end());
        return s1_sorted == s2_sorted;
    }
};

int main() {
    Solution obj;
    string s = "anagram", t = "nagaram";
    std::cout << obj.isAnagram(s, t) << std::endl;
    s = "rat", t = "car";
    std::cout << obj.isAnagram(s, t) << std::endl;

    return 0;
}
