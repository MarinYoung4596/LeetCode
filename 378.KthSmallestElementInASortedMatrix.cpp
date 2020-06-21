/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,
return 13.

Note: You may assume k is always valid, 1 ≤ k ≤ n^2.
*/


// First Solution: O(N^2)
// 完全没有利用矩阵行有序、列有序的特点
class Solution1 {
public:
    // 保留k个最小的数（不去重）
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // top 永远是最大的数
        std::priority_queue<int> pq;
        for (auto i = 0; i < matrix.size(); ++i) {
            for (auto j = 0; j < matrix[0].size(); ++j) {
                if (pq.size() < k) {
                    pq.push(matrix[i][j]);
                } else {
                    if (pq.top() < matrix[i][j]) {
                        continue;
                    } else {
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
            }
        }
        return pq.top();
    }
};


// Second Solution:
class Solution2 {
public:
    int kthSmallest(const std::vector<std::vector<int>>& matrix, int k) {
        const int n = matrix.size();
        auto low = matrix[0][0]; // 最小
        auto high = matrix[n - 1][n - 1]; // 最大

        while (low < high) {
            auto mid = low + (high - low) / 2;
            auto count = search_less_equal(matrix, mid); // 小于等于中位数的元素个数
            if (count < k) { // 小于k 继续向上搜索，改变下界
                low = mid + 1;
            } else { // 否则，改变上界
                high = mid;
            }
        }
        return low;
    }

private:
    int search_less_equal(const std::vector<std::vector<int>> &matrix, int target) {
        const int n = matrix.size();
        auto i = n - 1;
        auto j = 0; // 从左下角开始查找，每列有序
        auto result = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= target) { // 小于等于目标
                result += (i + 1); // 说明这一列都比target小，加上这0~i行,j列的所有元素
                ++j; // 列向后搜索
            } else {
                --i; // 行向前搜索
            }
        }
        return result;
    }
};
