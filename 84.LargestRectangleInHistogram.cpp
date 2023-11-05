/*
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


// First Solution: 暴力解法 Time Limit Exceeded
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


// Second Solution: 暴力解法
// 遍历到每个 index，向左、向右 展开，直至遇到 heights[i] 还小的数
class Solution2 {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int max_area = 0;
        for (auto i = 0; i < heights.size(); ++i) {
            auto cur_height = heights[i];
            auto left = i;
            while (left - 1 >= 0 && heights[left - 1] >= cur_height) {
                --left;
            }
            auto right = i;
            while (right + 1 < heights.size() && heights[right + 1] >= cur_height) {
                ++right;
            }
            auto cur_area = (right - left + 1) * cur_height;
            max_area = std::max(max_area, cur_area);
        }
        return max_area;
    }
};

// Third Solution: 单调（递增）栈
// 这种方式是对 solution1 的优化，好理解一些
class Solution3 {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        const auto n = heights.size();
        vector<int> left(n, 0); // left[i]: heights[i] 往左数第一个 比它小的元素下标
        stack<int> s1;
        for (auto i = 0; i < n; ++i) {
            while (!s1.empty() && heights[i] <= heights[s1.top()]) {  // tips 1：这里是等于，下面没有=，目的是去重，如【1，1，1】这种情况
                s1.pop();
            }
            left[i] = s1.empty() ? 0 : s1.top() + 1;
            s1.push(i);
        }
        vector<int> right(n, 0);
        stack<int> s2;
        for (int i = n - 1; i >= 0; --i) { // tips 2: 这里显式定义 int，否则会auto 会把 i 推断成 size_t 格式
            while (!s2.empty() && heights[i] < heights[s2.top()]) {
                s2.pop();
            }
            right[i] = s2.empty() ? n - 1 : s2.top() - 1;
            s2.push(i);
        }
        auto max_area = 0;
        for (auto i = 0; i < n; ++i) {
            auto cur_area = heights[i] * (right[i] - left[i] + 1);
            max_area = std::max(max_area, cur_area);
        }
        return max_area;
    }
};

class Solution4 {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 前后补0，对面积无影响，但是方便遍历
        heights.insert(heights.begin(), 0);
        heights.push_back(0);

        int max_area = 0;
        stack<int> min_hight_idx_stack;
        for (auto i = 0; i < heights.size(); ++i) {
            if (min_hight_idx_stack.empty() || heights[i] >= heights[min_hight_idx_stack.top()]) {
                min_hight_idx_stack.push(i);
            } else {
                while (!min_hight_idx_stack.empty() && heights[i] < heights[min_hight_idx_stack.top()]) {
                    auto cur = min_hight_idx_stack.top();
                    min_hight_idx_stack.pop();
                    auto left = min_hight_idx_stack.top() + 1;  // 左边界：这里不用 cur，因为要从 栈顶元素+1 位置 算起
                    auto right = i - 1;                         // 右边界：因为 heights[i] 最小，所以不包括在内
                    auto cur_area = (right - left + 1) * heights[cur];
                    max_area = std::max(cur_area, max_area);
                }
                min_hight_idx_stack.push(i);
            }
        }
        return max_area;
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
