/*
354. Russian Doll Envelopes

You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other) 

Example:
 Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]). 

*/


class Solution {
public:
    
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.empty()) return 0;
        
        std::sort(envelopes.begin(), envelopes.end(),
            [&](pair<int,int> &x, pair<int,int> &y)->bool
            {
                return x.first < y.first || \
                       (x.first == y.first && x.second < y.second);
            });
        
        vector<int> dp(envelopes.size(), 1);
        auto res = 0;
        for (auto i = 0; i < envelopes.size(); ++i)
        {
            for (auto j = 0; j < i; ++j)
            {
                if (envelopes[j].first < envelopes[i].first &&
                    envelopes[j].second < envelopes[i].second)
                    dp[i] = max(dp[i], dp[j]+1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};