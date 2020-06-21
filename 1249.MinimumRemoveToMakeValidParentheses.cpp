/*
Given a string s of '(' , ')' and lowercase English characters. 
Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
Formally, a parentheses string is valid if and only if:
    It is the empty string, contains only lowercase characters, or
    It can be written as AB (A concatenated with B), where A and B are valid strings, or
    It can be written as (A), where A is a valid string.
 

Example 1:
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.


Example 2:
Input: s = "a)b(c)d"
Output: "ab(c)d"


Example 3:
Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.


Example 4:
Input: s = "(a(b(c)d)"
Output: "a(b(c)d)"
 

Constraints:
1 <= s.length <= 10^5
s[i] is one of  '(' , ')' and lowercase English letters.

 */

// first solution: 时间换空间
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        std::stack<int> ss;
        std::unordered_set<int> us;
        for (auto i = 0; i < s.size(); ++i) {
            if (s[i] != '(' && s[i] != ')') {
                continue;
            }
            if (s[i] == '(') {
                ss.push(i);
                continue;
            }
            if (ss.empty()) {
                us.insert(i);
                continue;
            }
            ss.pop();
        }
        if (ss.empty() && us.empty()) {
            return s;
        }
        while (!ss.empty()) {
            us.insert(ss.top());
            ss.pop();
        }
        //std::cout << "us.size=" << us.size() << "\tss.size=" << ss.size() << '\n';
        std::string result;
        for (auto i = 0; i < s.size(); ++i) {
            if (us.find(i) != us.end()) {
                continue;
            }
            result += s[i];
        }
        return result;
    }
};


// second solution: 空间换时间；O(n)
// 用index数组而非set存储当前位置字符是否非法，最后做一次copy
