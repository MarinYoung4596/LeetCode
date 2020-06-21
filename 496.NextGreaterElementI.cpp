/**
You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.
The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.


Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.


Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // 保存索引位置
        std::unordered_map<int, int> nums1_index_map;
        for (auto i = 0; i < nums1.size(); ++i) {
            nums1_index_map[nums1[i]] = i;
        }

        std::stack<int> s;
        std::vector<int> result(nums1.size(), 0);
        // 从后往前, 避免覆盖
        for (int i = nums2.size() - 1; i >= 0; --i) {
            // 栈顶不是最大值
            while (!s.empty() && s.top() < nums2[i]) {
                s.pop();
            }
            auto tmp = s.empty() ? -1 : s.top(); // next greater element
            s.push(nums2[i]); // 保存当前最大值

            auto iter = nums1_index_map.find(nums2[i]);
            if (iter != nums1_index_map.end()) {
                auto idx = iter->second;
                result[idx] = tmp;
            }
        }
        return result;
    }
};