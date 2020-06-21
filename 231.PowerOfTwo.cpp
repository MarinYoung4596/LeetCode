/*
231. Power of Two

Given an integer, write a function to determine if it is a power of two. 
*/

class Solution {
public:
	/*Second Solution*/
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        int count = 0;
        
        while (n != 0)
        {
            if (n & 1) ++count;
            n >>= 1;
        }
        
        return 1 == count;
    }
	
	/*First Solution*/
	bool isPowerOfTwo(int n)
	{
		return n > 0 && !(n & (n-1));
	}
};