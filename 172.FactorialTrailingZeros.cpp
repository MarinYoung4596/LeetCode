/*
172. Factorial Trailing Zeroes.
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

int trailingZeroes(int n) {
    int result = 0;
    for (; n; n /= 5)
        result += (n/5); // not noly n/5, but also the situation of 5*5; such as 25; 125; ...
    return result;
}
