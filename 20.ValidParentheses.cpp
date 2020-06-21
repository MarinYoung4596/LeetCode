/*
20.	Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
ASCII (  )    [   ]   {   }
      40 41   91 93  123 125
*/

#include <iostream>
#include <cstring>
#include <stack>

int isLeft(char ch) {
    if (ch == '(' || ch == '[' || ch == '{') {
        return 1;
    } else if (ch == ')' || ch == ']' || ch == '}') {
        return -1;
    } else {
        return 0;
    }
}

bool isValid(string s) {
    const int len = s.length();
    if (len == 0) {
        return true;
    } else if (len % 2) {
        return false;
    }

    stack<char> strStack;
    for (int i = 0; i < len; i++) {
        // if curr is left and stack is left or empty (because it can't be right), 
		//  push curr into stack
        if (isLeft(s[i]) > 0) {
            if (strStack.empty()) {
                strStack.push(s[i]);
                continue;
            } else if (isLeft(strStack.top()) > 0) {
                strStack.push(s[i]);
                continue;
            }
        }
        // if curr is right
        if (isLeft(s[i]) < 0) {
            if (strStack.empty()) {
                return false;
            }
            // if curr is right and top is left
            if ((s[i] == ')' && strStack.top() == '(') ||
                (s[i] == ']' && strStack.top() == '[') ||
                (s[i] == '}' && strStack.top() == '{') ) {
                strStack.pop();
                continue;
            } else { 
                return false;
            }
        }
    }
    return strStack.empty();
}

void testCase_isValid() {
    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "(]";
    string s4 = "([)]";
    string s5 = "";
    string s6 = "((((((";
    string s7 = "[[[";

    cout << isValid(s1) << endl;
    cout << isValid(s2) << endl;
    cout << isValid(s3) << endl;
    cout << isValid(s4) << endl;
    cout << isValid(s5) << endl;
    cout << isValid(s6) << endl;
    cout << isValid(s7) << endl;
}
