/*
8	String to Integer (atoi)
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, 
please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given
input specs). You are responsible to gather all the input requirements up front.
*/

#include <cstring>
#include <iostream>

using namespace std;

int ATOI(string str)
{
    int i = 0, res = 0;
    char sign;

    while (i < str.length() && isspace(str[i]))
        i++;
    sign = (str[i] == '+' || str[i] == '-') ? str[i++] : '+';

    for (; i < str.length() && isdigit(str[i]); i++)
    {
        if ( res > INT_MAX / 10 ||
            (res == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10))
			return sign == '-' ? INT_MIN : INT_MAX;
        res = res * 10 + (int)(str[i] - '0');
    }
    return (sign == '+' ? res : -res);
}

void testCase_atoi()
{
    string a = "1323";
    string b = "    -21";
    string c = "+1";        // expected: 1
    string d = "  +124";
    string e = "+-2";       // expected: 0
    string f = "  -0012a42";// expected: -12
    string g = "";          // expected: 0
    string h = "2147483648";// expected: 2147483647

    cout<<ATOI(a)<<endl;
    cout<<ATOI(b)<<endl;
    cout<<ATOI(c)<<endl;
    cout<<ATOI(d)<<endl;
    cout<<ATOI(e)<<endl;
    cout<<ATOI(f)<<endl;
    cout<<ATOI(g)<<endl;
    cout<<ATOI(h)<<endl;
}
