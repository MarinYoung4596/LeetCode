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
	if (len <= 1) {
        return s;
    }
	string res;
	auto max = 0, sublen = 0;
	for (auto i = 0; i < len; ++i) {
		size_t j = 0;
		// odd
		for (; i - j > 0
                && i + j < len
                && s[i - j] == s[i + j];
                ++j);
		j = (s[i - j] == s[i + j]) ? j : --j;
		sublen = 2 * j + 1;
		if (sublen >= max) {
			res = s.substr(i - j, sublen);
			max = sublen;
		}
		// event
		for (j = 0; i - j > 0
                && i + j + 1 < len
                && s[i - j] == s[i + j + 1];
                ++j);
		j = (s[i - j] == s[i + j + 1]) ? j : --j;
		sublen = 2 * j + 2;
		if (sublen >= max) {
			res = s.substr(i - j, sublen);
			max = sublen;
		}
	}
	return res;
}

// second solution
std::string getPalindrom(const std::string &str, int left, int right) {
    if (left < 0 || right >= str.size() || left > right) {
        return std::string();
    }
    while (left >= 0 && right < str.size() && str[left] == str[right]) {
    	--left;
        ++right;
    }
    return str.substr(left + 1, right - right - 1);
}

std::string getLongestPalindrom(const std::string &str) {
    std::string result;
    for (auto i = 0; i < str.size(); ++i) {
        auto odds_result = getPalindrom(str, i, i);
        auto even_result = getPalindrom(str, i, i + 1);

        if (result.size() < odds_result.size()) {
            result = odds_result;
        }
        if (result.size() < even_result.size()) {
            result = even_result;
        }
    }
    return result;
}


int main(int argc, char **argv) {
	string s = "abjjddjjjjcs";
	std::cout << longestPalindrome(s) << std::endl; //jjddjj

	return 0;
}
