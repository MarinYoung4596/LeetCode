/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    316.RemoveDuplicateLetters.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/01/08 19:05:57
*   @brief:

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is
the smallest in lexicographical order among all possible results.

Example 1:
    Input: s = "bcabc"
    Output: "abc"

Example 2:
    Input: s = "cbacdcbc"
    Output: "acdb"

Constraints:
    1 <= s.length <= 10^4
    s consists of lowercase English letters.

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

*****************************************************************/

#include <stack>
#include "util.h"


// first solution: backtrack
// TODO bug 待调通
class Solution {
public:
    string removeDuplicateLetters(string s) {
        // 1) 先找出所有 uniq 字符
        unordered_map<char, vector<int>> char_pos_map;
        for (auto i = 0; i < s.size(); ++i) {
            auto ch = s[i];
            if (char_pos_map.find(ch) == char_pos_map.end()) {
                char_pos_map[ch] = vector<int>();
            }
            char_pos_map[ch].push_back(i);
        }
        vector<std::pair<char, vector<int>>> char_pos_list;
        for (auto [ch, pos_list] : char_pos_map) {
            char_pos_list.push_back(std::make_pair(ch, pos_list));
            // std::cout << "ch: " << ch << "\tpos: " << join(pos_list, ',') << "\n";
        }
        // 2）从每个ch 中选一个
        vector<string> candidates;
        vector<pair<char, int>> tmp_res;
        unordered_map<char, int> char_map;
        backtrack(char_pos_list, char_map, candidates, tmp_res, 0);

        // 4) 按照字典序排序
        std::sort(candidates.begin(), candidates.end());
        candidates.erase(std::unique(candidates.begin(), candidates.end()), candidates.end());
        print_vector(candidates);
        // 5) 返回第一个
        return candidates[0];
    }

private:
    string vec_to_str(vector<std::pair<char, int>> vec) {
        std::sort(vec.begin(), vec.end(),
                [&](const pair<char, int> &lhs, const pair<char, int> &rhs) {
                    return lhs.second < rhs.second;  // 按照位置排序
                });
        string res = "";
        for (auto& [ch, pos] : vec) {
            res += ch;
        }
        return res;
    }

    string tmp_vec_to_str(const vector<std::pair<char, int>> &vec) {
        stringstream ss;
        for (auto item : vec) {
            ss << item.first << "|" << item.second << ", ";
        }
        return ss.str();
    }

    void backtrack(const vector<std::pair<char, vector<int>>>& char_pos_list, /* 原始 */
                   unordered_map<char, int>& char_map,
                   vector<string>& final_res, /*最终结果*/
                   vector<std::pair<char, int>> tmp_res, /*临时结果*/
                   int index /*当前迭代位置*/) {

        auto tmp_res_str = vec_to_str(tmp_res);
        /*
        std::cout << "BEGIN: index=" << index
                  << " tmp_res_str=" << tmp_vec_to_str(tmp_res)
                  << " final_res_str=" << tmp_res_str << std::endl;
        */
        if (tmp_res.size() == char_pos_list.size()) {
            final_res.push_back(tmp_res_str);
            auto it = std::find(final_res.begin(), final_res.end(), tmp_res_str);
            if (it == final_res.end()) {
                final_res.push_back(tmp_res_str);
            }
            return;
        }
        for (auto i = index; i < char_pos_list.size(); ++i) {
            auto ch = char_pos_list[i].first;
            if (char_map.find(ch) != char_map.end()) {
                break;
            }
            char_map[ch] = tmp_res.size();

            auto tmp_str = vec_to_str(tmp_res);
            /*
            std::cout << "MID: index=" << index
                      << " tmp_res=" << tmp_str
                      << " cur_ch=" << ch
                      << " after=" << tmp_str + ch;
            */
            tmp_res.push_back(std::make_pair(ch, -1));
            auto& pos_list = char_pos_list[i].second;
            for (auto pos : pos_list) {
                // std::cout << " pos=" << pos << std::endl;
                tmp_res[char_map[ch]].second = pos;
                backtrack(char_pos_list, char_map, final_res, tmp_res, index + 1);
            }
        }
    }
};

// Second Solution: stack
// O(N), AC
class Solution2 {
public:
    string removeDuplicateLetters(string s) {
        std::stack<char> stk;
        std::vector<int> counter(256, 0);
        for (auto ch : s) {  // 统计s 中各字符频次
            counter[ch] += 1;
        }
        std::vector<bool> is_in_stack(256, false);
        for (auto ch : s) {
            counter[ch] -= 1;

            if (is_in_stack[ch]) {  // 当前字符已经在栈中,不入栈
                continue;
            }
            while (!stk.empty() && stk.top() > ch) {  // 比较当前字符 和 栈顶字符的大小（字典序）
                if (0 == counter[stk.top()]) {  // 后面没有栈顶字符, 不pop
                    break;
                }
                is_in_stack[stk.top()] = false;   // 否则,pop
                stk.pop();
            }
            is_in_stack[ch] = true;
            stk.push(ch);
        }
        //
        string result = "";
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        std::reverse(result.begin(), result.end());
        return result;
    }

};

int main() {
    Solution2 obj;
    std::string line = "cbacdcbc";
    auto res = obj.removeDuplicateLetters(line);

    std::cout << "input=" << line << "\toutput=" << res << std::endl;
    //while (std::getline(std::cin, line)) {
    //    auto res = obj.removeDuplicateLetters(line);
    //    std::cout << "input=" << line << "\toutput=" <<res << "\n";
    //}
    return 0;
}
