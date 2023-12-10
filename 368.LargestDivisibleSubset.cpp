/*
Given a set of distinct positive integers nums,
return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
    answer[i] % answer[j] == 0, or
    answer[j] % answer[i] == 0

If there are multiple solutions, return any of them.



Example 1:
    Input: nums = [1,2,3]
    Output: [1,2]
    Explanation: [1,3] is also accepted.

Example 2:
    Input: nums = [1,2,4,8]
    Output: [1,2,4,8]


Constraints:
    1 <= nums.length <= 1000
    1 <= nums[i] <= 2 * 10^9
    All the integers in nums are unique.
*/

/*
    First Solution: DFS
    Time Limit Exceeded,
*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        if (nums.empty() || nums.size() == 1) {
            return nums;
        }

        sort(nums.begin(), nums.end());
        vector<int> candidate;
        vector<vector<int>> result;
        dfs(nums, 0, candidate, result);
        sort(result.begin(), result.end(), CmpBySize());
        return result[0];
    }

private:
    void dfs(const vector<int> &nums, int index, vector<int> &candidate,
             vector<vector<int>> &result) {
        if (index == nums.size()) {
            result.push_back(candidate);
            return;
        }
        // nums[index] has not been pushed back into candidate yet
        if (candidate.empty() || nums[index] % candidate.back() == 0) {
            candidate.push_back(nums[index]);
            dfs(nums, 1 + index, candidate, result);
        } else {
            vector<int> v(1, nums[index]);
            dfs(nums, 1 + index, v, result);         // new
            dfs(nums, 1 + index, candidate, result); // old
        }
    }

    struct CmpBySize {
        bool operator()(const vector<int> &lhs, const vector<int> &rhs) {
            return lhs.size() > rhs.size();
        }
    };
};

// Second Solution: DP
class Solution {
public:
    // T[n] = the length of the largest divisible subset whose largest number is a[n]
    // T[n] = max{ 1 + T[i] | a[n] % a[i] == 0,  0 <= i < n}
    // else T[n] = 1
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        if (nums.size() < 2) {
            return nums;
        }
        sort(nums.begin(), nums.end());
        const auto len = nums.size();
        int max_len = 1, last_index = 0;
        vector<int> dp(len, 1);
        vector<int> parent(len, 0); // 表示排序后第i个元素的前序元素的编号

        for (auto i = 1; i < len; ++i) {
            for (auto j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > max_len) {
                max_len = dp[i];
                last_index = i;
            }
        }
        vector<int> res;
        for (auto i = 0; i < max_len && i < len; ++i) {
            res.push_back(nums[last_index]);
            last_index = parent[last_index];
        }
        sort(res.begin(), res.end());
        return res;
    }
};
