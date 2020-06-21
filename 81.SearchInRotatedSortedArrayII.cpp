/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
You are given a target value to search. If found in the array return true, otherwise return false.


Example 1:
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true


Example 2:
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false


Follow up:
This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?
*/


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return false;
        }
        auto begin = 0;
        auto end = nums.size() - 1;
        while (begin <= end) {
            auto mid = begin + (end - begin) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[begin] < nums[mid]) { // 前半段有序
                if (nums[begin] <= target && target < nums[mid]) { // 在前半段找
                    end = mid - 1;
                } else { // target < nums[begin] || target >= nums[mid], 说明在后半段
                    begin = mid + 1;
                }
            } else if (nums[begin] > nums[mid]) { // 后半段有序
                if (nums[mid] < target && target <= nums[end]) { // 去后半段找
                    begin = mid + 1;
                } else { // target <= nums[mid] || target > nums[end], 去前半段找
                    end = mid - 1;
                }
            } else { // nums[begin] == nums[mid], 重新划分范围查找, e.g.  1,2,3,1,1,1,1
                ++begin;
            }
        }
        return false;
    }
};