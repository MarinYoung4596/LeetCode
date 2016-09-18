/*
43. Multiply Strings

Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2)
	{
		// preprocessing
		if (num1 == "0" || num2 == "0" ||
			num1.empty() || num2.empty()) return "0";

		const auto len = num1.size() + num2.size();
		auto p = new int[len];
		memset(p, 0, len * sizeof(int));	// must be len*sizeof(int)
		// 不知道相乘后的长度，所以从前往后
		for (auto i = 0; i < num1.size(); ++i)
		{
			for (auto j = 0; j < num2.size(); ++j)
			{
				// here += 
				// +1 预留空间。防止最高位>= 10 进位的情况
				*(p+1 + i + j) += static_cast<int>(num1[i] - '0') * static_cast<int>(num2[j] - '0');
			}
		}
		for (int k = len - 1; k != 0; --k) // k>0
		{
			if (*(p + k) >= 10) // >= 10
			{
				*(p + k - 1) += *(p + k) / 10; // +=
				*(p + k) %= 10;
			}
		}

		string result;
		for (auto k = len - 1; k != 0; --k) // k > 0
			result += to_string(*(p + k));

		if (0 != *p)
			result += to_string(*p); // k = 0
		
		delete[] p;
		reverse(result.begin(), result.end());
		return result;
	}
};

int main(int argc, const char * argv[]) {
	// insert code here...
	Solution obj;
	string a = "456";
	string b = "123";
	std::cout << obj.multiply(a, b) << std::endl;

	system("pause");
	return 0;
}

