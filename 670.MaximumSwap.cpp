/*
Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.


Example 1:
    Input: 2736
    Output: 7236
    Explanation: Swap the number 2 and the number 7.

Example 2:
    Input: 9973
    Output: 9973
    Explanation: No swap.


Note:
    The given number is in the range [0, 10^8]
*/

class Solution {
public:
    int maximumSwap(int num) {
        auto str = to_string(num);
        stack<pair<int, int>> max_stack; // 保留 str[i] 位置之后的最大值及下标
        for (int i = str.size() - 1; i >= 0; --i) {
            auto cur = str[i] - '0';
            if (max_stack.empty() || cur > max_stack.top().first) {
                max_stack.push(make_pair(cur, i));
            } else {
                max_stack.push(max_stack.top());
            }
        }
        for (auto i = 0; i < str.size(); ++i) { // 从前往后，第一个不是最大值的位置交换
            auto cur = str[i] - '0';
            if (cur == max_stack.top().first) {
                max_stack.pop();
                continue;
            } else { // cur < max_stack.top
                swap(str[i], str[max_stack.top().second]);
                break;
            }
        }
        return stoi(str);
    }
};
