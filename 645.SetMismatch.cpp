/*
The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.

Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.

Example 1:
    Input: nums = [1,2,2,4]
    Output: [2,3]


Note:
    The given array size will in the range [2, 10000].
    The given array's numbers won't have any order.
*/

// First Solution: Time Complexity: O(N)  Space Complexity: O(N)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result;
        vector<int> vec(nums.size() + 1, 0);
        for (auto i = 0; i < nums.size(); ++i) {
            ++vec[nums[i]];
        }
        int missing = -1;
        int duplicate = -1;
        for (auto i = 1; i < vec.size(); ++i) {
            if (vec[i] == 0) {
                missing = i;
            }
            if (vec[i] > 1) {
                duplicate = i;
            }
            if (missing != -1 && duplicate != -1) {
                break;
            }
        }
        return vector<int>({duplicate, missing});
    }
};

// Second Solution: Time Complexity: O(N)  Space Complexity: O(1)
class Solution2 {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int duplicate = -1;
        for (auto i = 0; i < nums.size(); ++i) {
            auto index = abs(nums[i]) - 1;
            if (nums[index] < 0) {
                duplicate = abs(nums[i]); // 为负，说明重复出现
            } else {
                nums[index] *= -1; // 如果出现过，将对应的值变号
            }
        }

        int missing = -1;
        for (auto i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) { // > 0, 说明i位置的元素没有出现过，没人帮忙变号
                missing = i + 1;
                break;
            }
        }
        return vector<int>({duplicate, missing});
    }
};
