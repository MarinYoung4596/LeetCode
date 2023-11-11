/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.


Example 1:
    Input: nums = [3,2,3]
    Output: 3

Example 2:
    Input: nums = [2,2,1,1,1,2,2]
    Output: 2


Constraints:
    n == nums.length
    1 <= n <= 5 * 10^4
    -10^9 <= nums[i] <= 10^9


Follow-up: Could you solve the problem in linear time and in O(1) space?
*/

#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int n_times = 0;
        int candidate = 0;
        for(int i = 0; i < num.size(); i++) {
            if (n_times == 0) {
                candidate = num[i];
                n_times = 1;
            } else {
                if(candidate == num[i]) {
                    n_times++;
                } else {
                    n_times--;
                }
            }
        }
        return candidate;
    }
};

class Solution2 {
public:
    int majorityElement(vector<int> &num) {
        sort(num.begin(), num.end());
        return num[num.size() / 2];
    }
};
