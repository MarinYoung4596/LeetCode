/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target,
where index1 must be less than index2. Please note that your returned answers (both index1 and
index2) are not zero-based.

You may assume that each input would have exactly one solution.

    Input: numbers={2, 7, 11, 15}, target=9
    Output: index1=1, index2=2
*/

#include <vector>
#include <algorithm>
#include <unordered_map>

// First Solution: Time Complexity: sort O(NlogN) + find O(N)
// from: http://blog.csdn.net/magisu/article/details/12768283
// we can also write a struct/class and implement a comparable function.
class Solution {
public:
    typedef pair<int, int> valoffset_pair;

    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<valoffset_pair> arr;
        int index = 0;
        for (auto i : numbers) {
            arr.push_back(valoffset_pair(i, ++index));
        }
        // sort them
        std::sort(arr.begin(), arr.end(),
            [&](const valoffset_pair& v1, const valoffset_pair& v2) -> bool {
                return v1.first < v2.first;
            }
        );
        auto p_left = arr.begin();
        auto p_right = --arr.end();
        int sum = p_left->first + p_right->first;
        // search from the beginning and the end of the sorted array at the same time.
        while (sum != target) {
            sum = p_left->first + p_right->first;
            if (sum > target) {
                p_right--;
            } else if (sum < target) {
                p_left++;
            } else { // they are equal
                break;
            }
        }
        return vector<int>(
                {min(p_left->second, p_right->second),
                max(p_left->second, p_right->second)});
    }
};

// Second Solution: hasp map
class Solution2 {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, size_t> mapping;
        for (size_t i = 0; i < numbers.size(); i++) {
            mapping.insert(std::pair<int, size_t>(numbers[i], i));
        }
        for (size_t i = 0; i < numbers.size(); i++) {
            const int gap = target - numbers[i];
            if (mapping.find(gap) != mapping.end() && mapping[gap] > i) {
                return vector<int>({(int)(i + 1), (int)(mapping[gap] + 1)});
            }
        }
    }
};
