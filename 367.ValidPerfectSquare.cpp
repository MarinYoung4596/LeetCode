/*

367. Valid Perfect Square

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:
    Input: 16
    Returns: True

Example 2:
    Input: 14
    Returns: False
*/


class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        if (num == 1) return true;
        int start = 1, end = num/2;
        while (start <= end)
        {
            if (end-start == 1)
                return start*start==num || end*end==num;

            int mid = start + (end-start)/2;
            if (num / mid > mid)
                start = mid;
            else if(num / mid < mid)
                end = mid;
            else
                return mid*mid == num;
        }
        return false;
    }
};