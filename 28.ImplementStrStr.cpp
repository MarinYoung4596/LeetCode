/*
28. Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/
#include <iostream>
#include <string>

typedef std::size_t size_type;

// First Solution: bruce-force
int strStr(const string haystack, const string needle)
{
	const size_type hlen = haystack.size();
	const size_type nlen = needle.size();

	size_type i = 0, j = 0;
	for (; i < hlen && j < nlen;)
	{
		if (haystack[i] == needle[j])
		{
			++i;
			++j;
		}
		else
		{
			i -= (j - 1); // i = i - j + 1;
			j = 0;
		}
	}
	return (j == nlen) ? (i - j) : -1;
}


// Second Solution : KMP
// reference: [1] http://www.ituring.com.cn/article/59881
// [2] http://www.cppblog.com/oosky/archive/2006/07/06/9486.html
// [3] http://www.rudy-yuan.net/archives/182/
int kmp(const string haystack, const string needle)
{
	const size_type hlen = haystack.size();
	const size_type nlen = needle.size();

	int *next = new int[nlen];
	getNext(needle, next);

	size_type i = 0, j = 0;
	for (; i < hlen && j < nlen;)
	{
		if (haystack[i] == needle[j])
		{
			++i;
			++j;
		}
		else
			j = next[j];
	}
	delete[] next;
	return (j == nlen) ? (i - j) : -1;
}

void getNext(const string needle, int next[])
{
	const size_type nlen = needle.size();
	next[0] = -1;		// previous overlapped string's length
						// next[k] represents the k-length head sub-string's maximum overlapped prefix and postfix
	size_type j = 0;	// index of needle
	int k = -1;
	while (j < nlen)
	{
		if (k != -1 && needle[k] != needle[j])
			k = next[k];
		++j;
		++k;
		next[j] = (needle[j] == needle[k]) ? next[k] : k;
	}
}


// Third Solution: Boyer-Moore
// Reference:
// [1] http://www.ruanyifeng.com/blog/2013/05/boyer-moore_string_search_algorithm.html
// [2] http://blog.csdn.net/appleprince88/article/details/11881323
// [3] http://www.searchtb.com/2011/07/%E5%AD%97%E7%AC%A6%E4%B8%B2%E5%8C%B9%E9%85%8D%E9%82%A3%E4%BA%9B%E4%BA%8B%EF%BC%88%E4%B8%80%EF%BC%89.html?spm=0.0.0.0.DHXot1
int bm(const string haystack, const string needle)
{

}



void testCase_strStr()
{
    string haystack = "hello world, i am Marin Young";
    string s1 = "hello";
    string s2 = "world";
    string s3 = "i";
    string s4 = "am";
    string s5 = "Marin";
    string s6 = "Young";

    cout<<strStr(haystack, s1)<<endl;
    cout<<strStr(haystack, s2)<<endl;
    cout<<strStr(haystack, s3)<<endl;
    cout<<strStr(haystack, s4)<<endl;
    cout<<strStr(haystack, s5)<<endl;
    cout<<strStr(haystack, s6)<<endl;
}
