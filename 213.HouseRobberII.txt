/*
213. House Robber II 

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/


class Solution 
{
public:
/* House Robber:
the only constraint stopping you from robbing each of them is that adjacent 
houses have security system connected and it will automatically contact the 
police if two adjacent nHouses were broken into on the same night.

dp[n] = max(dp[n-1], dp[n-2]+nums[n])
*/
// 两种情况，拆分成两个子问题，取其中的大者。
    int rob(vector<int>& nums) 
    {
        const auto n = nums.size();
        if (0 == n) return 0;
        if (1 == n) return nums[0];
        if (2 == n) return max(nums[0], nums[1]);
        
        return max(robFromTo(nums, 0, n-2), robFromTo(nums, 1, n-1));
    }

private:
    int robFromTo(vector<int> &nums, int left, int right)
    {
        int pre = 0, curr = 0;
        for (int i = left; i <= right; ++i)
        {
            int tmp = max(pre+nums[i], curr);
            pre = curr;
            curr = tmp;
        }
        return curr;
    }

};