/*
152. Maximum Product Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

#include <vector>

// Dynamic Programming: 
// Time Complexity: O(N), Space Complexity: O(1)
// https://leetcode.com/discuss/19795/share-my-c-solution-maybe-is-the-simplest-solution
int maxProduct(vector<int>& nums)
{
	const int N = nums.size();

	int frontProduct = 1,
		backProduct = 1,
		res = INT_MIN;
	for (int i = 0; i < N; i++)
	{
		frontProduct *= nums[i];
		backProduct *= nums[N - 1 - i];
		res = max(res, max(frontProduct, backProduct));
		frontProduct = frontProduct == 0 ? 1 : frontProduct;
		backProduct = backProduct == 0 ? 1 : backProduct;
	}
	return res;
}


// Second Solution
// Time Complexity: O(N), Space Complexity: O(N)
// http://www.1point3acres.com/bbs/thread-105035-1-1.html
// http://www.cnblogs.com/bakari/p/4007368.html
// if nums[i] is negative, then nums[i] * minimum_negative = maximum_positive
// if nums[i] is positive, then nums[i] * maximum_positive = maximum_positive
int maxProduct_2(vector<int>& nums)
{
	const int N = nums.size();
	vector<int> maxdp(N), mindp(N);
	int res;
	res = maxdp[0] = mindp[0] = nums[0];
	for (int i = 1; i < N; i++)
	{
		maxdp[i] = max(mindp[i - 1] * nums[i], maxdp[i - 1] * nums[i]);
		maxdp[i] = max(maxdp[i], nums[i]);

		mindp[i] = min(mindp[i - 1] * nums[i], maxdp[i - 1] * nums[i]);
		mindp[i] = min(mindp[i], nums[i]);

		res = max(res, maxdp[i]);
	}
	return res;
}
