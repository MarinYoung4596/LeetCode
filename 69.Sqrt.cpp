/*
69. sqrt(x)
Implement int sqrt(int x).

Compute and return the square root of x.
*/

#include <cstdlib>

// First Solution: Newton's Method, see
// http://en.wikipedia.org/wiki/Newton%27s_method &
// http://www.nowamagic.net/librarys/veda/detail/2268
int mySqrt(int x)
{
	if (x < 0)
		exit(0);
	if (x == 0 || x == 1)
		return x;

	int res = 1, // res can be a random value
		last = 0;
	while (res != last)
	{
		last = res;
		res = (res + x / res) / 2;
	}
	return (int)res;
}

// Second Solution: From: https://github.com/soulmachine/leetcode
int mySqrt_2(int x)
{
	assert(x>0);
	if (x < 2)
		return x;
	/*
	e.g: x = 36
		left	right	mid		last_mid
	1	1		18		9		?	36 / 9 = 4 < 9,	right = mid - 1
	2			8		4		4	36 / 4 = 9 > 4, left = mid + 1
	3	5				5		5	36 / 5 = 7 > 5,	left = mid + 1
	4	6				7		5	36 / 7 = 5 < 7, right = mid - 1
	5	6		6					return q
	*/
	int left = 1, right = x / 2;
	int last_mid;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (x / mid > mid)	// mid * mid will overflow
		{
			left = mid + 1;
			last_mid = mid;
		}
		else if (x / mid < mid)
			right = mid - 1;
		else
			return mid;
	}
	return last_mid;
}

