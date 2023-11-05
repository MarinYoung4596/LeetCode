/*
There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the i-th round, you toggle every i bulb. For the n-th round, you only toggle the last bulb. Find how many bulbs are on after n rounds.

Example:
    Input: 3
    Output: 1
    Explanation:
        At first, the three bulbs are [off, off, off].
        After first round, the three bulbs are [on, on, on].
        After second round, the three bulbs are [on, off, on].
        After third round, the three bulbs are [on, off, off].

So you should return 1, because there is only one bulb is on.
*/

// First Solution: brute force: Time Limit Exceeded
class Solution {
public:
    int bulbSwitch(int n) {
        std::vector<bool> vec(n + 1, false);

        for (auto i = 1; i <= n; ++i) {
            for (auto j = 1 + i - 1; j <= n; j += i) {
                vec[j] = !vec[j];
            }
        }
        int result = 0;
        for (auto i = 1; i <= n; ++i) {
            if (vec[i]) {
                ++result;
            }
        }
        return result;
    }
};

// Second Solution:
class Solution2 {
public:
    // 1、因为电灯一开始都是关闭的，所以某一盏灯最后如果是点亮的，必然要被按奇数次开关
    // 2、  假设6栈灯，则第6栈灯是灭的，因为 6=1*6=2*3 (因子成对出现)
    // 3、  16=1*16=2*8=4*4；因子4重复出现，因子实际被按了5次，为奇数
    // 4、问题转化为判断当前这盏灯的编号是否是某个数的平方（即平方根），而平方根就是答案
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};