/*
179. Largest Number
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	string largestNumber(vector<int> &nums)
	{
		string res = "";
		if (nums.empty())
			return res;
	
		vector<string> arr;
		for (int i : nums)		// a new traversal method
			arr.push_back(to_string(i));	// a new method to convert integer to string
		
		sort(arr.begin(), arr.end(), compare);
	
		for (string str : arr)
			res += str;
	
	    if (res[0] == '0' && !res.empty())	// fot the case that res="000", then return "0"
			return "0";
		return res;
	}

private:
	static bool compare(string &s1, string &s2)
	{
		return s1 + s2 > s2 + s1;
	}
};

int main()
{
	Solution obj;
	
	int a[] = { 9, 30, 84, 5, 9, 78, 1, 64, 19 };
	vector<int> nums(&a[0], &a[0] + sizeof(a) / sizeof(int));
	cout << obj.largestNumber(nums) << endl;

	vector<int> b = { 10, 2 };
	cout << obj.largestNumber(b) << endl;
	
	return 0;
}
