/*
233. Number of Digit One

Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

Hint:

Beware of overflow.
*/


// First Solution : TLE
class Solution {
public:
    int countDigitOne(int n) 
    {
        int res = 0;
        for (int i = 0; i <= n; ++i)
        {
            res += numberOf1(i);
        }
        return res;
    }
    
private:
    int numberOf1(int n)
    {
        int res = 0;
        while (n)
        {
            if (n % 10 == 1)
                ++res;
            n /= 10;
        }
        return res;
    }
};