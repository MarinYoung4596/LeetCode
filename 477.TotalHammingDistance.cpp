/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.

Example:
Input: 4, 14, 2
Output: 6
Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
            showing the four bits relevant in this case). So the answer will be:
            HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.

Note:
Elements of the given array are in the range of 0 to 10^9
Length of the array will not exceed 10^4.

*/

// First Solution: O(N^2), Time Limit Exceeded
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int result = 0;
        std::sort(nums.begin(), nums.end());
        for (auto i = 0; i < nums.size(); ++i) {
            for (auto j = i + 1; j < nums.size(); ++j) {
                if (nums[j] == nums[i]) {
                    continue;
                }
                result += hamming_distance(nums[i], nums[j]);
            }
        }
        return result;
    }

private:
    int hamming_distance(int x, int y) {
        int result = 0;
        while (x > 0 || y > 0) {
            if ((x & 0b01) ^ (y & 0b01)) {
                ++result;
            }
            x = x >> 1;
            y = y >> 1;
        }
        return result;
    }
};

// Second Solution: to be continued...