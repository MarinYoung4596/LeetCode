/*
Given an array of integers arr, replace each element with its rank.
The rank represents how large the element is. The rank has the following rules:
    Rank is an integer starting from 1.
    The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
    Rank should be as small as possible.


Example 1:
    Input: arr = [40,10,20,30]
    Output: [4,1,2,3]
    Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.

Example 2:
    Input: arr = [100,100,100]
    Output: [1,1,1]
    Explanation: Same elements share the same rank.

Example 3:
    Input: arr = [37,12,28,9,100,56,80,5,12]
    Output: [5,3,4,2,8,6,7,1,3]


Constraints:
    0 <= arr.length <= 10^5
    -10^9 <= arr[i] <= 10^9
*/


// Runtime: 256 ms, faster than 45.15% of C++ online submissions for Rank Transform of an Array.
// Memory Usage: 40.7 MB, less than 42.00% of C++ online submissions for Rank Transform of an Array.
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) {
            return arr;
        }
        vector<std::pair<int, int>> vec; // original idx, value
        for (auto i = 0; i < arr.size(); ++i) {
            vec.push_back(std::make_pair(i, arr[i]));
        }
        std::sort(vec.begin(), vec.end(),
                 [&](const std::pair<int, int> &lhs, std::pair<int, int> &rhs) {
                     return lhs.second < rhs.second;
                 });

        auto pre_value = vec[0].second;
        auto pre_rank = 1;
        vector<std::pair<int, int>> idx_vec; // original order,  rank
        idx_vec.push_back(std::make_pair(vec[0].first, pre_rank));
        for (auto i = 1; i < vec.size(); ++i) {
            auto cur_value = vec[i].second;
            auto cur_rank = pre_rank;
            if (cur_value != pre_value) {
                cur_rank += 1;
            }
            idx_vec.push_back(std::make_pair(vec[i].first, cur_rank));
            pre_rank = cur_rank;
            pre_value = cur_value;
        }
        std::sort(idx_vec.begin(), idx_vec.end(),
                 [&](const std::pair<int, int> &lhs, std::pair<int, int> &rhs) {
                     return lhs.first < rhs.first;
                 });

        vector<int> result;
        for (const auto &item : idx_vec) {
            result.push_back(item.second);
        }
        return result;
    }
};