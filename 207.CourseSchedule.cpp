/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    207.CourseSchedule.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/02/19 23:28:53
*   @brief:

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
* For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return true if you can finish all courses. Otherwise, return false.


Example 1:
    Input: numCourses = 2, prerequisites = [[1,0]]
    Output: true
    Explanation:
        There are a total of 2 courses to take.
        To take course 1 you should have finished course 0. So it is possible.

Example 2:
    Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
    Output: false
    Explanation:
        There are a total of 2 courses to take.
        To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.


Constraints:
    1 <= numCourses <= 2000
    0 <= prerequisites.length <= 5000
    prerequisites[i].length == 2
    0 <= ai, bi < numCourses
    All the pairs prerequisites[i] are unique.

*****************************************************************/


class Solution {
public:
    // 检测图是否有环
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 建有向图
        vector<vector<int>> graph(numCourses);
        for (auto p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }
        // traverse
        vector<bool> visited(numCourses, false);  // 用于去重
        vector<bool> on_path(numCourses, false);  // 用于路径标记
        for (auto i = 0; i < numCourses; ++i) {   // 可能有多个互不相联的子图
            dfs(graph, i, visited, on_path);
        }
        return !has_cycle;
    }

private:
    void dfs(const vector<vector<int>> &graph,
             int index,
             vector<bool> &visited,
             vector<bool> &on_path) {
        if (on_path[index]) {  // 已经被访问过
            has_cycle = true;
        }
        if (visited[index] > 0 || has_cycle) {
            return;
        }
        visited[index] = true;
        on_path[index] = true;
        for (auto nodex : graph[index]) {
            dfs(graph, nodex, visited, on_path);
        }
        on_path[index] = false;
    }

private:
    bool has_cycle = false;
};
