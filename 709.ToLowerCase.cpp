/*
Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

 

Example 1:

Input: "Hello"
Output: "hello"

Example 2:

Input: "here"
Output: "here"

Example 3:

Input: "LOVELY"
Output: "lovely"

*/

class Solution {
public:
    string toLowerCase(string str) {
        for (auto it = str.begin(); it != str.end(); ++it) {
            if (*it >= 'A' && *it <= 'Z') {
                *it -= ('A' - 'a');
            }
        }
        return str;
    }
};