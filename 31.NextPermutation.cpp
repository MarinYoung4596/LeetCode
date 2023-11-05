/*
31. Next Permutation

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
    1,2,3 → 1,3,2
    3,2,1 → 1,2,3
    1,1,5 → 1,5,1

*/

class Solution {
public:
/*
1) 从最尾端开始往前寻找两个相临的元素,  v[i] 和 v[ii], 且满足v[i] < v[ii], 找到这样一组相邻的元素后,
2) 再从尾端开始往前找, 找到第一个##大于##v[i]的元素v[j], 将 v[i], v[j]对调
3) 再将v[ii]之后的所有元素颠倒排列
*/
    bool nextPermutation(vector<int>& nums) {
        const auto begin = 0;
        const auto end = nums.size() - 1;

        if (end <= 0) {
            return true; // less than 1 element
        }
        for (auto i = end; i >= begin; ) {
            auto ii = i;
            --i;
            if (nums[i] < nums[ii]) { // 找到相邻两个递增序的元素
                auto j = end;
                while (!(nums[i] < nums[j])) {  // 从后往前找到第一个大于（等于）nums[i] 的元素
                    --j;
                }
                swap(nums[i], nums[j]); // 交换二者位置
                reverse(nums, ii, end); // 然后将ii 之后的元素颠倒排列
                return true;
            }
            if (i == begin) { // 最前面
                reverse(nums, i, end);
                return false;
            }
        }
    }

private:
    void reverse(vector<int> &v, int begin, int end) {
        while (begin < end) {
            swap(v[begin++], v[end--]);
        }
    }
};
