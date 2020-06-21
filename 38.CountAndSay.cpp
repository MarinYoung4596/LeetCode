/*
38. Count And Say
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.
*/

#include <cstring>
#include <sstream>

void addIntAndChar(string &s, int n, char ch)
{
    //convert integer into string 
	// or to_string(n);
    stringstream ss;
    string tmp;
    ss<<n;
    ss>>tmp;
    s += tmp;
    // add char
    s += ch;
}

string getNextStr(string s)
{
    string res = "";
    int n = 0; // count of the number
    char num = s[0];
    for (int i = 0; i < s.size(); i++)
    {
        if (num == s[i])
            n++;
        else
        {
            addIntAndChar(res, n, num);
            num = s[i];
            n = 1;
        }
    }
    addIntAndChar(res, n, num);
    return res;
}

string countAndSay(int n)
{
    string s = "1";
    for (int i = 1; i < n; i++)
        s = getNextStr(s);
    return s;
}
