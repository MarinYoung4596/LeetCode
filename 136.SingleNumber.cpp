/*
136. Single Number.
Given an array of integers, every element appears twice except for one.Find that single one.

Note:
Your algorithm should have a linear runtime complexity.Could you implement it without using extra memory ?
*/
#include <vector>

// First Solution, Maximum space complexity: O(N/2),
// TIME LIMIT EXCEEDED
int singleNumber(int A[], int n) 
{
	vector<int> num;
	for (int i = 0; i < n; i++)
	{
		vector<int>::iterator iter = find(num.begin(), num.end(), A[i]);
		if (iter != num.end()) // FOUND
			num.erase(iter);
		else
			num.push_back(A[i]);
	}
	return num[0];
}

// Second Solution, no extra space
int singleNumber_2(int A[], int n)
{
	int res = 0;
	for (int i = 0; i < n; i++)
		res ^= A[i];
	return res;
}
