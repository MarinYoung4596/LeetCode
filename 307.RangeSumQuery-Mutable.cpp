/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
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

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);


/*
    First Solution: 前缀和 数组
        创建:  O(N)
        update: O(N)
        sumRange: O(1)
    问题：题目说 update 和 sumRange 函数调用均等（均匀分布），因此不够高效
*/

#include <vector>
using std::vector;

class NumArray {
public:
    NumArray(vector<int> &nums) : raw_arr(nums), prefix_sum(nums) {
        for (int i = 1; i < nums.size(); ++i) {
            prefix_sum[i] += prefix_sum[i - 1];
        }
    }

    void update(int index, int value) {
        for (int j = index; j < prefix_sum.size(); ++j) {  // index之后的所有前缀和都要更新
            prefix_sum[j] += (value - raw_arr[j]);
        }
        raw_arr[index] = value;
    }

    int sumRange(int i, int j) {
        return prefix_sum[j] - prefix_sum[i] + raw_arr[i];
    }

private:
    vector<int> raw_arr;
    vector<int> prefix_sum;
};


/*
    Second Solution: 树状数组
    时间：412ms  击败 86.08%使用 C++ 的用户
    内存：164.95MB  击败 54.55%使用 C++ 的用户
*/
class NumArray2 {
public:
    NumArray(vector<int>& nums) {
        data = nums;

        tree.resize(nums.size() + 1);
        for (auto idx = 0; idx < nums.size(); ++idx) {
            add(idx + 1, nums[idx]);
        }
    }

    void update(int idx, int val) {
        add(idx + 1, val - data[idx]);
        data[idx] = val;
    }

    int sumRange(int left, int right) {
        return preSum(right + 1) - preSum(left);
    }

private:
    int preSum(int idx) {
        int result = 0;
        while (idx > 0) {
            result += tree[idx];
            idx -= lowBit(idx);
        }
        return result;
    }

    void add(int idx, int val) {
        while (idx < tree.size()) {
            tree[idx] += val;
            idx += lowBit(idx);
        }
    }

    int lowBit(int idx) {
        return idx & (-idx);
    }

private:
    vector<int> tree;
    vector<int> data;
};


/* third solution: 线段树 */
class NumArray3 {
public:
    NumArray(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }
        n = nums.size();
        tree.resize(2 * n);
        for (auto i = 0; i < n; ++i) { // 叶子节点
            tree[n + i] = nums[i];
        }
        for (auto i = n - 1; i >= 0; --i) { // 上层父节点
            auto left = 2 * i;
            auto right = 2 * i + 1;
            tree[i] = tree[left] + tree[right];
        }
    }

    void update(int idx, int val) {
        auto pos = idx + n;
        auto delta = val - tree[pos];
        while (pos > 0) {
            tree[pos] += delta;
            pos >>= 1;
        }
    }

    int sumRange(int left, int right) {
        left += n;
        right += n;
        auto result = 0;
        while (left <= right) {
            if (left % 2 == 1) {
                result += tree[left];
                ++left;
            }
            if (right % 2 == 0) {
                result += tree[right];
                --right;
            }
            left >>= 1;
            right >>= 1;
        }
        return result;
    }

private:
    int n = 0;
    vector<int> tree;
};
