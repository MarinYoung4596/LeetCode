/*
14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.
*/

#include <string>
#include <vector>

// compare each character of each str in the vector.
string longestCommonPrefix(vector<string>& strs)
{
	if (strs.empty()) return "";

	for (int index = 0; index < strs[0].size(); index++)
	{
		for (size_t i = 1; i < strs.size(); i++)
		{
			if (strs[i][index] != strs[0][index])
				return strs[0].substr(0, index);
		}
	}
	return strs[0];
}
