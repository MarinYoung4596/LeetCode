/*
47. Permutations II

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        do {
            result.push_back(nums);
        } while (nextPermutation(nums));
        
        return result;
    }
    
private:
    bool nextPermutation(vector<int> &num) {
        // find the last adjacent two element that is in ##ascending## order
        int i = num.size() - 1;
        while (i > 0 && num[i - 1] >= num[i]) {
            --i;
        }
        
        // if the sequence is ##already in descending order##, reverse the whole sequence
        if (i == 0) {
            reverse(num, 0, num.size() - 1);
            return false;
        }
        
        // find the last element that is ##larger## than num[i-1] // !(nums[i-1] < nums[j])
        int j = num.size() - 1;
        while (j >= i && num[i - 1] >= num[j]) {
            --j;
        }
        
        // exchange num[i-1] and num[j]
        swap(num[i-1], num[j]);
        
        // reverse the sequence after i-1
        reverse(num, i, num.size() - 1);
        return true;
    }
    
    void reverse(vector<int> &v, int begin, int end) {
        while (begin < end) {
            swap(v[begin++], v[end--]);
        }
    }
};
