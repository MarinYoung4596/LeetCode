/*
344. Reverse String

Write a function that takes a string as input and returns the string reversed.

Example:
 Given s = "hello", return "olleh". 

*/

class Solution {
public:
    string reverseString(string s) {
        if (s.empty() || s.size() == 1) return s;
        
        int begin = 0, end = s.size() - 1;
        while (begin < end)
        {
            swap(s[begin++], s[end--]);
        }
        return s;
    }
};