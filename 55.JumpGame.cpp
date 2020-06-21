/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.

*/

class Solution {
public:
    // 判断最长可以走多远，只要长度 >= nums.size() - 1, 就能抵达末尾；
    bool canJump(vector<int>& nums) {
        int longest_dist = 0;
        for (auto i = 0; i < nums.size() - 1; ++i) { // 注意这里条件，i < nums.size() - 1
            // case [0] [2, 0, 0];
            // 因为遍历到倒数第二个元素, 就能判别，无需走到最后一步
            longest_dist = std::max(longest_dist, i + nums[i]);
            if (!nums[i] && longest_dist <= i) { // 当前步数为0，前面的最远距离也走不到这里
                return false;
            }
        }
        return longest_dist >= nums.size() - 1;
    }
};
