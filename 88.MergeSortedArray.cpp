/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
    You may assume that A has enough space (size that is greater or equal to m + n)
    to hold additional elements from B.
    The number of elements initialized in A and B are m and n respectively.
*/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int index = m + n - 1;
        m--; // A index
        n--; // B index
        while (m >= 0 && n >= 0) {
            if (A[m] > B[n]) {
                A[index--] = A[m--];
            } else {
                A[index--] = B[n--]; // including A[m] == B[n]
            }
        }
        while (m >= 0) {
            A[index--] = A[m--];
        }
        while (n >= 0) {
            A[index--] = B[n--];
        }
    }
};
