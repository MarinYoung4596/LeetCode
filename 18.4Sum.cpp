/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
Find all unique quadruplets in the array which gives the sum of target.

Note:
    Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
    The solution set must not contain duplicate quadruplets.

For example,
    given array S = {1 0 -1 0 -2 2}, and target = 0.
    A solution set is:
        (-1,  0, 0, 1)
        (-2, -1, 1, 2)
        (-2,  0, 0, 2)
*/

#include "util.h"
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


// First Solution: Hash, Time Limit Exceeded
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &num, int target) {
        vector<vector<int>> result;
        if (num.size() < 4) {
            return result;
        }
        std::sort(num.begin(), num.end());        // O(NlogN)

        unordered_multimap<int, pair<int, int>> cache;    // total elements: N*N/2
        for (size_t i = 0; i + 1 < num.size(); ++i) {
            for (size_t j = i + 1; j < num.size(); ++j) {    // O(N*N/2)
                cache.insert(make_pair((num[i] + num[j]), make_pair(i, j)));
            }
        }
        for (auto it = cache.begin(); it != cache.end(); ++it) {
            for (auto jt = std::next(it); jt != cache.end(); ++jt) {
                if (it->first + jt->first != target) {
                    continue;
                }
                // else, means they are equal
                auto a = it->second.first;
                auto b = it->second.second;
                auto c = jt->second.first;
                auto d = jt->second.second;
                if (a != c && a != d && b != c && b != d) { // previous job ensure that a != b and c != d
                    vector<int> vec = {num[a], num[b], num[c], num[d]};
                    std::sort(vec.begin(), vec.end());
                    result.push_back(vec);
                }
            }
        }
        std::sort(result.begin(), result.end());
        result.erase(std::unique(result.begin(), result.end()), result.end());
        return result;
    }
};

// Second Solution: Two Pointer
// Runtime: 104 ms, faster than 37.71% of C++ online submissions for 4Sum.
// Memory Usage: 12.9 MB, less than 80.79% of C++ online submissions for 4Sum.
class Solution2 {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) {
            return result;
        }
        std::sort(nums.begin(), nums.end());
        for (auto i = 0; i + 4 <= nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (auto j = i + 1; j + 3 <= nums.size(); ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                auto k = j + 1;
                auto h = nums.size() - 1;
                while (k < h) {
                    auto tmp_sum = nums[i] + nums[j] + nums[k] + nums[h];
                    if (tmp_sum < target) {
                        ++k;
                    } else if (tmp_sum > target) {
                        --h;
                    } else {
                        result.push_back(vector<int>({nums[i], nums[j], nums[k], nums[h]}));
                        while (k < h && nums[k] == nums[k + 1]) {
                            ++k;
                        }
                        while (k < h && nums[h - 1] == nums[h]) {
                            --h;
                        }
                        ++k;
                        --h;
                    }
                }
            }
        }
        return result;
    }
};

void test_4sum() {
    Solution2 obj;

    vector<int> v1 = { 1, 0, -1, 0, -2, 2 };
    auto res1 = obj.fourSum(v1, 0);
    print_matrix(res1);
    print_gap();

    vector<int> v2 = { 0, 0, 0, 0 };
    auto res2 = obj.fourSum(v2, 0);
    print_matrix(res2);
    print_gap();

    vector<int> v3 = {-494,-487,-471,-470,-465,-462,-447,-445,-441,-432,-429,-422,-406,-398,-397,-364,-344,-333,-328,-307,-302,-293,-291,-279,-269,-269,-268,-254,-198,-181,-134,-127,-115,-112,-96,-94,-89,-58,-58,-58,-44,-2,-1,43,89,92,100,101,106,106,110,116,143,156,168,173,192,231,248,256,281,316,321,327,346,352,353,355,358,365,371,410,413,414,447,473,473,475,476,481,491,498};
    auto res3 = obj.fourSum(v3, 8511);
    print_matrix(res3);
}


int main() {
    test_4sum();

    return 0;
}