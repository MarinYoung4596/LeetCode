/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    2368.ReachableNodesWithRestrictions.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/02/19 22:28:15
*   @brief:

There is an undirected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree. You are also given an integer array restricted which represents restricted nodes.

Return the maximum number of nodes you can reach from node 0 without visiting a restricted node.

Note that node 0 will not be a restricted node.


Example 1:
    Input: n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
    Output: 4
    Explanation:
        The diagram above shows the tree.
        We have that [0,1,2,3] are the only nodes that can be reached from node 0 without visiting a restricted node.

Example 2:
    Input: n = 7, edges = [[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]], restricted = [4,2,1]
    Output: 3
    Explanation:
        The diagram above shows the tree.
        We have that [0,5,6] are the only nodes that can be reached from node 0 without visiting a restricted node.

Constraints:
    2 <= n <= 10^5
    edges.length == n - 1
    edges[i].length == 2
    0 <= ai, bi < n
    ai != bi
    edges represents a valid tree.
    1 <= restricted.length < n
    1 <= restricted[i] < n
    All the values of restricted are unique.

*****************************************************************/

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        // step1: 创建图（邻接表存储）
        vector<vector<int>> graph(n);
        for (const auto &edge : edges) {
            auto point_a = edge[0];
            auto point_b = edge[1];
            graph[point_a].push_back(point_b);
            graph[point_b].push_back(point_a);
        }
        // step2:
        unordered_set<int> restrict_node;
        for (auto node : restricted) {
            restrict_node.insert(node);
        }

        // 遍历
        unordered_set<int> visited;
        dfs(graph, 0, restrict_node, visited);
        return visited.size();
    }

private:
    // first solution: dfs
    void dfs(const vector<vector<int>> &graph,
             int index,
             const unordered_set<int> &restricted,
             unordered_set<int> &visited) {
        if (restricted.count(index) > 0) {
            return;
        }
        if (index >= graph.size()) {
            return;
        }
        visited.insert(index);
        auto& next_node_list = graph[index];
        for (auto node : next_node_list) {
            if (visited.count(node) > 0) {
                continue;
            }
            dfs(graph, node, restricted, visited);
        }
    }

    // second solution: bfs
    int bfs(const vector<vector<int>> &graph,
            const unordered_set<int> &restricted) {
        queue<int> q;
        q.push(0);

        unordered_set<int> visited;
        while (!q.empty()) {
            const auto queue_len = q.size();
            for (auto i = 0; i < queue_len; ++i) {
                auto node = q.front();
                q.pop();

                if (restricted.count(node) > 0) {
                    continue;
                }
                if (visited.count(node) > 0) {
                    continue;
                }
                visited.insert(node);
                auto& next_node_list = graph[node];
                for (auto next_node : next_node_list) {
                    q.push(next_node);
                }
            }
        }
        return visited.size();
};
