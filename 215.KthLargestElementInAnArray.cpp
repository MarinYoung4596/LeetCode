/*
215. Kth Largest Element in an Array
 

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element. 

For example,
 Given [3,2,1,5,6,4] and k = 2, return 5. 

Note: 
 You may assume k is always valid, 1 = k = array's length.

*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (k < 1 || k > nums.size()) return -1;
        
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

// second solution
int findKthLargest(vector<int> &v, int k) {
    make_heap(v.begin(), v.end());
    int result;
    for (int i = 0; i < k; ++i) {
        result = v.front();
        pop_heap(v.begin(), v.end());
        v.pop_back();
    }
    return result;
}
