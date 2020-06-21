/*
https://leetcode.com/problems/binary-watch/

A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.


For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]

Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".

*/

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        std::vector<int> bit_num_map[6];
        get_bit_number_map(60, bit_num_map);

        std::vector<std::string> result;
        for (auto i = 0; i <= num && i < 4; ++i) {
            auto &hour_map = bit_num_map[i];
            for (const auto &hour : hour_map) {
                if (hour < 0 || hour > 11) {
                    break;
                }
                auto tmp_result = get_time_str(hour, false);
                for (auto j = 0; j <= num - i && j < 6; ++j) {
                    if (i + j != num) {
                        continue;
                    }
                    auto &minute_map = bit_num_map[j];
                    for (const auto &minute : minute_map) {
                        auto cur_time = tmp_result + ":" + get_time_str(minute, true);
                        result.push_back(cur_time);
                    }
                }
            }
        }
        return result;
    }
    
    std::string get_time_str(int n, int is_minute) {
        if (n < 10 && is_minute) {
            std::string str = "0";
            str.push_back(static_cast<char>('0' + n));
            return str;
        } else {
            return std::to_string(n);
        }
    }
    
    void get_bit_number_map(int n, std::vector<int>* bit_number_map) {
        for (auto i = 0; i < n; ++i) {
            auto nbits = count_bits(i);
            bit_number_map[nbits].push_back(i);
        }
    }
    
    int count_bits(int n) {
        int result = 0;
        while (n > 0) {
            result += (n & 0b01);
            n = n >> 1;
        }
        return result;
    }
};