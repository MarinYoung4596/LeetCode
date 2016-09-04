/*
198. House Robber
You are a professional robber planning to rob houses along a street. Each house has a certain amount 
of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses 
have security system connected and it will automatically contact the police if two adjacent houses 
were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the 
maximum amount of money you can rob tonight without alerting the police.
*/

#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

// First Solution: Dynamic Programming.
// dp[n] = max{dp[n-1], dp[n-2] + num[n]}
// Time Complexity: O(N), Space Complexity: O(N)

class Solution {
public:
    int rob(vector<int>& nums) {
        // dp = max(dp[i-1], dp[i-2] + nums[i])
    	if (nums.empty()) return 0;
	    const int N = nums.size();
	    dp = new int[N];
	    memset(dp, 0, sizeof(dp));

	    for (int i = 0; i < N; i++)
	    {
		    if (i == 0)
		    	dp[i] = nums[i];
		    else if (i == 1)
		    	dp[i] = max(nums[i], nums[i - 1]);
		    else
		    	dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
	    }
	    int x = dp[N-1];
	    delete []dp;
	    return x;
    }

private:
    int *dp;
};

// Second Solution: iterative Method
// Time Complexity: O(N), Space Complexity: O(1)
int rob2(vector<int>& nums)
{
	if (nums.empty()) return 0;
	int prevprev = 0, // n-2
		prev = nums[0]; // n-1
	for (int i = 1; i < nums.size(); i++)
	{
		int tmp = prev;
		prev = max(prev, prevprev + nums[i]);
		prevprev = tmp;
	}
	return prev;
}
