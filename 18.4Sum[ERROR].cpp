/*
18. 4Sum
Given an array S of n integers, are there elements a, b, c, and d in S such that
a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

A solution set is:
(-1,  0, 0, 1)
(-2, -1, 1, 2)
(-2,  0, 0, 2)
*/
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std::tr1;
using namespace std;

vector<vector<int> > fourSum(vector<int> &num, int target)
{
	vector<vector<int> > res;
	if (num.size() < 4)
		return res;
	std::sort(num.begin(), num.end());		// O(NlogN)

	unordered_multimap<int, pair<int, int> > cache;	// total elements: N*N/2
	for (size_t i = 0; i < num.size() - 1; ++i)
	{
		for (size_t j = i + 1; j < num.size(); ++j)	// O(N*N/2)
			cache.insert(make_pair(num[i] + num[j], make_pair(i, j)));
	}
	for (auto i = cache.begin(); i != prev(cache.end()); ++i)
	{
		for (auto j = next(i); j != cache.end(); ++j)
		{
			if (i->first + j->first != target)
				continue;
			// else, means they are equal
			auto a = i->second.first;
			auto b = i->second.second;
			auto c = j->second.first;
			auto d = j->second.second;
			if (a != c && a != d && b != c && b != d)// previous job ensure that a != b and c != d
			{
				vector<int> vec = { num[a], num[b], num[c], num[d] };
				std::sort(vec.begin(), vec.end());
				res.push_back(vec);
			}
		}
	}
	std::sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	return res;
}


void printMartix(vector<vector<int> > &num)
{
	for (size_t i = 0; i < num.size(); i++)
	{
		cout << "[ ";
		for (size_t j = 0; j < num[i].size(); j++)
			cout << num[i][j] << ' ';
		cout << "]" << endl;
	}
	cout << endl;
}

void testCase_4Sum()
{
	vector<int> v = { 1, 0, -1, 0, -2, 2 };
	int target = 0;
	vector<vector<int> > vv;
	vv = fourSum(v, target);
	printMartix(vv);

	cout << endl;
	v.clear();

	int a[] = { 0, 0, 0, 0 };
	v.insert(v.begin(), a, a + sizeof(a) / sizeof(int));
	target = 0;
	vv = fourSum(v, target);
	printMartix(vv);
}

