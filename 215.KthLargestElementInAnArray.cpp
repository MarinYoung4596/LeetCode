/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?


Example 1:
    Input: nums = [3,2,1,5,6,4], k = 2
    Output: 5

Example 2:
    Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
    Output: 4


Constraints:
    1 <= k <= nums.length <= 10^5
    -10^4 <= nums[i] <= 10^4
*/

// First Solution: partition ❌
// Time Limit Exceeded
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (k < 1 || k > nums.size()) {
            return -1;
        }

        int begin = 0, end = nums.size() - 1;
        int index = partition(nums, begin, end);
        while (index != k - 1) {
            if (index > k - 1) {
                end = index - 1;
            } else {
                begin = index + 1;
            }
            index = partition(nums, begin, end);
        }
        return nums[index];
    }

private:
    int partition(vector<int> &nums, int begin, int end) {
        int pivot = nums[end];
        int i = begin;
        for (auto j = begin; j < end; ++j) {
            if (nums[j] >= pivot) {
                swap(nums[i], nums[j]);
                ++i;
            }
        }
        swap(nums[i], nums[end]);
        return i;
    }
};

// second solution: 堆 ✅
// 时间：beats 38.42% c++ users;
// 内存：beats 58.39% c++ users;
class Solution2 {
public:
    int findKthLargest(vector<int> &nums, int k) {
        make_heap(nums.begin(), nums.end());
        int result;
        for (int i = 0; i < k; ++i) {
            result = nums.front();
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        return result;
    }
};

// Third Solution: 堆 ✅
// 时间：beats 100% c++ users;
// 内存：beats 17.81% c++ users;
class Solution3 {
public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        // 将数组的前 k 个元素入堆
        for (int i = 0; i < k; i++) {
            heap.push(nums[i]);
        }
        // 从第 k+1 个元素开始，保持堆的长度为 k
        for (int i = k; i < nums.size(); i++) {
            // 若当前元素大于堆顶元素，则将堆顶元素出堆、当前元素入堆
            if (nums[i] > heap.top()) {
                heap.pop();
                heap.push(nums[i]);
            }
        }
        return heap.top();
    }
};

// Forth Solution: sort ✅
// 时间：beats 44.48% c++ users;
// 内存：beats 40.46% c++ users;
class Solution4 {
public:
    int findKthLargest(vector<int> &nums, int k) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};
