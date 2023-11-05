/*
Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.


Example 1:
    Input: [1,12,-5,-6,50,3], k = 4
    Output: 12.75
    Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
 

Note:
    1 <= k <= n <= 30,000.
    Elements of the given array will be in the range [-10,000, 10,000].
*/


// Runtime: 300 ms, faster than 58.01% of C++ online submissions for Maximum Average Subarray I.
// Memory Usage: 77.6 MB, less than 84.07% of C++ online submissions for Maximum Average Subarray I.
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        auto sum = 0;
        double result = 0.0;
        auto flag = false;
        for (auto i = 0; i < nums.size(); ++i) {
            if (i < k) {
                sum += nums[i];
                continue;
            }
            double avg = static_cast<double>(sum) / k;
            result = flag ? std::max(avg, result) : avg;
            flag = true;

            sum -= nums[i - k];
            sum += nums[i];
        }
        double avg = static_cast<double>(sum) / k;
        result = flag ? std::max(avg, result) : avg;
        return result;
    }
};