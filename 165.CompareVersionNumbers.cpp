/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth
second-level revision of the second first-level revision.

Here is an example of version numbers ordering: 0.1 < 1.1 < 1.2 < 13.37
*/

#include <cstring>
#include <iostream>
#include <vector>


using namespace std;

class Solution {
private:
    void splitVersion(string s, vector<string> &v) {
        if (s.empty()) {
            return;
        }
        string tmp = "";
        for (int i = 0; i < s.length(); i++) {
            for (; s[i] != '.' && i < s.length(); i++) {
                // remove the 0 ahead of the string
                if (tmp == "" && s[i] == '0') {
                    continue;
                }
                tmp += s[i];
            }
            v.push_back(tmp);
            tmp = "";
        }
    }

    int compareNumberInString(string str1, string str2) {
        // we assume that there's no zero number ahead of the string, e.g. "0045" doesn't exist
        int res;
        if (str1.size() == str2.size()) {
            for (int i = 0; i < str1.size(); i++) {
                if (str1[i] == str2[i]) {
                    continue;
                }
                return str1[i] > str2[i] ? 1 : -1;
            }
            return 0;
        }
        return str1.size() > str2.size() ? 1 : -1;
    }

public:
    int compareVersion(string version1, string version2) {
        vector<string> v_str1, v_str2;
        splitVersion(version1, v_str1);
        splitVersion(version2, v_str2);

        // remove the right zeros
        while (!v_str1.empty() && v_str1.back().empty()) {
            v_str1.pop_back();
        }
        while (!v_str2.empty() && v_str2.back().empty()) {
            v_str2.pop_back();
        }

        int res;
        for (int i = 0; i < v_str1.size() && i < v_str2.size(); i++) {
            if ((res = compareNumberInString(v_str1[i], v_str2[i])) != 0) {
                return res;
            }
            // else means they are equal, go to compare next str
        }
        // if the above for-loop didn't return, means the first x string are equal,
        // and looped to the end of one or both of the vector, then check the length
        if (v_str1.size() == v_str2.size()) {
            return 0;
        } else {
            return v_str1.size() > v_str2.size() ? 1 : -1;
        }
    }
};

void testCase_CompareVersion() {
    string s1 = "132.4";
    string s2 = "13.24";
    string s3 = "13.4";
    string s4 = "013.24";
    string s5 = "13.024";
    string s6 = "1";
    string s7 = "0";
    string s8 = "001";
    string s9 = "1.0";
    string s10 = "1.2";
    string s11 = "1.10";
    string s12 = "01.0035.4.7";
    string s13 = "1.35.4.7.1";
    string s14 = "0.1";

    Solution obj;
    cout << "s1, s2; expected: 1\toutput: " << obj.compareVersion(s1, s2) << endl;
    cout << "s2, s1; expected: -1\toutput: " << obj.compareVersion(s2, s1) << endl;
    cout << "s2, s3; expected: 1\toutput: " << obj.compareVersion(s2, s3) << endl;
    cout << "s2, s4; expected: 0\toutput: " << obj.compareVersion(s2, s4) << endl;
    cout << "s2, s5; expected: 0\toutput: " << obj.compareVersion(s2, s5) << endl;
    cout << "s6, s7; expected: 1\toutput: " << obj.compareVersion(s6, s7) << endl;
    cout << "s6, s8; expected: 0\toutput: " << obj.compareVersion(s6, s8) << endl;
    cout << "s6, s9; expected: 0\toutput: " << obj.compareVersion(s6, s9) << endl;   //
    cout << "s9, s10; expected:-1\toutput: " << obj.compareVersion(s9, s10) << endl; //
    cout << "s9, s14; expected: 1\toutput: " << obj.compareVersion(s9, s14) << endl;
    cout << "s10, s11; expected: -1\toutput: " << obj.compareVersion(s10, s11) << endl;
    cout << "s12, s13; expected: -1\toutput: " << obj.compareVersion(s12, s13) << endl;
}

int main(int argc, char **argv) {
    testCase_CompareVersion();

    return 0;
}
