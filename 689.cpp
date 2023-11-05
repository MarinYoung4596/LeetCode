
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
        const auto n = nums.size();
        vector<int> prefix_sum(n + 1, 0);
        for (auto i = 1; i <= n; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
        }
        vector<vector<int>> dp(n, vector<int>(3, 0)); // 定义 dp[i][j] 为考虑前 i 个数，凑成无重叠子数组数量为 j 个时的最大值

        return dp[n - 1][2];
    }
};
