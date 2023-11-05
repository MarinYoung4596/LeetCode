/*
Implement obj.ATOI to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge,
please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*/

#include <cstring>
#include <iostream>

using namespace std;

class Solution {
public:
    int ATOI(string str) {
        int i = 0, res = 0;
        char sign;

        while (i < str.length() && isspace(str[i])) {
            i++;
        }
        sign = (str[i] == '+' || str[i] == '-') ? str[i++] : '+';
        for (; i < str.length() && isdigit(str[i]); i++) {
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) {
                return sign == '-' ? INT_MIN : INT_MAX;
            }
            res = res * 10 + static_cast<int>(str[i] - '0');
        }
        return (sign == '+' ? res : -res);
    }
};

void test_ATOI() {
    string a = "1323";
    string b = "    -21";
    string c = "+1"; // expected: 1
    string d = "  +124";
    string e = "+-2";        // expected: 0
    string f = "  -0012a42"; // expected: -12
    string g = "";           // expected: 0
    string h = "2147483648"; // expected: 2147483647

    Solution obj;
    cout << obj.ATOI(a) << endl;
    cout << obj.ATOI(b) << endl;
    cout << obj.ATOI(c) << endl;
    cout << obj.ATOI(d) << endl;
    cout << obj.ATOI(e) << endl;
    cout << obj.ATOI(f) << endl;
    cout << obj.ATOI(g) << endl;
    cout << obj.ATOI(h) << endl;
}
