/*
46. Permutations

Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/

// first solution
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) {
            return result;
        }
        const auto n = NumOfFullPermuations(nums.size());
        do {
            result.push_back(nums);
            nextPermutation(nums);
        } while (result.size() < n);

        return result;
    }

private:
    void nextPermutation(vector<int> &num) {
        // find the last adjacent two element that is in ascending order
        int i = num.size() - 1;
        while (i > 0 && num[i - 1] >= num[i]) {
            --i;
        }

        // if the sequence is already in descending order, reverse the whole sequence
        if (i == 0) {
            reverse(num, 0, num.size() - 1);
            return;
        }

        // find the last element that is larger than num[i-1]
        int j = num.size() - 1;
        while (j >= i && num[i - 1] >= num[j]) {
            --j;
        }

        // exchange num[i-1] and num[j]
        swap(num[i-1], num[j]);

        // reverse the sequence after i-1
        reverse(num, i, num.size() - 1);
    }

    void reverse(vector<int> &v, int begin, int end) {
        while (begin < end) {
            swap(v[begin++], v[end--]);
        }
    }

    int NumOfFullPermuations(int n) {
        if (n <= 2) {
            return n;
        }
        return n * NumOfFullPermuations(n - 1);
    }
};


/**
 * second solution
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return

    for 选择 in 选择列表:
        递归之前做选择
        backtrack(路径, 选择列表)
        递归之后撤销选择
 */
class Solution2 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> subres;
        vector<vector<int>> result;
        vector<bool> visited(input.size(), false);
        backtrack(input, 0, visited, subres, result);
        return result;
    }

private:
    void backtrack(const vector<int> &input, int index,
                    vector<bool> &visited,
                    vector<int> &subres,
                    vector<vector<int>> &result) {
        if (subres.size() == input.size()) {
            result.push_back(subres);
            return;
        }
        for (auto i = 0; i < input.size(); ++i) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            subres.push_back(input[i]);
            backtrack(input, i + 1, visited, subres, result);
            subres.pop_back();
            visited[i] = false;
        }
    }
};
