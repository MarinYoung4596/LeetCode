/*
171. Excel Sheet Column Number
Given a column title as appear in an Excel sheet, return its corresponding column number.
A->1; B->2; ......; AA->27; AB->28
*/

#include <iostream>
#include <cstring>

using namespace std;

int titleToNumber(string s)
{
    int res = 0, bit;
    for(int i=s.length()-1; i>=0; i--)
    {
        bit = (int)(s[i] - 64);
        res += pow(26, s.length()-i-1) * bit;
    }
    return res;
}
