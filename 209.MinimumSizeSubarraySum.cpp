/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.


Example 1:
    Input: target = 7, nums = [2,3,1,2,4,3]
    Output: 2
    Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
    Input: target = 4, nums = [1,4,4]
    Output: 1

Example 3:
    Input: target = 11, nums = [1,1,1,1,1,1,1,1]
    Output: 0


Constraints:
    1 <= target <= 10^9
    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^4


Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).
*/

#include <vector>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int cur_sum = 0;
        int min_len = INT_MAX;
        while (right < nums.size()) {
            cur_sum += nums[right];
            ++right;
            while (cur_sum >= target) {
                min_len = std::min(min_len, right - left);
                cur_sum -= nums[left];
                ++left;
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};

class Solution2 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len = INT_MAX;
        int cur_sum = 0;
        int left = 0;
        int right = 0;
        while (right < nums.size()) {
            while (right < nums.size() && cur_sum < target) { // right一次走完了，left没法收缩
                cur_sum += nums[right];
                ++right;
            }
            while (left < right && cur_sum >= target) {
                min_len = min(min_len, right - left);
                cur_sum -= nums[left];
                ++left;
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};

int main() {
    vector<pair<vector<int>, int>> test_cases = {
        {{2,3,1,2,4,3}, 7},
        {{1,4,4}, 4},
        {{1,1,1,1,1,1,1,1}, 11},
        {{1,2,3,4,5}, 11}
    };
    Solution2 obj;
    for (auto &item : test_cases) {
        cout << obj.minSubArrayLen(item.second, item.first) << endl;
    }

    return 0;
}