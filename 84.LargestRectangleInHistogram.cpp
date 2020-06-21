/*

84. Largest Rectangle in Histogram

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
       6
     5| |
    | | |
    | | |  3
 2  | | |2| |
| |1| | | | |
| | | | | | |
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
       6
     5| |
    |/|/|
    |/|/|  3
 2  |/|/|2| |
| |1|/|/| | |
| | |/|/| | |
The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.

*/

#include <iostream>
#include <vector>
#include <stack>


// Second Solution: Time Limit Exceeded
class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        if (heights.empty()) {
            return 0;
        }
        const auto len = heights.size();
        std::vector<std::vector<int>> arr(len, std::vector<int>(len, 0));
        int res = INT_MIN;
        for (auto i = 0; i < len; ++i) {
            for (auto j = i; j < len; ++j) {
                arr[i][j] = find_min(heights, i, j) * (j - i + 1);
                res = std::max(res, arr[i][j]);
            }
        }
        return res;
    }

private:
    int find_min(std::vector<int> &heights, int start, int end) {
        if (start == end) {
            return heights[start];
        }
        int res = heights[start];
        for (int i = start + 1; i <= end; ++i) {
            if (heights[i] < res) {
                res = heights[i];
            }
        }
        return res;
    }
};


// Third Solution:
class Solution2 {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> s;
        int result = 0;
        for (auto i = 0; i <= heights.size(); ++i) {
            auto height = (i == heights.size() ? 0 : heights[i]);
            if (s.empty() || height >= heights[s.top()]) {
                s.push(i);
            } else { // heights[i] < heights[s.top()]
                int left = s.top();
                s.pop();

                int curr_area = heights[left] * (s.empty() ? i : i - 1 - s.top());
                result = std::max(curr_area, result);
                --i;
            }
        }
        return result;
    }
};

int main() {
    Solution obj;
    int arr1[] = {2,1,6,5,3,2};

    std::vector<int> v(arr1, arr1 + sizeof(arr1) / sizeof(int));
    std::cout << v.size() << std::endl;
    std::cout << obj.largestRectangleArea(v) << std::endl;

    return 0;
}
