/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
ASCII (  )    [   ]   {   }
     40 41   91 93  123 125
*/

#include <iostream>
#include <cstring>
#include <stack>

class Solution {
private:
    int is_left(char ch) {
        if (ch == '(' || ch == '[' || ch == '{') {
            return 1;
        } else if (ch == ')' || ch == ']' || ch == '}') {
            return -1;
        } else {
            return 0;
        }
    }

public:
    bool isValid(string s) {
        const int len = s.length();
        if (len == 0) {
            return true;
        } else if (len % 2) {
            return false;
        }
        stack<char> bracket_stack;
        for (int i = 0; i < len; i++) {
            // if curr is left and stack is left or empty (because it can't be right),
            //  push curr into stack
            if (is_left(s[i]) > 0) {
                if (bracket_stack.empty()) {
                    bracket_stack.push(s[i]);
                    continue;
                } else if (is_left(bracket_stack.top()) > 0) {
                    bracket_stack.push(s[i]);
                    continue;
                }
            }
            // if curr is right
            if (is_left(s[i]) < 0) {
                if (bracket_stack.empty()) {
                    return false;
                }
                // if curr is right and top is left
                if ((s[i] == ')' && bracket_stack.top() == '(') ||
                    (s[i] == ']' && bracket_stack.top() == '[') ||
                    (s[i] == '}' && bracket_stack.top() == '{') ) {
                    bracket_stack.pop();
                    continue;
                } else {
                    return false;
                }
            }
        }
        return bracket_stack.empty();
    }
};

int main() {
    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "(]";
    string s4 = "([)]";
    string s5 = "";
    string s6 = "((((((";
    string s7 = "[[[";

    Solution obj;
    cout << obj.isValid(s1) << endl;
    cout << obj.isValid(s2) << endl;
    cout << obj.isValid(s3) << endl;
    cout << obj.isValid(s4) << endl;
    cout << obj.isValid(s5) << endl;
    cout << obj.isValid(s6) << endl;
    cout << obj.isValid(s7) << endl;

    return 0;
}
