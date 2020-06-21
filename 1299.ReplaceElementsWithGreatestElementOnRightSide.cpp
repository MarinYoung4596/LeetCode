/*
Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.

 

Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
 

Constraints:

1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5

*/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        std::vector<std::pair<int, int>> vec;
        for (auto i = 0; i < arr.size(); ++i) {
            vec.push_back(std::make_pair(i, arr[i]));
        }
        std::sort(vec.begin(), vec.end(),
                  [&](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
                      return lhs.second > rhs.second;
                  });

        std::vector<int> result;
        auto j = 0;
        for (auto i = 0; i < arr.size() - 1; ++i) {
            while (j < vec.size() && vec[j].first <= i) {
                ++j;
            }
            result.push_back(vec[j].second);
        }
        result.push_back(-1);
        return result;
    }
};