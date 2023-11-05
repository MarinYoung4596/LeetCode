/*
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.



Example 1:
    Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
    Output: 3
    Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

Example 2:
    Input: envelopes = [[1,1],[1,1],[1,1]]
    Output: 1


Constraints:
    1 <= envelopes.length <= 10^5
    envelopes[i].length == 2
    1 <= wi, hi <= 10^5
*/


// 二维动态规划，类似 最长递增子序列的解法
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.empty()) {
            return 0;
        }
        std::sort(envelopes.begin(), envelopes.end(),
            [&](pair<int,int> &x, pair<int,int> &y)->bool {
                return x.first < y.first ||
                       (x.first == y.first && x.second < y.second);
            });

        vector<int> dp(envelopes.size(), 1);
        auto res = 0;
        for (auto i = 0; i < envelopes.size(); ++i) {
            for (auto j = 0; j < i; ++j) {
                if (envelopes[j].first < envelopes[i].first &&
                        envelopes[j].second < envelopes[i].second) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
