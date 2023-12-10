/*
137. Single Number II

Given an array of integers, every element appears three times except for one. Find that single one.

Note:
    Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

*/

// First Solution: Space Complexity:  O(N)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const auto len = sizeof(int) * 8; // sizeof means Bytes
        vector<int> bits(len, 0);

        for (auto i = 0; i < nums.size(); ++i) {
            for (auto j = 0; j < len; ++j) {
                *(bits + j) += ((nums[i] >> j) & 1);
            }
        }
        int result = 0;
        for (auto i = 0; i < len; ++i) { // 相当于记录 所求数 的所有二进制位，
            if (*(bits + i) % 3 != 0) {
                result += (1 << i);
            }
        }

        return result;
    }
};

// Second Solution: Space Complexity: O(1)
//
