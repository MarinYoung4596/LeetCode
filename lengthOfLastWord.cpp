/*
58. Length of Last Word
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
return the length of last word in the string.
If the last word does not exist, return 0.
Note: A word is defined as a character sequence consists of non-space characters only.
For example,
Given s = "Hello World",
return 5.
*/

#include <iostream>
#include <cstring>

using namespace std;

int lengthOfLastWord(string s)
{
	int len = s.size();
	if (len == 0)
		return 0;
	int count = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		if (s[i] == ' ')
		{
			if (!count)
				continue;
			else
				return count;
		}
		count++;
	}
	return count;
}


int lengthOfLastWord(const char *s)
{
	int len = strlen(s);
	if (len == 0)
		return 0;
	int count = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		if (*(s + i) == ' ')
		{
			if (!count)
				continue;
			else
				return count;
		}
		count++;
	}
	return count;
}


void testCase_lengthOfLastWord()
{
    char *s1 = "hello world";
    char *s2 = " hello world ";
    char *s3 = "";
    char *s4 = "wo shi yang nan";
    char *s5 = " ";
    char *s6 = "world";

    cout<<lengthOfLastWord(s1)<<endl;
    cout<<lengthOfLastWord(s1)<<endl;
    cout<<lengthOfLastWord(s3)<<endl;
    cout<<lengthOfLastWord(s4)<<endl;
    cout<<lengthOfLastWord(s5)<<endl;
    cout<<lengthOfLastWord(s6)<<endl;
}

int main()
{
	testCase_lengthOfLastWord();
}
