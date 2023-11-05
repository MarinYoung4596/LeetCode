/*
264. Ugly Number II
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.

Hint:

The naive approach is to call isUgly for every number until you reach the nth one.
    Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
The key is how to maintain the order of the ugly numbers. Try a similar approach of
    merging from three sorted lists: L1, L2, and L3.
Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).
*/

class Solution {
public:
    int Min(int num1, int num2, int num3) {
        int tmp = num1 < num2 ? num1 : num2;
        return tmp < num3 ? tmp : num3;
    }

    int nthUglyNumber(int n) {
        if (n <= 0) {
            return 0;
        }

        int* pUglyNumbers = new int[n];
        pUglyNumbers[0] = 1;

        int *multiply2 = pUglyNumbers;
        int *multiply3 = pUglyNumbers;
        int *multiply5 = pUglyNumbers;

        for (int i = 1; i < n; ++i) {
            int min = Min(*multiply2 * 2, *multiply3 * 3, *multiply5 * 5);
            pUglyNumbers[i] = min;

            while (*multiply2 * 2 <= min) {
                ++multiply2;
            }
            while (*multiply3 * 3 <= min) {
                ++multiply3;
            }
            while (*multiply5 * 5 <= min) {
                ++multiply5;
            }
        }

        int ugly = pUglyNumbers[--n];
        delete[] pUglyNumbers;
        return ugly;
    }
};
