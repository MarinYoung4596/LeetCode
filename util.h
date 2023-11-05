#ifndef _UTIL_H_
#define _UTIL_H_

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <algorithm>

using namespace std;

template <typename Iter>
void printx(Iter begin, Iter end, char sep='\t', bool wrap_line=true) {
    for (Iter it = begin; it != end - 1; ++it) {
        std::cout << *it << sep;
    }
    std::cout << *(end - 1);
    if (wrap_line) {
        std::cout << '\n';
    }
}

template <typename T>
void print_vector(const std::vector<T> &vec, char sep='\t', bool wrap_line=true) {
    printx(vec.begin(), vec.end(), sep, wrap_line);
}

// template <typename T>
// void print_vector(const std::vector<T> &vec, int begin, int end, char sep='\t') {
//     for (auto i = begin; i < end; ++i) {
//         std::cout << vec[i] << sep;
//     }
// }

template <typename Type>
void shuffle_vector(std::vector<Type> &vec) {
    shuffle(vec.begin(), vec.end(), std::default_random_engine(std::random_device()()));
}

template <typename T>
void print_matrix(const std::vector<std::vector<T>> &matrix) {
    for (const auto &row : matrix) {
        printx(row.begin(), row.end(), '\t', true);
    }
}

void print_gap(const std::string &comment="", char sep='-', int len=50) {
    std::vector<char> vec(len, sep);
    print_vector(vec, char(), false);
    std::cout << comment;
    print_vector(vec, char(), true);
}

template <typename Type>
void split(const std::string &str, Type sep, std::vector<std::string> &vec) {
    auto begin = 0;
    auto end = str.find_first_of(sep, begin);
    while (end != std::string::npos) {
        vec.push_back(str.substr(begin, end - begin));

        begin = str.find_first_not_of(sep, end);
        end = str.find_first_of(sep, begin);
    }
    if (begin != end) {
        vec.push_back(str.substr(begin, str.size() - begin));
    }
}

template <typename Type>
std::string join(const std::vector<Type> &vec, char sep='\t') {
    if (vec.empty()) {
        return std::string();
    }
    std::stringstream ss;
    for (auto i = 0; i != vec.size() - 1; ++i) {
        ss << vec[i] << sep;
    }
    ss << vec[vec.size() - 1];
    return ss.str();
}

// 差分数组, 降低计算量
class DifferenceVector {
public:
    DifferenceVector(const std::vector<int>& v) {
        diff.resize(v.size(), 0);
        for (auto i = 1; i < v.size(); ++i) {
            diff[i] = v[i] - v[i - 1];
        }
    }

    // 给[begin, end] 闭区间增加 val
    void increment(int begin, int end, int value) {
        diff[begin] += value;  // begin 位置+value
        if (end + 1 < diff.size()) {
            diff[end + 1] -= value;  // end 的下一个位置-value (因为 num 每个区间都+value了)
        }
    }

    // 返回结果数组
    std::vector<int> get_result() const {
        std::vector<int> res(diff.size(), 0);
        res[0] = diff[0];
        for (auto i = 1; i < res.size(); ++i) {
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }

private:
    std::vector<int> diff;
};

#endif /* _UTIL_H_ */
