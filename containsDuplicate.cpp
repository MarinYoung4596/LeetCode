/*
217.	Contains Duplicate
Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in 
the array, and it should return false if every element is distinct.
*/
#include <vector>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for (auto i = nums.begin(); i != nums.end(); ++i)
        {
            if (us.find(*i) == us.end())
                us.insert(*i);
            else
                return true;
        }
        return false;
    }
};