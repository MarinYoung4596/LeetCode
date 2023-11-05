/*
169. Majority Element.
Given an array of size n, find the majority element.
The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.
*/

#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int n_times = 0;
        int candidate = 0;
        for(int i = 0; i < num.size(); i++) {
            if(n_times == 0) {
                candidate = num[i];
                n_times = 1;
            } else {
                if(candidate == num[i]) {
                    n_times++;
                } else {
                    n_times--;
                }
            }
        }
        return candidate;
    }
};

class Solution2 {
public:
    int majorityElement(vector<int> &num) {
        sort(num.begin(), num.end());
        return num[num.size() / 2];
    }
};
