/*
https://leetcode.com/problems/interval-list-intersections/

Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.
Return the intersection of these two interval lists.
(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

Example 1:
(pic)
Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.

Note:
0 <= A.length < 1000
0 <= B.length < 1000
0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9

NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        std::vector<std::vector<int>> result;

        auto i = 0;
        auto j = 0;
        while (i < A.size() && j < B.size()) {
            auto apair = std::pair<int, int>(A[i][0], A[i][1]);
            auto bpair = std::pair<int, int>(B[j][0], B[j][1]);

            if (exist_intersection(apair, bpair)) {
                result.push_back(get_intersection(apair, bpair));
            }
            // update, 右边界比较小的移动
            if (apair.second < bpair.second) {
                ++i;
            } else {
                ++j;
            }
        }
        return result;
    }

private:
    inline bool exist_intersection(const std::pair<int, int> &lhs,
                           const std::pair<int, int> &rhs) {
        return !(lhs.first > rhs.second || lhs.second < rhs.first);
    }

    inline std::vector<int> get_intersection(const std::pair<int, int> &lhs,
                           const std::pair<int, int> &rhs) {
        return std::vector<int>({std::max(lhs.first, rhs.first),
                                 std::min(lhs.second, rhs.second)});
    }
};