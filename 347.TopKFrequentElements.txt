/*
347. Top K Frequent Elements

Given a non-empty array of integers, return the k most frequent elements.

For example,
 Given [1,1,1,2,2,3] and k = 2, return [1,2]. 

Note: 

•You may assume k is always valid, 1 = k = number of unique elements.
•Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

*/

class Solution {
public:
	/* First Solution: using vector (linear array), 842ms in total*/
	vector<int> topKFrequent(vector<int>& nums, int k)
	{
		vector<pair<int, int>> mapping;
		auto iter_map = mapping.begin();
		for (auto iter = nums.begin(); iter != nums.end(); ++iter)
		{	
			iter_map = find_if(mapping.begin(), mapping.end(), [&](const pair<int, int> &x)->bool{
				    return x.first == *iter;
			});
			if ( iter_map != mapping.end())
				++iter_map->second;
			else
				mapping.push_back({ *iter, 1 });
		}

		std::sort(mapping.begin(), mapping.end(),
			[&](const pair<int, int> &x, const pair<int, int> &y)->bool{
			return x.second > y.second;
		});

		vector<int> res;
		auto i = 0;
		for (auto iter = mapping.begin(); iter != mapping.end() && i < k; ++i, ++iter)
		{
			res.push_back(iter->first);
		}
		return res;
	}
	
	
	/*Second Solution: using map (rb-tree) & unordered_map (hash-table)*/
	vector<int> topKFrequent(vector<int>& nums, int k)
	{
		unordered_map<int,int> um; // <key, freq>
		for (auto &x : nums)
		{
		    um[x]++;
		}
		multimap<int,int, greater<int>> mm; // <freq, key>
		for (auto it = um.begin(); it != um.end(); ++it)
		{
		    mm.insert({it->second, it->first});
		}
		vector<int> res; // <key>
		for (auto it = mm.begin(); k != 0 && it != mm.end(); --k, ++it)
		{
		    res.push_back(it->second);
		}
		return res;
	}
	
	
	/*Third Solution: using priority queue (max heap)*/
};