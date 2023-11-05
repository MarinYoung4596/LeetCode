/*
In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.

Return the element repeated N times.

 
Example 1:

Input: [1,2,3,3]
Output: 3
Example 2:

Input: [2,1,2,5,3,2]
Output: 2
Example 3:

Input: [5,1,5,2,5,3,5,4]
Output: 5
 

Note:

4 <= A.length <= 10000
0 <= A[i] < 10000
A.length is even
*/

class Solution {
public:
    // 方法一：
    int repeatedNTimes(vector<int>& A) {
        std::sort(A.begin(), A.end());
        
        int left = A.size() / 2 - 1;
        int right = left + 1;
        if (A[left] == A[left - 1]) {
            return A[left];
        } else {
            return A[right];
        }
    }

    // second solution: unordered_set

};