/*
34. Search for a Range

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const auto n = nums.size();
        int start = 0, end = n-1;
        while (start <= end)
        {
            // NOT FOUND
            if (nums[end] < target || nums[start] > target)
                return vector<int>({-1,-1});
            
            if (end - start == 1)
            {
                start = nums[start]==target ? start : start + 1;
                end = nums[end] == target ? end : end - 1;
            }
            // BINARY SEARCH
            int mid = start + (end - start)/2;
            if (nums[mid] < target) start = mid;
            else if (nums[mid] > target) end = mid;
            else
            {
                auto s = mid, e = mid;
                for (; s >= start && nums[s] == target; --s);
                for (; e <= end && nums[e] == target; ++e);
                return vector<int>({s+1, e-1});
            }
        }
        return vector<int>({-1, -1});
    }
};