/*
343. Integer Break


Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get. 

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4). 

Note: you may assume that n is not less than 2. 

Hint:
1.There is a simple O(n) solution to this problem.
2.You may check the breaking results of n ranging from 7 to 10 to discover the regularities.

*/

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2 || n == 3) return n-1;
        if (n == 4) return n;
        
        int res = 0;
        int minus3 = 2; // 2
        int minus2 = 3; // 3
        int minus1 = 4; // 4
        for (auto i = 5; i <= n; ++i)
        {
            res = max(minus3 * 3, minus2 * 2);
            minus3 = minus2;
            minus2 = minus1;
            minus1 = res;
        }
        return res;
    }
};