/*
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -2^28 to 2^28 - 1 and the result is guaranteed to be at most 2^31 - 1.

Example:
    Input:
        A = [ 1, 2]
        B = [-2,-1]
        C = [-1, 2]
        D = [ 0, 2]
    Output: 2
    Explanation:
        The two tuples are:
        1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
        2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

*/


// First Solution : Bruce Force: Time Limit Exceeded
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        auto result = 0;
        for (const auto a : A) {
            for (const auto b : B) {
                for (const auto c : C) {
                    for (const auto d : D) {
                        if (a + b + c + d == 0) {
                            ++result;
                        }
                    }
                }
            }
        }
        return result;
    }
};


// Second Solution: Hash
// Runtime: 260 ms, faster than 93.04% of C++ online submissions for 4Sum II.
// Memory Usage: 27.9 MB, less than 78.80% of C++ online submissions for 4Sum II.
class Solution2 {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        auto result = 0;
        unordered_map<int, int> two_sum_map;
        for (const auto a : A) {
            for (const auto b : B) {
                two_sum_map[a + b]++;
            }
        }
        for (const auto c : C) {
            for (const auto d : D) {
                auto tmp_sum = -1 * (c + d);
                auto iter = two_sum_map.find(tmp_sum);
                if (iter != two_sum_map.end()) {
                    result += iter->second;
                }
            }
        }
        return result;
    }
};