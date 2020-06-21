/*
153. Find Minimum in Rotated Sorted Array

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        //no duplicate exists in the array.
        if (nums.empty()) {
            return -1;
        }
        auto begin = 0;
        auto end = nums.size() - 1;
        if (nums[begin] < nums[end]) {
            return nums[begin];
        }
        while (begin < end) {
            if (begin + 1 == end) {
                return nums[end];
            }
            
            auto mid = (begin + end)/2;
            if (nums[begin] < nums[mid]) {// [begin, mid] in order
                begin = mid;
            } else if (nums[mid] < nums[end]) {// [mid, end] in order
                end = mid;
            }
        }
        return nums[end];
    }
};
