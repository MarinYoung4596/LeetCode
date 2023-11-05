/*
93. Restore IP Addresses
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

#include "util.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


// First Solution : dfs
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ip;
        dfs(s, 0, 0, ip, res);
        return res;
    }

private:
    void dfs(const string &s,
            size_t start,
            size_t step,
            string ip,
            vector<string> &res) {
        if (start == s.size() && step == 4) {
            ip = ip.substr(0, ip.size() - 1);    // drop '\0'
            res.push_back(ip);
            return;
        }

        if ((s.size() - start) > 3 * (4 - step)    // 剪枝，判明剩下的不符合要求
                || (s.size() - start) < 1 * (4 - step)) {
            return;
        }

        int tmp = 0;
        for (size_t i = start; i < start + 3; i++) {
            tmp = tmp * 10 + (int)(s[i] - '0');
            if (tmp <= 255) {// every bit 0 <= x <= 255
                ip += s[i];
                dfs(s, i + 1, step + 1, ip + '.', res);
            }
            if (tmp == 0) {
                break;
            }
        }
    }
};

// Second Solution : backtrack
class Solution2 {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> candidate;
        backtrack(s, 0, candidate, result);
        return result;
    }

private:
    void backtrack(const string &s,
                   int index,
                   vector<string> &candidate,
                   vector<string> &result) {
        if (index == s.size() && candidate.size() == 4) {
            auto tmp_res = vec_to_str(candidate);
            result.push_back(tmp_res);
            return;
        }
        for (auto i = index; i < s.size(); ++i) {
            auto sub_item = s.substr(index, i - index + 1);
            if (!is_valid(sub_item)) {
                continue;
            }
            candidate.push_back(sub_item);
            backtrack(s, i + 1, candidate, result);
            candidate.pop_back();
        }
    }

    bool is_valid(const string &s) {
        if (s.size() == 0 || s.size() > 3) {
            return false;
        }
        if (s.size() > 1 && s[0] == '0') {
            return false;
        }
        auto addr = -1;
        try {
            addr = std::stoi(s);
        } catch (const std::exception &e) {
            return false;
        }
        return (addr >= 0 && addr <= 255);
    }

    string vec_to_str(const vector<string> &vec) {
        string result = vec[0];
        for (auto i = 1; i < vec.size(); ++i) {
            result += ".";
            result += vec[i];
        }
        return result;
    }
};

int main() {
    Solution obj;
    string s = "25525511135";
    vector<string> v = obj.restoreIpAddresses(s);
    print_vector<string>(v);

    return 0;
}
