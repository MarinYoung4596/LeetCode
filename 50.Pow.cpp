/*
50. Pow(x, n)
Implement pow(x, n).
*/

#include <iostream>
#include <cmath>

#ifndef _INT_MAX_
#define  INT_MAX 2147483647
#endif
#ifndef _INT_MIN_
#define INT_MIN (-INT_MAX - 1)
#endif

using namespace std;

const double EPSILON = 0.00000001;

// First Solution：  x^n = (x^2)^(n/2)
double POW(double x, int n)
{
	if (n == 0)
		return 1.0;
	if (n == 1)
		return x;
	// x == +/-1.0 or x == +/-0.0
	if (abs(abs(x) - 1.0) < EPSILON || abs(abs(x) - 0.0) < EPSILON)
	{
		if (abs(n) % 2 == 0)
			return x < 0 ? -x : x;
		else
			return x;
	}

	unsigned int N = abs(n);
	double res = 1.0;
	while (N) // x^n = (x^(n/2)) * (x^(n/2))
	{
		if (N & 1) // for the case that N < 1
			res *= x;
		N >>= 1;
		x *= x;
	}
	return n > 0 ? res : 1 / res;
}

// Second Solution： 

void testCase_pow()
{
	cout << POW(34.00515, -3) << endl;
	cout << POW(0.00001, 2147483647) << endl;
	// why we use INT_MIN instead of -2147483648? see: 
	// http://www.hankcs.com/program/cpp/error-c4146-%E4%B8%80%E5%85%83%E8%B4%9F%E8%BF%90%E7%AE%97%E7%AC%A6%E5%BA%94%E7%94%A8%E4%BA%8E%E6%97%A0%E7%AC%A6%E5%8F%B7%E7%B1%BB%E5%9E%8B%EF%BC%8C%E7%BB%93%E6%9E%9C%E4%BB%8D%E4%B8%BA%E6%97%A0.html
	cout << POW(1.00000, INT_MIN) << endl;
	cout << POW(-1.00000, INT_MIN) << endl;
	cout << POW(0.44894, -5) << endl;
	cout << POW(3.89707, 2) << endl;
	cout << POW(8.88023, 3) << endl;
}

