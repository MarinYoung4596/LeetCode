/*
168. Excel Sheet Column Title
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
1->A; AA->27
*/

#include <iostream>
#include <cstring>

string convertToTitle(int n)
{
    string result;
    char bit;
    while(n != 0)
    {
        bit = (char)((n-1) % 26 + 65);
        result.insert(result.begin(), bit);
        n -= (n-1) % 26; // for the case that n = 26*k, then n/26 = 1 != 0, so bit = 'A', and result = "ZA"
        n /= 26;
    }
    return result;
}
