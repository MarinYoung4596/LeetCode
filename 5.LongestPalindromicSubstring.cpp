/*
	5	Longest Palindromic Substring
	
	Given a string S, find the longest palindromic substring in S. 
	You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/
#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s)
{
	const auto len = s.size();
	if (len <= 1) return s;
	string res = "";
	auto max = 0, sublen = 0;
	for (auto i = 0; i < len; ++i)
	{
		size_t j = 0;
		// odd
		for (; i-j > 0 && i+j < len && s[i-j] == s[i+j]; ++j);
		j = s[i-j] == s[i+j] ? j : --j;
		sublen = 2*j+1;
		if (sublen >= max)
		{
			res = s.substr(i-j, sublen);
			max = sublen;
		}
		// event
		for (j = 0; i-j > 0 && i+j+1 < len && s[i-j] == s[i+j+1]; ++j);
		j = s[i-j] == s[i+j+1] ? j : --j;
		sublen = 2*j+2;
		if (sublen >= max)
		{
			res = s.substr(i-j, sublen);
			max = sublen;
		}
	}
	return res;
}


int main(int argc, char **argv)  
{
	string s = "abjjddjjjjcs";
	std::cout << longestPalindrome(s) << std::endl; //jjddjj


	system("pause");
	return 0;
}