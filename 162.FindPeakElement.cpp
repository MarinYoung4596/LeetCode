/*
162. Find Peak Element

A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.
*/


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        
        int begin = 0, end = nums.size() - 1;
        while (begin < end)
        {
            if (end - begin == 1)
                return nums[begin] > nums[end] ? begin : end;
            
            int mid = begin + (end - begin) / 2;
            if (nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1])
                return mid;
            if (nums[mid] > nums[mid+1]) // more likely to be [begin, mid]
                end = mid;
            else  // [mid, end]
                begin = mid;
        }
        return nums[begin] > nums[end] ? begin : end;
    }
};