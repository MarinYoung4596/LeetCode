/*
Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
    Input: [5, 4, 3, 2, 1]
    Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
    Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal".
        For the left two athletes, you just need to output their relative ranks according to their scores.

Note:
    N is a positive integer and won't exceed 10,000.
    All the scores of athletes are guaranteed to be unique.

*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        std::vector<std::string> result;
        if (nums.empty()) {
            return result;
        }

        std::vector<std::pair<int, int>> vec;
        for (auto i = 0; i < nums.size(); ++i) {
            vec.push_back(std::pair<int, int>(i, nums[i]));
        }
        std::sort(vec.begin(), vec.end(),
            [&](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) -> bool {
                return lhs.second > rhs.second;
            });

        std::string medal[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        result.resize(nums.size());
        for (auto i = 0; i < vec.size(); ++i) {
            if (i < 3) {
                result[vec[i].first] = medal[i];
            } else {
                result[vec[i].first] = std::to_string(i + 1);
            }
        }

        return result;
    }
};
