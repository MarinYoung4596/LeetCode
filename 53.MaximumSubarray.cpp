/*
53. Maximum Subarray, 最大连续子序列的和

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

#include <vector>

// First Solution:
// f[j] = max{f[j-1] + s[j], s[j]}; 1 <= j <= N
// TARGET = max{f[j]}; 1 <= j <= N
// Time Complexity: O(N)
int maxSubArray(vector<int>& nums)
{
	const int N = nums.size();
	if (!N) return 0;
	int res = INT_MIN, f = 0;
	for (int i = 0; i < N; i++)
	{
		f = max(f + nums[i], nums[i]);
		res = max(res, f);
	}
	return res;
}

// Second Solution:
// to be continued...

