/*

307. Range Sum Query - Mutable

Given an integer array nums, find the sum of the elements between indices i and j (i ¡Ü j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
*/

class NumArray {
public:
    NumArray(vector<int> &nums) : rawArr(nums), dp(nums)
    {
        for (int i = 1; i < nums.size(); ++i)
            dp[i] += dp[i-1];
    }

    void update(int i, int val) {
        for (int j = i; j < dp.size(); ++j)
            dp[j] += (val - rawArr[i]);
        rawArr[i] = val;
    }

    int sumRange(int i, int j) {
        return dp[j] - dp[i] + rawArr[i];
    }

private:
    vector<int> rawArr;
    vector<int> dp;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);