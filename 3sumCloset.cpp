/*
16. 3Sum Closet
Given an array S of n integers, find three integers in S such that the sum is closest to a given number,
target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
#include <vector>
#include <algorithm>

int threeSumClosest(vector<int> &num, int target)
{
	int res = 0;
	int min_gap = INT_MAX;
	std::sort(num.begin(), num.end());	// O(NlogN), very important
	for (auto a = num.begin(); a != prev(num.end(), 2); ++a) // same as num.end()-2
	{
		auto b = next(a); // a + 1
		auto c = prev(num.end()); // num.end()-1
		while (b < c)
		{
			const int sum = *a + *b + *c;
			const int gap = abs(sum - target);

			if (gap < min_gap)
			{
				res = sum;
				min_gap = gap;
			}
			if (sum < target) ++b;
			else --c;	// sum > target, because it is impossible to be equal.
		}
	}
	return res;
}
