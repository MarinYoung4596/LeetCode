/*

279. Perfect Squares

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/

class Solution {
public:
    // dp[n] = min{dp[i]+dp[n-i]}; 1 <= i <= n-1
   int numSquares(int n) 
   {
       int x = static_cast<int>(sqrt(n));
        if (x * x == n) return 1;
        
        vector<int> dp({0});// SET STATIC TO BOOST THE SPEED
        while (dp.size() <= n)
        {
            int squares = INT_MAX;
            int m = dp.size();
            for (int i = 1; i * i <= m; ++i)
                squares = min(squares, 1 + dp[m-i*i]);
            dp.push_back(squares);
        }
        return dp.back();
    }
};


//// Second Solution £º Time Limit Exceeded
class Solution {
public:
    // dp[n] = min{dp[i]+dp[n-i]}; 1 <= i <= n-1
   int numSquares(int n) 
   {
       int x = static_cast<int>(sqrt(n));
        if (x * x == n) return 1;
        
        unordered_set<int> _set;
        for (int i = 1; i <= x; ++i)
            _set.insert(i*i); // squares

        vector<int> dp(n+1, 0);
        for (int i = 1; i <= n; ++i )
        {
            if (_set.find(i) != _set.end())
                dp[i] = 1;
            else
            {
                for (auto iter = _set.begin(); iter != _set.end(); ++iter)
                {
                    if (*iter > i) continue;
                    if (dp[i] == 0) dp[i] = dp[*iter] + dp[i-*iter];
                    else dp[i] = min(dp[i], dp[*iter] + dp[i-*iter]);
                }
            }
        }
        return dp[n];
    }
};