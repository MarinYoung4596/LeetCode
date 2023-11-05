/*
80. Remove Duplicates from Sorted Array II

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
    Given sorted array nums = [1,1,1,2,2,3],
    Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();
        int duplicates = 1;
        int index = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            duplicates = (nums[i] == nums[i-1] ? duplicates + 1 : 1);
            if (duplicates < 3)
            {
                nums[++index] = nums[i];
            }
        }
        return nums.empty() ? 0 : index + 1;
    }
};