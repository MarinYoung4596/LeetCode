/*
93. Restore IP Addresses
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void DFS(string s, size_t start, size_t step, string ip, vector<string> &res)
{
	if (start == s.size() && step == 4)
	{
		ip = ip.substr(0, ip.size() - 1);	// drop '\0'
		res.push_back(ip);
		return;
	}

	if ((s.size() - start) > 3 * (4 - step) ||	
		(s.size() - start) < (4 - step))
		return;

	int tmp = 0;
	for (size_t i = start; i < start + 3; i++)
	{
		tmp = tmp * 10 + (int)(s[i] - '0');
		if (tmp <= 255)	// every bit 0 <= x <= 255
		{
			ip += s[i];
			DFS(s, i + 1, step + 1, ip + '.', res);
		}
		if (tmp == 0)
			break;
	}
}

vector<string> restoreIpAddresses(string s)
{
	vector<string> res;
	string ip;
	DFS(s, 0, 0, ip, res);
	return res;
}

int main()
{
	string s = "25525511135";
	vector<string> v = restoreIpAddresses(s);
	for (auto i = v.begin(); i != v.end(); ++i)
		cout << *i << ", ";

	return 0;
}
