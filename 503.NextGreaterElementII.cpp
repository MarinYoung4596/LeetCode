/**
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
    Input: [1,2,1]
    Output: [2,-1,2]
    Explanation:
        The first 1's next greater number is 2;
        The number 2 can't find next greater number;
        The second 1's next greater number needs to search circularly, which is also 2.

Example 2:
    Input: nums = [1,2,3,4,3]
    Output: [2,3,4,-1,4]

Note: The length of given array won't exceed 10000.

*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        stack<int> s; // 存储当前最大的值
        // 循环：将数组首位拼接起来，相当于循环两遍
        // 因为是next，所以从后往前遍历
        for (int i = 2 * nums.size() - 1; i >= 0; --i) {
            int idx = i % nums.size();
            // 栈顶都比当前值小，找到比当前值大的元素
            while (!s.empty() && s.top() <= nums[idx]) {
                s.pop();
            }
            result[idx] = s.empty() ? -1 : s.top();
            s.push(nums[idx]);
        }
        return result;
    }
};
