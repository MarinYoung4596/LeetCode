/*

The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):
    "123"
    "132"
    "213"
    "231"
    "312"
    "321"

Given n and k, return the kth permutation sequence.

Example 1:
    Input: n = 3, k = 3
    Output: "213"

Example 2:
    Input: n = 4, k = 9
    Output: "2314"

Example 3:
    Input: n = 3, k = 1
    Output: "123"


Constraints:
    1 <= n <= 9
    1 <= k <= n!
*/

// First Solution: Time Limit Exceeded!

class Solution {
public:
    string getPermutation(int n, int k) {
        string str(n, 'x');
        for (int i = 0; i < n; ++i) {
            str[i] = static_cast<char>(i + 1 + '0');
        }
        for (int i = 1; i < k; ++i) {
            nextPermutation(str);
        }
        return str;
    }

private:
    bool nextPermutation(string &str) {
        int i = str.size() - 1;
        while (i > 0 && !(str[i - 1] < str[i])) {
            --i; // find last two adjacent elements in ascending order
        }

        if (i == 0) {
            reverse(str, 0, str.size() - 1);
            return false;
        }

        int j = str.size() - 1;
        while (j >= i && !(str[i - 1] < str[j])) {
            --j; // find last element that larger than str[i-1]
        }

        swap(str[i-1], str[j]);
        reverse(str, i, str.size() - 1);
        return true;
    }

    inline void reverse(string &str, int i, int j) {
        if (i == j) {
            return;
        }
        while (i < j) {
            swap(str[i++], str[j--]);
        }
    }
};


// Second Solution: backtrack, beats 5.02% c++ users
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<bool> used(n + 1, false);
        string candidate = "";
        int cur_k = 0;
        backtrack(n, candidate, used, cur_k, k);
        return res;
    }

private:
    void backtrack(int n, string &candidate, vector<bool> &used, int &cur_k, int k) {
        if (candidate.size() == n) {
            ++cur_k;
            if (cur_k == k) {
                res = candidate;
            }
            return;
        }
        if (cur_k >= k) {
            return;
        }
        for (auto i = 1; i <= n; ++i) {
            if (used[i]) {
                continue;
            }
            used[i] = true;
            candidate.push_back(i + '0');
            backtrack(n, candidate, used, cur_k, k);
            candidate.pop_back();
            used[i] = false;
        }
    }

private:
    string res = "";
};