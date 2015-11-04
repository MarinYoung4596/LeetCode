/*
205. Isomorphic Strings
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters.
No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/
#include <iostream>
#include <map>
#include <string>

using namespace std;


bool isIsomorphic(string s, string t)
{
	if (s.length() != t.length()) return false;
	map<char, char> maps2t, mapt2s;
	
	// why we use size_t instead of unsigned int?
	// see: http://stackoverflow.com/questions/131803/unsigned-int-vs-size-t
	for (size_t i = 0; i < s.length(); i++)
	{
		if (maps2t.find(s[i]) == maps2t.end())
		{
			if (mapt2s.find(t[i]) != mapt2s.end())
			{
				if (mapt2s[t[i]] != s[i])
					return false;
			}
			maps2t.insert(map<char, char>::value_type(s[i], t[i]));
			mapt2s.insert(map<char, char>::value_type(t[i], s[i]));
			// or the following sentence, each of them is OK
			// maps2t.insert(pair<char, char>(s[i], t[i]));
			// maps2t.insert(make_pair(s[i], t[i]));
			// maps2t[s[i]] = t[i];
		}
		else if (maps2t[s[i]] != t[i])
			return false;
	}
	return true;
}


int main()
{
	string s[] = { "egg", "foo", "paper", "ab" };
	string t[] = { "add", "bar", "title", "aa" };

	for (int i = 0; i < 4; i++)
		cout << isIsomorphic(s[i], t[i]) << endl;

	system("pause");
	return 0;
}
