/*****************************************************************
*   Copyright (C) 2023 All rights reserved.
*
*   @file:    468.ValidateIPAddress.cpp
*   @author:  marinyoung@163.com
*   @date:    2023/12/03 19:28:42
*   @brief:

Given a string queryIP, return
    "IPv4" if IP is a valid IPv4 address,
    "IPv6" if IP is a valid IPv6 address or
    "Neither" if IP is not a correct IP of any type.

A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain leading zeros.

For example, "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses while "192.168.01.1", "192.168.1.00", and "192.168@1.1" are invalid IPv4 addresses.

A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:
    1 <= xi.length <= 4
    xi is a hexadecimal string which may contain digits, lowercase English letter ('a' to 'f') and upper-case English letters ('A' to 'F').
    Leading zeros are allowed in xi.

For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and "2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 addresses, while "2001:0db8:85a3::8A2E:037j:7334" and "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are invalid IPv6 addresses.


Example 1:
    Input: queryIP = "172.16.254.1"
    Output: "IPv4"
    Explanation: This is a valid IPv4 address, return "IPv4".

Example 2:
    Input: queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
    Output: "IPv6"
    Explanation: This is a valid IPv6 address, return "IPv6".

Example 3:
    Input: queryIP = "256.256.256.256"
    Output: "Neither"
    Explanation: This is neither a IPv4 address nor a IPv6 address.


Constraints:
    queryIP consists only of English letters, digits and the characters '.' and ':'.

*****************************************************************/


class Solution {
public:
    string validIPAddress(string queryIP) {
        auto sep = queryIP.find(':') != string::npos ? ':' : '.';
        vector<string> vec;
        split_str(queryIP, vec, sep);
        if (sep == ':') {
            return check_valid_ipv6(vec) ? "IPv6" : "Neither";
        } else {
            return check_valid_ipv4(vec) ? "IPv4" : "Neither";
        }
    }

private:
    void split_str(const string &str, vector<string> &vec, char sep) {
        if (str.empty()) {
            return;
        }
        if (!vec.empty()) {
            vec.clear();
        }
        auto beg = 0;
        auto end = str.find_first_of(sep);
        while (end != string::npos) {
            vec.push_back(str.substr(beg, end - beg));

            beg = end + 1;
            end = str.find_first_of(sep, beg);
        }
        vec.push_back(str.substr(beg, str.size() - beg));
    }

    bool check_valid_ipv4(const vector<string> &vec) {
        if (vec.size() != 4) {
            return false;
        }
        for (const auto &item : vec) {
            if (item.empty() || item.size() > 3) {
                return false;
            }
            auto v = 0;
            for (auto i = 0; i < item.size(); ++i) {
                if (!isdigit(item[i])) {
                    return false;
                }
                if (item.size() > 1 && i == 0 && item[i] == '0') {
                    return false;
                }
                v = v * 10 + (item[i] - '0');
            }
            if (v > 255) {
                return false;
            }
        }
        return true;
    }

    bool check_valid_ipv6(const vector<string> &vec) {
        if (vec.size() != 8) {
            return false;
        }
        for (const auto &item : vec) {
            if (item.empty() || item.size() > 4) {
                return false;
            }
            for (auto i = 0; i < item.size(); ++i) {
                if (!(isdigit(item[i]) || isalpha(item[i]))) {
                    return false;
                }
                if (isalpha(item[i]) &&
                        !((item[i] >= 'a' && item[i] <= 'f') ||
                        (item[i] >= 'A' && item[i] <= 'F'))) {
                    return false;
                }
            }
        }
        return true;
    }
};