/*
268.	Missing Number
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

#include <vector>

/*First Solution*/
int missingNumber(vector<int>& nums) {
    vector<bool> tmp(nums.size() + 1, false);

    for (auto i = 0; i < nums.size(); ++i) {
        tmp[nums[i]] = true;
    }

    for (auto i = 0; i < tmp.size(); ++i) {
        if (!tmp[i]) {
            return i;
        }
    }
}

/*Second Solution  bit manipulation*/
int missingNumber(vector<int>& nums) {
    const auto len = nums.size(); // N
    int res = len;
    for (auto i = 0; i < len; ++i) {
        res ^= i ^ nums[i];
    }
    return res;
}
