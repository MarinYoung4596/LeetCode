/*
4. Median of Two Sorted Arrays
There are two sorted arrays nums1 and nums2 of size m and n respectively. 
Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).
*/

#include <vector>

// First Solution: Time Complexity: O(M+N)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	const int M = nums1.size();
	const int N = nums2.size();
	if (nums1.empty()) {
		return N % 2 == 1 ? \
                nums2[(N - 1) / 2] : \
                static_cast<double>(nums2[N / 2] + nums2[(N - 1) / 2]) / 2;
    }
    if (nums2.empty()) {
		return M % 2 == 1 ? \
                nums1[(M - 1) / 2] : \
                static_cast<double>(nums1[M / 2] + nums1[(M - 1) / 2]) / 2;
    }

    vector<int> arr(M + N, 0);
	auto k = 0;
    auto i = 0;
    auto j = 0;
	while (i < M && j < N) {
		arr[k++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
    }
	while (i < M) {
		arr[k++] = nums1[i++];
    }
	while (j < N) {
		arr[k++] = nums2[j++];
    }

	return (M + N) % 2 == 1 ? \
            arr[(M + N - 1) / 2] : \
            static_cast<double>(arr[(M + N - 1) / 2] + arr[(M + N) / 2]) / 2;
}

// Second Solution
/* 因为我们仅仅需要第k大的元素。
我们可以用一个计数器，记录当前已经找到第m大的元素了。同时我们使用两个指针pA和pB，
分别指向A和B数组的第一个元素。使用类似于merge sort的原理，如果数组A当前元素小，
那么pA++，同时m++。如果数组B当前元素小，那么pB++，同时m++。最终当m等于k的时候，
就得到了我们的答案——O(k)时间，O(1)空间。
*/


// Third Solution: Time Complexity O(log(M + N))
// see: http://blog.csdn.net/zxzxy1988/article/details/8587244
// (1) 当某个数组查找的起始位置大于等于该数组长度时，说明这个数组中的所有数已经被淘汰，
//     则只需要在另一个数组找查找即可
// (2) 如果k=1时，即需要查找第一个数，则找到两个数组起始位置中最小的那个即可。
// https://www.nowcoder.com/discuss/196951

class Solution {
public:
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
        const auto len = num1.size() + num2.size();
        if (len & 0x01) {
            return find_kth(num1.begin(), num1.size(), num2.begin(), num2.size(), len / 2 + 1);
        } else {
            auto v1 = find_kth(num1.begin(), num1.size(), num2.begin(), num2.size(), len / 2);
            auto v2 = find_kth(num1.begin(), num1.size(), num2.begin(), num2.size(), len / 2 + 1);
            return static_cast<double>(v1 + v2) / 2;
        }
    }

private:
    typedef std::vector<int>::const_iterator Iterator;

    int find_kth(Iterator A, int m,
                 Iterator B, int n,
                 int k) {
        // always assume that A.size() is equal or smaller than B.size()
        if (m > n) {
            return find_kth(B, n, A, m, k);
        }
        // A为空，直接返回B[k-1] （前面已经假设A比B短）
        if (m == 0) {
            return B[k - 1];
        }
        // k == 1
        if (k == 1) {
            return std::min(A[0], B[0]);
        }
        int pa = std::min(k / 2, m); // 从1/2处开始
        int pb = k - pa;
        if (A[pa - 1] < B[pb - 1]) { // 0~pa 抛弃
            return find_kth(A + pa, m - pa, B, n, k - pa);
        } else if (A[pa - 1] > B[pb - 1]) { // 0~pb 抛弃
            return find_kth(A, m, B + pb, n - pb, k - pb);
        } else { // 二者相等, 说明前面有pa-1+pb-1 = pa - 1 + k - pa - 1 = k - 2 个元素，直接返回它本身即可
            return A[pa - 1];
        }
    }
};
