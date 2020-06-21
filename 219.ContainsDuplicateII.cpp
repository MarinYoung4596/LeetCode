/*
219.	Contains Duplicate II
Given an array of integers and an integer k, find out whether there are two distinct 
indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
*/
#include <vector>
#include <map>

bool containsNearbyDuplicate(vector<int>& nums, int k) {
	if (nums.empty()) {
        return false;
    }

	map<int, vector<int>::iterator> um;
	for (auto i = nums.begin(); i != nums.end(); ++i) {
		if (um.find(*i) == um.end()) {
			um.insert({ *i, i });
        } else {
			if (i - um[*i] <= k) {
				return true;
            }
            um[*i] = i;
		}
	}
	return false;
}