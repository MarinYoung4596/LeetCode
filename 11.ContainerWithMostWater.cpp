/*

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

*/
// First Solutioin: Time Limit Exceeded
class Solution {
public:
    int maxArea(vector<int>& height) {
        const auto n = height.size();
        int res = INT_MIN;
        for (auto i = 0; i < n-1; ++i) {
            for (auto j = i+1; j < n; ++j) {
                int tmp = (j - i) * min(height[i],height[j]);
                res = max(res, tmp);
            }
        }
        return res;
    }
};

// second Solution
class Solution2 {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int start = 0, end = height.size()-1;
        while (start < end) {
            int h = min(height[start], height[end]);
            water = max(water, h * (end - start));
            while (start < end && height[start] <= h) ++start;
            while (start < end && height[end] <= h) --end;
        }
        return water;
    }
};