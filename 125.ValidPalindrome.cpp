/*
125.	Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
*/

#include <iostream>
#include <string>
#include <typeinfo>
#include <ctype.h>

string removeNoise(const string s)
{
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        // if isDigit or isNumber
        if (isalnum(s[i]))
            res.push_back(tolower(s[i]));
    }
    return res;
}

bool isPalindrome(string s)
{
    if (s == "") return true;
    s = removeNoise(s);
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (s[i] != s[s.length() - 1- i])
            return false;
    }
    return true;
}
