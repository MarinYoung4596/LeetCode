/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    797.AllPathsFromSourceToTarget.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/02/12 18:37:05
*   @brief:

Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

Example 1:
    Input: graph = [[1,2],[3],[3],[]]
    Output: [[0,1,3],[0,2,3]]
    Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

Example 2:
    Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
    Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]

Constraints:
    n == graph.length
    2 <= n <= 15
    0 <= graph[i][j] < n
    graph[i][j] != i (i.e., there will be no self-loops).  // 无环
    All the elements of graph[i] are unique.
    The input graph is guaranteed to be a DAG.

*****************************************************************/

// 有向无环图的邻接表遍历
// First Solution:  backtrack
class Solution {
public:
    // 注意: graph的 index 代表每个节点, vector<int> 存储的是每个节点的邻接表
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;
        auto cur = 0;  // 初始化
        path.push_back(cur);

        traverse(graph, result, path, cur);
        return result;
    }

private:
    void backtrack(const vector<vector<int>>& graph,
                   vector<vector<int>> &result,
                   vector<int> &path,
                   int cur) {
        if (!path.empty() && path.back() == graph.size() - 1) {  // 到达边缘
            result.push_back(path);
            return;
        }
        auto& next_node_list = graph[cur];
        for (auto v : next_node_list) {
            if (graph[v].empty() && v != graph.size() - 1) {
                continue;
            }
            path.push_back(v);
            backtrack(graph, result, path, v);
            path.pop_back();
        }
    }
};
