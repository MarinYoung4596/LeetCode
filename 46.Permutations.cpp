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

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> result;
        if (nums.empty()) return result;
        const auto n = NumOfFullPermuations(nums.size());
        do
        {
            result.push_back(nums);
            nextPermutation(nums);
        }
        while (result.size() < n);
        
        return result;
    }

private:
    void nextPermutation(vector<int> &num) 
    {
        // find the last adjacent two element that is in ascending order
        int i = num.size() - 1;
        while (i > 0 && num[i - 1] >= num[i]) --i;
        
        // if the sequence is already in descending order, reverse the whole sequence
        if (i == 0) 
        {
            reverse(num, 0, num.size()- 1);
            return;
        }
        
        // find the last element that is larger than num[i-1]
        int j = num.size() - 1;
        while (j >= i && num[i - 1] >= num[j]) --j;
        
        // exchange num[i-1] and num[j]
        swap(num[i-1], num[j]);
        
        // reverse the sequence after i-1
        reverse(num, i, num.size() - 1);
    }

    void reverse(vector<int> &v, int begin, int end)
    {
        while (begin < end)
        {
            swap(v[begin++], v[end--]);
        }
    }
    
    int NumOfFullPermuations(int n)
    {
        if (n <= 2) return n;
        return n * NumOfFullPermuations(n - 1);
    }
};