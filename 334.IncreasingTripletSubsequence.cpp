/*
334. Increasing Triplet Subsequence

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.
*/

// First Solution: bruce force
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        const auto n = nums.size();
        if (n < 3) return false;
        for (auto i = 0; i < n-2; ++i)
        {
            for (auto j = i+1; j < n-1; ++j)
            {
                if (!(nums[i] < nums[j])) continue;
                for (auto k = j+1; k < n; ++k)
                {
                    if (!(nums[j]<nums[k])) continue;
                    return true;
                }
            }
        }
        return false;
    }
};

// Second Solution: Find if LIS >=3 
// see : https://discuss.leetcode.com/topic/37601/just-using-the-lis-to-solve-the-problem-in-8ms

// Third Solution: 
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        const auto n = nums.size();
        if (n < 3) return false;
        
        int first = INT_MAX;
        int second = INT_MAX;
        for (auto i = 0; i < n; ++i)
        {
            if (nums[i] <= first) 
                first = nums[i]; // 此时first是最小的元素
            else if (nums[i] <= second) // 此时以确定 first < nums[i] 
                second = nums[i]; // 若nums[i] <= second，则second存储次小元素
            else // 上几次循环已使得 first < second < nums[i]
                return true;
        }
        return false;
    }
};