/*
7.	Reverse Integer
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

#ifndef INT_MAX
#define INT_MAX 2147483647
#endif
#ifndef INT_MIN
#define INT_MIN (-INT_MAX - 1)
#endif

int reverse(int x)
{
    int res = 0;
    for (; x; x = x/10)
    {
        // checking overflow / underflow
        // for the case that res > 214748364 or res < -214748346
        // the next loop it will be overflow/underflow.
        if (res > INT_MAX / 10 || res < INT_MIN / 10)
            return 0;
        res = res * 10 + x % 10;
    }
    return res;
}
