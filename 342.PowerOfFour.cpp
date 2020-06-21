/*
342. Power of Four

Given an integer (signed 32 bits), write a function to check whether it is a power of 4. 

Example:
 Given num = 16, return true. Given num = 5, return false. 

Follow up: Could you solve it without loops/recursion? 

*/

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0 || (num & (num - 1))) 
            return false;
        if (num == 1) return true;
        int n = 0x01;
        while (n)
        {
            if ((n & num)) return true;
            n <<= 2;
        }
        return false;
    }
};