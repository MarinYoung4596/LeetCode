#ifndef _UTIL_H_
#define _UTIL_H_

#include <iostream>
#include <cstdio>
#include <vector>

template <typename Iter>
void printx(Iter begin, Iter end, char sep='\t') {
    for (Iter it = begin; it != end; ++it) {
        std::cout << *it << sep;
    }
    std::cout << '\n';
}

template <typename T>
void print_vector(const std::vector<T> &vec, char sep='\t') {
    printx(vec.begin(), vec.end(), sep);
}

template <typename T>
void print_vector(const std::vector<T> &vec, int begin, int end, char sep='\t') {
    for (auto i = begin; i < end; ++i) {
        std::cout << vec[i] << sep;
    }
    std::cout << '\n';
}

template <typename T>
void print_matrix(const std::vector<std::vector<T>> &matrix) {
    for (const auto &row : matrix) {
        printx(row.begin(), row.end());
    }
}

void print_gap() {
    std::vector<char> vec(50, '-');
    print_vector(vec, char());
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

#endif /* _UTIL_H_ */
