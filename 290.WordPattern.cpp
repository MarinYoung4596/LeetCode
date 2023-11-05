/*

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.


Examples:
    pattern = "abba", str = "dog cat cat dog" should return true.
    pattern = "abba", str = "dog cat cat fish" should return false.
    pattern = "aaaa", str = "dog cat cat dog" should return false.
    pattern = "abba", str = "dog dog dog dog" should return false.


Constraints:
    1 <= pattern.length <= 300
    pattern contains only lower-case English letters.
    1 <= s.length <= 3000
    s contains only lowercase English letters and spaces ' '.
    s does not contain any leading or trailing spaces.
    All the words in s are separated by a single space.
*/


class Solution {
public:
    bool wordPattern(string &pattern, string &str)  {
        vector<string> vec;
        split(str, vec, ' ');
        if (vec.size() != pattern.size()) {
            return false;
        }

        unordered_map<string, char> map_str_pattern;
        unordered_map<char, string> map_pattern_str;

        for (auto i = 0; i < vec.size(); ++i) {
            if (map_str_pattern.find(vec[i]) == map_str_pattern.end()) {
                map_str_pattern.insert(std::pair<string, char>(vec[i], pattern[i]));
            }
            if (map_pattern_str.find(pattern[i]) == map_pattern_str.end()) {
                map_pattern_str.insert(std::pair<char, string>(pattern[i], vec[i]));
            }
            if (map_str_pattern[vec[i]] != pattern[i] || map_pattern_str[pattern[i]] != vec[i]) {
                return false;
            }
        }
        return true;
    }

private:
    void split(string &str, vector<string> &result, char delimiter) {
        int begin = 0;
        int end = str.find_first_of(delimiter, begin);
        while (end != string::npos) {
            result.push_back(str.substr(begin, end-begin));

            begin = str.find_first_not_of(delimiter, end);
            end = str.find_first_of(delimiter, begin);
        }
        if (end != begin) {
            result.push_back(str.substr(begin, end - begin));
        }
    }
};