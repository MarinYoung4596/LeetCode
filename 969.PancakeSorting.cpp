/*
Given an array A, we can perform a pancake flip: We choose some positive integer k <= A.length, then reverse the order of the first k elements of A.  We want to perform zero or more pancake flips (doing them one after another in succession) to sort the array A.
Return the k-values corresponding to a sequence of pancake flips that sort A.  Any valid answer that sorts the array within 10 * A.length flips will be judged as correct.


Example 1:
    Input: [3,2,4,1]
    Output: [4,2,4,3]
    Explanation:
        We perform 4 pancake flips, with k values 4, 2, 4, and 3.
        Starting state: A = [3, 2, 4, 1]
        After 1st flip (k=4): A = [1, 4, 2, 3]
        After 2nd flip (k=2): A = [4, 1, 2, 3]
        After 3rd flip (k=4): A = [3, 2, 1, 4]
        After 4th flip (k=3): A = [1, 2, 3, 4], which is sorted.


Example 2:
    Input: [1,2,3]
    Output: []
    Explanation: The input is already sorted, so there is no need to flip anything.
        Note that other answers, such as [3, 3], would also be accepted.


Note:
    1 <= A.length <= 100
    A[i] is a permutation of [1, 2, ..., A.length]

*/

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        std::vector<int> result;
        pancake_sort_helper(result, A, A.size());
        return result;
    }

private:
    // 1、找到堆中（大小为n）的最大饼。
    // 2、把最大饼移到堆底。
    // 3、递归， pancakeSort(A, n - 1)。
    void pancake_sort_helper(std::vector<int> &result, std::vector<int> &A, int n) {
        if (n == 1) {
            return;
        }
        int max_cake = INT_MIN;
        int max_cake_index = 0;
        for (auto i = 0; i < n; ++i) {
            if (max_cake < A[i]) {
                max_cake = A[i];
                max_cake_index = i;
            }
        }

        // 1st step
        reverse(A, 0, max_cake_index);
        result.push_back(max_cake_index + 1);

        // 2nd step
        reverse(A, 0, n - 1);
        result.push_back(n); //

        // 3rd step: recursive
        pancake_sort_helper(result, A, n - 1);
    }

    void reverse(std::vector<int> &A, int begin, int end) {
        while (begin < end) {
            swap(A[begin++], A[end--]);
        }
    }
};