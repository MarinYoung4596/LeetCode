/*
242. Valid Anagram


Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        map<char, size_t> map_s;
        for (size_t i = 0; i != s.size(); ++i)
        {
            if (s[i] == t[i])
                continue;
            if (map_s.find(s[i]) != map_s.end())
                ++map_s[s[i]];
            else
                map_s.insert(pair<char, size_t> (s[i], 1));

            if (map_s.find(t[i]) != map_s.end())
                --map_s[t[i]];
        }

        map<char, size_t>::iterator it;
        for (it = map_s.begin(); it != map_s.end(); ++it)
        {
            if (it->second != 0)
                return false;
        }
        return true;
    }
};

int main()
{
	Solution obj;
	string s = "anagram", t = "nagaram";
	std::cout<< obj.isAnagram(s, t) << std::endl;
	s = "rat", t = "car";
	std::cout<< obj.isAnagram(s, t) << std::endl;

	return 0;
}
