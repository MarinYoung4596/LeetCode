/*
Given an integer array nums, find the sum of the elements between indices i and j (i ¡Ü j), inclusive.

Example:
    Given nums = [-2, 0, 3, -5, 2, -1]

    sumRange(0, 2) -> 1
    sumRange(2, 5) -> -1
    sumRange(0, 5) -> -3

Note:
    You may assume that the array does not change.
    There are many calls to sumRange function.


Your NumArray object will be instantiated and called as such:
    NumArray numArray(nums);
    numArray.sumRange(0, 1);
    numArray.sumRange(1, 2);
*/

class NumArray {
  public:
    NumArray(vector<int> &nums) {
        res = nums;
        for (int i = 1; i < nums.size(); ++i) {
            res[i] += res[i - 1];
        }
    }

    int sumRange(int i, int j) {
        if (i >= res.size() || j >= res.size() || i > j) {
            return 0;
        }
        int nums_i = (i == 0 ? res[i] : res[i] - res[i - 1]);
        return res[j] - res[i] + nums_i;
    }

  private:
    vector<int> res;
};

int main() {
    int arr[] = {1, 2, 3};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
    NumArray numArray(v);
    std::cout << numArray.sumRange(0, 1) << std::endl;
    std::cout << numArray.sumRange(1, 2) << std::endl;

    return 0;
}
