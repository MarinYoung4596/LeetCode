/*
374. Guess Number Higher or Lower

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!

Example:
    n = 10, I pick 6.
    Return 6.
*/


// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int start = 1, end = n;
        while (start < end)
        {
            if (end - start == 1)
                return 0 == guess(start) ? start:end;

            int mid = start + (end - start) / 2; // ²»ÓÃ(start+end)/2 ·ÀÖ¹Òç³ö e.g. end = 2^31 - 1 = 2147483647
            int res = guess(mid);
            if (res > 0) start = mid;
            else if (res < 0) end = mid;
            else return mid;
        }
        return start;
    }
};