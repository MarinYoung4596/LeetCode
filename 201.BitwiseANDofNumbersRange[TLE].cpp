/*
201. Bitwise AND of Numbers Range

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
*/

// First Solution : TLE
class Solution {
public:
    int rangeBitwiseAnd(int m, int n)
    {
        if (m > n) return 0;
        if (m == n) return m;
        
        int result = INT_MAX;
        for (; n != m && m < n; )
        {
            result &= ((m++) & (n--));
        }
        return result;
    }
};


// Second Solution
