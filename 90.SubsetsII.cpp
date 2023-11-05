/*

Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:
    Input: [1,2,2]
    Output:
    [
        [2],
        [1],
        [1,2,2],
        [2,2],
        [1,2],
        []
    ]
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::vector<vector<int>> result;
        std::vector<int> subres;
        backtrack(nums, result, subres, 0);
        return result;
    }

private:
    void backtrack(const std::vector<int>& nums,
                   std::vector<std::vector<int>> &result,
                   vector<int> &subres,
                   int start) {
        bool dup = false;
        for (const auto &vec : result) {
            if (duplicate(vec, subres)) {  // 这里判重逻辑有点复杂，待优化
                dup = true;
                break;
            }
        }
        if (!dup) {
            result.push_back(subres);
        }
        for (auto i = start; i < nums.size(); ++i) {
            subres.push_back(nums[i]);
            backtrack(nums, result, subres, i + 1);
            subres.pop_back();
        }
    }

    bool duplicate(const std::vector<int> &vec1, const std::vector<int> &vec2) {
        if (vec1.size() != vec2.size()) {
            return false;
        }
        std::unordered_map<int, int> counter;
        for (const auto &x : vec1) {
            if (counter.count(x) > 0) {
                ++counter[x];
            } else {
                counter[x] = 1;
            }
        }
        for (const auto &x : vec2) {
            auto iter = counter.find(x);
            if (iter != counter.end()) {
                if (iter->second <= 0) {
                    return false;
                } else {
                    --(iter->second);
                }
            } else {
                return false;
            }
        }
        return true;
    }
};


//  second solution
class Solution2 {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());  // 这里是关键
        vector<vector<int>> result;
        vector<int> subres;
        backtrack(nums, 0, results, subres);
        return results;
    }

private:
    void backtrack(const vector<int> &nums, int start,
                   vector<vector<int>> &results,
                   vector<int> &subres) {
        if (start == nums.size()) {
            result.push_back(subres);
            return;
        }
        for (auto i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) {  // 靠排序来去重
                continue;
            }
            subres.push_back(nums[i]);
            backtrack(nums, i + 1, results, subres);
            subres.pop_back();
        }
    }
};
