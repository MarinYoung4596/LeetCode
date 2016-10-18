/*
415. Add Strings

Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

class Solution {
public:
	string addStrings(string &num1, string &num2)
	{
		if (num1.empty() || num1 == "0") return num2;
		if (num2.empty() || num2 == "0") return num1;

		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		int n = max(num1.size(), num2.size()) + 1;
		vector<int> v(n, 0);
		int i = 0;
		for (; i < num1.size() && i < num2.size(); ++i)
		{
			v[i] = static_cast<int>(num1[i] - '0') + static_cast<int>(num2[i] - '0');
		}
		for (; i < num1.size(); ++i)
		{
			v[i] = static_cast<int>(num1[i] - '0');
		}
		for (; i < num2.size(); ++i)
		{
			v[i] = static_cast<int>(num2[i] - '0');
		}
		for (i = 0; i < v.size() - 1; ++i)
		{
			v[i + 1] += v[i] / 10;
			v[i] %= 10;
		}
		// vector to string
		string res = "";
		for (auto iter = v.begin(); iter != v.end(); ++iter)
		{
			res += to_string(*iter);
		}
		if (res.back() == '0')
		{
			res.erase(res.end() - 1);
		}
		reverse(res.begin(), res.end());
		return res;
	}
};