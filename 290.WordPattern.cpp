/*

290. Word Pattern

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

*/


class Solution {
public:
    bool wordPattern(string &pattern, string &str) 
    {
        vector<string> splitstr;
        split(str, splitstr, ' ');
        if (splitstr.size() != pattern.size()) return false;
        
        unordered_map<string, char> map_str_pattern;
        unordered_map<char, string> map_pattern_str;
        
        for (auto i = 0; i < splitstr.size(); ++i)
        {
            if (map_str_pattern.find(splitstr[i]) == map_str_pattern.end())
                map_str_pattern.insert(std::pair<string, char>(splitstr[i], pattern[i]));
            if (map_pattern_str.find(pattern[i]) == map_pattern_str.end())
                map_pattern_str.insert(std::pair<char, string>(pattern[i], splitstr[i]));
            if (map_str_pattern[splitstr[i]] != pattern[i] ||
                map_pattern_str[pattern[i]] != splitstr[i])
                return false;
        }
        return true;
    }
    
private:
    void split(string &str, vector<string> &result, char delimiter)
    {
        int begin = 0;
        int end = str.find_first_of(delimiter, begin);
        while (end != string::npos)
        {
            result.push_back(str.substr(begin, end-begin));
            
            begin = str.find_first_not_of(delimiter, end);
            end = str.find_first_of(delimiter, begin);
        }
        if (end != begin)
            result.push_back(str.substr(begin, end-begin));
    }
};