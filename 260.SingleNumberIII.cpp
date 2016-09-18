/*
260. Single Number III

Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. 

For example: 

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5]. 

Note:

1.The order of the result is not important. So in the above example, [5, 3] is also correct.
2.Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        if (nums.empty()) return nums;
        
        //???????????
        int temp;
        for (auto i = 0; i < nums.size(); ++i)
            temp ^= nums[i];
        
        // ?????1?? 
        size_t k = 0;
        for (; k < sizeof(int)*8; ++k)
        {
            if (temp & 1) break;
            temp >>= 1;
        }
        
        // ?j??1,?????????j???????  ??????
        int res1(0), res2(0);
        for (auto i = 0; i < nums.size(); ++i)
        {
            if ((nums[i]>>k) & 1)
                res1 ^= nums[i];
            else
                res2 ^= nums[i];
        }
        return {res1, res2};
    }
};