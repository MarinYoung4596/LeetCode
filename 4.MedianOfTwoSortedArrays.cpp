/*
4. Median of Two Sorted Arrays
There are two sorted arrays nums1 and nums2 of size m and n respectively. 
Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).
*/

#include <vector>

// First Solution: Time Complexity: O(M+N)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	const int M = nums1.size();
	const int N = nums2.size();
	if (nums1.empty())
		return N % 2 == 1 ? nums2[(N - 1) / 2] : (double)(nums2[N / 2] + nums2[(N - 1) / 2]) / 2;
	if (nums2.empty())
		return M % 2 == 1 ? nums1[(M - 1) / 2] : (double)(nums1[M / 2] + nums1[(M - 1) / 2]) / 2;

	vector<int> arr(M + N);
	int i, j, k;
	i = j = k = 0;
	for (; i < M && j < N;)
		arr[k++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
	while (i < M)
		arr[k++] = nums1[i++];
	while (j < N)
		arr[k++] = nums2[j++];

	return (M + N) % 2 == 1 ? arr[(M + N - 1) / 2] : (double)(arr[(M + N - 1) / 2] + arr[(M + N) / 2]) / 2;
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
double findMedianSortedArrays_2(vector<int>& nums1, vector<int>& nums2)
{
	const int Total = nums1.size() + nums2.size();
	return 0.0;
}
