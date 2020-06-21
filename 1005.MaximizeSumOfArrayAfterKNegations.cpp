/*
Given an array A of integers, we must modify the array in the following way: we choose an i and replace A[i] with -A[i], and we repeat this process K times in total.  (We may choose the same index i multiple times.)
Return the largest possible sum of the array after modifying it in this way.



Example 1:
Input: A = [4,2,3], K = 1
Output: 5
Explanation: Choose indices (1,) and A becomes [4,-2,3].


Example 2:
Input: A = [3,-1,0,2], K = 3
Output: 6
Explanation: Choose indices (1, 2, 2) and A becomes [3,1,0,2].


Example 3:
Input: A = [2,-3,-1,5,-4], K = 2
Output: 13
Explanation: Choose indices (1, 4) and A becomes [2,3,-1,5,4].


Note:
    1 <= A.length <= 10000
    1 <= K <= 10000
    -100 <= A[i] <= 100

*/


// Runtime: 8 ms, faster than 86.15% of C++ online submissions for Maximize Sum Of Array After K Negations.
// Memory Usage: 9.2 MB, less than 16.54% of C++ online submissions for Maximize Sum Of Array After K Negations.
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        if (A.empty()) {
            return 0;
        }
        std::sort(A.begin(), A.end());
        auto i = 0;
        auto k = 0;
        for (; k < K && i < A.size() && A[i] < 0; ++i, ++k) {
            A[i] *= (-1);
        }
        if (k < K) {
            if (i < A.size()) { // A[i] >= 0
                if (i == 0) { // 说明原始数组所有元素都>0
                    update_value(A, i, K - k);
                } else {
                    auto min_idx = A[i - 1] < A[i] ? i - 1 : i;
                    update_value(A, min_idx, K - k);
                }
            } else { // i >= A.size(), 说明原始数组所有元素都<0
                update_value(A, A.size() - 1, K - k);
            }
        }
        return std::accumulate(A.begin(), A.end(), 0);
    }

private:
    void update_value(std::vector<int> &A, int idx, int cnt) {
        auto flag = cnt & 0b01 ? -1 : 1;
        A[idx] *= flag;
    }
};