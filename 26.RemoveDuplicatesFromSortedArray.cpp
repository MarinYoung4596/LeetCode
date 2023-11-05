/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
    Given input array A = [1,1,2],
    Your function should return length = 2, and A is now [1,2].
*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) {
            return 0;
        }
        auto slow = 0;
        auto fast = 0;
        while (fast < n) {
            if (A[slow] != A[fast]) {
                ++slow;
                A[slow] = A[fast];
            }
            ++fast;
        }
        return slow + 1;
    }
};

void testCase_RemoveDuplicates() {
    int a[10] = {1, 1, 2, 2, 2, 3, 4, 4, 5, 5};
    int b[2] = {1, 1};
    int c[3] = {1, 1, 2};
    int d[] = {};
    Solution obj;
    cout << obj.removeDuplicates(a, 10) << endl;
    cout << obj.removeDuplicates(b, 2) << endl;
    cout << obj.removeDuplicates(c, 3) << endl;
    cout << obj.removeDuplicates(d, 0) << endl;
}
