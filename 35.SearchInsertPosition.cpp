/*
35. Search Insert Position

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 ¡ú 2
[1,3,5,6], 2 ¡ú 1
[1,3,5,6], 7 ¡ú 4
[1,3,5,6], 0 ¡ú 0
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        const auto n = nums.size();
        int start = 0, end = n-1;
        if (nums[end] < target) return n; // for the case: [1,3,5,6], 7 ¡ú 4
        while (start < end)
        {
            if (target <= nums[start]) return start;
            if (nums[end] <= target) return end;
            if (end - start == 1) return end; // start + 1
            
            int mid = start + (end - start)/2;
            if (nums[mid] < target) start = mid;
            else if (target < nums[mid]) end = mid;
            else return mid;
        }
        return start;
    }
};