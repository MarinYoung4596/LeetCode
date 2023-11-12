/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    1345.JumpGameIV.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/12 00:31:42
*   @brief:

Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:
    i + 1 where: i + 1 < arr.length.
    i - 1 where: i - 1 >= 0.
    j where: arr[i] == arr[j] and i != j.

Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.


Example 1:
    Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
    Output: 3
    Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.

Example 2:
    Input: arr = [7]
    Output: 0
    Explanation: Start index is the last index. You do not need to jump.

Example 3:
    Input: arr = [7,6,9,6,9,6,9,7]
    Output: 1
    Explanation: You can jump directly from index 0 to index 7 which is last index of the array.


Constraints:
    1 <= arr.length <= 5 * 10^4
    -10^8 <= arr[i] <= 10^8

*****************************************************************/


class Solution {
public:
    // 转换成图的遍历问题，
    int minJumps(vector<int>& arr) {
        const auto n = arr.size();
        if (n == 1) {
            return 0;
        }
        // 临时记录 val 相等数组元素的下标
        unordered_map<int, vector<int>> val_idx_map; // val : indexs
        for (auto i = 0; i < n; ++i) {
            if (val_idx_map.count(arr[i]) < 1) {
                val_idx_map[arr[i]] = {};
            }
            val_idx_map[arr[i]].push_back(i);
        }
        // 遍历，求 0 ==> n-1 的最短路径
        int result = 0;
        unordered_set<int> visited;  // 不用 vector，为了节省空间
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            const auto queue_len = q.size();
            for (auto i = 0; i < queue_len; ++i) {  // 这里，类似二叉树的层序遍历
                auto cur_idx = q.front();
                q.pop();
                visited.insert(cur_idx);
                if (cur_idx == n - 1) {
                    return result;
                }
                if (cur_idx > 0 && !visited.count(cur_idx - 1) > 0) {
                    q.push(cur_idx - 1);
                }
                if (cur_idx + 1 < n && !visited.count(cur_idx + 1) > 0) {
                    q.push(cur_idx + 1);
                }
                if (val_idx_map.count(arr[cur_idx]) > 0) {
                    auto &neighbors = val_idx_map[arr[cur_idx]];
                    for (auto idx : neighbors) {
                        if (visited.count(idx) > 0) {
                            continue;
                        }
                        q.push(idx);
                    }
                    val_idx_map.erase(arr[cur_idx]); // 同样，这里每次遍历后删除，也是为了节省空间
                }
            }
            ++result;
        }
        return -1;
    }
};