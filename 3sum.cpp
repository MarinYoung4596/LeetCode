/*
15. Three Sum
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)
*/
#include <vector>
#include <algorithm>

vector<vector<int> > threeSum(vector<int> &num)
{
	vector<vector<int> > res;
	if (num.size() < 3)
		return res;

	std::sort(num.begin(), num.end());

	for (auto i = num.begin(); i != prev(num.end(), 2); ++i)
	{
		if (i > num.begin() && *i == *(i - 1)) continue;
		auto j = i + 1;		// iterator
		auto k = num.end() - 1;
		while (j < k)
		{
			if (*i + *j + *k < 0)
			{
				++j;
				while (j < k && *(j - 1) == *j) ++j;
			}
			else if (*i + *j + *k > 0)
			{
				--k;
				while (j < k && *k == *(k + 1)) --k;
			}
			else
			{
				res.push_back({ *i, *j, *k });
				++j;
				--k;
				while (j < k && *(j - 1) == *j) ++j;
				while (j < k && *k == *(k + 1)) --k;
			}
		}
	}
	return res;
}


// Another way, same method, different style.
vector<vector<int> > threeSum_2(vector<int> &num)
{
	vector<vector<int> > res;
	if (num.size() < 3)
		return res;

	std::sort(num.begin(), num.end());

	for (size_t i = 0; i < num.size() - 2; i++)// num.size()-2: because we suppose num[i] is the first element
	{
	    if (i > 0 && num[i - 1] == num[i])  // that's also very important
	        continue;   // without which, will be "Output Limited Exceeded"
		size_t left = i + 1,
			right = num.size() - 1;
		while (left < right)
		{
			int tmp = num[i] + num[left] + num[right];
			if (tmp < 0)
			{
				left++;
				while (left < right && num[left] == num[left - 1]) left++;
				tmp = num[i] + num[left] + num[right];
			}
			else if (tmp > 0)
			{
				right--;
				while (left < right && num[right] == num[right + 1]) right--;
				tmp = num[i] + num[left] + num[right];
			}
			else
			{
				res.push_back({ num[i], num[left], num[right] });

				left++;
				right--;
				while (left < right && num[left] == num[left - 1]) left++;
				while (right < right && num[right] == num[right + 1]) right--;
			}
		} // end while
	} // end for
	return res;
}
