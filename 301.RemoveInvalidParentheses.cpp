/*
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note:
    The input string may contain letters other than the parentheses ( and ).

Example 1:
    Input: "()())()"
    Output: ["()()()", "(())()"]

Example 2:
    Input: "(a)())()"
    Output: ["(a)()()", "(a())()"]

Example 3:
    Input: ")("
    Output: [""]


Hint
1) Since we don't know which of the brackets can possibly be removed, we try out all the options!
2) We can use recursion to try out all possibilities for the given expression. For each of the brackets, we have 2 options:
    a) We keep the bracket and add it to the expression that we are building on the fly during recursion.
    b) OR, we can discard the bracket and move on.
3) The one thing all these valid expressions have in common is that they will all be of the same length i.e. as compared to the original expression, all of these expressions will have the same number of characters removed. Can we somehow find the number of misplaced parentheses and use it in our solution?
4) For every left parenthesis, we should have a corresponding right parenthesis. We can make use of two counters which keep track of misplaced left and right parenthesis and in one iteration we can find out these two values.
    0 1 2 3 4 5 6 7
    ( ) ) ) ( ( ( )
    i = 0, left = 1, right = 0
    i = 1, left = 0, right = 0
    i = 2, left = 0, right = 1
    i = 3, left = 0, right = 2
    i = 4, left = 1, right = 2
    i = 5, left = 2, right = 2
    i = 6, left = 3, right = 2
    i = 7, left = 2, right = 2
    We have 2 misplaced left and 2 misplaced right parentheses.
5) We found out that the exact number of left and right parenthesis that has to be removed to get a valid expression. So, e.g. in a 1000 parentheses string, if there are 2 misplaced left and 2 misplaced right parentheses, after we are done discarding 2 left and 2 right parentheses, we will have only one option per remaining character in the expression i.e. to consider them. We can't discard them.

*/


// first solution: bfs
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        queue<string> q;
        unordered_set<string> visited;
        bool is_found = false;
        q.push(s);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();

            if (is_valid(t)) {
                result.push_back(t);
                is_found = true;
            }
            if (is_found) {
                continue; // 防止在合法括号字符串里删除
            }
            for (auto i = 0; i < t.size(); ++i) {
                if (t[i] != '(' && t[i] != ')') {
                    continue;
                }
                // 删除当前字符 t[i]
                auto substr = t.substr(0, i) + t.substr(i + 1, t.size() - i - 1);
                // 防止重复
                if (visited.count(substr) > 0) {
                    continue;
                }
                q.push(substr);
                visited.insert(substr);
            }
        }
        return result;
    }

private:
    bool is_valid(const string &str) {
        stack<int> s;
        for (auto i = 0; i < str.size(); ++i) {
            if (str[i] == '(') {
                s.push(i);
            } else if (str[i] == ')') {
                if (s.empty()) {
                    return false;
                }
                s.pop();
            }
        }
        return s.empty();
    }
};