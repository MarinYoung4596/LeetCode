/*
154. Find Minimum in Rotated Sorted Array II

> Follow up for "Find Minimum in Rotated Sorted Array":
> What if duplicates are allowed?
> Would this affect the run-time complexity? How and why?

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/

class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        if (nums.empty()) return -1;
        auto begin = 0;
        auto end = nums.size() - 1;

        while (begin < end)
        {
            if (nums[begin] < nums[end]) return nums[begin];
            
            if (begin + 1 == end) return nums[end];// not in order
            
            auto mid = begin + (end-begin)/2;
            if (nums[begin] > nums[mid]) end = mid; // not in order
            else if (nums[mid] > nums[end]) begin = mid;  // not in order
            else
            {
                int res = nums[begin];
                for (auto i = begin+1; i < end; ++i)
                {
                    res = min(res, nums[i]);
                }
                return res;
            }
        }
        return nums[end];
    }
};