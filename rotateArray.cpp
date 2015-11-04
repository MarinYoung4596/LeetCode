/*
189.	Rotate Array
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Hint:
Could you do it in-place with O(1) extra space?
Related problem: Reverse Words in a String II
*/
#include <iostream>

using namespace std;

void rotate(int nums[], int n, int k)
{
    if (k == n)
        return;
    k = k % n;
    int *tmp = new int[n];
    // tmp[0]~tmp[k-1] <-- nums[n-k]~nums[n-1]
    memcpy(tmp, nums + (n-k), k * sizeof(int));
    // tmp[k]~tmp[n-1] <-- nums[0]~num[n-k-1]
    memcpy(tmp + k, nums, (n-k) * sizeof(int));
    memcpy(nums, tmp, n * sizeof(int));
    delete[] tmp;
}
