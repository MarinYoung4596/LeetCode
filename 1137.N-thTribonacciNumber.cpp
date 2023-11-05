/*
The Tribonacci sequence Tn is defined as follows:
T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
Given n, return the value of Tn.


Example 1:
    Input: n = 4
    Output: 4
    Explanation:
        T_3 = 0 + 1 + 1 = 2
        T_4 = 1 + 1 + 2 = 4

Example 2:
    Input: n = 25
    Output: 1389537


Constraints:
    0 <= n <= 37
    The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.
*/


// First Solution:
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for N-th Tribonacci Number.
// Memory Usage: 6.1 MB, less than 29.37% of C++ online submissions for N-th Tribonacci Number.
class Solution {
public:
    int tribonacci(int n) {
        std::vector<int> vec(n + 1, 0);
        if (n < 1) {
            return 0;
        } else if (n < 3) {
            return 1;
        }
        vec[1] = vec[2] = 1;
        for (auto i = 3; i <= n; ++i) {
            vec[i] = vec[i - 1] + vec[i - 2] + vec[i - 3];
        }
        return vec[n];
    }
};


// Second Solution:
// See 509. Fibonacci Number.cpp