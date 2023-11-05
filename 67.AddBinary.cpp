/*
Given two binary strings, return their sum (also a binary string).

For example,
    a = "11"
    b = "1"
    Return "100".
*/

#include <string>
#include <sstream>
#include <iostream>

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty()) {
            return b;
        }
        if (b.empty()) {
            return a;
        }

        string res = "";
        int index_a = a.length() - 1;
        int index_b = b.length() - 1;
        int carry = 0;
        string bit;
        for (; index_a >= 0 && index_b >= 0; --index_a, --index_b) {
            bit = binaryAdder(a[index_a], b[index_b], carry);
            res = bit + res;
        }
        while (index_a >= 0) {
            bit = binaryAdder(a[index_a--], '0', carry);
            res = bit + res;
        }
        while (index_b >= 0) {
            bit = binaryAdder('0', b[index_b--], carry);
            res = bit + res;
        }
        if (carry) {
            res.insert(res.begin(), '1');
        }
        return res;
    }

private:
    string binaryAdder(char aa, char bb, int &c) {
        int a = static_cast<int>(aa - '0');
        int b = static_cast<int>(bb - '0');
        int res = (~aa & ~b & c) | (~a & b & ~c) | (a & ~b & ~c) | (a & b & c);
        c = (a & ~b & c) | (a & b & ~c) | (b & c);
        return to_string(res);
    }
};

int main(int argc, char **argv) {
    string a = "001";
    string b = "011";

    if (argc == 3) {
        a = argv[1];
        a = argv[2];
    }
    Solution obj;
    std::cout << obj.addBinary(a, b) << std::endl;

    return 0;
}
