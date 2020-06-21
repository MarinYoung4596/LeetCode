/*
67. Add Binary
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

#include <string>
#include <sstream>
#include <iostream>

string binaryAdder(char aa, char bb, int &c)
{
	int a = static_cast<int>(aa - '0'),
		b = static_cast<int>(bb - '0'),
		res;

	res = (~aa & ~b & c) | (~a & b & ~c) | (a & ~b & ~c) | (a & b & c);
	c = (a & ~b & c) | (a & b & ~c) | (b & c);
	
	// stringstream ss;
	// string s;
	// ss << res;
	// ss >> s;
	return to_string(res);
}

string addBinary(string a, string b)
{
	if (a.empty()) return b;
	if (b.empty()) return a;

	string res = "";
	int indexA = a.length() - 1;
	int indexB = b.length() - 1;
	int carry = 0;
	string bit;
	for (; indexA >= 0 && indexB >= 0; --indexA, --indexB)
	{
		bit = binaryAdder(a[indexA], b[indexB], carry);
		res = bit + res;
	}
	while (indexA >= 0)
	{
		bit = binaryAdder(a[indexA--], '0', carry);
		res = bit + res;
	}
	while (indexB >= 0)
	{
		bit = binaryAdder('0', b[indexB--], carry);
		res = bit + res;
	}
	if (carry)
		res.insert(res.begin(), '1');
	return res;
}

int main(int argc, char **argv)
{
	string a = "001",
		b = "011";
	
	if (argc == 3)
	{
		a = argv[1];
        a = argv[2];
	}
	std::cout << addBinary(a, b) << std::endl;
	
	return 0;
}

