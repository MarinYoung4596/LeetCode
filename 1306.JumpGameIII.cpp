/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    1306.JumpGameIII.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/11/11 23:46:47
*   @brief:

Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach any index with value 0.

Notice that you can not jump outside of the array at any time.


Example 1:
    Input: arr = [4,2,3,0,3,1,2], start = 5
    Output: true
    Explanation: All possible ways to reach at index 3 with value 0 are:
        index 5 -> index 4 -> index 1 -> index 3
        index 5 -> index 6 -> index 4 -> index 1 -> index 3

Example 2:
    Input: arr = [4,2,3,0,3,1,2], start = 0
    Output: true
    Explanation: One possible way to reach at index 3 with value 0 is:
        index 0 -> index 4 -> index 1 -> index 3

Example 3:
    Input: arr = [3,0,2,1,2], start = 2
    Output: false
    Explanation: There is no way to reach at index 1 with value 0.


Constraints:
    1 <= arr.length <= 5 * 10^4
    0 <= arr[i] < arr.length
    0 <= start < arr.length

*****************************************************************/

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return dfs(arr, visited, start);
    }

private:
    bool dfs(vector<int> &arr, vector<bool> &visited, int index) {
        if (index < 0 || index >= arr.size()) {
            return false;
        }
        if (arr[index] == 0) {
            return true;
        }
        if (visited[index]) {
            return false;
        }
        visited[index] = true;
        return dfs(arr, visited, index + arr[index]) ||
               dfs(arr, visited, index - arr[index]);
    }
};
