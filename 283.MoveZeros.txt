/*
283. Move Zeroes
 
 
 Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements. 

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0]. 

Note:

1.You must do this in-place without making a copy of the array.
2.Minimize the total number of operations.

*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) return;
        using std::swap;
        for (auto i = 0, j = 1; j < nums.size(); ++i, ++j)
        {
            if (0 == nums[i])
            {
                while (j < nums.size() && 0 == nums[j]) ++j;
                if (j == nums.size()) return;
                swap(nums[i], nums[j]);
            }
        }
    }
};