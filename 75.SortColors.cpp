/*
75. Sort Colors

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue. 

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively. 

Note:
 You are not suppose to use the library's sort function for this problem. 

click to show follow up.


Follow up:
 A rather straight forward solution is a two-pass algorithm using counting sort.
 First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty()) return;
        
        
        //First Solution: two-pass algorithm
        /*
        unordered_map<int, int> _m(3);
        _m.insert({0, 0});
        _m.insert({1, 0});
        _m.insert({2, 0});
        for (auto i = nums.begin(); i != nums.end(); ++i)
        {
            _m[*i]++;
        }
        int i = 0;
        for (auto j = 0; j < _m[0]; ++j) nums[i++] = 0;
        for (auto j = 0; j < _m[1]; ++j) nums[i++] = 1;
        for (auto j = 0; j < _m[2]; ++j) nums[i++] = 2;
        */
        
        /*
        Second Solution: one-pass algorithm
        */
        int red = -1, white = -1, blue = -1;
        for (auto &i : nums)
        {
            if (i == 0) // red
            {
                // because zero is former: 0, 1, 2
                // if red plus 1, then all blue and white elements move to its' next position
                nums[++blue] = 2;
                nums[++white] = 1;
                nums[++red] = 0;
            }
            else if (i == 1) // white
            {
               nums[++blue] = 2;
                nums[++white] = 1;
            }
            else // i == 2, blue
            {
                nums[++blue] = 2;
            }
        }
        
    }
};