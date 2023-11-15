/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.


Example 1:
    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4

Example 2:
    Input: nums = [4,5,6,7,0,1,2], target = 3
    Output: -1

Example 3:
    Input: nums = [1], target = 0
    Output: -1


Constraints:
    1 <= nums.length <= 5000
    -10^4 <= nums[i] <= 10^4
    All values of nums are unique.
    nums is an ascending array that is possibly rotated.
    -10^4 <= target <= 10^4
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // no duplicate exists in the array
        int begin = 0, end = nums.size() - 1;
        while (begin <= end) {
            auto mid = (begin + end) >> 1;
            if (nums[mid] == target) {
                return mid;
            }
            // first type : 3 4 5 6 7 8 | 1 2
            if (nums[begin] <= nums[mid]) { // 说明前半部分有序, 即 nums[mid] > nums[end]
                if (nums[begin] <= target && target < nums[mid]) {
                    end = mid - 1; // 在前半部分找
                } else {
                    begin = mid + 1; // 否则
                }
            } else if (nums[mid] < nums[end]) { // // second type: 7 8 | 0 1 2 3 4 5 说明后半部分有序, 即 nums[begin] > nums[mid]
                if (nums[mid] < target && target <= nums[end]) {
                    begin = mid + 1; // 在后半部分找
                } else {
                    end = mid - 1; // 否则
                }
            } else { // normal type : 0 1 2 3 4 5
                if (target < nums[mid]) {
                    end = mid - 1;
                } else {
                    begin = mid + 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution obj;

    vector<int> num1;
    num1 = { 4, 5, 6, 7, 0}; // first type
    cout << obj.search(num1, 8) << endl; // -1 excluded
    cout << obj.search(num1, 4) << endl; // 0 head
    cout << obj.search(num1, 5) << endl; // 1
    cout << obj.search(num1, 6) << endl; // 2 mid
    cout << obj.search(num1, 7) << endl; // 3
    cout << obj.search(num1, 0) << endl; // 4 tail

    num1 = { 8, 0, 1, 2, 3 }; // second type
    cout << obj.search(num1, 5) << endl; // -1 excluded
    cout << obj.search(num1, 8) << endl; // 0 head
    cout << obj.search(num1, 0) << endl; // 1
    cout << obj.search(num1, 1) << endl; // 2 mid
    cout << obj.search(num1, 2) << endl; // 3
    cout << obj.search(num1, 3) << endl; // 4 tail

    return 0;
}
