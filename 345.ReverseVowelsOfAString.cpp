/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
    Given s = "hello", return "holle".

Example 2:
    Given s = "leetcode", return "leotcede".

*/

class Solution {
public:
    string reverseVowels(string s) {
        if (s.empty() || s.size() == 1) {
            return s;
        }

        unordered_set<char> _set = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
        size_t begin = 0, end = s.size() - 1;
        while (begin < end) {
            while ((begin < end && _set.find(s[begin]) == _set.end())) {
                ++begin;
            }
            while ((begin < end && _set.find(s[end]) == _set.end())) {
                --end;
            }
            if (begin < end) {
                swap(s[begin++], s[end--]);
            }
        }
        return s;
    }
};