/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:
    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
    The solution set must not contain duplicate triplets.


For example,
    given array S = {-1 0 1 2 -1 -4},
    A solution set is:
        (-1, 0, 1)
        (-1, -1, 2)
*/

#include <vector>
#include <algorithm>

// First Solution: two pointers
class Solution {
public:
    vector<vector<int>> threeSum(std::vector<int> &num) {
        std::vector<std::vector<int> > res;
        if (num.size() < 3) {
            return res;
        }
        std::sort(num.begin(), num.end());
        for (auto i = num.begin(); i != prev(num.end(), 2); ++i) {
            if (i > num.begin() && *i == *(i - 1)) {
                continue;
            }
            auto j = i + 1;        // iterator
            auto k = num.end() - 1;
            while (j < k) {
                if (*i + *j + *k < 0) {
                    ++j;
                    while (j < k && *(j - 1) == *j) {
                        ++j;
                    }
                } else if (*i + *j + *k > 0) {
                    --k;
                    while (j < k && *k == *(k + 1)) {
                        --k;
                    }
                } else {
                    res.push_back({ *i, *j, *k });
                    
                    ++j;
                    while (j < k && *(j - 1) == *j) {
                        ++j;
                    }
                    --k;
                    while (j < k && *k == *(k + 1)) {
                        --k;
                    }
                }
            }
        }
        return res;
    }
};

